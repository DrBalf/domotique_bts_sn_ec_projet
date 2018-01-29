#include <Wire.h>
#include "arduino.h"
#include <SFE_BMP180.h>
#include <SFE_BMP180.h>

void setup() {
  Serial.begin(9600);
  if (pressure.begin())
    Serial.println("BMP180 init success");
  else
  {
    Serial.println("BMP180 init fail\n\n");
    while(1); // Pause forever.
  }

}

void loop() {

  double T;
    
  pressure.startTemperature();
  pressure.getTemperature(T);

}
