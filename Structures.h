#include "Macro.h"
#ifndef MONOPOLY_STRUCTURES_H
#define MONOPOLY_STRUCTURES_H



typedef struct
{
    char nomJ[TAILLE_NOM_MAX];
    int placement; //de 1 a 32
    int argent; //1500 au début
    int nbMaisonsJ;// max 4 par propriété
    int nbHotelsJ;// max 1 par propriété
    int nbProprietes;
    int nbGroupes;
    int cartesPrison; //0 on en a pas et 1 on en a
    int faillite;
    int nbHypotheque;
    int nbDouble;
    int fortune;
    int* possessionParCase; // réprésente la relation entre un joueur et une case du jeu, vaut le nombre de maison à l'indice de la case , -2 s'il ne possède pas, -1 s'il la hypothéquée, -3 si ce n'est une pas une propriété
    int* possessionParGroupe;
    int numeroJ;
}Joueurs;

typedef struct
{
    char nomPro[TAILLE_NOM_MAX];
    int type; // 0 = legende; 1 = carte chance; 2 = carte communaute; 3 = case depart; 4 = prison; 5 = perte/gain d'argent sur case; 6 = avancement; 7 = case libre
    int donne; //ce que tu reçois par la case
    int prix;
    int loyer;
    int dispo;
    int valeurHypotheque;
    int hypotheque;
    int numero;
    int numeroGroupes;
    int nbMaison;
    int newCase;
    int nbHotel;
    int* prixMaison;
    char nomGroupe[TAILLE_NOM_MAX];
    int possibilite; // 0 disponible , le chiffre de dizaine indique le joueur et l'unité le nombre de maisons : 10 possede par j1, 11 avec 1 maison
}Case;

typedef struct {
    char nomCarte[TAILLE_NOM_MAX];
    int numero;
} CartesChance;

typedef struct {
    char nomCarte[TAILLE_NOM_MAX];
    int numero;
} CartesCommunaute;

#endif //MONOPOLY_STRUCTURES_H
