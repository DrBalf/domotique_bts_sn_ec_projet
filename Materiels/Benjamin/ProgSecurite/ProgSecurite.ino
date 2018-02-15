#include <Arduino.h>
#include "securite.h"

#define CAPTEUR_INCENDIE 2
#define CAPTEUR_MOUVEMENT 3

void setup()
{
  Serial.begin(9600);
  pinMode(CAPTEUR_INCENDIE, INPUT);
  pinMode(CAPTEUR_MOUVEMENT, INPUT);
}

void loop() 
{
  if(mouvementDetecte()== true){
    Serial.println("Mouvement detecte !");
    delay(2000);
  }
  
  if(isFumeDetected()== true){
    Serial.println("A l'help !");
    delay(1000);
  }
  else{
    Serial.println("Aucune fumee");
    delay(1000);
  }
}




