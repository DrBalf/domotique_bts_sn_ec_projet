#include "relai.h"
#include"Arduino.h"
int pin_relai = 2;
char valeur;

void initrelai(){
  pinMode(pin_relai, OUTPUT);
}

void relai(bool mode, double temperature, double temperatureUtilisateur, bool valeur){
  if (mode==false){  
      if (valeur==true){
        digitalWrite(pin_relai,HIGH); 
      }
      if (valeur==false){
        digitalWrite(pin_relai,LOW);
      }
  }
  if (mode==true){
    if(temperature<=temperatureUtilisateur-1){
      digitalWrite(pin_relai,HIGH);
    }
    if(temperature>=temperatureUtilisateur){
      digitalWrite(pin_relai,LOW);   
    }
  }
}

bool etatRelai(){
  bool val = digitalRead(pin_relai);
  return val;
}

