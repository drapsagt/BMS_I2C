#include <Arduino.h>
#include <Wire.h>
#include "I2S_module.h"

#define S 2
#define high_V 4.2
#define low_V 3.2
#define high_T 60
#define max_I 2

void discoverI2CSlaves();

I2S_module modules[S];
bool tooManyDevices = false;

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  discoverI2CSlaves();
}

void loop()
{
  // put your main code here, to run repeatedly:
}

void discoverI2CSlaves()
{
  byte error, address;
  int nDevices;

  Serial.println("Scanning...");

  nDevices = 0;
  for (address = 1; address < 127; address++)
  {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0)
    {
      if (nDevices >= S)
      {
        tooManyDevices = true;
        continue;
      }
      modules[nDevices] = I2S_module(address);

      nDevices++;
    }
  }
}