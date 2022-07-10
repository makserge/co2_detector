#include <PubSubClient.h>

#define TIME_BETWEEN_MQTT_PUBLISH 30 //30s
#define SECONDS_BETWEEN_RETRIES 15
#define MAX_CONNECTION_RETRIES 5

uint64_t lastTimeMQTTPublished = 0;
bool enableMQTT = true;

WiFiClient espClient;
PubSubClient mqttClient(espClient);

void mqttReconnect() {
  static uint64_t timeStamp = 0;
  static uint16_t connectionRetries = 0;
  if (millis() - timeStamp >= (SECONDS_BETWEEN_RETRIES * 1000)) { // Max one try each secondsBetweenRetries*1000 seconds
    timeStamp = millis();
    if (!mqttClient.connected()) {
      Serial.printf("-->[MQTT] Attempting MQTT connection... ");
      // Attempt to connect            
      if (mqttClient.connect(MQTT_CLIENT_ID, MQTT_USER, MQTT_PASS)) {
        activeMQTT = true;
        Serial.printf("connected\n");
      } else {
        ++connectionRetries;
        mqttClient.setSocketTimeout(2); //Drop timeout to 2 secs for subsecuents tries
        Serial.printf(" not possible to connect to %s ", MQTT_BROKER);
        Serial.printf("Connection status:  %d. (%d of %d retries)\n", mqttClient.state(), connectionRetries, MAX_CONNECTION_RETRIES); // Possible States: https://pubsubclient.knolleary.net/api#state
        if (connectionRetries >= MAX_CONNECTION_RETRIES) {
          enableMQTT = false;
          Serial.printf("-->[MQTT] Max retries to connect to MQTT broker reached, disabling MQTT...\n");
        }
      }
    }
  }
}

void publishIntMQTT(String topic, int16_t payload) {
  char charPublish[20];
  dtostrf(payload, 0, 0, charPublish);
  topic = MQTT_ROOT_TOPIC + topic;
  Serial.printf("-->[MQTT] Publishing %d to ", payload);
  Serial.println("topic: " + topic);
  mqttClient.publish((topic).c_str(), charPublish);
}

void publishFloatMQTT(String topic, float payload) {
  char charPublish[20];
  dtostrf(payload, 0, 2, charPublish);
  topic = MQTT_ROOT_TOPIC + topic;
  Serial.printf("-->[MQTT] Publishing %.0f to ", payload);
  Serial.println("topic: " + topic);
  mqttClient.publish((topic).c_str(), charPublish);
}

void initMQTT() {
  if (mqttClient.connected()) {
    mqttClient.disconnect();
  }
  Serial.printf("-->[MQTT] Initializing MQTT to broker IP: %s\n", MQTT_BROKER);
  mqttClient.setServer(MQTT_BROKER, 1883);
  mqttReconnect();
}

void publishMQTT() {
  if (activeWIFI && activeMQTT && mqttClient.connected() && (millis() - lastTimeMQTTPublished >= TIME_BETWEEN_MQTT_PUBLISH * 1000)) {
    publishIntMQTT("/co2", co2);
    publishFloatMQTT("/temp", temp);
    publishFloatMQTT("/hum", hum);
    lastTimeMQTTPublished = millis();
  }
}

void mqttClientLoop() {
  if (enableMQTT) {
    mqttReconnect();
    if (mqttClient.connected()) {
      mqttClient.loop();
    }
  }
}