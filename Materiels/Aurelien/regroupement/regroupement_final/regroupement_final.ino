#include "capteur.h"
#include "relai.h"
#include "horodatage.h"
#include "affichage.h"

int interruptePinCompteur = 3; //Variable Compteur

unsigned short flagCompteurEnergie=0;

void setup(){
  Serial.begin(9600);
  
  initrelai();
  initHorodatage();
  initCapteur();

  //Setup Compteur interruption
  pinMode(interruptePinCompteur, INPUT_PULLUP);                             
  attachInterrupt(digitalPinToInterrupt(interruptePinCompteur), interruption, LOW);
  

}

void loop(){
  affichageTempHumi(temperature(), humidite());
  Serial.print("Qualite de l'air : ");
  qualiteAir();
  relai();

  if (flagCompteurEnergie==1){
        Serial.print ("Horodatage : ");
        horodatage();
        flagCompteurEnergie=0;
  }  

  Serial.println("");  
  delay(3000);   
}


void interruption(){

  delay(50);
  if (digitalRead(interruptePinCompteur)==0){
    flagCompteurEnergie=1;
    while(digitalRead(interruptePinCompteur)!=1);  
  }
}

