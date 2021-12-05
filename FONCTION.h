#include "MACRO.h"
#include "STRUCTURE.h"

#ifndef MONOPOLY_FONCTION_H
#define MONOPOLY_FONCTION_H
int getRandomInteger();
int jeuDes(int* desUn, int* desDeux);
void dooble(int* desUn, int* desDeux, int* total);
int nombreJoueur();
Joueurs* saisirNoms();
Joueurs* creer(char* nom, int placement, int argent, int nbProprietes, int nbGroupes , int nbMaisons, int nbHotels, int cartesPrison, int faillite, int hypotheque);
void tablJoueurs(Joueurs*** tabNom, int* taille, int* nbJoueurs, char* nom, int placement, int argent, int nbProprietes, int nbGroupes , int nbMaisons, int nbHotels, int cartesPrison, int faillite, int hypotheque);
void afficherTous(Joueurs** tablNom, int taille);
void afficher(Joueurs* c);
void achatRue(Case* p, Joueurs* pAcheteur, Joueurs* pProprio);
void caseDepart(Joueurs* p);
void changement(Joueurs* p);
void perteOuGainArgent(Joueurs* joueur);
void allezPrison(Joueurs* joueur);
void attributionCarteChance(int numero, Joueurs* j);
void afficherCarteChance(CartesChance* carte);
void melangerCartesChance(CartesChance* paquet);
void initJoueur(int nbJoueurs);
Case initProp(int numero, int numeroGroupes, int loyer, char* nom, int prix, int type, int donne, int valeurHypotheque, int prixMaison, char* nomGroupe , int possibilite);
Case* initCases();
void prixLoyer(Case* prop, Joueurs* pAcheteur, Joueurs* pProprio);
void achatMaison(Case* prop, Joueurs* pAcheteur);
void typeCartes(Case* prop, Joueurs* player, Joueurs* pProprio, CartesChance* paquetChance);
void fonctionHypoteque(Case* prop, Joueurs* pAcheteur);
#endif //MONOPOLY_FONCTION_H
