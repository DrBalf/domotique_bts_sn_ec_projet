#include <SoftwareSerial.h>

void setup()
{
  Serial.begin(9600);
  Serial.print("Enter AT commands:");
  Serial1.begin(9600);  
}
 
void loop()
{
 
  // Read from HC-05 and send it to Arduino Serial Monitor
  if (Serial1.available())
  {
    Serial.write(Serial1.read());
  }
 
  // Read from Arduino Serial Monitor and send to HC-05
  if (Serial.available())
  {
    Serial1.write(Serial.read());
  }
}
