#include "decodage.h"
#include "arduino.h"
#include "maison.h"

  Maison::Maison(){
    
  lumiere = false;
  lumex = "";
  volet1 = false;
  volet2 = false;
  radiateur = false;
  temperature = "";
  air = "";
  humidite = "";
  conso = "";
  energie = "";
  trameLumiere = "";
  trameVolet1 = "";
  trameVolet2 = "";
  trameRadiateur = "";
  selecteur = 0;
  }
Maison::~Maison(){
  
}

void recuperationTrame(Maison maison, String trame,boolean trameComplete){
  
    Serial.println(trame);
      char valeur;
      for(int i=0;i<=trame.length();i++){
        if(maison.selecteur==0 && trame[i]!= '!'){
           valeur = trame[i];
           maison.trameLumiere += valeur;
           }
         if(maison.selecteur==1 && trame[i]!= '!'){
           valeur = trame[i];
           maison.lumex += valeur;
           }
         if(maison.selecteur==2 && trame[i]!= '!'){
           valeur = trame[i];
           maison.trameVolet1 += valeur;
           }
        if(maison.selecteur==3 && trame[i]!= '!'){
           valeur = trame[i];
           maison.trameVolet2 += valeur;
           }
        if(maison.selecteur==4 && trame[i]!= '!'){
           valeur = trame[i];
           maison.trameRadiateur += valeur;
           }
        if(maison.selecteur==5 && trame[i]!= '!'){
           valeur = trame[i];
           maison.temperature += valeur;
           }
        if(maison.selecteur==6 && trame[i]!= '!'){
           valeur = trame[i];
           maison.air += valeur;
           }
        if(maison.selecteur==7 && trame[i]!= '!'){
           valeur = trame[i];
           maison.humidite += valeur;
           }
        if(maison.selecteur==8 && trame[i]!= '!'){
           valeur = trame[i];
           maison.conso += valeur;
           }
        if(maison.selecteur==9 && trame[i]!= '!'){
           valeur = trame[i];
           maison.energie += valeur;
          }
        if(trame[i]== '!'){
          maison.selecteur++;
        }
       }
           Serial.print("lumiere : ");
           Serial.println(maison.trameLumiere);
           Serial.print("lumiere exterieur : ");
           Serial.println(maison.lumex);
           Serial.print("volet 1 : ");
           Serial.println(maison.trameVolet1);
           Serial.print("volet 2 : ");
           Serial.println(maison.trameVolet2);
           Serial.print("radiateur : ");
           Serial.println(maison.trameRadiateur);
           Serial.print("temperature : ");
           Serial.println(maison.temperature);
           Serial.print("air : ");
           Serial.println(maison.air);
           Serial.print("humidite : ");
           Serial.println(maison.humidite);
           Serial.print("consomation electrique : ");
           Serial.println(maison.conso);
           Serial.print("energie : ");
           Serial.println(maison.energie);
           maison.selecteur = 0;
           trame="";
           trameComplete = false;
     
}

void traductionTrame(Maison maison){
  if(maison.trameLumiere==0){
    maison.lumiere=false;
  }
  if(maison.trameLumiere==1){
    maison.lumiere=true;
  }
  if(maison.trameVolet1==0){
    maison.volet1=false;
  }
  if(maison.trameVolet1==1){
    maison.volet1=true;
  }
  if(maison.trameVolet2==0){
    maison.volet2=false;
  }
  if(maison.trameVolet2==1){
    maison.volet2=true;
  }
  if(maison.trameRadiateur==0){
    maison.radiateur=false;
  }
  if(maison.trameRadiateur==1){
    maison.radiateur=true;
  }
}

void resetTrame(Maison maison){
  maison.lumiere="";
   maison.lumex="";
   maison.volet1="";
   maison.volet2="";
   maison.radiateur="";
   maison.temperature="";
   maison.air="";
   maison.humidite="";
   maison.conso="";
   maison.energie="";
}

