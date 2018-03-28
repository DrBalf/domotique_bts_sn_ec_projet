#include "Arduino.h"
#include "capteurSecurite.h"

#define CAPTEUR_INCENDIE 35
#define CAPTEUR_MOUVEMENT 36

void initCapteur(void){
  pinMode(CAPTEUR_INCENDIE, INPUT);
  pinMode(CAPTEUR_MOUVEMENT, INPUT);
}

bool incendie(void){
  int fumeeDetecte = digitalRead(CAPTEUR_INCENDIE);
  if(fumeeDetecte == HIGH){
    return true;
  }
  else{
    return false;
  }
}

bool mouvement(void){
  int mouvementDetecte = digitalRead(CAPTEUR_MOUVEMENT);
  if(mouvementDetecte == HIGH){
    return true;
  }
  else{
    return false;
  }
}

