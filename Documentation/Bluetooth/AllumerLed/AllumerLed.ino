int ledPin = 13;                    
String readString;                  

/*Effectue le programme une seule fois*/
void setup() {
Serial1.begin(9600);               
pinMode(ledPin, OUTPUT);            
}

/*Effectue le programme en boucle*/
void loop() {
while (Serial1.available()) {     
delay(3);                   

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
