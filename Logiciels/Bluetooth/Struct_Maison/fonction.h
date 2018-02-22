#ifndef __STRUCTMAISON_H__
#define __STRUCTMAISON_H__
#include"Arduino.h"

struct Maison
{
    bool lumiere=false;
    bool radiateur=false;
    bool volet1=false;
    bool volet2=false;
    short temperature=20;
    char qualiteAire='3';
    unsigned short humidité=5;
    unsigned int consomation=200;
    unsigned int heurodatage=86400; 
};

#endif
