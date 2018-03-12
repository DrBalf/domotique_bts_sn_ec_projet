
void setup()
{
  Serial.begin(9600);
  Serial.print("Enter AT commands:");
  Serial2.begin(9600);
  Serial1.begin(9600);
  pinMode(9, OUTPUT);  // this pin will pull the HC-05 pin 34 (key pin) HIGH to switch module to AT mode
  digitalWrite(9, HIGH);
}
 
void loop()
{
   Serial1.print("lum Eteinte$lux 16$vol1 Ouvert$vol2 Fermer$rad allumé$tem 22$con 65$air 10$hum 20$der 12/03/2018$"); 
   delay(300);
}
