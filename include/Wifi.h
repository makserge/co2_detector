#include <FS.h>
#include <SPIFFS.h>
#include <ArduinoJson.h> // https://github.com/bblanchon/ArduinoJson

#include "../src/WiFiManager/WiFiManager.h" // https://github.com/tzapu/WiFiManager

WiFiManager wm;

char mqttBroker[40] = MQTT_BROKER;
char mqttPort[6] = MQTT_PORT;
char mqttUser[20];
char mqttPass[20];
char mqttRootTopic[30] = MQTT_ROOT_TOPIC; 

WiFiManagerParameter customMqttBroker, customMqttPort, customMqttUser, customMqttPass, customMqttRootTopic;

void WiFiEvent(WiFiEvent_t event) {
  switch (event) {
    case SYSTEM_EVENT_STA_GOT_IP:
      activeWIFI = true;
      break;
    case WL_DISCONNECTED:
      activeWIFI = false;
      break;  
    default:
      break;
  }
  showWiFiIcon(activeWIFI, 2, 3);    
}

void saveConfigCallback () {
  Serial.println("saving config");

  if (SPIFFS.begin()) {
    Serial.println("mounted file system");
 
    File configFile = SPIFFS.open(CONFIG_FILE, "w");
    if (!configFile) {
      Serial.println("failed to open config file for writing");
      return;
    }

    DynamicJsonDocument json(1024);
  
    json["mqtt_broker"] = customMqttBroker.getValue();
    json["mqtt_port"] = customMqttPort.getValue();
    json["mqtt_user"] = customMqttUser.getValue();
    json["mqtt_pass"] = customMqttPass.getValue();
    json["mqtt_topic"] = customMqttRootTopic.getValue();

    serializeJson(json, configFile);
    configFile.close();

    SPIFFS.end();
  } else {
    Serial.println("failed to mount FS");
  }
}

void loadCredentials() {
  if (SPIFFS.begin()) {
    Serial.println("mounted file system");
    if (SPIFFS.exists(CONFIG_FILE)) {
      Serial.println("reading config file");
      File configFile = SPIFFS.open(CONFIG_FILE, "r");
      if (configFile) {
        Serial.println("opened config file");
        size_t size = configFile.size();
        std::unique_ptr<char[]> buf(new char[size]);

        configFile.readBytes(buf.get(), size);

        DynamicJsonDocument json(1024);
        auto deserializeError = deserializeJson(json, buf.get());
        if (!deserializeError) {
          strcpy(mqttBroker, json["mqtt_broker"]);
          strcpy(mqttPort, json["mqtt_port"]);
          strcpy(mqttUser, json["mqtt_user"]);
          strcpy(mqttPass, json["mqtt_pass"]);
          strcpy(mqttRootTopic, json["mqtt_topic"]);
        } else {
          Serial.println("failed to load json config");
        }
        configFile.close();
        SPIFFS.end();
      }
    }
  } else {
    Serial.println("failed to mount FS");
  }
}

void initWifi() {
  WiFi.mode(WIFI_STA);
  WiFi.onEvent(WiFiEvent); 
    
  //reset settings - wipe credentials for testing
  //wm.resetSettings();
  wm.setConfigPortalBlocking(false);

  loadCredentials();

  new (&customMqttBroker) WiFiManagerParameter("mqtt_broker", "MQTT broker", mqttBroker, 40);
  new (&customMqttPort) WiFiManagerParameter("mqtt_port", "MQTT port", mqttPort, 6);
  new (&customMqttUser) WiFiManagerParameter("mqtt_user", "MQTT user", mqttUser, 20);
  new (&customMqttPass) WiFiManagerParameter("mqtt_pass", "MQTT pass", mqttPass, 20);
  new (&customMqttRootTopic) WiFiManagerParameter("mqtt_topic", "MQTT root topic", mqttRootTopic, 30);

  wm.addParameter(&customMqttBroker);
  wm.addParameter(&customMqttPort);
  wm.addParameter(&customMqttUser);
  wm.addParameter(&customMqttPass);
  wm.addParameter(&customMqttRootTopic);
  
  wm.setSaveConfigCallback(saveConfigCallback);

  //automatically connect using saved credentials if they exist
  //If connection fails it starts an access point with the specified name
  if (wm.autoConnect("CO2 sensor")){
      Serial.println("connected...");
  } else {
      Serial.println("Configportal running");
  }
}

void processWifi() {
  wm.process();
}