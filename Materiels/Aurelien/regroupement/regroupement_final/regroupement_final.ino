#include "capteur.h"
#include "relai.h"
#include "horodatage.h"
#include "affichage.h"
#include "maison.h"
#include <avr/io.h>
#include <avr/interrupt.h>

Maison maison;

unsigned short interruptePinCompteur = 3; //Variable Compteur

unsigned short flagCompteurEnergie=0;

unsigned short flagCompteurTimer=0;

volatile unsigned int cpt=0;

void setup(){

  //config timer2
  TCCR2A=0x00;
  TCCR2B|=(1<<CS22)|(1<<CS21)|(1<<CS20);
  TIMSK2|=(1<<TOIE2);
  sei();
  
  Serial.begin(9600);
  Serial2.begin(9600);
  
  initrelai();
  initHorodatage();
  initCapteur();

  //Setup Compteur interruption
  pinMode(interruptePinCompteur, INPUT_PULLUP);                             
  attachInterrupt(digitalPinToInterrupt(interruptePinCompteur), interruptionCompteur, LOW);
}

void loop(){

    if (flagCompteurTimer==1){
        maison.temperature=temperature();
        maison.humidite=humidite();
        maison.etatRadiateur=etatRelai();
        affichage(maison.temperature, maison.humidite, maison.etatRadiateur);
        flagCompteurTimer=0;
    }
    if (flagCompteurTimer==2){
        maison.qualiteAir=qualiteAir();
        maison.temperature=temperature();
        maison.humidite=humidite();
        maison.etatRadiateur=etatRelai();
        affichage(maison.temperature, maison.humidite, maison.etatRadiateur);
        affichage(maison.qualiteAir);
        flagCompteurTimer=0;
        cpt=0;    
    }
    
  while(Serial2.available() > 0) {  
    double c = Serial2.read();
    if (c==8){
      maison.radiateurMode=true; 
    }
    if (c==9){
      maison.radiateurMode=false;
    }
    if (c>=10 && c<=30){   
      maison.temperatureUtilisateur = c;
    }
    if (c==6){
      if (maison.radiateur==true){
        maison.radiateur=false;   
      }
    }
    if (c==7){
      if (maison.radiateur==false){
        maison.radiateur=true;   
      }
    }
  }
  
  relai(maison.radiateurMode, maison.temperature, maison.temperatureUtilisateur, maison.radiateur);

  if (flagCompteurEnergie==1){
        maison.consomation=consomation();
        maison.annee=annee();
        maison.mois=mois();
        maison.jour=jour();
        maison.heure=heure();
        maison.minutes=minutes();
        maison.seconde=seconde();
        horodatage(maison.consomation);             
        flagCompteurEnergie=0;
  }
}


void interruptionCompteur(){

  delay(50);
  if (digitalRead(interruptePinCompteur)==0){
    flagCompteurEnergie=1;
    while(digitalRead(interruptePinCompteur)!=1);  
  }
}

ISR(TIMER2_OVF_vect){
   cpt++;
   if (cpt==305){
      flagCompteurTimer=1;
   }
   if (cpt==610){
      flagCompteurTimer=2;
   }
}

