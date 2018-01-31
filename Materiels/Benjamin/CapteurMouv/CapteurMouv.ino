#define PIR_MOTION_SENSOR 2//Use pin 2 to receive the signal from the module 

void setup()
{
  Serial.begin(9600);
  pinMode(PIR_MOTION_SENSOR, INPUT);
}

void loop() 
{
  if(isPeopleDetected()== true){
    Serial.println("Mouvement detecte !");
    delay(1000);
  }
  else{
    Serial.println("Aucun mouvement");
    delay(1000);
  }
}

boolean isPeopleDetected()
{
  int sensorValue = digitalRead(PIR_MOTION_SENSOR);
  if(sensorValue == HIGH)
  {
    return true;
  }
  else
  {
    return false;
  }
}
