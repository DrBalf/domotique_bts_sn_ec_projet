#include "capteur.h"
#include "Arduino.h"
#include <HIH6130.h>
#include <AirQuality.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_TSL2561_U.h>
#define CAPTEUR_INCENDIE 35
#define CAPTEUR_MOUVEMENT 36

Adafruit_TSL2561_Unified tsl = Adafruit_TSL2561_Unified(TSL2561_ADDR_FLOAT, 12345);

HIH6130 rht(0x27);

AirQuality airqualitysensor;
int current_quality =-1;

int answer;
char aux_string[30];
char phone_number[]="+33648977501";

void initCapteur(){
  Serial.println("initialisation des capteurs...");
  rht.begin();  
  pinMode(CAPTEUR_INCENDIE, INPUT);
  pinMode(CAPTEUR_MOUVEMENT, INPUT); 
  airqualitysensor.init(A0);
  delay (5000);
  Serial.println("Capteurs initialises.");  
}

/********************************Fonction Capteur : Temperature, Humiditée, Qualitée d'air, Luminosité, Incendie, Mouvement**************************************/

double capteurTemperature(){
  rht.readRHT();
  return rht.temperature; 
}

double capteurHumidite(){
  rht.readRHT();
  return rht.humidity;
}

int capteurQualiteAir(){
  current_quality=airqualitysensor.slope();
  return current_quality;
}

float capteurLuminosite(void){
  tsl.setGain(TSL2561_GAIN_16X);

  sensors_event_t event;
  tsl.getEvent(&event);

  return event.light;
}

bool capteurIncendie(void){
  int fumeeDetecte = digitalRead(CAPTEUR_INCENDIE);
  if(fumeeDetecte == HIGH){
    return true;
  }
  else{
    return false;
  }
}

bool capteurMouvement(void){
  int mouvementDetecte = digitalRead(CAPTEUR_MOUVEMENT);
  if(mouvementDetecte == HIGH){
    return true;
  }
  else{
    return false;
  }
}

/***********************************************Fonction d'envoie du SMS d'alerte********************************************/

unsigned int envoieSMS(bool incendie, bool mouvement){
    
    //while( (sendATcommand("AT+CREG?", "+CREG: 0,1", 500) || sendATcommand("AT+CREG?", "+CREG: 0,5", 500)) == 0 );
    // Activation du mode texte pour les SMS.  
    sendATcommand("AT+CMGF=1", "OK", 1000);
     
    sprintf(aux_string,"AT+CMGS=\"%s\"", phone_number);
    // Envoi du numéro de téléphone au module GSM. 
    sendATcommand(aux_string, ">", 2000);        

    if (mouvement==true || incendie==true){
      if(mouvement==true){
        Serial.println("un mouvement est detecte !");
        Serial1.println("un mouvement est detecte !");
        Serial1.write(0x1A);
              return 1;
      }
      if(incendie==true){
        Serial1.println("un incendie est detecte !");
        Serial1.write(0x1A);
              return 1;
      }
    }
    else{
      return 0;
    }
}


/***************************************Fonction Timer et Commande  AT****************************************/


int sendATcommand(char* ATcommand, char* expected_answer, unsigned int timeout){

    int x=0,  answer=0;
    char response[100];
    unsigned long previous;

    // Initialisation de la chaine de caractère (string).
    memset(response, '\0', 100);
    
    delay(50);
    
    // Initialisation du tampon d'entrée (input buffer).
    while( Serial1.available() > 0) Serial1.read();
    
    // Envoi des commandes AT
    Serial1.println(ATcommand);


    x = 0;
    previous = millis();

    // Cette boucle attend la réponse du module GSM.
    
    do{
// Cette commande vérifie s'il y a des données disponibles dans le tampon.
//Ces données sont comparées avec la réponse attendue.
        if(Serial1.available() != 0){    
            response[x] = Serial1.read();
            x++;
            // Comparaison des données
            if (strstr(response, expected_answer) != NULL)    
            {
                answer = 1;
            }
        }
    // Attente d'une réponse.
    }while((answer == 0) && ((millis() - previous) < timeout));    

    //Serial.println(response); //Cette ligne permet de debuguer le programme en cas de problème !
    return answer;
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


