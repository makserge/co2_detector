#include "../src/WiFiManager/WiFiManager.h" // https://github.com/tzapu/WiFiManager

WiFiManager wm;
WiFiManagerParameter custom_mqtt_server("server", "mqtt server", "", 40);

void saveParamsCallback () {
  Serial.println("Get Params:");
  Serial.print(custom_mqtt_server.getID());
  Serial.print(" : ");
  Serial.println(custom_mqtt_server.getValue());
}

void WiFiEvent(WiFiEvent_t event) {
    switch (event) {
        case SYSTEM_EVENT_STA_GOT_IP:
            Serial.print("Obtained IP address: ");
            Serial.println(WiFi.localIP());
            activeWIFI = true;
            break;
        default:
            break;
    }
}

void initWifi() {
  WiFi.mode(WIFI_STA);
  WiFi.onEvent(WiFiEvent); 
    
  //reset settings - wipe credentials for testing
  //wm.resetSettings();
  wm.addParameter(&custom_mqtt_server);
  wm.setConfigPortalBlocking(false);
  wm.setSaveParamsCallback(saveParamsCallback);

  //automatically connect using saved credentials if they exist
  //If connection fails it starts an access point with the specified name
  if (wm.autoConnect("CO2 sensor")){
      Serial.println("connected...yeey :)");
  } else {
      Serial.println("Configportal running");
  }
}

void processWifi() {
  wm.process();
}