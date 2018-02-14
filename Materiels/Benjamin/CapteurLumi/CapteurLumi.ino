#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_TSL2561_U.h>


Adafruit_TSL2561_Unified tsl = Adafruit_TSL2561_Unified(TSL2561_ADDR_FLOAT, 12345);


void setup(void) 
{
  Serial.begin(9600);
  tsl.setGain(TSL2561_GAIN_16X);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop(void) 
{  
  sensors_event_t event;
  tsl.getEvent(&event);

  if((event.light)<25.00){
    //Serial.print(event.light);
    //Serial.println(" lux");    //Appel de la méthode qui renvoie la valeur en lux
    digitalWrite(3, HIGH);
    delay(1000);
    digitalWrite(3, LOW);
  }
  
  if((event.light)>25.00){
    //Serial.print(event.light);
    //Serial.println(" lux");    //Appel de la méthode qui renvoie la valeur en lux
    digitalWrite(2, HIGH);
    delay(1000);
    digitalWrite(2, LOW);
  }
}


