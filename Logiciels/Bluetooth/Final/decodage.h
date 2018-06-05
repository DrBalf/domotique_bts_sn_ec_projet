#ifndef __DECODAGE_H__
#define __DECODAGE_H__
#include"Arduino.h"
#include "maison.h"

void recuperationTrame(Maison, String, boolean);
void traductionTrame(Maison);
void resetTrame(Maison);
Maison* getAdresse();

#endif
