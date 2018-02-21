int cmdUp = 6;
int cmdDown = 7;
int switchUp = 4;
int switchDown = 5;
char valeur;

void setup() {
  Serial.begin(9600);
  pinMode(cmdUp, OUTPUT);
  pinMode(cmdDown, OUTPUT);
  pinMode(switchUp, INPUT);
  pinMode(switchDown, INPUT);
}

void loop() {
    
    if (Serial.available() > 0) {
      
    valeur = Serial.read();
    
      if (valeur=='1'){
        while(digitalRead(switchUp)==HIGH){
           digitalWrite(cmdUp,HIGH);
        }
        digitalWrite(cmdUp,LOW);        
      }
      
      if(valeur=='2'){
        while(digitalRead(switchDown)==HIGH){
          digitalWrite(cmdDown,HIGH);
        }
        digitalWrite(cmdDown,LOW);
      }
          
    }
}
