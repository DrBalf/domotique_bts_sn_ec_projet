#include <Wire.h>
#include <HIH6130.h>
#include<AirQuality.h>
#include"Arduino.h"

//Déclaration des variables globale pour la capteur de qualité d'air
AirQuality airqualitysensor;
int current_quality =-1;

// L'adresse du capteur HIH6130 est 0x27
HIH6130 rht(0x27);

//Déclaration des variables globale pour le relai
int pin_relai = 2;
char valeur;

void setup(){

  Serial.begin(9600);
  
  //setup capteur HIH6130
  rht.begin();
  
  //setup capteur qualité air
  airqualitysensor.init(A0);

  //setup relai
  pinMode(pin_relai, OUTPUT);
  digitalWrite(pin_relai,HIGH);
  Serial.println("0 = allumer radiateur");
  Serial.println("1 = eteindre radiateur");
}

void loop(){

  //patie température/humidité
  rht.readRHT();
  Serial.print(rht.humidity);
  Serial.println ("%");
  Serial.print(rht.temperature);
  Serial.println (" Celsius");

  //partie qualité d'air
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


 //partie relai 
 if (Serial.available() > 0) {
    valeur = Serial.read();
    Serial.print("Radiateur = ");
    if (valeur=='1'){
      digitalWrite(pin_relai,HIGH);
      Serial.println("etteind");  
    }
    else{
      digitalWrite(pin_relai,LOW);
      Serial.println("allumer");   
    }
 }   

  Serial.println("");  
  delay(2000);

  
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
