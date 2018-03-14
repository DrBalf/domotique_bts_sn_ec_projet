#include "affichage.h"
#include"Arduino.h"

void affichageTempHumi (double temperature, double humidite){
    Serial.print("Temperature : ");
    Serial.print(temperature);
    Serial.println(" C");
    Serial.print("Humidite : ");
    Serial.print(humidite);
    Serial.println(" %");  
}

void affichageQAirRad (int qualiteAir, bool radiateur){

  
}

