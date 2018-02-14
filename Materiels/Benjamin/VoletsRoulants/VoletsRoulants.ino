void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  if(digitalRead(3)==LOW){
    digitalWrite(2, HIGH);
  }
  
  if(digitalRead(4)==LOW){
    digitalWrite(2, LOW);
  }
}
