#include <SoftwareSerial.h>
SoftwareSerial SSerial(2,3);
void setup()
{
  SSerial.begin(9600);
  SSerial.print("$lum0;$rad1;$vol1;$tem30;$hum25;$con5000;$air5;$heu10:25:30;\n");
  delay(10);
}

 
void loop()
{
}

