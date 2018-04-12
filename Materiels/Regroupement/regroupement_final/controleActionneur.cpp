#include "controleActionneur.h"
#include "Arduino.h"
#include "capteur.h"

int cmdUp = 24;
int cmdDown = 25;
int switchUp = 26;
int switchDown = 27;

int cmdUp2 = 28;
int cmdDown2 = 29;
int switchUp2 = 30;
int switchDown2 = 31;

int pinThermostat = 2;
int pinLumiere = 33;
char valeurEtat;

void initActionneur(){
  pinMode(pinThermostat, OUTPUT);
  pinMode(pinLumiere, OUTPUT);

  pinMode(cmdUp, OUTPUT);
  pinMode(cmdDown, OUTPUT);
  pinMode(switchUp, INPUT);
  pinMode(switchDown, INPUT);

  pinMode(cmdUp2, OUTPUT);
  pinMode(cmdDown2, OUTPUT);
  pinMode(switchUp2, INPUT);
  pinMode(switchDown2, INPUT);
}

/********************************Fonction Controle des actionneurs : Thermostat, Lumiere, Volet**************************************/

void controleThermostat(bool mode, double temperature, double temperatureUtilisateur, bool valeurEtat){
  if (mode==false){  
      if (valeurEtat==true){
        digitalWrite(pinThermostat,HIGH); 
      }
      if (valeurEtat==false){
        digitalWrite(pinThermostat,LOW);
      }
  }
  if (mode==true){
    if(temperature<=temperatureUtilisateur-1){
      digitalWrite(pinThermostat,HIGH);
    }
    if(temperature>=temperatureUtilisateur){
      digitalWrite(pinThermostat,LOW);   
    }
  }
}

bool controleLumiere(int positionLumiere){
  bool etat=false; 
  if(positionLumiere==1){
    digitalWrite(pinLumiere, HIGH);
    etat=true;
  }

  if(positionLumiere==0){
    digitalWrite(pinLumiere, LOW);
    etat=false;
  }

  return etat;
}

bool controleVolet1(bool sens, bool mode){
  
    bool positionVolet;
    if(mode==true){
      if(sens==true){                              //ouvrir
          while(digitalRead(switchUp)==HIGH){
             digitalWrite(cmdUp,HIGH);
          }
          digitalWrite(cmdUp,LOW);
          positionVolet = true;
      }
        
      if(sens==false){                              //fermer
          while(digitalRead(switchDown)==HIGH){
            digitalWrite(cmdDown,HIGH);
          }
          digitalWrite(cmdDown,LOW);
          positionVolet = false;
      }
    }

    if(mode==false){
      if(capteurLuminosite()<25.00){
          while(digitalRead(switchUp)==HIGH){
              digitalWrite(cmdUp,HIGH);
          }
          digitalWrite(cmdUp,LOW);
          positionVolet = true;
      }
      if(capteurLuminosite()>25.00){
          while(digitalRead(switchDown)==HIGH){
              digitalWrite(cmdDown,HIGH);
          }
          digitalWrite(cmdDown,LOW);
          positionVolet = false;
      }
    }
    return positionVolet;
}


bool controleVolet2(bool sens, bool mode){
  
    bool positionVolet;
    if(mode==true){
      if(sens==true){                              //ouvrir
          while(digitalRead(switchUp2)==HIGH){
             digitalWrite(cmdUp2,HIGH);
          }
          digitalWrite(cmdUp2,LOW);
          positionVolet = true;
      }
        
      if(sens==false){                              //fermer
          while(digitalRead(switchDown2)==HIGH){
            digitalWrite(cmdDown2,HIGH);
          }
          digitalWrite(cmdDown2,LOW);
          positionVolet = false;
      }
    }

    if(mode==false){
      if(capteurLuminosite()<25.00){
          while(digitalRead(switchUp2)==HIGH){
              digitalWrite(cmdUp2,HIGH);
          }
          digitalWrite(cmdUp2,LOW);
          positionVolet = true;
      }
      if(capteurLuminosite()>25.00){
          while(digitalRead(switchDown2)==HIGH){
              digitalWrite(cmdDown2,HIGH);
          }
          digitalWrite(cmdDown2,LOW);
          positionVolet = false;
      }
    }
    return positionVolet;
}

/*************************Récupération de létat du thermostat : allumer/etteint*****************************/

bool etatThermostat(){
  bool val = digitalRead(pinThermostat);
  return val;
}
