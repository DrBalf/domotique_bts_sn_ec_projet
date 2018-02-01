#include<AirQuality.h>
#include"Arduino.h"
AirQuality airqualitysensor;
int current_quality =-1;

void setup() {
    Serial.begin(9600);
    airqualitysensor.init(A0); //initialisation à la pate A0
                               //de la carte arduino
}

void loop() {
    airqualitysensor.slope(); //on appelle la fonction slope a l'objet
                              //qui récupère les informations du capteur  
                              //et les traite 
    delay(2000);
}

ISR(TIMER1_OVF_vect) //utilisation d'un timer
{
  if(airqualitysensor.counter==61)//une fois que le nombre de marqueur 
                                  //atteind 61 (~30ms) on exécute les 
                                  //lignes de commande suivante
  {
      /*On récupére la dernière valeur avant de la remplacer par 
       *une valeur plus récentes puis on remet le nombre de marqueur  
       * à zéro et on relance le timer*/
      airqualitysensor.last_vol=airqualitysensor.first_vol;
      airqualitysensor.first_vol=analogRead(A0);
      airqualitysensor.counter=0;
      airqualitysensor.timer_index=1;
      PORTB=PORTB^0x20;
     /*La bibliothèque compare les deux valeur last_vol et
      *first_vol pour nous indiquer la qualité de l'air*/
  }
  else
  {
    airqualitysensor.counter++;
  }
}
