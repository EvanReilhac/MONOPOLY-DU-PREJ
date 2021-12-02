#define MAX 100
#include "Structures.h"

#ifndef MONOPOLY_FONCTIONS_H
#define MONOPOLY_FONCTIONS_H

typedef struct
{
    int numeroCase;
    int argentDuJoueur;
}Condition;
Condition laConditionDeLaCase(int cases);

Case* initProp(int numero, int loyer, char* nom, int prix, int type, int donne, int nbMaison);
Case* initChgt(int numero, char* nom, int type, int newCase, int donne);
void initCases();
void initCaseChangement();

void perteOuGainArgent(Joueurs* joueur);


void prison();
int getRandomInteger();
int jeuDes(int* desUn, int* desDeux);
int dooble(int* desUn, int* desDeux);


#endif //MONOPOLY_FONCTIONS_H
