#include <TFT_eSPI.h>
#include <SPI.h>

#include "FontArchivoNarrow_Regular10pt7b.h"
#include "FontCO2Gadget50ptDigits.h"
#include "icons.h"

#define FF90 &ArchivoNarrow_Regular10pt7b
#define FF95 &FontCO2GadgetDigits50pt7b

TFT_eSPI tft = TFT_eSPI();

void initDisplay() {
  pinMode(BACKLIGHT_PIN, OUTPUT);
  ledcSetup(0, 5000, 8);
  ledcAttachPin(BACKLIGHT_PIN, 0);
  ledcWrite(0, 255);
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  tft.setTextSize(2);
}

void showCO2(uint16_t lastCo2, uint16_t co2) {
  if (co2 > 9999) {
    co2 = 9999;
  }
  
  tft.setTextSize(1);
  tft.setTextDatum(BR_DATUM);
  tft.setFreeFont(FF95);
  
  if (lastCo2 > co2) {
    tft.setTextColor(TFT_BLACK, TFT_BLACK);
    tft.drawString(String(lastCo2), tft.width() - 39, 112);
  }
   
  if (co2 >= CO2_RED_RANGE) {
    tft.setTextColor(TFT_RED, TFT_BLACK);
  } else if (co2 >= CO2_ORANGE_RANGE) {
    tft.setTextColor(TFT_ORANGE, TFT_BLACK);
  } else {
    tft.setTextColor(TFT_GREEN, TFT_BLACK);
  }
  
  tft.drawString(String(co2), tft.width() - 39, 112);

  tft.setTextDatum(BR_DATUM);
  tft.setFreeFont(FF90);
  tft.drawString("ppm", tft.width(), 102);
}

void showTemperature(float temp) {
  if (temp >= 30) {
    tft.setTextColor(TFT_ORANGE, TFT_BLACK);
  } else if (temp >= 10) {
    tft.setTextColor(TFT_LIGHTGREY, TFT_BLACK);
  } else {
    tft.setTextColor(TFT_SKYBLUE, TFT_BLACK);
  }
  tft.setTextSize(1);
  tft.setTextDatum(BL_DATUM);
  tft.setSwapBytes(true);
  tft.pushImage(2, tft.height() - 22, 16, 16, iconTemperature);
  tft.drawString(String(temp, 1) + "`" , 23 , tft.height() - 2);
}

void showHumidity(float hum) {
  if (hum <= 25) {
    tft.setTextColor(TFT_WHITE, TFT_RED);
  } else if (hum < 40) {
    tft.setTextColor(TFT_ORANGE, TFT_BLACK);
  } else if (hum <= 60) {
    tft.setTextColor(TFT_LIGHTGREY, TFT_BLACK);
  } else if (hum < 75) {
    tft.setTextColor(TFT_SKYBLUE, TFT_BLACK);
  } else {
    tft.setTextColor(TFT_RED, TFT_SKYBLUE);
  }
  tft.setTextSize(1);
  tft.setTextDatum(BR_DATUM);
  tft.setSwapBytes(true);
  tft.pushImage(tft.width() - 60, tft.height() - 22, 16, 16, iconHumidity);
  tft.drawString(String(hum, 0) + "%", tft.width() - 5, tft.height()) - 2;
}

void showWiFiIcon(bool activeWIFI, int32_t posX, int32_t posY) {
  int8_t rssi = WiFi.RSSI();
  tft.drawRoundRect(posX - 2, posY - 2, 16 + 4, 16 + 4, 2, TFT_DARKGREY);
  if (!activeWIFI) {
    tft.drawBitmap(posX, posY, iconWiFi, 16, 16, TFT_BLACK, TFT_DARKGREY );
  } else {
    if (WiFi.status() == WL_CONNECTED) {
      if (rssi < 60)
        tft.drawBitmap(posX, posY, iconWiFi, 16, 16, TFT_BLACK, TFT_CYAN);
      else if (rssi < 70)
        tft.drawBitmap(posX, posY, iconWiFiMed, 16, 16, TFT_BLACK, TFT_ORANGE);
      else if (rssi < 90)
        tft.drawBitmap(posX, posY, iconWiFiMed, 16, 16, TFT_BLACK, TFT_YELLOW);
    } else {
      tft.drawBitmap(posX, posY, iconWiFiLow, 16, 16, TFT_BLACK, TFT_RED);
    }
  }
}

void showMQTTIcon(int32_t posX, int32_t posY) {
  tft.drawRoundRect(posX - 2, posY - 2, 16 + 4, 16 + 4, 2, TFT_DARKGREY);
  if (!activeMQTT) {
    tft.drawBitmap(posX - 1, posY - 1, iconMQTT, 16, 16, TFT_BLACK, TFT_DARKGREY);
  } else {
    tft.drawBitmap(posX - 1, posY - 1, iconMQTT, 16, 16, TFT_BLACK, TFT_CYAN);
  }
}

void showInfo(int32_t posX, int32_t posY, String data) {
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(1);
  tft.setSwapBytes(true);
  tft.drawString(data, posX, posY);
}


void showTime(String time) {
  showInfo(tft.width() - 20, 25, time);
}