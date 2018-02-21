//#include <SoftwareSerial.h>

// SoftwareSerial Serial1(2,3); // RX // TX

#define ledPin 13   
                            
/*Effectue le programme une seule fois*/
void setup() {
  Serial1.begin(9600);               
  pinMode(ledPin, OUTPUT);
  //Serial1.print("Hello");
}

/*Effectue le programme en boucle*/
void loop() {
    short c = -1;
    String etatLampe;  
    
    while (Serial1.available()) {       
         c = Serial1.read();                
    }
    
    if (c == 1){
        digitalWrite(ledPin, HIGH);
        etatLampe="Eteinte";
        Serial1.print(etatLampe);
    }
    if (c == 0){
        digitalWrite(ledPin, LOW);
        etatLampe="Allumee";
        Serial1.print(etatLampe);
    }
}
