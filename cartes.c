//
// Created by User on 18-11-21.
//

#include "cartes.h"
#include <stdio.h>
#include <stdlib.h>
#define NB_CARTESCHANCE_MAX 10
#define NB_CARTESCOMMUNAUTE_MAX 10


void afficherCarteChance(CartesChance carte) {
    printf("Vous avez pioch%c : %c %s \n" , 130, carte.nomCarte);
}

void attributionCarteChance(int numero) {
    switch(numero) {
        case 0 :
            printf("Allez %c la case de d%cpart. (Collectez 200 euros)\n", 133, 130);
            break;
        case 1 :
            printf("Allez %c foot2. Collectez votre salaire si vous passez la case d%cpart\n", 133, 130);
            break;
        case 2 :
            printf("Allez %c tennis1. Collectez votre salaire si vous passez la case d%cpart\n", 133, 130);
            break;
    case 3 :
        printf("La banque vous paye 50 euros\n");
        break;
    case 4 :
        printf("Vous pouvez sortir de prison\n");
        break;
    case 5 :
        printf("Reculez de 3 cases\n");
        break;
    case 6 :
        printf("Allez directement en prison, vous ne passez pas par la case départ\n");
        break;
    case 7 :
        printf("Vous faites des r%cparations sur vos propri%ct%cs : Payez 25 euros/maison et 100 euros/hotel\n", 130, 130, 130);
        break;
    case 8 :
        printf("Vous avez %ct%c %clu maire, payez 50 euros %c chaque joueur\n", 130, 130, 130, 133);
        break;
    case 9 :
        printf("Exces de vitesse : payez 100 euros\n");
        break;
}

void melangerCartesChance(CartesChance* paquet) {
    int k = 0, enattente = 0;
    for(int i = 0; i < NB_CARTESCHANCE_MAX; i++) {
        k = rand() % 9;
        enattente = paquet[i].numero;
        paquet[i].numero = paquet[k].numero;
        paquet[k].numero = enattente;
    }
}

void afficherLesCartesChance(CartesChance* tabNomCartes) {
    printf("Voici les cartes chance : \n");
    for(int i = 0; i < NB_CARTESCHANCE_MAX; i++) {
        printf("%s", tabNomCartes[i]);
    }
}

void afficherCarteCommunaute(CartesCommunaute carte) {
    printf("Vous avez pioch%c : %s %s \n" , 130, carte.nomCarte);
}

void melangerCartesCommunaute(CartesCommunaute* paquet) {
    int k = 0, enattente = 0;
    for (int i = 0; i < NB_CARTESCOMMUNAUTE_MAX; i++) {
        k = rand() % 9;
        enattente = paquet[i].numero;
        paquet[i].numero = paquet[k].numero;
        paquet[k].numero = enattente;
    }
}

void afficherLesCartesCommunaute(CartesCommunaute* tabNomCartes) {
    printf("Voici les cartes communaut%c : \n", 130);
    for(int i = 0; i < NB_CARTESCOMMUNAUTE_MAX; i++) {
        printf("%s", tabNomCartes[i]);
    }
}

void afficherCartePropriete(CartesPropriete carte) {
    printf("Vous avez pioch%c : %s %s \n" , 130, carte.nomCarte);
}

// on affecte le loyer en fonction du nombre de maison. Je fais une fonction par nombre de maison
// Exemple : si numeroGroupe = 1 et emplacement = 2, on aura Zinedine Zidane


void montantLoyerZeroMaison(int numeroGroupe, int emplacement, Case* p) {
        int loyer = 0;
        switch(numeroGroupe) {
            case 1 : if(emplacement = 1) {
                    p.loyer = 60;
                }
                else {
                    p.loyer = 80;
                }
                break;
                case 2 :
                    if(emplacement == 1) {
                        p.loyer = 100;
                    }
                    else {
                        p.loyer = 120;
                    }
                    break;
                    case 3 :
                        if(emplacement == 1) {
                            p.loyer = 140;
                        }
                        else {
                            p.loyer = 160;
                        }
                        break;
                        case 4 :
                            if(emplacement == 1) {
                                p.loyer = 180;
                            }
                            else {
                                loyer =200;
                            }
                            break;
                            case 5 :
                                if(emplacement == 1) {
                                    p.loyer = 220;
                                }
                                else {
                                    p.loyer = 240;
                                }
                                break;
                                case 6 :
                                    if(emplacement == 1) {
                                        p.loyer = 260;
                                    }
                                    else {
                                        loyer = 280;
                                    }
                                    break;
                                    case 7 :
                                        if(emplacement == 1) {
                                            loyer = 300;
                                        }
                                        else {
                                            loyer = 320;
                                        }
                                        break;
                                        case 8 :
                                            if(emplacement == 1) {
                                                loyer = 350;
                                            }
                                            else {
                                                loyer = 400;
                                            }
        }
    }

void montantLoyerUneMaison(int numeroGroupe, int emplacement) {
    int loyer = 0;
    switch(numeroGroupe) {
        case 1 :
            if(emplacement == 1) {
                loyer = 100;
            }
            else {
                loyer = 150
            }
    }
    case 2 :
        if(emplacement == 1) {
            loyer = ;
        }
        else {
            loyer = 120;
        }
    break;
    case 3 :
        if(emplacement == 1) {
            loyer = 140;
        }
        else {
            loyer = 160;
        }
    break;
    case 4 :
        if(emplacement == 1) {
            loyer = 180;
        }
        else {
            loyer =200;
        }
    break;
    case 5 :
        if(emplacement == 1) {
            loyer = 220;
        }
        else {
            loyer = 240;
        }
    break;
    case 6 :
        if(emplacement == 1) {
            loyer = 260;
        }
        else {
            loyer = 280;
        }
    break;
    case 7 :
        if(emplacement == 1) {
            loyer = 300;
        }
        else {
            loyer = 320;
        }
    break;
    case 8 :
        if(emplacement == 1) {
            loyer = 350;
        }
        else {
            loyer = 400;
        }
}
}
}

void montantLoyerDeuxMaisons(int numeroGroupe, int emplacement) {
    int loyer = 0;
    switch (numeroGroupe) {
        case 1 :
            if(emplacement == 1) {
                loyer =
            }
    }
}

void montantLoyerTroisMaisons(int numeroGroupe, int emplacement) {
    int loyer = 0;
    switch (numeroGroupe) {
        case 1 : if(emplacement = 1) {
        }
    }
    }
}

void affecterLoyer(int nbMaisons, int numeroGroupe) {
        int loyer = 0;
        switch(nbMaisons) {
            case 0 :
                loyer = montantLoyerZeroMaison(numeroGroupe);
                break;
        case 1 :
            loyer = montantLoyerUneMaison()
        }