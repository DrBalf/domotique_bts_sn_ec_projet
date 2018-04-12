#ifndef CAPTEUR_H
#define CAPTEUR_H

void initCapteur (void);

double capteurTemperature (void);

double capteurHumidite (void);

int capteurQualiteAir (void);

float capteurLuminosite(void);

bool capteurIncendie(void);

bool capteurMouvement(void);

void envoieSMS(bool, bool);

int sendATcommand (char*, char*, unsigned int);

#endif 
