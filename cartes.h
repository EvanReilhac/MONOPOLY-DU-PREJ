//
// Created by User on 18-11-21.
//

#ifndef MONOPOLYJM_CARTES_H
#define MONOPOLYJM_CARTES_H

typedef struct {
    char* nomCarte;
    int numero;
} CartesChance;

typedef struct {
    char* nomCarte;
    int numero;
} CartesCommunaute;

typedef struct {
    char* nomCarte;
    int numero;
    int taxeHabitation;
    int loyerHabitation;
    int prixAchat;
} CartesPropriete;




void afficherCarteChance(CartesChance carte);
void attributionCarteChance(int numero);
void melangerCartesChance(CartesChance* paquet);
void afficherLesCartesChance(CartesChance* tabNomCartes);
void afficherCarteCommunaute(CartesCommunaute carte);
void melangerCartesCommunaute(CartesCommunaute* paquet);
void afficherLesCartesCommunaute(CartesCommunaute* tabNomCartes);
void afficherCartePropriete(CartesPropriete carte);
void montantLoyerZeroMaison(int numeroGroupe);
void montantLoyerDeuxMaisons(int numeroGroupe);
void montantLoyerTroisMaisons(int numeroGroupe)
void affecterLoyer(int nbMaisons, int nbHotel);

#endif //MONOPOLYJM_CARTES_H
