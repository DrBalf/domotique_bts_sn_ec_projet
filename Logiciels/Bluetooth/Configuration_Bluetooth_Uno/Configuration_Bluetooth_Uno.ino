void setup()
{
  Serial.begin(9600);
  Serial.print("Enter AT commands:");
  Serial3.begin(9600);
  pinMode(9, OUTPUT);  // this pin will pull the HC-05 pin 34 (key pin) HIGH to switch module to AT mode
  digitalWrite(9,HIGH);
}
 
void loop()
{
 
  // Read from HC-05 and send it to Arduino Serial Monitor


  if (Serial3.available() > 0)
  {
    Serial.write(Serial3.read());
  }
 
  // Read from Arduino Serial Monitor and send to HC-05
  if (Serial.available())
  {
    Serial3.write(Serial.read());
  }
}
