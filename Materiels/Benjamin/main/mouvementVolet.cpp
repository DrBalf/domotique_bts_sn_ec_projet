#include "Arduino.h"
#include "mouvementVolet.h"
#include "capteurLuminosite.h"

int cmdUp = 24;
int cmdDown = 25;
int switchUp = 26;
int switchDown = 27;

int cmdUp2 = 28;
int cmdDown2 = 29;
int switchUp2 = 30;
int switchDown2 = 31;

void initVolet(void){
    pinMode(cmdUp, OUTPUT);
    pinMode(cmdDown, OUTPUT);
    pinMode(switchUp, INPUT);
    pinMode(switchDown, INPUT);

    pinMode(cmdUp2, OUTPUT);
    pinMode(cmdDown2, OUTPUT);
    pinMode(switchUp2, INPUT);
    pinMode(switchDown2, INPUT);
}

bool volet1(int sens, bool mode){
  
    bool positionVolet;
    if(mode==true){
      if(sens==1){                              //ouvrir
          while(digitalRead(switchUp)==HIGH){
             digitalWrite(cmdUp,HIGH);
          }
          digitalWrite(cmdUp,LOW);
          positionVolet = true;
      }
        
      if(sens==2){                              //fermer
          while(digitalRead(switchDown)==HIGH){
            digitalWrite(cmdDown,HIGH);
          }
          digitalWrite(cmdDown,LOW);
          positionVolet = false;
      }
    }

    if(mode==false){
      if(luminosite()>25.00){
          while(digitalRead(switchUp)==HIGH){
              digitalWrite(cmdUp,HIGH);
          }
          digitalWrite(cmdUp,LOW);
          positionVolet = true;
      }
      if(luminosite()<25.00){
          while(digitalRead(switchDown)==HIGH){
              digitalWrite(cmdDown,HIGH);
          }
          digitalWrite(cmdDown,LOW);
          positionVolet = false;
      }
    }
    return positionVolet;
}


bool volet2(int sens, bool mode){
  
    bool positionVolet;
    if(mode==true){
      if(sens==1){                              //ouvrir
          while(digitalRead(switchUp2)==HIGH){
             digitalWrite(cmdUp2,HIGH);
          }
          digitalWrite(cmdUp2,LOW);
          positionVolet = true;
      }
        
      if(sens==2){                              //fermer
          while(digitalRead(switchDown2)==HIGH){
            digitalWrite(cmdDown2,HIGH);
          }
          digitalWrite(cmdDown2,LOW);
          positionVolet = false;
      }
    }

    if(mode==false){
      if(luminosite()>25.00){
          while(digitalRead(switchUp2)==HIGH){
              digitalWrite(cmdUp2,HIGH);
          }
          digitalWrite(cmdUp2,LOW);
          positionVolet = true;
      }
      if(luminosite()<25.00){
          while(digitalRead(switchDown2)==HIGH){
              digitalWrite(cmdDown2,HIGH);
          }
          digitalWrite(cmdDown2,LOW);
          positionVolet = false;
      }
    }
    return positionVolet;
}

