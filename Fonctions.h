#define MAX 100

#ifndef MONOPOLY_FONCTIONS_H
#define MONOPOLY_FONCTIONS_H

typedef struct
{
    int numeroCase;
    int argentDuJoueur;
}Condition;
Condition laConditionDeLaCase(int cases);




void prison();
int getRandomInteger();
int jeuDes(int* desUn, int* desDeux);
int dooble(int* desUn, int* desDeux);


#endif //MONOPOLY_FONCTIONS_H
