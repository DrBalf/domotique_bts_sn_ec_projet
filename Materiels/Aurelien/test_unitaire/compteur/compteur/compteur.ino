int interuptePinCompteur = 2;
bool flag=0;
void setup() {
  Serial.begin(9600);
  pinMode(interuptePinCompteur, INPUT_PULLUP);
  pinMode(3,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(interuptePinCompteur), interuption, LOW);
}

void loop() {
  

}

void interuption(){
  delay(50);
  if (digitalRead(interuptePinCompteur)==0){
    Serial.println("bonjour");
    if(flag){
      digitalWrite(3,HIGH);
      flag=0;
    }
    else{
      digitalWrite(3,LOW);
      flag=1;
    }
    while(digitalRead(interuptePinCompteur)!=1);  
  }   
}



