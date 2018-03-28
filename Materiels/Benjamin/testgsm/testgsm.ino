int8_t answer;
int onModulePin= 2; // Il s'agit du port DTR (ou PWR) du module SIM900.
char aux_string[30];
// Inscrivez ici le numéro de téléphone pour l'envoie du SMS.
char phone_number[]="+33600000000";
void setup()
{

    pinMode(onModulePin, OUTPUT);
    Serial.begin(9600);
    Serial2.begin(9600);    
        
    Serial.println("------------------------------------------------------");
    Serial.println("----Upsilon Audio - Envoyer un SMS avec le SIM900-----");
    Serial.println("------------------------------------------------------");
    Serial.println("");
    Serial.println("Initialisation en cours ...");
    power_on();
    
    delay(3000);
    
    // Cette commande active la carte SIM.
    //Supprimez cette ligne si vous n'avez pas de code PIN.
    sendATcommand("AT+CPIN=****", "OK", 2000);
    
    delay(3000);
    
    Serial.println("Connexion au reseau en cours ...");

    while( (sendATcommand("AT+CREG?", "+CREG: 0,1", 500) || 
            sendATcommand("AT+CREG?", "+CREG: 0,5", 500)) == 0 );

    Serial.println("Mode SMS en cours d'activation ...");
    // Activation du mode texte pour les SMS.
    sendATcommand("AT+CMGF=1", "OK", 1000);
    sendATcommand("AT+CSMP=17,167,0,240", "OK", 1000); // Flaash SMS
    Serial.println("Envoi du SMS en cours ...");
    
    sprintf(aux_string,"AT+CMGS=\"%s\"", phone_number);
    // Envoi du numéro de téléphone au module GSM.
    answer = sendATcommand(aux_string, ">", 2000);
    if (answer == 1)
    {
        // Insérez ici le coprs du message.
        Serial2.println("Ceci est un SMS !");
        Serial2.write(0x1A);
        answer = sendATcommand("", "OK", 20000);
        if (answer == 1)
        {
            Serial.println("Message envoye !");    
        }
        else
        {
            Serial.print("Erreur !");
        }
    }
    else
    {
        Serial.print("Erreur !");
        Serial.println(answer, DEC);
    }

}


void loop() // Il n'y a aucune commandes dans la fonction loop.
{
}

// Définition des différentes fonctions.

void power_on(){

    uint8_t answer=0;
    
    // Cette commande vérifie si le module GSM est en marche.
    answer = sendATcommand("AT", "OK", 2000);
    if (answer == 0)
    {
        // Mise en marche du module GSM
        digitalWrite(onModulePin,HIGH);
        delay(3000);
        digitalWrite(onModulePin,LOW);
    
        // Envoie d'une commande AT toutes les deux secondes et attente d'une réponse.
        while(answer == 0){
            answer = sendATcommand("AT", "OK", 2000);    
        }
    }
    
}

// Cette fonction permet d'envoyer des commandes AT au module GSM.
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
