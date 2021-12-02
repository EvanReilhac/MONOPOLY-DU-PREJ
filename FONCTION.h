#include "MACRO.h"
#include "STRUCTURE.h"

#ifndef MONOPOLY_FONCTION_H
#define MONOPOLY_FONCTION_H
int getRandomInteger();
void jeuDes(int* desUn, int* desDeux);
void dooble(int* desUn, int* desDeux);
int nombreJoueur();
Joueurs* saisirNoms();
Joueurs* creer(char* nom, int placement, int argent, int nbProprietes, int nbGroupes , int nbMaisons, int nbHotels, int cartesPrison, int faillite, int hypotheque);
void tablJoueurs(Joueurs*** tabNom, int* taille, int* nbJoueurs, char* nom, int placement, int argent, int nbProprietes, int nbGroupes , int nbMaisons, int nbHotels, int cartesPrison, int faillite, int hypotheque);
void afficherTous(Joueurs** tablNom, int taille);
void afficher(Joueurs* c);
Propriete* initProp(int numero, int loyer, char* nom, int prix, int type, int donne);
#endif //MONOPOLY_FONCTION_H
