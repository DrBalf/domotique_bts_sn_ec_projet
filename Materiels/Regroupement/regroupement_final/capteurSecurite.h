#ifndef CAPTEURSECURITE_H
#define CAPTEURSECURITE_H

void initCapteurSecu(void);
bool incendie(void);
bool mouvement(void);
void sms(bool, bool);
int8_t sendATcommand(char*, char*, unsigned int);

#endif 
