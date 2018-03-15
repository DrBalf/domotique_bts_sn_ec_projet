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
    if (valeur=='1'){
      digitalWrite(pin_relai,HIGH); 
    }
    else{
      digitalWrite(pin_relai,LOW);
    }
 }
}

bool etatRelai(){
  bool val = digitalRead(pin_relai);
  return val;
}

