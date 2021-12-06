
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
    char possessionParGroupe[8]; // 0 si aucune propriete du gp , 1 si une possedees et 2 si 2 possedees
    int* possessionParCase; // réprésente la relation entre un joueur et une case du jeu, vaut le nombre de maison à l'indice de la case , -2 s'il ne possède pas, -1 s'il l'a hypothéquée, -3 si ce n'est une pas une propriété
    int nbGroupes;
    int fortune;
    int cartesPrison;
    int faillite;
    int nbHypotheque;
    int numeroJ;
    int nbDouble;
    int enPrison;
    int placementSur32;
    int nbJoueursVivant;

}Joueurs;

typedef struct
{
    char nomPro[TAILLE_NOM_MAX];
    int type; // 0 = legende; 1 = carte chance; 2 = carte communaute; 3 = case depart; 4 = prison; 5 = perte/gain d'argent sur case; 6 = avancement; 7 = case libre
    int donne; //ce que tu reçois par la case
    int prix;
    int loyer;
    int hypotheque;
    int valeurHypotheque;
    int numero;
    int nbMaison;
    int nbHotel;
    int prixMaison;
    int newCase;
    int numeroGroupes;
    char nomGroupe[TAILLE_NOM_MAX];
    int possibilite; //-1 si pas une propriete, 0 disponible , x si appartient au joueur x ...
}Case;


typedef struct
{
    char nomCarte[TAILLE_NOM_MAX];
    int numero;
    int prixAPayer;
    int prixARecevoir;
} CartesChance;

typedef struct {
    char nomCarte[TAILLE_NOM_MAX];
    int numero;
    int prixAPayer;
    int prixARecevoir;
} CartesCommunaute;
#endif //MONOP_EVAN_STRUCTURE_H
