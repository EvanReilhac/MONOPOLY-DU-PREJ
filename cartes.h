//
// Created by User on 18-11-21.
//
#define MAX 100
#define TAILLE_NOM_MAX 100
#ifndef MONOPOLYJM_CARTES_H
#define MONOPOLYJM_CARTES_H

typedef struct {
    char nomCarte[TAILLE_NOM_MAX];
    int numero;
} CartesChance;

typedef struct {
    char nomCarte[TAILLE_NOM_MAX];
    int numero;
} CartesCommunaute;

typedef struct{
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
    int cartesSortirPrison;
    int faillite;
    int nbHypotheque;
    int nbDouble;
}Joueurs;


int nombreJoueur();
int getRandomInteger(int nbJoueurs);
void tirageAuSortJoueurs(Joueurs* tabJoueurs, int nbJoueurs);
void goPrison(Joueurs* joueur);
void afficherCarteChance(CartesChance* carte);
void attributionCarteChance(int numero, Joueurs* j);
void attributionCarteCommunaute(int numero, Joueurs* j);
void melangerCartesChance(CartesChance* paquet);
void afficherLesCartesChance(CartesChance* tabNomCartes);
void afficherCarteCommunaute(CartesCommunaute* carte);
void melangerCartesCommunaute(CartesCommunaute* paquet);
void afficherLesCartesCommunaute(CartesCommunaute* tabNomCartes);
void afficherCartePropriete(Case carte);
int montantLoyerZeroMaison(int numeroGroupe, int emplacement, Case* p);
int montantLoyerUneMaison(int numeroGroupe, int emplacement, Case* p);
int montantLoyerDeuxMaisons(int numeroGroupe, int emplacement, Case* p);
int montantLoyerTroisMaisons(int numeroGroupe, int emplacement, Case* p);
int montantLoyerQuatreMaisons(int numeroGroupe, int emplacement, Case* p);
int montantLoyerUnHotel(int numeroGroupe, int emplacement, Case* p);
void affecterLoyer(int nbMaisons, int nbHotel);

#endif //MONOPOLYJM_CARTES_H
