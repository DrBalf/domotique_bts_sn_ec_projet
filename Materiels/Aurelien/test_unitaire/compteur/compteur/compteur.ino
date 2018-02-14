int interuptePinCompteur = 2;

void setup() {
  Serial.begin(250000);
  pinMode(interuptePinCompteur, INPUT);
  attachInterrupt(digitalPinToInterrupt(interuptePinCompteur), interuption, FALLING);
}

void loop() {
  

}

void interuption(){
   Serial.println("bonjour");
}



