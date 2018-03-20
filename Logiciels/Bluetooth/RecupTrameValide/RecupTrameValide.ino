String trame;
bool trameComplete=false;

void setup() {
  // put your setup code here, to run once:
Serial3.begin(9600);
Serial.begin(9600);

}

void loop() {
  if (trameComplete==true) { Serial.println(trame); trameComplete=false; trame=""; }
 

}

void serialEvent3(){
  char caractere=Serial3.read();
  trame+=caractere;
  if (caractere=='\n') {trameComplete= true;}
  
}

