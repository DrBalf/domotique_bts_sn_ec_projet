#include <Wire.h>
#include <HIH6130.h>

// L'adresse du capteur est 0x27
HIH6130 rht(0x27);

void setup(){

	Serial.begin(9600);
 //on lance le programme RHT
 //"Read Humidity Temperature"
	rht.begin();
}

void loop(){

	// lecture des information
  //qui seront mise dans l'objet rht
	rht.readRHT();

  //Affichage des informations 
  //hummidité et temperature 
  //de l'objet rht
	Serial.print(rht.humidity);
  Serial.println ("%");
	Serial.print(rht.temperature);
  Serial.println (" Celsius");

	delay(2000);
}
