#include "SoftwareSerial.h"

SoftwareSerial mySerial(0, 1);

void setup()
{
  Serial.begin(115200);
  Serial.print("Enter AT commands:");
  mySerial.begin(115200);  
}
 
void loop()
{
 
  if (mySerial.available())
  {
    Serial.write(mySerial.read());
  }
 
  if (Serial.available())
  {
    mySerial.write(Serial.read());
  }
}
