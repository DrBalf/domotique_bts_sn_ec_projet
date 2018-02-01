int ledPin = 8;
int commande = 0;

void setup() {
  
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if(commande==1){
    digitalWrite(ledPin, HIGH);
  }

  if(commande==0){
    digitalWrite(ledPin, LOW);
  }

}
