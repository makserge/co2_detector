#define TIMEZONE "CET-1CEST,M3.5.0,M10.5.0/3" //Europe/Berlin , full list of timezones at https://github.com/nayarsystems/posix_tz_db/blob/master/zones.csv

#define BACKLIGHT_PIN 33

#define CO2_RED_RANGE 1000
#define CO2_ORANGE_RANGE 700

#define HOSTNAME "co2detector"   // http://co2detector.local

bool activeWIFI = false;
bool activeMQTT = false;

void showWiFiIcon(bool activeWIFI, int32_t posX, int32_t posY);

#include "include/Wifi.h"
#include "include/TFT.h"
#include "include/Sensor.h"
#include "include/Clock.h"

uint16_t co2 = 0;
float temp = 0.0;
float hum = 0.0;

#include "include/Web.h"

uint16_t lastCo2;
float lastTemp, lastHum;

void setup() {
  Serial.begin(115200);
  setCpuFrequencyMhz(80);
  initSensor();
  initDisplay();
  initClock();
  initWifi();
  if (activeWIFI) {
    initWeb();
  }
}

void loop() {
  processWifi();
  readSensor(co2, temp, hum);
  if (lastCo2 != co2) {
    showCO2(lastCo2, co2);
    lastCo2 = co2;
  }  
  if (lastTemp != temp) {
    lastTemp = temp;
    showTemperature(temp);
  }
  if (lastHum != hum) {
    lastHum = hum;
    showHumidity(hum);
  } 
  showClock();
  delay(5000);
}
