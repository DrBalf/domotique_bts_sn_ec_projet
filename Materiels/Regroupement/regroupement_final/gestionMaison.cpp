#include "gestionmaison.h"
#include "Arduino.h"

void initSerial (){    
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);
  Serial3.begin(9600);  
}

/********************************Fonction de récupération des donnée de la tablette************************************/

void Maison::lectureTablette (){
  
    while(Serial2.available() > 0) {  
    double c = Serial2.read();
    if (c==0){ //lumiere eteinte
      if (lumiere==true){
        lumiereEtat=false;
      } 
    }
    if (c==1){ //lumiere allumer
      if (lumiere==false){
        lumiereEtat=true;
      } 
    }
    if (c==2){ //volet1 fermer
      if (volet1Etat==true){
        volet1Etat=false; 
      }
    }
    if (c==3){ //volet1 ouvrir
      if (volet1Etat==false){
        volet1Etat=true; 
      }
    }
    if (c==4){ //volet2 fermer
      if (volet2Etat==true){
        volet2Etat=false; 
      } 
    }
    if (c==5){ //volet2 ouvrir
      if (volet2Etat==false){
        volet2Etat=true; 
      } 
    }
    if (c==6){ //chauffage etteind
      if (radiateur==true){
        radiateur=false;   
      }
    }
    if (c==7){ //chauffage allumer
      if (radiateur==false){
        radiateur=true;   
      }
    }
    if (c==8){ //chauffage manuel
      radiateurMode=true; 
    }
    if (c==9){ //chauffage auto
      radiateurMode=false;
    }
    if (c>=10 && c<=30){   
      temperatureUtilisateur = c;
    }
    if (c==31){ //volet manuel
      voletMode=true; 
    }
    if (c==32){ //volet auto
      voletMode=false;
    }
  }
}

/********************************Fonction d'emission des valeurs au serveur Web et a la Tablette************************************/

void Maison::emissionTrame (){

    String trame;
  
    //tablette       
    trame += lumiere;      
    trame += "!";
    trame += luminosite;
    trame += "!";
    trame += volet1Etat; 
    trame += "!";
    trame += volet2Etat;
    trame += "!";
    trame += etatRadiateur; 
    trame += "!";
    trame += temperature;
    trame += "!";
    trame += consomation;
    trame += "!";
    trame += humidite;
    trame += "!";
    trame += qualiteAir; 
    //relevé date
    trame += "!";
    trame += jour;
    trame += "!";
    trame += mois;
    trame += "!";
    trame += annee;
    trame += "!";
    trame += heure;
    trame += "!";
    trame += minutes;
    trame += "!";
    Serial.println(trame);
    Serial2.println(trame);
    Serial3.println(trame);
    trame = "";
}
