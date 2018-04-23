#include "terminal.h"

/*positionnement du curseur:
Force Cursor Position <ESC>[{ROW};{COLUMN}f
*/
void terminalPosition(int ligne, int col){
  int longCol,longLig;
  char bufferCol[5];
  char bufferLig[5];
  longCol=sprintf(bufferCol,"%d",col);
  longLig=sprintf(bufferLig,"%d",ligne);
  Serial3.write(0x1b);
  Serial3.write('[');
  Serial3.write(bufferLig[0]);
  if (longLig==2){
    Serial3.write(bufferLig[1]);
  }
  Serial3.write(';');
  Serial3.write(bufferCol[0]);
  if (longCol==2){
    Serial3.write(bufferCol[1]);
  }
  Serial3.write('f');
}


/*initialisation du terminal
Set Attribute Mode <ESC>[{attr1};...;{attrn}m
Sets multiple display attribute settings. The following lists standard attributes:
0 Reset all attributes
*/
void terminalInit(void){
  //remettre a 0 toutes les attributs d'affichages
  Serial3.write(0x1b);
  Serial3.write('[');
  Serial3.write('0');
  Serial3.write('m');
  terminalEfface();
}


/*effacer le terminal
Erase Screen <ESC>[2J
Erases the screen with the background colour and moves the cursor to home.
*/
void terminalEfface(void){
  Serial3.write(0x1b);
  Serial3.write('[');
  Serial3.write('2');
  Serial3.write('J');
}



/*choix des couleurs pour le texte et le fond d'ecran
            Foreground Colours
              30 Black
              31 Red
              32 Green
              33 Yellow
              34 Blue
              35 Magenta
              36 Cyan
              37 White
            Background Colours
              40 Black
              41 Red
              42 Green
              43 Yellow
              44 Blue
              45 Magenta
              46 Cyan
              47 White
*/
void terminalCouleur (int texte,int font){
  char couleurTexte[3];
  char couleurFont[3];
  sprintf(couleurTexte,"%d",texte);
  sprintf(couleurFont,"%d",font);
  Serial3.write(0x1b);
  Serial3.write('[');
  Serial3.write(couleurTexte[0]);
  Serial3.write(couleurTexte[1]);
  Serial3.write(';');
  Serial3.write(couleurFont[0]);
  Serial3.write(couleurFont[1]);
  Serial3.write('m');
}
