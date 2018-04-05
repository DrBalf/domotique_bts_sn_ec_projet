#include "controleRadiateur.h"
#include"Arduino.h"
int pinRelai = 2;
char valeurEtat;

void initRelai(){
  pinMode(pinRelai, OUTPUT);
}

void relai(bool mode, double temperature, double temperatureUtilisateur, bool valeurEtat){
  if (mode==false){  
      if (valeurEtat==true){
        digitalWrite(pinRelai,HIGH); 
      }
      if (valeurEtat==false){
        digitalWrite(pinRelai,LOW);
      }
  }
  if (mode==true){
    if(temperature<=temperatureUtilisateur-1){
      digitalWrite(pinRelai,HIGH);
    }
    if(temperature>=temperatureUtilisateur){
      digitalWrite(pinRelai,LOW);   
    }
  }
}

bool etatRelai(){
  bool val = digitalRead(pinRelai);
  return val;
}

