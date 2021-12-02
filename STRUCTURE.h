#include <stdio.h>
#include "MACRO.h"


#ifndef MONOPOLY_STRUCTURE_H
#define MONOPOLY_STRUCTURE_H
typedef struct{
    char nom[NOMBRE_MAX];
    int placement;
    int argent;
    int nbMaisons;
    int nbHotels;
    int nbProprietes;
    int nbGroupes;
    int cartesPrison;
    int faillite;
    int hypotheque;

}Joueurs;

typedef struct{
    char nom[NOMBRE_MAX];
    int type;
    int donne;
    int prix;
    int loyer;
    int dispo;
    int hypotheque;
    int numero;

}Propriete;
#endif //MONOPOLY_STRUCTURE_H
