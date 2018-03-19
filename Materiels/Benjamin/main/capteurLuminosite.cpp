#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_TSL2561_U.h>

Adafruit_TSL2561_Unified tsl = Adafruit_TSL2561_Unified(TSL2561_ADDR_FLOAT, 12345);

float luminosite(void){
  tsl.setGain(TSL2561_GAIN_16X);

  sensors_event_t event;
  tsl.getEvent(&event);

  return event.light;
}

