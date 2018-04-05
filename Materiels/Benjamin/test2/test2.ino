#include <String.h>
boolean sms;

void setup(){
  Serial1.begin(9600);  // Démarrage du modem
  Serial.begin(9600);   // Initialisation de la communication série
  delay(500);           // Délai connexion
  sms = true;
  if(Serial1.available())
    Serial.write(Serial1.read());
  }

void loop(){
  if(sms==true){   // on ne passe qu’une seule fois dans le loop()
    sendsms();
  sms = false;
}
}

void sendsms(){
  // set SMS mode
  Serial.println("SMS sender");
  Serial1.print("AT+CMGF=1\r");    // initialise le mode SMS
  delay(100);
  // phone number
  Serial.println("Enter the phone number :");
  char number[20] ;
  readSerial(number);
  Serial1.print("AT+CMGS=");
  Serial1.print(number);
  Serial1.print("\"\r");
  // message
  delay(100);
  Serial.print("Enter your message to send to : ");
  Serial.println(number);
  char message[200];
  readSerial(message);
  Serial1.println(message);
  Serial1.print(char(26));
  delay(100);
  Serial1.println();
  Serial.print("Message : ");
  Serial.println(message);
  Serial.println("Text send");
 }

int readSerial(char result[]){
  int i = 0;
  while (1)
  {
  while (Serial.available() > 0){
    char inChar = Serial.read();
    if (inChar == '\n')
    {
  result[i] = '\0';
  Serial.flush();
  return 0;
  }
  if (inChar != '\r'){
    result[i] = inChar;
    i++;
   }
  }
 }
}
