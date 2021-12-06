//
// Created by evanr on 06/12/2021.
//
#include "structure.h"
#ifndef MONOP_EVAN_CARTES_H
#define MONOP_EVAN_CARTES_H
void melangerCartesChance(CartesChance* paquet);
void afficherCarteChance(CartesChance* carte);
void attributionCarteChance(int numero, Joueurs* j);
int getRandomInteger1(int nbJoueurs);
void tirageAuSortJoueurs(Joueurs* tabJoueurs, int nbJoueurs);
void goPrison(Joueurs* joueur);
void afficherLesCartesCommunaute(CartesCommunaute *tabNomCartes);
void attributionCarteCommunaute(int numero, Joueurs *j, int nombreJ);
void afficherCartePropriete(Case carte);
void melangerCartesCommunaute(CartesCommunaute *paquet);
//CartesChance creerChance(int numero, char* nom, int prixAPayer, int prixARecevoir);
CartesChance* initCarteChance();
//CartesCommunaute creerCommunaute(int numero, char* nom, int prixAPayer, int prixARecevoir);
CartesCommunaute * initCarteCommunaute();




#endif //MONOP_EVAN_CARTES_H
