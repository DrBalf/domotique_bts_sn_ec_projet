#include "Arduino.h"
#include "capteurSecurite.h"

#define CAPTEUR_INCENDIE 35
#define CAPTEUR_MOUVEMENT 36

int8_t answer;
char aux_string[30];
char phone_number[]="+33695168550";

void initCapteur(void){
  pinMode(CAPTEUR_INCENDIE, INPUT);
  pinMode(CAPTEUR_MOUVEMENT, INPUT);
}

bool incendie(void){
  int fumeeDetecte = digitalRead(CAPTEUR_INCENDIE);
  if(fumeeDetecte == HIGH){
    sms();
    return true;
  }
  else{
    return false;
  }
}

bool mouvement(void){
  int mouvementDetecte = digitalRead(CAPTEUR_MOUVEMENT);
  if(mouvementDetecte == HIGH){
    sms();
    return true;
  }
  else{
    return false;
  }
}


void sms(void){
    Serial2.begin(9600);    
           
    delay(3000);

    while( (sendATcommand("AT+CREG?", "+CREG: 0,1", 500) || 
            sendATcommand("AT+CREG?", "+CREG: 0,5", 500)) == 0 );
            
    // Activation du mode texte pour les SMS.
    sendATcommand("AT+CMGF=1", "OK", 1000);
     
    sprintf(aux_string,"AT+CMGS=\"%s\"", phone_number);
    // Envoi du numéro de téléphone au module GSM.
    sendATcommand(aux_string, ">", 2000);
    
    if(mouvement()==true){
      Serial2.println("un mouvement est detecte !");
      Serial2.write(0x1A);
    }
    if(incendie()==true){
      Serial2.println("un incendie est detecte !");
      Serial2.write(0x1A);
    }
}


int8_t sendATcommand(char* ATcommand, char* expected_answer, unsigned int timeout){

    uint8_t x=0,  answer=0;
    char response[100];
    unsigned long previous;

    // Initialisation de la chaine de caractère (string).
    memset(response, '\0', 100);
    
    delay(100);
    
    // Initialisation du tampon d'entrée (input buffer).
    while( Serial2.available() > 0) Serial2.read();
    
    // Envoi des commandes AT
    Serial2.println(ATcommand);


    x = 0;
    previous = millis();

    // Cette boucle attend la réponse du module GSM.
    
    do{
// Cette commande vérifie s'il y a des données disponibles dans le tampon.
//Ces données sont comparées avec la réponse attendue.
        if(Serial2.available() != 0){    
            response[x] = Serial2.read();
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

