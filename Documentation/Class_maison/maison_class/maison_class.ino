#ifndef __MAISON_H__
#define __MAISON_H__
#include"Arduino.h"
class Maison
{
public:
    bool lumiere=false;
    bool radiateur=false;
    bool volet1=false;
    bool volet2=false;
    short temperature=20;
    char qualiteAire='3';
    unsigned short humidité=50;
    unsigned int consomation=200;
    unsigned int heurodatage=86400; 
    
private:
    
};
#endif
