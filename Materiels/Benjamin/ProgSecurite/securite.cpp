#include <Arduino.h>
#include "securite.h"

#define CAPTEUR_INCENDIE 2
#define CAPTEUR_MOUVEMENT 3
#define INTERRUPTEUR 4

bool isFumeDetected()
{
  if(digitalRead(4)==HIGH){
      int valCapteur = digitalRead(CAPTEUR_INCENDIE);
      if(valCapteur == HIGH)
      {
        return true;
      }
      else
      {
        return false;
      }
  }
}

bool mouvementDetecte()
{
  int valeurCapteur = digitalRead(CAPTEUR_MOUVEMENT);
  if(valeurCapteur == HIGH)
  {
    return true;
  }
  else
  {
    return false;
  }
}


