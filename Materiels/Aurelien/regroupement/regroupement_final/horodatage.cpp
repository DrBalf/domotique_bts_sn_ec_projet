#include <SPI.h>          //
#include <SdFat.h>        //Bibliothèque carte SD   
#include <RTClib.h>       //Bibliothèque RTC
#include "horodatage.h" 
/*Le module SD focntion en liason SPI et les pin SPI sont différente en fonction de la carte
carte Arduino utilisé. cf : https://www.arduino.cc/en/Reference/SPI */ 
#define BUFFER_SIZE 250   //déffinition de la taille du buffer.


SdFat sd;                 //
uint8_t buf[BUFFER_SIZE]; //Variable SD
float pulsion = 0.1;  
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

void horodatage(){

      SdFile fichier; 
  
      //ecriture dans le fichier txt Compteur_Elec dans la SD
      if(!fichier.open(&sd, "Compteur_Elec_Energie.txt", O_RDWR|O_TRUNC|O_AT_END|O_SYNC)){
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
    
      //sd.ls("/", LS_SIZE|LS_R);
    
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
}

