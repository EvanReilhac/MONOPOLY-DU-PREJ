
//evan version
#ifndef MONOP_EVAN_STRUCTURE_H
#define MONOP_EVAN_STRUCTURE_H
#include "MACRO.h"
typedef struct{
    char nomJ[TAILLE_NOM_MAX];
    int placement; // de 1 a 32
    int argent; // 1500 au début
    int nbMaisonsJ; // max 4 par propriété
    int nbHotelsJ; // max 1 par propriété
    int nbProprietes;

    char possessionParCase[32]; // réprésente la relation entre un joueur et une case du jeu, vaut le nombre de maison à l'indice de la case , -3 s'il ne possède pas, -1 s'il la hypothéquée, -2 si ce n'est une pas une propriété
    int nbGroupes;
    int fortune;
    int cartesPrison;
    int faillite;
    int nbHypotheque;

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
    int numero;
    int nbMaison;
    int nbHotel;
    int prixMaison;
    int newCase;
    char nomGroupe[TAILLE_NOM_MAX];
}Case;
#endif //MONOP_EVAN_STRUCTURE_H
