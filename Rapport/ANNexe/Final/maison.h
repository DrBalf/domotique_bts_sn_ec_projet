#ifndef __MAISON_H__
#define __MAISON_H__
#include"Arduino.h"
#include"decodage.h"
class Maison
{
public:
  Maison();
  int adresse;
  bool lumiere;
  String lumex;
  bool volet1;
  bool volet2;
  bool radiateur;
  String temperature;
  String air;
  String humidite;
  String conso;
  String energie;
  String trameLumiere;
  String trameVolet1;
  String trameVolet2;
  String trameRadiateur;
  int selecteur;
  ~Maison();
void recuperationTrame(Maison, String, boolean);
void traductionTrame(Maison);
void resetTrame(Maison);
Maison* getAdresse();
private:
int* adressage(Maison);

     
};
#endif
