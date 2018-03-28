#ifndef __MAISON_H__
#define __MAISON_H__
#include"Arduino.h"
class Maison
{
public:
    bool lumiere=false;
    bool volet1=false;
    bool volet2=false;
    bool incendie=false;
    bool mouvement=false;
    float luminosite;
    double temperatureUtilisateur=21;//lore
    bool etatRadiateur; //lore
    bool radiateur=false; //lore
    double temperature; //lore
    char qualiteAir; //lore
    double humidite; //lore
    float consomation; //lore
    bool radiateurMode=false;//lore false=0=mode manuel|true=1=mode automatique
    //lore
    int annee;
    int jour;    
    int mois;    
    int heure;    
    int minutes;    
    int seconde;
    //
private:
     
};
#endif
