#include <Wire.h>
#include "SFE_BMP180.h"
SFE_BMP180 pressure;

void setup() {
  Serial.begin(9600);
  if (pressure.begin())
    Serial.println("BMP180 init success");
  else
  {
    Serial.println("BMP180 init fail\n\n");
    while(1);
  }

}

void loop() {

  double T;
    
  pressure.startTemperature();
  delay(5);
  pressure.getTemperature(T);
  Serial.print("temperature: ");
  Serial.print(T,2);
  Serial.println(" deg C");
  delay(3000);  
    

}
