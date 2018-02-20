#define Key 9 

void setup()
{
  Serial.begin(9600);
  Serial.print("Enter AT commands:");
  Serial1.begin(9600);
  pinMode(9, OUTPUT);  // this pin will pull the HC-05 pin 34 (key pin) HIGH to switch module to AT mode
  digitalWrite(9, HIGH); 
}
 
void loop()
{

     if (Serial1.available())
  {
    Serial.write(Serial1.read());
  }
 
  // Read from Arduino Serial Monitor and send to HC-05
   Serial1.print("AT\r\n");
  delay(20);
   Serial1.print("AT+UART=9600,0,0\r\n");
  delay(20);
   Serial1.print("AT+ROLE=1\r\n");
  delay(20);
    Serial1.print("AT+ROLE?\r\n");
  delay(20);
   Serial1.print("AT+CMODE=0\r\n");
  delay(20);
   Serial1.print("AT+RESET\r\n");
  delay(20);
   Serial1.print("AT+INIT\r\n");
  delay(20);
   Serial1.print("AT+INQM=1,2,12\r\n");
  delay(20);
   Serial1.print("AT+INQ\r\n");
  delay(20);
   Serial1.print("AT+STATE\r\n");
  delay(20);
   Serial1.print("AT+BIND=98d3,32,10c2a1\r\n");
  delay(20);
   Serial1.print("AT+STATE\r\n");
  delay(20);
   Serial1.print("AT+PAIR=98d3,32,10c2a1,10\r\n");
  delay(20);
   Serial1.print("AT+STATE\r\n");
  delay(20);
   Serial1.print("AT+LINK=98d3,32,10c2a1\r\n");
  delay(20);
   Serial1.print("AT+STATE\r\n");
  }


