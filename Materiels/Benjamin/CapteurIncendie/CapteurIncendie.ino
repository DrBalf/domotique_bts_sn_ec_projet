#define CAPTEUR_INCENDIE 2

void setup()
{
  Serial.begin(9600);
  pinMode(CAPTEUR_INCENDIE, INPUT);
}

void loop() 
{
  if(isFumeDetected()== true){
    Serial.println("A l'help !");
    delay(1000);
  }
  else{
    Serial.println("Aucune fumee");
    delay(1000);
  }
}

boolean isFumeDetected()
{
  int valCapteur = digitalRead(CAPTEUR_INCENDIE);
  if(valCapteur == HIGH)
  {
    return true;
  }
  else
  {
    return false;
  }
}


