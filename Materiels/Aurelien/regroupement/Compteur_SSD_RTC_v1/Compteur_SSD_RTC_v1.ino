#include <SPI.h>          //
#include <SdFat.h>        //Bibliothèque carte SD   
#include <RTClib.h>       //Bibliothèque RTC
#define SDCS 10           //  
#define BUFFER_SIZE 100   //Define SD

SdFat sd;                 //
uint8_t buf[BUFFER_SIZE]; //Variable SD

int interruptePinCompteur = 2; //Variable Compteur

RTC_DS1307 rtc;           //Variable RTC 

       

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
    sd.ls("/", LS_SIZE|LS_R);

    //lecture du contenue du fichier txt Compteur_Elec dans la SD
    if(!fichier.open(&sd, "Compteur_Elec.txt", O_READ)){
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

    delay(10000);
}


void interruption(){
  delay(50);
  DateTime now=rtc.now();
    //affichage de la date 
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" ");
    //affichage de l'heure
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
  SdFile fichier;
  if (digitalRead(interruptePinCompteur)==0){
    //ecriture dans le fichier txt Compteur_Elec dans la SD
    if(!fichier.open(&sd, "Compteur_Elec.txt", O_RDWR|O_TRUNC|O_AT_END|O_SYNC)){
      Serial.println("Erreur");
      return;
    }      
    
    fichier.close();
    while(digitalRead(interruptePinCompteur)!=1);  
  }
}



