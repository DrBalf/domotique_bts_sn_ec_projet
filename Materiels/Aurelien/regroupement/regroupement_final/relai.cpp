#include "relai.h"
#include"Arduino.h"
int pin_relai = 2;
char valeur;

void initrelai(){
  pinMode(pin_relai, OUTPUT);
  digitalWrite(pin_relai,LOW);
  Serial.println("entre 0 pour allumer le radiateur");
  Serial.println("entre 1 pour eteindre le radiateur\n");
}

void relai(){
    while(Serial2.available() > 0) {  
    valeur = Serial2.read();
    Serial.println(valeur);
  }  
  if (valeur==6){
    digitalWrite(pin_relai,LOW); 
  }
  if (valeur==7){
    digitalWrite(pin_relai,HIGH);
  }
}

bool etatRelai(){
  bool val = digitalRead(pin_relai);
  return val;
}

