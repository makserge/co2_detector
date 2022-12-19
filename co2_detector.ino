#define TIMEZONE "CET-1CEST,M3.5.0,M10.5.0/3" //Europe/Berlin , full list of timezones at https://github.com/nayarsystems/posix_tz_db/blob/master/zones.csv

#define BACKLIGHT_PIN 33

#define CO2_RED_RANGE 1000
#define CO2_ORANGE_RANGE 700

#define HOSTNAME "co2detector"   // http://co2detector.local

#define CONFIG_FILE "/config.json"
#define MQTT_BROKER "192.168.8.100"
#define MQTT_PORT "1883"
#define MQTT_CLIENT_ID "co2detector"
#define MQTT_ROOT_TOPIC "co2detector"

#define START_CHECKING_AFTER 5000 //5s

#define LOW_BRIGTNESS_HOUR 22
#define HIGH_BRIGTNESS_HOUR 7

#define BRIGHTNESS_LOW 20
#define BRIGHTNESS_HIGH 150

bool activeWIFI, activeMQTT, newReadingsAvailable;

uint16_t co2, lastCo2;
float temp, hum, lastTemp, lastHum;
int64_t lastReadingsCommunicationTime;
int32_t hours;

void showWiFiIcon(bool activeWIFI, int32_t posX, int32_t posY);

#include "include/Wifi.h"
#include "include/TFT.h"
#include "include/Sensor.h"
#include "include/Clock.h"
#include "include/MQTT.h"
#include "include/Web.h"

void setup() {
  Serial.begin(115200);
  setCpuFrequencyMhz(80);
  initSensor();
  initDisplay();
  initClock();
  initWifi();
  if (activeWIFI) {
    initWeb();
    initMQTT();
  }
}

void loop() {
  mqttClientLoop();
  processWifi();
  if ((millis() - lastReadingsCommunicationTime >= START_CHECKING_AFTER)) {
    lastReadingsCommunicationTime = millis();

    readSensor(co2, temp, hum);
    showMQTTIcon(30, 3);
    showClock();
    setBrightness();
  }
  if (lastCo2 != co2) {
    showCO2(lastCo2, co2);
    lastCo2 = co2;
    newReadingsAvailable = true;
  }  
  if (lastTemp != temp) {
    lastTemp = temp;
    showTemperature(temp);
    newReadingsAvailable = true;
  }
  if (lastHum != hum) {
    lastHum = hum;
    showHumidity(hum);
    newReadingsAvailable = true;
  }
  if (newReadingsAvailable) {
    newReadingsAvailable = false;
    publishMQTT();
  }
}
