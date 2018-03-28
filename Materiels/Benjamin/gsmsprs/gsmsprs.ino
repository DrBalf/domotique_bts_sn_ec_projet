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

  sendATcommand("AT", "OK", 2000);
}



int8_t sendATcommand(char* ATcommand, char* expected_answer, unsigned int timeout){

    uint8_t x=0,  answer=0;
    char response[100];
    unsigned long previous;

    // Initialisation de la chaine de caractère (string).
    memset(response, '\0', 100);
    
    delay(100);
    
    // Initialisation du tampon d'entrée (input buffer).
    while( GPRS.available() > 0) GPRS.read();
    
    // Envoi des commandes AT
    GPRS.println(ATcommand);


    x = 0;
    previous = millis();

    // Cette boucle attend la réponse du module GSM.
    
    do{
// Cette commande vérifie s'il y a des données disponibles dans le tampon.
//Ces données sont comparées avec la réponse attendue.
        if(GPRS.available() != 0){    
            response[x] = GPRS.read();
            x++;
            // Comparaison des données
            if (strstr(response, expected_answer) != NULL)    
            {
                answer = 1;
            }
        }
    // Attente d'une réponse.
    }while((answer == 0) && ((millis() - previous) < timeout));    

    //Serial.println(response); //Cette ligne permet de debuguer le programme en cas de problème !
    return answer;
}
