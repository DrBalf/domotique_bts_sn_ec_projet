/*
SLAVE
MODULE BLUETOOTH
v1.0
*/

#define power 11
#define state 10
#define enable 9
#define led 13

void setup() {
  pinMode(power, OUTPUT);
  pinMode(state, OUTPUT);
  pinMode(enable, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  Serial1.begin(9600);

digitalWrite(power, HIGH);
digitalWrite(enable, HIGH);
}

void loop() {
  
int c;
if(digitalRead(state) == HIGH){
   if(Serial1.available()>0){
    c = Serial1.read();
    if (c == 0) digitalWrite(led, LOW);
    if (c == 1){
      digitalWrite(led, HIGH);
      delay(10);
    }
   }
}
   else{ 
    digitalWrite(enable, LOW);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
  }       
  do{
    delay(5);
    digitalWrite(enable, HIGH);       
    delay(5);
    Serial.println("conexion");
    if(digitalRead(state) == HIGH){
      Serial.println("conecter !");
    }
  }
  while(digitalRead(state) == LOW);
}
  
  
  
  
  
  //if (Serial1.available()>0)
  //{
   //c = Serial1.read();
   //if (c == 0) digitalWrite(led, LOW);
   //if (c == 1) digitalWrite(led, HIGH); 
  //}
//}
