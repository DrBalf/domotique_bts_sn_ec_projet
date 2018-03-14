#define ledPin 13   

void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(9, OUTPUT);  // this pin will pull the HC-05 pin 34 (key pin) HIGH to switch module to AT mode
  digitalWrite(9, HIGH);
}
 
void loop()
{
    short led = -1;
    short volet1 = -1;
    short volet2 = -1;
    short radiateur = -1;
    String etatLampe;
    String etatVolet1;
    String etatVolet2;
    String etatRadiateur;
    
/*********************Led******************/
    while (Serial2.available()) {       
         led = Serial2.read();                
    }
    
    if (led == 0){
        digitalWrite(ledPin, LOW);
        etatLampe="Eteinte";
        Serial2.print(etatLampe);
    }
    if (led == 1){
        digitalWrite(ledPin, HIGH);
        etatLampe="Allumee";
        Serial2.print(etatLampe);
    }       
/*****************Volet 1******************/
     while (Serial2.available()) {       
         volet1 = Serial2.read();                
    }
    
    if (volet1 == 2){
        digitalWrite(ledPin, HIGH);
        etatVolet1="Fermer";
        Serial2.print(etatVolet1);
    }
    if (volet1 == 3){
        digitalWrite(ledPin, LOW);
        etatVolet1="Ouvert";
        Serial2.print(etatVolet1);
    }
/*****************Volet 2******************/
     while (Serial2.available()) {       
         volet2 = Serial2.read();                
    }
    
    if (volet2 == 4){
        digitalWrite(ledPin, HIGH);
        etatVolet2="Fermer";
        Serial2.print(etatVolet2);
    }
    if (volet2 == 5){
        digitalWrite(ledPin, LOW);
        etatVolet2="Ouvert";
        Serial2.print(etatVolet2);
    }
/*********************Radiateur******************/
    while (Serial2.available()) {       
         radiateur = Serial2.read();                
    }
    
    if (radiateur == 6){
        digitalWrite(ledPin, HIGH);
        etatRadiateur="Eteint";
        Serial2.print(etatRadiateur);
    }
    if (radiateur == 7){
        digitalWrite(ledPin, LOW);
        etatRadiateur="Allume";
        Serial2.print(etatRadiateur);
    }
    

   Serial2.print("$lum Eteinte$lux 4464$vol1 Ouvert$vol2 Fermer$rad allumé$tem 22$con 65$air 10$hum 20$der 12/03/2018$"); 
   delay(300);
}
