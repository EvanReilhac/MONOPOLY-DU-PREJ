//
// Created by User on 02/12/2021.
//

#ifndef MONOPOLY_STRUCTURES_H
#define MONOPOLY_STRUCTURES_H

typedef struct{
    char nom[MAX];
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
    char nom[MAX];
    int type;
    int donne;
    int prix;
    int loyer;
    int dispo;
    int hypotheque;
    int numero;

}Propriete;

#endif //MONOPOLY_STRUCTURES_H
