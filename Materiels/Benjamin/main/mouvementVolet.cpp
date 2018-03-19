#include "Arduino.h"
#include "mouvementVolet.h"

int cmdUp = 6;
int cmdDown = 7;
int switchUp = 4;
int switchDown = 5;

void initVolet(void){
    pinMode(cmdUp, OUTPUT);
    pinMode(cmdDown, OUTPUT);
    pinMode(switchUp, INPUT);
    pinMode(switchDown, INPUT);
}

bool volet1(int sens){
    
    
    bool positionVolet = false;
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
    return positionVolet;
}


bool volet2(int sens){

    bool positionVolet = false;
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
    return positionVolet;
}

