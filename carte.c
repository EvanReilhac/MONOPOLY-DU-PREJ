#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Fonctions.h"
#include "Structures.h"
#include "Macro.h"

CartesChance initChance(int numero, char* nom, int prixAPayer, int prixARecevoir)
{
    CartesChance carteChance;
    carteChance.numero = numero;
    carteChance.prixAPayer = prixAPayer;
    carteChance.prixARecevoir = prixARecevoir;
    strcpy(carteChance.nomCarte, nom);
    return carteChance;
}

CartesChance* initCarteChance()
{
    CartesChance* tabCarteChance =  calloc(NB_CARTE , sizeof(CartesChance));
    tabCarteChance[0] = initChance(1, "AllezCaseDepart", 0, 200);
    tabCarteChance[1] = initChance(2,"Zidane", 0, 0);
    tabCarteChance[2] = initChance(3, "Paire", 0, 0);
    tabCarteChance[3] = initChance(4, "BanqueKhalass", 0, 50);
    tabCarteChance[4] = initChance(5, "CartePrison", 0, 0);
    tabCarteChance[5] = initChance(6, "Reculez", 0, 0);
    tabCarteChance[6] = initChance(7, "AllezPrison", 0, 0);
    tabCarteChance[7] = initChance(8, "Reparations", 100, 0);
    tabCarteChance[8] = initChance(9, "Maire", 50, 0);
    tabCarteChance[9] = initChance(10, "ExcesDeVitesse", 100, 0);
}


CartesCommunaute initCommunaute(int numero, char* nom, int prixAPayer, int prixARecevoir)
{
    CartesCommunaute carteCommunaute;
    carteCommunaute.numero = numero;
    carteCommunaute.prixAPayer = prixAPayer;
    carteCommunaute.prixARecevoir = prixARecevoir;
    strcpy(carteCommunaute.nomCarte, nom);
    return carteCommunaute;
}

CartesChance* initCarteCommunaute()
{
    CartesCommunaute * tabCarteCommunaute =  calloc(NB_CARTE , sizeof(CartesCommunaute));
    tabCarteCommunaute[0] = initCommunaute(1, "AllezCaseDepart", 0, 200);
    tabCarteCommunaute[1] = initCommunaute(2,"Docteur", 50, 0);
    tabCarteCommunaute[2] = initCommunaute(3, "cartePrison", 0, 0);
    tabCarteCommunaute[3] = initCommunaute(4, "AllezPrison", 0, 0);
    tabCarteCommunaute[4] = initCommunaute(5, "VideGrenier", 0, 30);
    tabCarteCommunaute[5] = initCommunaute(6, "Racket", 0, 0);
    tabCarteCommunaute[6] = initCommunaute(7, "Rentes", 0, 100);
    tabCarteCommunaute[7] = initCommunaute(8, "Hopital", 100, 0);
    tabCarteCommunaute[8] = initCommunaute(9, "ConcoursBeaute", 0, 10);
    tabCarteCommunaute[9] = initCommunaute(10, "Heritage", 0, 100);
}