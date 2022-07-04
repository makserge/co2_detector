#define BACKLIGHT_PIN 33

#define CO2_RED_RANGE 1000
#define CO2_ORANGE_RANGE 700

bool activeWIFI = false;

#include "include/Wifi.h"
#include "include/TFT.h"
#include "include/Sensor.h"

uint16_t co2 = 0;
float temp = 0.0;
float hum = 0.0;

uint16_t lastCo2 = 400;
float lastTemp, lastHum;

void setup() {
  Serial.begin(115200);
  setCpuFrequencyMhz(80);
  initSensor();
  initDisplay();
  initWifi();
  delay(3000);
}

void loop() {
  processWifi();
  readSensor(co2, temp, hum);
  //Serial.println(co2);  
  if (lastCo2 != co2) {
    lastCo2 = co2;
    showCO2(co2);
  }  
  if (lastTemp != temp) {
    lastTemp = temp;
    showTemperature(temp);
  }
  if (lastHum != hum) {
    lastHum = hum;
    showHumidity(hum);
  } 
  showWiFiIcon(24, 3);
  delay(5000);
}
