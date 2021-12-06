#include "structure.h"

#ifndef MONOP_EVAN_PROPRIETE_H
#define MONOP_EVAN_PROPRIETE_H
Case initProp(int numero, int loyer, char* nom, int prix, int type, int donne, int valeurHypotheque, int prixMaison, char* nomGroupe , int possibilite , int hypotheque);
Case* initCases();
Case initChgt(int numero, char* nom, int type, int newCase, int donne);
void prixLoyer(Case* prop, Joueurs* pAcheteur, Joueurs* pProprio,int nombreJoueur, Joueurs* tablJ);

void fonctionHypotheque(Case* prop, Joueurs* pAcheteur, int prix, int nombreJoueur, Joueurs* tablJ);


#endif //MONOP_EVAN_PROPRIETE_H
/*   valeurHypotheque  , nbHotel , prixMaison , nexCase , nomGroupe , possibilite */