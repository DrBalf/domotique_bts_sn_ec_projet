#include <SFE_BMP180.h>
#include <Wire.h>
#include "SFE_BMP180.h"
SFE_BMP180 pressure;

void setup() {
  Serial.begin(9600);
  //lancement du programme d'initialisation 
  if (pressure.begin())
    Serial.println("initialisation BMP180 reussi");
  else
  {
    Serial.println("initialisation BMP180 echouer\n\n");
    while(1);
  }

}

void loop() {

  double T;

  //lecture des données de température   
  pressure.startTemperature();
  delay(5);
  //récupération
  pressure.getTemperature(T);
  //affichage
  Serial.print("temperature: ");
  Serial.print(T,2);
  Serial.println(" deg C");
  delay(3000);  
    

}
