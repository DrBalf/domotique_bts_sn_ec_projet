const int interruptButtonPin=3;
bool buttonEtteint=true;
bool buttonAllumer=false;

void setup()
{
  Serial.begin(9600);
  pinMode(interruptButtonPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptButtonPin), interruptButton, RISING);
}

 
void loop()
{
}

void interruptButton(){
  if (buttonEtteint==true){
    buttonEtteint=false;
    buttonAllumer=true;
    Serial.println("Allumer");
  }
  else{
    buttonEtteint=true;
    buttonAllumer=false;
    Serial.println("Etteint");
  }
}

