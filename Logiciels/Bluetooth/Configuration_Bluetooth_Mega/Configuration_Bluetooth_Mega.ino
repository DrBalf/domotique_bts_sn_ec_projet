#include <SoftwareSerial.h>

SoftwareSerial Bluetooth(2,3); // RX // TX

void setup()
{
  pinMode(5,OUTPUT);
  digitalWrite(5,HIGH);
  Serial.begin(9600);
  Bluetooth.begin(9600);
  Serial.print("Enter AT commands:");
  

}
 
void loop()
{
  
  // Read from HC-05 and send it to Arduino Serial Monitor
  if (Bluetooth.available())
  {
    Serial.write(Bluetooth.read());
  }
 
  // Read from Arduino Serial Monitor and send to HC-05
  if (Serial.available())
  {
    Bluetooth.write(Serial.read());
  }
}
   
