#include "structure.h"

#ifndef MONOP_EVAN_PROPRIETE_H
#define MONOP_EVAN_PROPRIETE_H
Case initProp(int numero, int loyer, char* nom, int prix, int type, int donne, int valeurHypotheque, int prixMaison, char* nomGroupe , int possibilite );
Case* initCases();
Case initChgt(int numero, char* nom, int type, int newCase, int donne);
#endif //MONOP_EVAN_PROPRIETE_H
/*   valeurHypotheque  , nbHotel , prixMaison , nexCase , nomGroupe , possibilite */