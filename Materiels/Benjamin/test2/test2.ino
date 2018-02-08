int cmdUp = 2;
int cmdDown = 3;
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
      while(digitalRead(switchUp)==LOW){
         Serial.println("Le volet monte");
         digitalWrite(cmdUp,HIGH);
      }
      
    }
    if(valeur=='2'){
      while(digitalRead(switchDown)==LOW){
        Serial.println("Le volet descend");
        digitalWrite(cmdDown,HIGH);
      }
    }
      
    
    }
  }
