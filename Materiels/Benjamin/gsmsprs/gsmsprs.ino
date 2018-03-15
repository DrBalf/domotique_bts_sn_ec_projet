#include <SoftwareSerial.h>

#define SRX 7
#define STX 8

SoftwareSerial GPRS(SRX, STX);

unsigned char buffer[64];

int count=0;

void setup(){
  GPRS.begin(9600);
  Serial.begin(9600);
}

void loop(){
  if(GPRS.available()){
    while(GPRS.available()){
      buffer[count++]=GPRS.read();
      if(count==64)break;
    }
    Serial.write(buffer, count);
    memset(buffer,0,sizeof(buffer)*sizeof(unsigned char));
    count=0;
  }

  unsigned char tmp;
  if(Serial.available()){
    tmp=Serial.read();
    if(tmp=='#'){
      tmp=0x1A;
    }
    GPRS.write(tmp);
  }
}


