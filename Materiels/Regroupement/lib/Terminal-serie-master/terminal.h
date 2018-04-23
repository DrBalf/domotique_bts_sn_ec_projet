/*bibliotheque permettant d'envoyer des commandes ANSI au terminal afin
de pouvoir jouer sur la mise en forme de la page affichee. */
/*realisee par Pisak Sebastien :
version 2.0 du 14/09/2017
*/

#ifndef TERMINAL_H
#define TERMINAL_H
#include "Arduino.h"
#include <stdio.h>


void terminalInit(void);    //initialistation du terminal avec les valeurs d'attributs par defaut
void terminalPosition (int col, int ligne);//position du curseur
void terminalCouleur(int text,int font);//couleur du texte et du fond d'ecran
void terminalEfface(void);				//efface l'ecran de l'hyperterminal


#endif
