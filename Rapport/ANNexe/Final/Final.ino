#include <SPI.h> //bibliothèqe pour SPI
#include <Ethernet.h> //bibliothèque pour Ethernet
#include "decodage.h"
#include "maison.h"

Maison maison;
String adresse = "";
int valeur[10] = {0, 2, 0, 1, 0, 6, 7, 8, 9, 10};
int date[8] = {1, 2, 0, 3, 2, 0, 1, 8};
int heure[6] = {1, 2, 4, 2, 5, 9};

byte mac[] = {0x90, 0xA2, 0xDA, 0xCC, 0xDF, 0xAB}; // tableau pour l'adresse MAC de votre carte
byte ip[] = {192, 168, 190, 46}; //tableau pour l'adresse IP
EthernetServer serveur(80); // déclare l'objet serveur au port d'écoute 80
String trame = "";         // a String to hold incoming data
boolean trameComplete = false;  // whether the string is complete
char c = 0;

void setup() {
  Serial.begin (9600); //initialisation de communication série
  Serial1.begin(9600); //initialisation de communication bluetooth
  Ethernet.begin (mac, ip); //initialisation de la communication Ethernet
  Serial.print("\nLe serveur est sur l'adresse : ");
  Serial.println(Ethernet.localIP()); //on affiche l'adresse IP de la connexion
  serveur.begin(); // démarre l'écoute
  }

void loop() {

if(trameComplete == true){                                            // Quand on recois une trame complete on l'affiche sur le site
  recuperationTrame(maison, trame, trameComplete);                    // Fonction qui recupère la trame recue
  traductionTrame(maison);                                            // Fonction qui interprete la trame
   }                                                                  //on écoute le port
  EthernetClient client = serveur.available();                        // On attend la conexion d'un utilisateur au site
  if (client) { //si client connecté                                  // Si il y a un client 
    Serial.println("Client en ligne\n");                              //on le dit...               
    if (client.connected()) {                                         // tant qu'il a des infos à transmettre
      while (client.available()) {                                    // tant que le client et connecté 
        char c=client.read();                                         // on lit le caractère  
        Serial.write(c);                                              // on l'écrit sur le moniteur série
        delay(1);                                                     //delai de lecture
      }
      //réponse au client et affichage du site 
      client.println("HTTP/1.1 200 OK"); // type du HTML
      client.println("Connection: close");  // fermeture de la connexion quand toute la réponse sera envoyée
      client.println("Refresh: 5");  // rafraîchissement automatique de la page toutes les 5 secondes
      client.println(); //saut de ligne obligatoire avant la suite
      client.println("<!DOCTYPE HTML>"); // informe le navigateur du type de document à afficher
      client.println("<html>"); //début du code html
      client.println("<head>"); //entête
      client.println("<title>La Maison du Futur connectée</title>"); //titre de la fenêtre
      //client.println("link rel=""icon"" type=""image/png"" href=""image/favicon.png""/>");
      client.println("<meta charset=""UTF-8"">");
      
      // CSS // CSS // CSS // CSS // CSS // CSS // CSS // CSS // CSS // CSS // CSS // CSS // CSS // CSS // CSS // CSS // CSS // CSS // CSS // CSS // CSS // CSS // CSS //  CSS // CSS // CSS // CSS //CSS // CSS // CSS // CSS // CSS // CSS // CSS // CSS // CSS // CSS // CSS
      
      client.println("<style type=text/css>body{margin-left:auto;margin-right:auto;font-family:""Arial Narrow"",serif;text-align:center;background-color :#F9F9F9;max-width:800px;}");
      client.println("#entete{text-align:center;margin-left:20%;margin-right:auto;min-width:600px;padding-bottom:20px;}");
      client.println("#valeur {padding-top:40px;margin-left:auto;padding-bottom:340px;font-size:24px;margin-right:auto;min-width:600px;}");
      client.println("h2{color:#07578a;}");
      client.println("h1{font-size:200%;}");
      client.println(".valeur {background-color:#07578a;border-style:solid;border-width:3px;vertical-align:middle;text-align:center;color:#f9f9f9}</style>");
      
      
      // CSS // CSS // CSS // CSS // CSS // CSS // CSS // CSS // CSS // CSS // CSS // CSS // CSS // CSS // CSS // CSS // CSS // CSS // CSS // CSS // CSS // CSS // CSS //  CSS // CSS // CSS // CSS //CSS // CSS // CSS // CSS // CSS // CSS // CSS // CSS // CSS // CSS // CSS
      // REMPLISSAGE TABLEAU // REMPLISSAGE TABLEAU // REMPLISSAGE TABLEAU // REMPLISSAGE TABLEAU // REMPLISSAGE TABLEAU // REMPLISSAGE TABLEAU // REMPLISSAGE TABLEAU // REMPLISSAGE TABLEAU // REMPLISSAGE TABLEAU // REMPLISSAGE TABLEAU // REMPLISSAGE TABLEAU // REMPLISSAGE TABLEAU //
      client.println("</head>");//fin d'entête
      client.println("<body>"); //corps
      client.println("<div id=""CentrePage"">");
      client.println("<h1>La Maison du Futur connectée</h1>"); //titre en grosse lettres
      client.println("<h2>Voici le dernier relevé reçu le "); 
      client.print(date[0]);
      client.print(date[1]);
      client.print("/");
      client.print(date[2]);
      client.print(date[3]);
      client.print("/");
      client.print(date[4]);
      client.print(date[5]);
      client.print(date[6]);
      client.print(date[7]);
      client.print(" à ");
      client.print(heure[0]);
      client.print(heure[1]);
      client.print(":");
      client.print(heure[2]);
      client.print(heure[3]);
      client.print(":");
      client.print(heure[4]);
      client.print(heure[5]);
      client.print(".</h2>");
      client.println("<hr>"); //ligne horizontale
      client.println("<table id=""valeur""><tr>");
      client.println("<td class=""valeur"" colspan=""2""><h3> Détail du relevé <br/></h3></td></tr>");
      client.println("<tr><td class=""valeur""> Lumière :</td>");
      client.println("<td class=""valeur"">");
      if(maison.lumiere == 0){
        client.print("Fermer"); 
      }
      if(maison.lumiere == 1){
        client.print("Ouvert"); 
      }
      client.print(" </td></tr>");
      client.println("<tr><td class=""valeur""> Luminosité extérieur :</td>");
      client.println("<td class=""valeur"">");
      client.print(maison.lumex); 
      client.print(" Lux</td></tr>");  
      client.println("<tr><td class=""valeur""> Volet n°1 :</td>");
      client.println("<td class=""valeur"">");
       if( maison.volet1 == 0){
       client.print("Fermer"); 
      }
      if( maison.volet1 == 1){
        client.print("Ouvert"); 
      } 
      client.print(" </td></tr>"); 
      client.println("<tr><td class=""valeur""> Volet n°2 :</td>");
      client.println("<td class=""valeur"">");
       if( maison.volet2 == 0){
        client.print("Fermer"); 
      }
      if( maison.volet2 == 1){
        client.print("Ouvert"); 
      } 
      client.print(" </td></tr>"); 
      client.println("<tr><td class=""valeur""> Radiateur :</td>");
      client.println("<td class=""valeur"">");
       if(maison.radiateur == 0){
        client.print("Eteint"); 
      }
      if(maison.radiateur == 1){
        client.print("Allumer"); 
      } 
      client.print("  </td></tr>"); 
      client.println("<tr><td class=""valeur""> Température :</td>");
      client.println("<td class=""valeur"">");
      client.print(maison.temperature); 
      client.print(" °c</td></tr>"); 
      client.println("<tr><td class=""valeur""> Consomation d'énergie :</td>");
      client.println("<td class=""valeur"">");
      client.print(maison.air); 
      client.print(" W/h</td></tr>"); 
      client.println("<tr><td class=""valeur""> Taux d'humidité :</td>");
      client.println("<td class=""valeur"">");
      client.print(maison.humidite); 
      client.print(" %</td></tr>"); 
      client.println("<tr><td class=""valeur""> Qualité de l'air :</td>");
      client.println("<td class=""valeur"">");
      client.print(maison.conso); 
      client.print(" (1 à 10)</td>");
      client.print("</tr></table>");
      // REMPLISSAGE TABLEAU // REMPLISSAGE TABLEAU // REMPLISSAGE TABLEAU // REMPLISSAGE TABLEAU // REMPLISSAGE TABLEAU // REMPLISSAGE TABLEAU // REMPLISSAGE TABLEAU // REMPLISSAGE TABLEAU // REMPLISSAGE TABLEAU // REMPLISSAGE TABLEAU // REMPLISSAGE TABLEAU // REMPLISSAGE TABLEAU //
      client.println("</div>");
      client.println("<hr>"); //ligne horizontale
      client.println("<div id=""piedpage""><h3>Bonjour. Si Vous souhaitez interagir avec votre maison via votre télèphone télècharger l'application !</h3></div>");
      client.println("</body>"); //fin du corps
      client.println("</html>"); //fin du code html
      client.stop(); //on déconnecte le client
      Serial.println("Fin de communication avec le client");
      void resetTrame(Maison);                                      // Fonction qui supprime le contenue de la trame precedente
       }
    }
  }

void serialEvent1(){                                                // Programme d'interuption qui se lance a la fin de chaque loop
  while (Serial1.available()) {
    // get the new byte:
    char lettre  = (char)Serial1.read();                            // Lecture du charactère envoyer via bluetooth
    // add it to the inputString:
    trame += lettre;                                                // Ajout a la trame
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (lettre == '\n') {                                           // Si la phrase et terminer 
      trameComplete = true;                                         // La trame est complète
    Serial.println(trame);                                          // On l'affiche
    }
  }
}
 

