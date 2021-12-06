#include "Structures.h"
#include "Macro.h"


#ifndef MONOPOLY_FONCTIONS_H
#define MONOPOLY_FONCTIONS_H

void menuPrinc();

void fonctionHypoteque(Case* prop, Joueurs* pAcheteur, int prix);

/*Case* initProp(int numero, int loyer, char* nom, int prix, int type, int donne, int nbMaison);
Case* initChgt(int numero, char* nom, int type, int newCase, int donne);
void initCases();
void initCaseChangement();*/
Case initProp(int numero, int loyer, char* nom, int prix, int type, int donne, int valeurHypotheque, int prixMaison, char* nomGroupe , int possibilite );
Case* initCases();
Case initChgt(int numero, char* nom, int type, int newCase, int donne);

void perteOuGainArgent(Joueurs* joueur);


void goPrison(Joueurs* joueur);
void sortirPrison(Joueurs* joueur, int* tourPrison);
int getRandomInteger();
int jeuDes(int* desUn, int* desDeux);
void dooble(int* desUn, int* desDeux, int* total);

int placement( Joueurs* p);

void faillitte(Joueurs* joueur, Joueurs* joueurPossedantLaCase, Case* cases, CartesCommunaute* carteCommu, CartesChance* carteChance);

Joueurs creerJoueur();
Joueurs * initJoueur(int nbJoueurs);
int nombreJoueur();

CartesChance initChance(int numero, char* nom, int prixAPayer, int prixARecevoir);
CartesChance* initCarteChance();

#endif //MONOPOLY_FONCTIONS_H
