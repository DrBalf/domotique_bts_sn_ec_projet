#include "relai.h"
#include"Arduino.h"
int pin_relai = 2;
char valeur;

void initrelai(){
  pinMode(pin_relai, OUTPUT);
  digitalWrite(pin_relai,HIGH);
  Serial.println("entre 0 pour allumer le radiateur");
  Serial.println("entre 1 pour eteindre le radiateur\n");
}

void relai(){
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

