#define Key 9 

void setup()
{
  Serial.begin(9600);
  Serial.print("Enter AT commands:");
  Serial1.begin(9600);
  pinMode(9, OUTPUT);            //Pin Key
  digitalWrite(9, HIGH);         //

  
}
 
void loop()
{
 if (Serial1.available())
  {
    Serial.write(Serial1.read());
  }
 
   Serial1.print("AT\r\n");
   
   Serial1.print("AT+UART=9600,0,0\r\n");

   Serial1.print("AT+ROLE=1\r\n");

  Serial1.print("AT+ROLE?\r\n");

   Serial1.print("AT+CMODE=0\r\n");

   Serial1.print("AT+RESET\r\n");

   Serial1.print("AT+INIT\r\n");

   Serial1.print("AT+INQM=1,2,12\r\n");

   Serial1.print("AT+INQ\r\n");

   Serial1.print("AT+STATE\r\n");

   Serial1.print("AT+BIND=98d3,32,10c2a1\r\n");

   Serial1.print("AT+STATE\r\n");

   Serial1.print("AT+PAIR=98d3,32,10c2a1,10\r\n");
 
   Serial1.print("AT+STATE\r\n");

   Serial1.print("AT+LINK=98d3,32,10c2a1\r\n");

   Serial1.print("AT+STATE\r\n");

  
  }


