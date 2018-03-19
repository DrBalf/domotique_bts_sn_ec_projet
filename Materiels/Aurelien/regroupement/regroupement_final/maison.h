#ifndef __MAISON_H__
#define __MAISON_H__
#include"Arduino.h"
class Maison
{
public:
    bool lumiere=false;
    bool radiateur; //lore
    bool volet1=false;
    bool volet2=false;
    bool incendie=false;
    bool mouvement=false;
    float luminosite;
    double temperature; //lore
    char qualiteAir; //lore
    double humidite; //lore
    float consomation; //lore
    String dateHeure; //lore
    
private:
     
};
#endif
