void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
Serial1.print("$lumAllumé$lux3$vol1Ouvert$vol2Fermer$rad5$tem6$con7$air8$hum9$der10");
}
