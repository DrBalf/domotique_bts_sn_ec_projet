#include "capteur.h"
#include <HIH6130.h>
#include<AirQuality.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_TSL2561_U.h>

Adafruit_TSL2561_Unified tsl = Adafruit_TSL2561_Unified(TSL2561_ADDR_FLOAT, 12345);

HIH6130 rht(0x27);

AirQuality airqualitysensor;
int current_quality =-1;

void initCapteur(){
  Serial.println("initialisation des capteurs...");
  rht.begin(); 
  airqualitysensor.init(A0);
  delay (5000);
  Serial.println("Capteurs initialises.");  
}

double temperature(){
  rht.readRHT();
  return rht.temperature;  
}

double humidite(){
  rht.readRHT();
  return rht.humidity;
}

int qualiteAir(){
  current_quality=airqualitysensor.slope();
  return current_quality;
}

float luminosite(void){
  tsl.setGain(TSL2561_GAIN_16X);

  sensors_event_t event;
  tsl.getEvent(&event);

  return event.light;
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


