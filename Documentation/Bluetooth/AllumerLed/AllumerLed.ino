int ledPin = 13;                    
String readString;                  
int message = 1;
/*Effectue le programme une seule fois*/
void setup() {
Serial1.begin(9600);               
pinMode(ledPin, OUTPUT);       
}

/*Effectue le programme en boucle*/
void loop() {
     
while (Serial1.available()) {     
    delay(3);                   
   Serial1.println("False\r");
   delay(2);
   Serial1.flush();
    char c = Serial1.read();
        readString += c;
        
    }
    if (readString.length() >0) {
        Serial1.println(readString);
        if (readString == "onLum")
        {
            digitalWrite(ledPin, HIGH);
        }
        if (readString == "offLum")
        {
            digitalWrite(ledPin, LOW);
        }
        readString="";
    }

}
