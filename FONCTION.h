#include "MACRO.h"
#include "STRUCTURE.h"

#ifndef MONOPOLY_FONCTION_H
#define MONOPOLY_FONCTION_H
int getRandomInteger();
int jeuDes(int* desUn, int* desDeux);
int dooble(int* desUn, int* desDeux);
int nombreJoueur();
Joueurs* saisirNoms();
Joueurs* creer(char* nom, int placement, int argent, int nbProprietes, int nbGroupes , int nbMaisons, int nbHotels, int cartesPrison, int faillite, int hypotheque);
void tablJoueurs(Joueurs*** tabNom, int* taille, int* nbJoueurs, char* nom, int placement, int argent, int nbProprietes, int nbGroupes , int nbMaisons, int nbHotels, int cartesPrison, int faillite, int hypotheque);
void afficherTous(Joueurs** tablNom, int taille);
void afficher(Joueurs** c);
void achatRue(char nom, int* dispo, int loyer, int hypotheque, int* argent, int numero);
Propriete* initProp(int numero, int loyer, char* nom, int prix, int type, int donne);
int caseDepart(Joueurs* p);
void changement(Joueurs* p);
void perteOuGainArgent(Joueurs* joueur);
#endif //MONOPOLY_FONCTION_H
