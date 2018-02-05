/*
SLAVE
MODULE BLUETOOTH
v1.0
*/

int LED = 13;
int c;

void setup() {
  pinMode(LED, OUTPUT);
  Serial1.begin(9600);
}

void loop() {
  if (Serial1.available()>0)
  {
   c = Serial1.read();
   if (c == 0) digitalWrite(LED, LOW);
   if (c == 1) digitalWrite(LED, HIGH); 
  }
}
