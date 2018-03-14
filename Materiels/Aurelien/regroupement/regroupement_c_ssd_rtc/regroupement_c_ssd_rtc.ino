#include <SPI.h>          //
#include <SdFat.h>        //Bibliothèque carte SD   
#include <RTClib.h>       //Bibliothèque RTC
#define SDCS 10           //  
#define BUFFER_SIZE 250   //Define SD

SdFat sd;                 //
uint8_t buf[BUFFER_SIZE]; //Variable SD

int interruptePinCompteur = 2; //Variable Compteur

RTC_DS1307 rtc;           //Variable RTC 

unsigned short flagCompteurEnergie=0;
float pulsion = 0.1;       

void setup() {
  Serial.begin(9600);

  //Setup Compteur interruption
  pinMode(interruptePinCompteur, INPUT_PULLUP);                             
  pinMode(3, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(interruptePinCompteur), interruption, LOW);

  //Setup SD
  Serial.println("init SD");
  if(!sd.begin(SDCS,SPI_HALF_SPEED)){
    Serial.println("erreur init");
    return;
  } 
  rtc.begin();
  rtc.isrunning();
}


void loop() {
    SdFile fichier; 
    if (flagCompteurEnergie==1){
        //ecriture dans le fichier txt Compteur_Elec dans la SD
        if(!fichier.open(&sd, "Compteur_Elec_Energie.txt", O_RDWR|O_CREAT|O_AT_END|O_SYNC)){
          Serial.println("Erreur");
          return;
        }
        fichier.print(pulsion);
        fichier.print("KWh ");      
        DateTime now = rtc.now();
        //affichage de la date 
        fichier.print(now.year(), DEC);
        fichier.print('/');
        fichier.print(now.month(), DEC);
        fichier.print('/');
        fichier.print(now.day(), DEC);
        fichier.print(" ");
        //affichage de l'heure
        fichier.print(now.hour(), DEC);
        fichier.print(':');
        fichier.print(now.minute(), DEC);
        fichier.print(':');
        fichier.println(now.second(), DEC);
        fichier.close();

        sd.ls("/", LS_SIZE|LS_R);

        //lecture du contenue du fichier txt Compteur_Elec dans la SD
        if(!fichier.open(&sd, "Compteur_Elec_Energie.txt", O_READ)){
          Serial.println("erreur");
          return;
        }
        fichier.read(buf, sizeof(buf));
        String myString = String ((char *)buf);
        myString.trim();
        Serial.print("\"");
        Serial.print(myString);
        Serial.println("\"");
        fichier.close();
        pulsion=pulsion+0.1;
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
