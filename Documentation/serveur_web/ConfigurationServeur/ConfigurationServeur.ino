#include <SPI.h> //bibliothèqe pour SPI
#include <Ethernet.h> //bibliothèque pour Ethernet

byte mac[] = {0x90, 0xA2, 0xDA, 0xCC, 0xDF, 0xAB}; // tableau pour l'adresse MAC de votre carte
byte ip[] = {192, 168, 190, 46}; //tableau pour l'adresse IP

EthernetServer serveur(80); // déclare l'objet serveur au port d'écoute 80

void setup() {
  Serial.begin (9600); //initialisation de communication série
    // no point in carrying on, so do nothing forevermore:
    if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
     Ethernet.begin (mac, ip); //initialisatio de la communication Ethernet
    Serial.print("\nLe serveur est sur l'adresse : ");
    }
     Serial.println(Ethernet.localIP()); //on affiche l'adresse IP de la connexion
   serveur.begin(); // démarre l'écoute

}
void loop() {
  EthernetClient client = serveur.available(); //on écoute le port
  if (client) { //si client connecté
    Serial.println("Client en ligne\n"); //on le dit...
    if (client.connected()) { // si le client est en connecté
      while (client.available()) { // tant qu'il a des infos à transmettre
        char c=client.read(); // on lit le caractère  
        Serial.write(c);// on l'écrit sur le moniteur série
        delay(1); //délai de lecture
      }
      //réponse au client
      client.println("<!DOCTYPE HTML>"); // informe le navigateur du type de document à afficher
      client.println("<html>Bonjour OpenClassRooms !<br></html>"); //code html
      client.stop(); //on déconnecte le client
      Serial.println("Fin de communication avec le client");
    }
  }
}

