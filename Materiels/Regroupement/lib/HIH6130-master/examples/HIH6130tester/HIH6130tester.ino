/*
	Example showing how to use the HIH6130 library for Arduino
	Tested on the Arduino Uno R3 with Arduino v1.0.6 installed

	Written by David Hagan, December 2, 2014
*/

#include <Wire.h>
#include <HIH6130.h>

// Define the address used by the HIH6130
byte address = 0x27;

HIH6130 rht(address);

void setup(){

	Serial.begin(9600);
	rht.begin();
	Serial.println("RH (%)\tT (C)");

}

void loop(){

	// Read data
	rht.readRHT();

	// Print the data
	Serial.print(rht.humidity); Serial.print("\t");
	Serial.println(rht.temperature);

	delay(2000);
}