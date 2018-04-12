#ifndef __MAISON_H__
#define __MAISON_H__
class Maison
{
public:
    bool lumiere=false;
    bool volet1=false;
    bool volet2=false;
    float luminosite;
    bool incendie;
    bool mouvement;
    
    double temperatureUtilisateur=21;//lore
    bool radiateur=false; //lore
    double temperature; //lore
    int qualiteAir; //lore
    double humidite; //lore
    float consomation; //lore
    
    bool etatRadiateur; //lore
    bool lumiereEtat=false; //_false=0=etteind|true=1=allumer
    bool volet1Etat=false; //_false=0=etteind|true=1=allumer
    bool volet2Etat=false; //_false=0=etteind|true=1=allumer
    
    bool voletMode=true; //_true=0=mode manuel|false=1=mode automatique
    bool radiateurMode=false;//lore _false=0=mode manuel|true=1=mode automatique
    
    //lore
    int annee;
    int jour;    
    int mois;    
    int heure;    
    int minutes;    
    int seconde;
    //

    void emissionTrame (void);

    void lectureTablette (void);
    
private:

     
};

void initSerial (void);

#endif
