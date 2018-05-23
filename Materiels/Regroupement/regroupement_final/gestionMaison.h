#ifndef __MAISON_H__
#define __MAISON_H__
class Maison
{
public:
    bool lumiere=false;
    bool volet1=false;
    bool volet2=false;
    float luminosite;
    bool alarme=false;
    bool incendie;
    bool mouvement;
    
    double temperatureUtilisateur=21;
    bool radiateur=false; 
    double temperature; 
    int qualiteAir; 
    double humidite; 
    float consomation; 
    
    bool etatRadiateur; 
    bool lumiereEtat=false; //_false=0=etteind|true=1=allumer
    bool volet1Etat=false; //_false=0=etteind|true=1=allumer
    bool volet2Etat=false; //_false=0=etteind|true=1=allumer
    
    bool voletMode=true; //_true=0=mode manuel|false=1=mode automatique
    bool radiateurMode=false;//_false=0=mode manuel|true=1=mode automatique
    
    int annee;
    int jour;    
    int mois;    
    int heure;    
    int minutes;    
    int seconde;

    void emissionTrame (void);

    void lectureTablette (void);
    
private:     
};

void initSerial (void);

#endif
