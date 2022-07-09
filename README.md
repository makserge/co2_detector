# CO2 detector

Based on https://github.com/melkati/CO2-Gadget

If Wi-fi is not configured / not available on boot, device enables access point on http://192.168.4.1

Once Wi-fi was configured, device will switch off access point and immediately connects to selected Wi-fi network and updates date / time by NTP.

Web interface data should be loaded to SPIFFS as well as sketch.
To load data to SPIFFS, copy tool/esp32fs.jar to ~/Documents/arduino/tools/ESP32FS/tool
then open Arduino 1.x, open sketch folder and run Tools -> ESP32 Sketch Data Upload

Device data is available via http://co2detector.local/
