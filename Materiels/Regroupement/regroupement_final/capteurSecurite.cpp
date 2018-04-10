#include "Arduino.h"
#include "capteurSecurite.h"

#define CAPTEUR_INCENDIE 35
#define CAPTEUR_MOUVEMENT 36

int8_t answer;
char aux_string[30];
char phone_number[]="+33648977501";

void initCapteurSecu(void){
  pinMode(CAPTEUR_INCENDIE, INPUT);
  pinMode(CAPTEUR_MOUVEMENT, INPUT);
}

bool incendie(void){
  int fumeeDetecte = digitalRead(CAPTEUR_INCENDIE);
  if(fumeeDetecte == HIGH){
    return true;
  }
  else{
    return false;
  }
}

bool mouvement(void){
  int mouvementDetecte = digitalRead(CAPTEUR_MOUVEMENT);
  if(mouvementDetecte == HIGH){
    return true;
  }
  else{
    return false;
  }
}


void sms(bool incendie, bool mouvement){

    //while( (sendATcommand("AT+CREG?", "+CREG: 0,1", 500) || sendATcommand("AT+CREG?", "+CREG: 0,5", 500)) == 0 );
    // Activation du mode texte pour les SMS.  
    sendATcommand("AT+CMGF=1", "OK", 1000);
     
    sprintf(aux_string,"AT+CMGS=\"%s\"", phone_number);
    // Envoi du numéro de téléphone au module GSM. 
    sendATcommand(aux_string, ">", 2000);        

    
    if(mouvement==true){
      Serial.println("un mouvement est detecte !");
      Serial1.println("un mouvement est detecte !");
      Serial1.write(0x1A);
    }
    if(incendie==true){
      Serial1.println("un incendie est detecte !");
      Serial1.write(0x1A);
    }
}


int8_t sendATcommand(char* ATcommand, char* expected_answer, unsigned int timeout){

    uint8_t x=0,  answer=0;
    char response[100];
    unsigned long previous;

    // Initialisation de la chaine de caractère (string).
    memset(response, '\0', 100);
    
    delay(50);
    
    // Initialisation du tampon d'entrée (input buffer).
    while( Serial1.available() > 0) Serial1.read();
    
    // Envoi des commandes AT
    Serial1.println(ATcommand);


    x = 0;
    previous = millis();

    // Cette boucle attend la réponse du module GSM.
    
    do{
// Cette commande vérifie s'il y a des données disponibles dans le tampon.
//Ces données sont comparées avec la réponse attendue.
        if(Serial1.available() != 0){    
            response[x] = Serial1.read();
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

