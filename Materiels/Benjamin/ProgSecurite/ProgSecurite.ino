#include <Arduino.h>
#include "securite.h"

//#define CAPTEUR_INCENDIE 2
#define CAPTEUR_MOUVEMENT 3
#define INTERRUPTEUR 4

void setup()
{
  Serial.begin(9600);
  //pinMode(CAPTEUR_INCENDIE, INPUT);
  pinMode(CAPTEUR_MOUVEMENT, INPUT);
  pinMode(INTERRUPTEUR, INPUT);
}

void loop(){
  if(digitalRead(4)==HIGH){
    if(mouvementDetecte()== true){
      Serial.println("Mouvement detecte !");
      delay(2000);
    }
  }
  
  //if(isFumeDetected()== true){
    //Serial.println("fumee detecte !");
    //delay(1000);
  //}
}


