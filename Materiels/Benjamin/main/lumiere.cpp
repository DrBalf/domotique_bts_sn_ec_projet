#include "Arduino.h"
#include "lumiere.h"

int ledPin = 8;

void initLumiere(void){
  pinMode(ledPin, OUTPUT);
}

bool lumiere(int positionLumiere){
  bool etat=false; 
  if(positionLumiere==1){
    digitalWrite(ledPin, HIGH);
    etat=true;
  }

  if(positionLumiere==0){
    digitalWrite(ledPin, LOW);
    etat=false;
  }

  return etat;
}

