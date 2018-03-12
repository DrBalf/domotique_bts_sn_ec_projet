#include "capteur.h"
#include <HIH6130.h>
#include<AirQuality.h>

HIH6130 rht(0x27);

AirQuality airqualitysensor;
int current_quality =-1;

void initCapteur(){
  Serial.println("initialisation des capteurs...");
  rht.begin(); 
  airqualitysensor.init(A0);
  delay (5000);
}

int temperature(){
  rht.readRHT();
  Serial.print(rht.temperature);
  Serial.println (" Celsius");  
}

int humidite(){
  rht.readRHT();
  Serial.print(rht.humidity);
  Serial.println ("%");
}

int qualiteAir(){
  current_quality=airqualitysensor.slope();
  if (current_quality >= 0)// if a valid data returned.
  {
      if (current_quality==0)
          Serial.println("Pollution importante !!");
      else if (current_quality==1)
          Serial.println("Pollution");
      else if (current_quality==2)
          Serial.println("Faible pollution");
      else if (current_quality ==3)
          Serial.println("Air pure");
  }
}

ISR(TIMER1_OVF_vect) //timer
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
