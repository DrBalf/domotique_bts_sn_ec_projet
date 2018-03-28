#include "Arduino.h"

#define BUTTON 7

int activation=0;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON, INPUT);
}
 
void loop() {
  if(digitalRead(BUTTON)==HIGH){
    if(activation==0){
      activation=1;
    }
    if(activation==1){
      activation=0;
    }
  }
  Serial.println(activation);
}
