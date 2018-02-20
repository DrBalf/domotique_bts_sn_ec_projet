#include <SoftwareSerial.h>

SoftwareSerial Bluetooth(2,3); // RX // TX

#define ledPin 13   
                            
/*Effectue le programme une seule fois*/
void setup() {
  Bluetooth.begin(9600);               
  pinMode(ledPin, OUTPUT);
}

/*Effectue le programme en boucle*/
void loop() {
    short c = -1;
    String etatLampe;  
    
    while (Bluetooth.available()) {       
         c = Bluetooth.read();                
    }
    
    if (c == 1){
        digitalWrite(ledPin, HIGH);
        etatLampe="Eteinte";
        Bluetooth.print(etatLampe);
    }
    if (c == 0){
        digitalWrite(ledPin, LOW);
        etatLampe="Allumee";
        Bluetooth.print(etatLampe);
    }
}
