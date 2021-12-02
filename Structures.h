//
// Created by User on 02/12/2021.
//

#ifndef MONOPOLY_STRUCTURES_H
#define MONOPOLY_STRUCTURES_H

typedef struct
{
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

typedef struct
{
    char nom[MAX];
    int type; // 0 = legende; 1 = carte chance; 2 = carte communaute; 3 = case depart; 4 = prison; 5 = perte/gain d'argent sur case; 6 = avancement; 7 = case libre
    int donne; //ce que tu reçois par la case
    int prix;
    int loyer;
    int dispo;
    int hypotheque;
    int numero;
    int nbMaison;
    int newCase;
}Case;

#endif //MONOPOLY_STRUCTURES_H
