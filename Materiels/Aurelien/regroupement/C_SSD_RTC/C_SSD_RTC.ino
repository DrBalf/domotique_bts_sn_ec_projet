#include "horodatage.h"

int interruptePinCompteur = 3; //Variable Compteur

unsigned short flagCompteurEnergie=0;
     

void setup() {
  Serial.begin(9600);

  //Setup Compteur interruption
  pinMode(interruptePinCompteur, INPUT_PULLUP);                             
  attachInterrupt(digitalPinToInterrupt(interruptePinCompteur), interruption, LOW);

  initHorodatage();
}


void loop() {
    
    if (flagCompteurEnergie==1){
        horodatage();
        flagCompteurEnergie=0;
    }    
}


void interruption(){

  delay(50);
  if (digitalRead(interruptePinCompteur)==0){
    flagCompteurEnergie=1;
    while(digitalRead(interruptePinCompteur)!=1);  
  }
}







    


