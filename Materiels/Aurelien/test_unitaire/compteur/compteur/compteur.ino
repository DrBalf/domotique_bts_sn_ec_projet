int interruptePinCompteur = 2;
void setup() {
  Serial.begin(9600);
  //INPUT_PULLUP nous sers a utiliser la résistance de pull_up lier à la broche 
  pinMode(interruptePinCompteur, INPUT_PULLUP);
  pinMode(3, OUTPUT);
  //déclaration d'une interruption le premier parramètre est la broche a utiliser
  //le deuxième paramètre est est le nom de la fonction 
  //le troisième paramètre est l'état de la pate qui déclenchera l'interruption. 
  attachInterrupt(digitalPinToInterrupt(interruptePinCompteur), interruption, LOW);
}

void loop() {
  

}

void interruption(){
  //le delay nous permet de ne pas lancer l'interruption 
  //en cas de perturbation electrique
  delay(50);
  //on vérifie l'état de la broche
  if (digitalRead(interruptePinCompteur)==0){
    Serial.println("bonjour");
    //on attend que la broche repasse a l'état haut
    while(digitalRead(interruptePinCompteur)!=1);  
  }   
}



