#include "MACRO.h"
#include "STRUCTURE.h"

#ifndef MONOPOLY_FONCTION_H
#define MONOPOLY_FONCTION_H
int getRandomInteger();
void jeuDes(int* desUn, int* desDeux);
void dooble(int* desUn, int* desDeux);
int nombreJoueur();
Joueurs* saisirNoms();
Joueurs* creer(char* nom, int argent, int nbProprietes, int nbGroupes , int nbMaisons, int nbHotels, int cartesPrison, int faillite, int hypotheque);
void tablJoueurs(Joueurs*** tabNom, int* taille, int* nbJoueurs, char* nom, int argent, int nbProprietes, int nbGroupes , int nbMaisons, int nbHotels, int cartesPrison, int faillite, int hypotheque);
void afficherTous(Joueurs** tablNom, int taille);
void afficher(Joueurs* c);
#endif //MONOPOLY_FONCTION_H
