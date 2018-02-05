#include <SPI.h>
#include <SdFat.h>
#define SDCS 10
#define BUFFER_SIZE 100
SdFat sd;
uint8_t buf[BUFFER_SIZE];

void setup() {
  String bonjour="bonjour ! NICO EST SALEE COMME LE DEMON !!!!!!!!!!";
  int n=0;
  String myString=""; 
  SdFile fichier;
  Serial.begin(9600);
  
  //init
  Serial.begin(9600); 
  Serial.println("init SD");
  if(!sd.begin(SDCS,SPI_HALF_SPEED)){
    Serial.println("erreur init");
    return;
  }

 //ecriture
  if(!fichier.open(&sd, "toto.txt", O_RDWR|O_TRUNC|O_AT_END|O_SYNC)){
    Serial.println("Erreur");
    return;
  }
  fichier.println(bonjour);
  fichier.close();
  
  //liste du contenue de la carte
  sd.ls("/", LS_SIZE|LS_R);
  //lecture
   if(!fichier.open(&sd, "toto.txt", O_READ)){
    Serial.println("erreur");
    return;
  }
  
  //lecture nb d'octets dans le fichier 
  n = fichier.read(buf, sizeof(buf));
  Serial.print(n);
  Serial.println(" octet(s) lu(s)");
  
  //lecture de la chaine de caractère
  myString = String ((char *)buf);
  myString.trim();
  Serial.print("\"");
  Serial.print(myString);
  Serial.println("\"");

  

}

void loop() {


}
