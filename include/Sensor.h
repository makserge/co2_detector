#include <Wire.h>

#define I2C_SDA 44
#define I2C_SCL 43
const int16_t SCD_ADDRESS = 0x62;

void initSensor() {
  Wire.begin(I2C_SDA, I2C_SCL);
  // wait until sensors are ready, > 1000 ms according to datasheet
  delay(1000);
  // start scd measurement in periodic mode, will update every 5 s
  Wire.beginTransmission(SCD_ADDRESS);
  Wire.write(0x21);
  Wire.write(0xb1);
  Wire.endTransmission();
}

void  readSensor(uint16_t &co2, float &temp, float &hum) {
  uint8_t data[12], counter;

  // send read data command
  Wire.beginTransmission(SCD_ADDRESS);
  Wire.write(0xec);
  Wire.write(0x05);
  if (Wire.endTransmission() != 0) {
    return;
  }
  
  // read measurement data: 2 bytes co2, 1 byte CRC,
  // 2 bytes T, 1 byte CRC, 2 bytes RH, 1 byte CRC,
  // 2 bytes sensor status, 1 byte CRC
  // stop reading after 12 bytes (not used)
  // other data like  ASC not included
  Wire.requestFrom(SCD_ADDRESS, 12);
  counter = 0;
  while (Wire.available()) {
    data[counter++] = Wire.read();
  }
  
  // floating point conversion according to datasheet
  co2 = (uint16_t)data[0] << 8 | data[1];
  // convert T in degC
  temp = -45 + 175 * (float)((uint16_t)data[3] << 8 | data[4]) / 65536;
  // convert RH in %
  hum = 100 * (float)((uint16_t)data[6] << 8 | data[7]) / 65536;
}