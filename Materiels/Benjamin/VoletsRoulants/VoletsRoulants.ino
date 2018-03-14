int cmdUp = 6;
int cmdDown = 7;
int switchUp = 4;
int switchDown = 5;
char valeur;

void setup() {
  Serial.begin(9600);
  pinMode(cmdUp, OUTPUT);
  pinMode(cmdDown, OUTPUT);
  pinMode(switchUp, INPUT);
  pinMode(switchDown, INPUT);
}

void loop() {
  if (Serial.available() > 0) {  
    valeur = Serial.read();
    
    if (valeur=='1'){                           //si l'utilisateur rentre 1
        while(digitalRead(switchUp)==HIGH){     //tant qu'il n'est pas en fin de course
           digitalWrite(cmdUp,HIGH);            //le volet monte
        }
        digitalWrite(cmdUp,LOW);        
    }
      
    if(valeur=='2'){                            //si l'utilisateur rentre 2
        while(digitalRead(switchDown)==HIGH){   //tant qu'il n'est pas en fin de course
          digitalWrite(cmdDown,HIGH);           //le volet descend
        }
        digitalWrite(cmdDown,LOW);
    }      
  }
}


