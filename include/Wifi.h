#include "../src/WiFiManager/WiFiManager.h" // https://github.com/tzapu/WiFiManager

WiFiManager wm;

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

void initWifi() {
  WiFi.mode(WIFI_STA);
  WiFi.onEvent(WiFiEvent); 
    
  //reset settings - wipe credentials for testing
  //wm.resetSettings();
  wm.setConfigPortalBlocking(false);

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