#include "capteur.h"
#include "relai.h"
#include "horodatage.h"
#include "affichage.h"
#include "maison.h"

Maison maison;

unsigned short interruptePinCompteur = 3; //Variable Compteur

unsigned short flagCompteurEnergie=0;

void setup(){
  
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
  static int tempo=0;
  if (tempo==500 || tempo==1000){
    maison.temperature=temperature();
    maison.humidite=humidite();
    maison.radiateur=etatRelai();
    affichage(maison.temperature, maison.humidite, maison.radiateur);   
  }
  if (tempo==1000){
    maison.qualiteAir=qualiteAir();
    affichage(maison.qualiteAir);
    tempo=0; 
  }
  while(Serial2.available() > 0) {  
    int c = Serial2.read();
    if (c>=10 && c<=30){  
      Serial.println(c);
    }
  }
  relai();

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
  tempo++;
  delay(10);
}


void interruptionCompteur(){

  delay(50);
  if (digitalRead(interruptePinCompteur)==0){
    flagCompteurEnergie=1;
    while(digitalRead(interruptePinCompteur)!=1);  
  }
}


