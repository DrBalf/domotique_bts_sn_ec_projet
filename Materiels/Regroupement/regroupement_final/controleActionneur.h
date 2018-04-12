#ifndef CONTROLEACTIONNEUR_H
#define CONTROLEACTIONNEUR_H

void initActionneur(void);

void controleThermostat (bool, double, double, bool);

bool controleLumiere(int);

bool controleVolet1(bool, bool);

bool controleVolet2(bool, bool);

bool etatThermostat (void);

#endif 
