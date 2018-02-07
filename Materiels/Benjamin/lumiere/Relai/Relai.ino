#include"Arduino.h"
int pin_relai = 2;
char valeur;

void setup() {
  pinMode(pin_relai, OUTPUT);
  digitalWrite(pin_relai,HIGH);
  Serial.begin(9600);
  Serial.println("0 = allumer radiateur");
  Serial.println("1 = eteindre radiateur");
}

void loop() {
  
  if (Serial.available() > 0) {
    valeur = Serial.read();
    Serial.print("Radiateur = ");
    if (valeur=='1'){
      digitalWrite(pin_relai,HIGH);
      Serial.println("etteind");  
    }
    else{
      digitalWrite(pin_relai,LOW);
      Serial.println("allumer");   
    }
  }              
}
