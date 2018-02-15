int interuptePinCompteur = 2;

void setup() {
  Serial.begin(9600);
  pinMode(interuptePinCompteur, INPUT);
  attachInterrupt(digitalPinToInterrupt(interuptePinCompteur), interuption, FALLING);
}

void loop() {
  

}

void interuption(){
   Serial.println("bonjour");
}



