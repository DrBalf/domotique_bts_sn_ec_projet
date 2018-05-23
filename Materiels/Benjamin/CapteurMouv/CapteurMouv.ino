#define CAPTEUR_MOUVEMENT 3

unsigned short interruptBouton=2;

bool boutonEteint=true;

bool boutonAllumer=false; 

void setup()
{
  Serial.begin(9600);
  pinMode(CAPTEUR_MOUVEMENT, INPUT);
  pinMode(interruptBouton, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptBouton), interruptionBouton, RISING); 
}

void loop() 
{
  if(boutonAllumer==true){
    if(mouvementDetecte()== true){
      Serial.println("Mouvement detecte !");
    }
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

void interruptionBouton(){
  if (boutonEteint==true){    //Si les variables du bouton indique qu'il est éteint
    boutonEteint=false;       //On allume le bouton
    boutonAllumer=true;
    Serial.println("allumer");
  }
  else{
    boutonEteint=true;
    boutonAllumer=false;
    Serial.println("eteint");
  }
}


