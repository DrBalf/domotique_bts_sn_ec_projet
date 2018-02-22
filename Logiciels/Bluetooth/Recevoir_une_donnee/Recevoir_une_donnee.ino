/*C'est validé*/
void setup()
{
  Serial1.begin(9600);
}
 
void loop()
{
 Serial1.print("Lum 17,Lux 16,Vol1 Ouvert,Vol2 Fermer,Rad 12,Tem 22,Con 65,Qua 10,Tau 35,Der 22/02/18,"); 
  delay(300);
}
