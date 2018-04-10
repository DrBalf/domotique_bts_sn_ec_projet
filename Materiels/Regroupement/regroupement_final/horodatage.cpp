#include <SPI.h>          //
#include <SdFat.h>        //Bibliothèque carte SD   
#include <RTClib.h>       //Bibliothèque RTC
#include "horodatage.h"
#include "maison.h" 
/*Le module SD focntion en liason SPI et les pin SPI sont différente en fonction de la carte
carte Arduino utilisé. cf : https://www.arduino.cc/en/Reference/SPI */ 
#define BUFFER_SIZE 250   //déffinition de la taille du buffer.


SdFat sd;                 //
uint8_t buf[BUFFER_SIZE]; //Variable SD
float pulsion = 0;  
RTC_DS1307 rtc;           //Variable RTC 

void initHorodatage(){

    initSD();
    initRTC();
}

void initSD(){
    //Setup SD
    Serial.println("init SD");
    if(!sd.begin()){
      Serial.println("erreur init");
      return;
    } 
}

void initRTC(){
    rtc.begin();
    rtc.isrunning();  
}

void horodatage(float consomation){

      SdFile fichier; 

      pulsion=pulsion+0.1;
      //ecriture dans le fichier txt Compteur_Elec dans la SD
      if(!fichier.open(&sd, "Compteur_bis_bis_bis.txt", O_RDWR|O_CREAT|O_AT_END)){
        Serial.println("Erreur");
        return;
      }
      fichier.print(consomation);
      fichier.print("KWh ");
      DateTime now = rtc.now();
      //affichage de la date 
      fichier.print(now.year());
      fichier.print('/');
      fichier.print(now.month());
      fichier.print('/');
      fichier.print(now.day());
      fichier.print(" ");
      //affichage de l'heure
      fichier.print(now.hour());
      fichier.print(':');
      fichier.print(now.minute());
      fichier.print(':');
      fichier.println(now.second());
      fichier.close();
    
      //sd.ls("/", LS_SIZE|LS_R);
    
      //lecture du contenue du fichier txt dans la SD
      if(!fichier.open(&sd, "Compteur_bis_bis_bis.txt", O_READ)){
        Serial.println("erreur");
        return;
      }
      fichier.read(buf, sizeof(buf));
      String myString = String ((char *)buf);
      myString.trim();
      Serial.println(myString);
      fichier.close();  
}

float consomation(){
      pulsion=pulsion+0.1;
      return pulsion;
}

int annee(){
  DateTime now = rtc.now();
  return now.year();  
}

int mois(){
  DateTime now = rtc.now();
  return now.month();
}

int jour(){
  DateTime now = rtc.now();
  return now.day();
}

int heure(){
  DateTime now = rtc.now();
  return now.hour();
}
  
int minutes(){
  DateTime now = rtc.now();
  return now.minute();
}

int seconde(){
  DateTime now = rtc.now();
  return now.second();
}

