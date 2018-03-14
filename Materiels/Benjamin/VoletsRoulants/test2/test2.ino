#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_TSL2561_U.h>

int cmdUp = 6;
int cmdDown = 7;
int switchUp = 4;
int switchDown = 5;
int ledPin = 3;

Adafruit_TSL2561_Unified tsl = Adafruit_TSL2561_Unified(TSL2561_ADDR_FLOAT, 12345);

void setup() {
  Serial.begin(9600);
  tsl.setGain(TSL2561_GAIN_16X);
  pinMode(cmdUp, OUTPUT);
  pinMode(cmdDown, OUTPUT);
  pinMode(switchUp, INPUT);
  pinMode(switchDown, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  
  sensors_event_t event;
  tsl.getEvent(&event);    
  if((event.light)>25.00){                //si la luminosité est supérieure à 25 lux
     while(digitalRead(switchUp)==HIGH){  //tant que le volet n'est pas en fin de course
       digitalWrite(cmdUp,HIGH);          //le volet monte
       digitalWrite(ledPin, LOW);         //la lumière s'éteint
     }
     digitalWrite(cmdUp,LOW);        
  }
      
  if((event.light)<25.00){                  //si la luminosité est inférieur à 25 lux
     while(digitalRead(switchDown)==HIGH){  //tant que le volet n'est pas en fin de course
        digitalWrite(cmdDown,HIGH);         //le volet descend
        digitalWrite(ledPin, HIGH);         //la lumière s'allume
     }
     digitalWrite(cmdDown,LOW);
  }      
}


