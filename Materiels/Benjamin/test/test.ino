int cmdVolets = 2;
int switchDown = 3;
char valeur;

void setup() {
  Serial.begin(9600);
  pinMode(cmdVolets, OUTPUT);
  pinMode(switchDown, OUTPUT);
  digitalWrite(cmdVolets,LOW);
  digitalWrite(switchDown,LOW);
}

void loop() {
    
    if (Serial.available() > 0) {
      valeur = Serial.read();
      if (valeur=='1'){
        digitalWrite(cmdVolets,LOW);
      }
      if (valeur=='2'){
        digitalWrite(cmdVolets,HIGH);
      }
      while(digitalRead(cmdVolets)==HIGH){
        digitalWrite(switchDown,HIGH);
    }
    }
 
}
