#include "capteur.h"
#include "relai.h"

void setup(){
  Serial.begin(9600);
  initrelai();
  initCapteur();
}

void loop(){
  temperature();
  humidite();
  qualiteAir();
  relai();

  Serial.println("");  
  delay(2000);   
}




