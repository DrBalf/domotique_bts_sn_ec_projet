void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
}

void loop() {
  if(digitalRead(2)==LOW){
    Serial.println("les volets sont fermé");
  }

  if(digitalRead(2)==HIGH){
    Serial.println("les volets sont ouvert");
  }
}
