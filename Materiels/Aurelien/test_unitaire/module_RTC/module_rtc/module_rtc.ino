#include <Wire.h>
#include <RTClib.h>

RTC_DS1307 rtc;

char daysOfTheWeek[7][12] = {"Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi", "Dimanche"};

void setup() {
  Serial.begin(9600);
  rtc.begin();
  rtc.isrunning();
  rtc.adjust(DateTime(2018, 02, 07, 17, 45, 0));
}

void loop() {
   DateTime now = rtc.now();
      
      Serial.print(now.year(), DEC);
      Serial.print('/');
      Serial.print(now.month(), DEC);
      Serial.print('/');
      Serial.print(now.day(), DEC);
      Serial.print(" (");
      Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
      Serial.print(") ");
      Serial.print(now.hour(), DEC);
      Serial.print(':');
      Serial.print(now.minute(), DEC);
      Serial.print(':');
      Serial.print(now.second(), DEC);
      Serial.println();

      delay(1000);
}
