#include "capteur.h"
#include "controleRadiateur.h"
#include "horodatage.h"
#include "maison.h"
#include "capteurSecurite.h"
#include "lumiere.h"
#include "mouvementVolet.h"
#include <avr/io.h>
#include <avr/interrupt.h>

Maison maison;

void envoieTrame (void);

void lectureTablette (void);

unsigned short interruptePinCompteur = 3; //Variable Compteur

unsigned short flagCompteurEnergie=0;

unsigned short flagCompteurTimer=0;

String trame;

volatile unsigned int cpt=0;

void setup(){
  //config timer2
  TCCR2A=0x00;
  TCCR2B|=(1<<CS22)|(1<<CS21)|(1<<CS20);
  TIMSK2|=(1<<TOIE2);
  sei();
  
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);
  Serial3.begin(9600);

  initVolet();
  initLumiere();
  initCapteurSecu();
  initRelai();
  initHorodatage();
  initCapteur();

  //Setup Compteur interruption
  pinMode(interruptePinCompteur, INPUT_PULLUP);                             
  attachInterrupt(digitalPinToInterrupt(interruptePinCompteur), interruptionCompteur, LOW);
}

void loop(){
  
    if (flagCompteurTimer==1){
        sms(maison.incendie, maison.mouvement);
        maison.temperature=temperature();
        maison.humidite=humidite();
        maison.etatRadiateur=etatRelai();
        envoieTrame(); 
        maison.incendie=false;
        maison.mouvement=false;       
        flagCompteurTimer=0;
        
    }
    if (flagCompteurTimer==2){
        maison.qualiteAir=qualiteAir();
        maison.temperature=temperature();
        maison.humidite=humidite();
        maison.etatRadiateur=etatRelai();
        maison.luminosite=luminosite();
        envoieTrame();
        maison.incendie=false;
        maison.mouvement=false;  
        flagCompteurTimer=0;
        cpt=0;    
    }
    
  lectureTablette();
  
  maison.incendie=incendie();
  maison.mouvement=mouvement();
  
  relai(maison.radiateurMode, maison.temperature, maison.temperatureUtilisateur, maison.radiateur);  
  maison.volet1=volet1(maison.volet1Etat, maison.voletMode);
  maison.volet2=volet2(maison.volet2Etat, maison.voletMode);
  maison.lumiere=lumiere(maison.lumiereEtat);  

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

void lectureTablette (){
  
    while(Serial2.available() > 0) {  
    double c = Serial2.read();
    if (c==0){ //lumiere eteinte
      if (maison.lumiere==true){
        maison.lumiereEtat=false;
      } 
    }
    if (c==1){ //lumiere allumer
      if (maison.lumiere==false){
        maison.lumiereEtat=true;
      } 
    }
    if (c==2){ //volet1 fermer
      if (maison.volet1Etat==true){
        maison.volet1Etat=false; 
      }
    }
    if (c==3){ //volet1 ouvrir
      if (maison.volet1Etat==false){
        maison.volet1Etat=true; 
      }
    }
    if (c==4){ //volet2 fermer
      if (maison.volet2Etat==true){
        maison.volet2Etat=false; 
      } 
    }
    if (c==5){ //volet2 ouvrir
      if (maison.volet2Etat==false){
        maison.volet2Etat=true; 
      } 
    }
    if (c==6){ //chauffage etteind
      if (maison.radiateur==true){
        maison.radiateur=false;   
      }
    }
    if (c==7){ //chauffage allumer
      if (maison.radiateur==false){
        maison.radiateur=true;   
      }
    }
    if (c==8){ //chauffage manuel
      maison.radiateurMode=true; 
    }
    if (c==9){ //chauffage auto
      maison.radiateurMode=false;
    }
    if (c>=10 && c<=30){   
      maison.temperatureUtilisateur = c;
    }
    if (c==31){ //volet manuel
      maison.voletMode=true; 
    }
    if (c==32){ //volet auto
      maison.voletMode=false;
    }
  }
}

void envoieTrame (){
    //tablette       
    trame += maison.lumiere;      
    trame += "!";
    trame += maison.luminosite;
    trame += "!";
    trame += maison.volet1Etat; 
    trame += "!";
    trame += maison.volet2Etat;
    trame += "!";
    trame += maison.etatRadiateur; 
    trame += "!";
    trame += maison.temperature;
    trame += "!";
    trame += maison.consomation;
    trame += "!";
    trame += maison.humidite;
    trame += "!";
    trame += maison.qualiteAir; 
    //relevé date
    trame += "!";
    trame += maison.jour;
    trame += "!";
    trame += maison.mois;
    trame += "!";
    trame += maison.annee;
    trame += "!";
    trame += maison.heure;
    trame += "!";
    trame += maison.minutes;
    trame += "!";
    Serial.println(trame);
    Serial2.println(trame);
    Serial3.println(trame);
    trame = "";
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

