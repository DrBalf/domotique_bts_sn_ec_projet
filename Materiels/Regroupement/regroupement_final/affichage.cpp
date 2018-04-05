#include "affichage.h"
#include"Arduino.h"

void affichage (double temperature, double humidite, bool radiateur){
    Serial.println("----------------------------");  
    Serial.print("Temperature : ");
    Serial.print(temperature);
    Serial.println(" C");
    Serial.print("Humidite : ");
    Serial.print(humidite);
    Serial.println(" %");
    
    Serial.print("Etat du radiateur : ");
    if (radiateur==0){
      Serial.println("Eteint");
    }
    else if (radiateur==1){
      Serial.println("Allume");
    }
    Serial.println("----------------------------");   
}

void affichage (int qualiteAir){
  Serial.println("----------------------------");  
  Serial.print("Qualite de l'air : ");
  if (qualiteAir >= 0)// if a valid data returned.
  {
      if (qualiteAir==0)
          Serial.println("Pollution importante !!");
      else if (qualiteAir==1)
          Serial.println("Pollution");
      else if (qualiteAir==2)
          Serial.println("Faible pollution");
      else if (qualiteAir==3)
          Serial.println("Air pur");
  }
  Serial.println("----------------------------");   
}

