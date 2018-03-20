int cmdUp = 6;
int cmdDown = 7;
int switchUp = 4;
int switchDown = 5;
short c = 2;

void setup() {
  Serial.begin(9600);
  Serial2.begin(9600);
  pinMode(cmdUp, OUTPUT);
  pinMode(cmdDown, OUTPUT);
  pinMode(switchUp, INPUT);
  pinMode(switchDown, INPUT);
}

void loop() {
  while(Serial2.available() > 0) {  
    c = Serial2.read();
    Serial1.println(3);
    Serial.println(c);
  }
    if (c==3){                                //si l'utilisateur rentre 1
        while(digitalRead(switchUp)==HIGH){     //tant qu'il n'est pas en fin de course
           digitalWrite(cmdUp,HIGH);            //le volet monte
        }
        digitalWrite(cmdUp,LOW);        
    }
      
    if(c==2){                                       //si l'utilisateur rentre 2
        while(digitalRead(switchDown)==HIGH){   //tant qu'il n'est pas en fin de course
          digitalWrite(cmdDown,HIGH);           //le volet descend
        }
        digitalWrite(cmdDown,LOW);
    }
}


