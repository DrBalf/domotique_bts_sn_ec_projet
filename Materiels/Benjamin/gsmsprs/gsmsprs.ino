#include <SoftwareSerial.h>

SoftwareSerial gsm(2, 3);

void setup(){
  gsm.begin(9600);
  gsm.print("AT\r\n");
}


void loop(){ 
}
