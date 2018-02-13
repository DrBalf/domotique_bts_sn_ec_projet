#define CAPTEUR_MOUVEMENT 2

void setup()
{
  Serial.begin(9600);
  pinMode(CAPTEUR_MOUVEMENT, INPUT);
}

void loop() 
{
  if(mouvementDetecte()== true){
    Serial.println("Mouvement detecte !");
    delay(2000);
  }
}

boolean mouvementDetecte()
{
  int valeurCapteur = digitalRead(CAPTEUR_MOUVEMENT);
  if(valeurCapteur == HIGH)
  {
    return true;
  }
  else
  {
    return false;
  }
}


