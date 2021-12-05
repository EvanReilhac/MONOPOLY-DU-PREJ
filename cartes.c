//
// Created by User on 18-11-21.
//

#include "cartes.h"
#include <stdio.h>
#include <stdlib.h>
#include "time.h"


#define NB_CARTESCHANCE_MAX 10
#define NB_CARTESCOMMUNAUTE_MAX 10

// fonction de Romain : (permet de déterminer le nombre de joueurs dans la partie)

int nombreJoueur() {
    int nbJoueurs = 0;
    while ((nbJoueurs < 2) || (nbJoueurs > 6)) {
        printf("Bonjour a tous, bienvenue dans le monopoly des LEGENDES DU SPORT.\nVeuillez saisir le nombre de participant:\n>");
        scanf("%d", &nbJoueurs);
        if (nbJoueurs < 2) {
            printf("Vous ne pouvez pas jouer tout seul... Allez chercher un ami!!\n");
        } else if (nbJoueurs > 6) {
            printf("Vous etes trop nombreux...Jouez seulement entre vrais amis. :)\n");
        }
    }
    return nbJoueurs;
}

// permet d'avoir un nombre aléatoire entre deux et le nombre de joueurs (6 maximum)

int getRandomInteger(int nbJoueurs) {
    int nombreAleatoire = (rand() % (nbJoueurs)) + 1;
    return nombreAleatoire;
}

// tirage au sort du nombre de joueurs

void tirageAuSortJoueurs(Joueurs* tabJoueurs, int nbJoueurs) {
    printf("C'est %c %s de jouer", 133, tabJoueurs[getRandomInteger(nbJoueurs)].nomJ);
}

// affiche la carte chance piochée

void goPrison(Joueurs* joueur) //mettre a la carte chance et commu et double et case
{
    printf("Vous allez en prison car vous avez pris des dopants et cela s'est vu etant donne que vous avez fait le mararthon en 1h30 sans entrainement. \n");
    joueur->placement = 9;
}

void afficherCarteChance(CartesChance* carte) {
    printf("Vous avez pioch%c : %s \n" , 130, carte->nomCarte);
}

// affiche ce qui est censé être écrit sur la carte chance et les conséquences de celle-ci.

void attributionCarteChance(int numero, Joueurs* j) {
    int a = 0; // Nombre de joueurs
    int nbM = 0; // Nombre de maison
    int nbH = 0; // Nombre d'hôtels
    switch (numero) {
        case 0 :
            printf("Vous vous etes fait plaqu%c par Chabal. Allez %c la case de d%cpart. (Collectez 200 euros pour les frais d'hopitaux)\n",
                   130, 133, 130);
            j->argent += 200;
            j->fortune += 200;
            break;
        case 1 :
            printf("Allez voir Zinedine Zidane. Collectez votre salaire si vous passez la case d%cpart\n", 130);
            // Si le joueur est après la case de Zidane et avant la case départ, il passe forcément
            //par la case départ. Il reçoit donc obligatoirement 200 euros.
            if(j->placement > 4 && j->placement <= 32) {
                j->argent += 200;
                j->fortune += 200;
            }
        case 2 :
            printf("Allez calmer Benoit Paire, il ne s'arrete pas d'insulter son adversaire. Collectez votre salaire si vous passez la case d%cpart\n", 130);
            // Même explication que pour celle de Zidane.
            if(j->placement > 26 && j->placement <= 32) {
                j->argent += 200;
                j->fortune += 200;
            }
            break;
        case 3 :
            printf("La banque vous paye 50 euros\n");
            // on ajoute 5O euros dans la structure argent et fortune.
                j->argent += 50;
                j->fortune += 50;
            break;
        case 4 :
            printf("Vous pouvez sortir de prison\n");
            // On dit que le joueur a une carte prison pour vérifier si le joueur
            // a bien la carte s'il veut l'utiliser.
            j->cartesSortirPrison = 1;
            break;
        case 5 :
            printf("Vous avez eu peur de Mike Tyson, reculez de 3 cases\n");
            // Le joueur reucle de 3 cases. On enlève 3 au nombre de cases actuel.
            j->placement -= 3;
            printf("Vous reculez %c la case %d\n", 133,j->placement);
            break;
        case 6 :
            goPrison(j);
            break;
        case 7 :
            printf("Des portugais sont l%c pour faire des r%cparations sur vos propri%ct%cs :"
                   " Payez 25 euros/maison et 100 euros/hotel\n",
                   133, 130, 130, 130);
            int nbM = j->nbMaisonsJ;
            int nbH = j->nbHotelsJ;
            j->argent -= 25 * nbM + 100 * nbH;
            j->fortune -= 25 * nbM + 100 * nbH;
            break;
        case 8 :
            printf("F%clicitations, vous etes corrompu, vous avez %ct%c %clu maire !"
                   " Payez 50 euros %c chaque joueur pour feter ceci.\n",130, 130, 130, 130, 133);
            int a = nombreJoueur();
            j->argent -= 50 * a;
            j->fortune -= 50 * a;
            break;
        case 9 :
            printf("Exces de vitesse : payez 100 euros\n");
            j->argent -= 100;
            j->fortune -= 100;
            break;
    }
}

void melangerCartesChance(CartesChance* paquet) {
    int k = 0, enattente = 0;
    for(int i = 0; i < NB_CARTESCHANCE_MAX; i++) {
        srand(time(NULL));
        k = rand() % 9;
        enattente = paquet[i].numero;
        paquet[i].numero = paquet[k].numero;
        paquet[k].numero = enattente;
    }
}

void afficherLesCartesChance(CartesChance* tabNomCartes) {
    printf("Voici les cartes chance : \n");
    for(int i = 0; i < NB_CARTESCHANCE_MAX; i++) {
        printf("%s", tabNomCartes[i].nomCarte);
    }
}

void afficherCarteCommunaute(CartesCommunaute* carte) {
    printf("Vous avez pioch%c : %s \n" , 130, (*carte).nomCarte);
}


void attributionCarteCommunaute(int numero, Joueurs* j) {
        int a = 0;
        switch(numero) {
            case 1 :
                printf("Apres avoir un peu trop bu, Maradona vous a confondu avec un ballon de foot,"
                       "vous volez direction la case départ (collectez 200 euros)\n");
                j->argent += 200;
                j->fortune += 200;
                break;
            case 2 :
                printf("Vous vous etes fait tacl%c par Khalid %c la cheville,"
                       "payez 50 euros pour les frais de docteur. \n",130, 133);
                j->argent -= 50;
                j->fortune -= 50;
                break;
            case 3 :
                printf("Vous avez une carte permettant de sortir de prison.\n");
                j->cartesSortirPrison = 1;
                break;
            case 4 :
                j->cartesPrison = 1;
                goPrison(j);
                break;
            case 5 :
                printf("Vous avez vendu un objet vol%c %c la Guilloti%cre,"
                       "recevez 30 euros. \n", 130, 133, 130);
                j->argent += 30;
                j->fortune += 30;
                break;
            case 6 :
                printf("C'est l'heure du racket ! tous les joueurs vous donnent 10 euros chacun. \n");
                int a = nombreJoueur();
                j->argent += 10 * a;
                j->fortune += 10 * a;
                break;
            case 7 :
                printf("Votre business marche plutot bien, collectez 100 euros. \n");
                j->argent += 100;
                j->fortune += 100;
                break;
            case 8 :
                printf("Vous avez un kyste tr%cs d%crangeant,"
                       " payez 100 euros pour les frais d'h%cpital. \n", 138, 130, 147);
                j->argent -= 100;
                j->fortune -= 100;
                break;
            case 9 :
                printf("Vous avez gagn%c le concours de baby foot."
                       "Bravo ! Vous gagnez (que) 10 euros. \n");
                j->argent += 100;
                j->fortune += 100;
                break;
            case 10 :
                printf("Vous %ctes vraiment bg. Recevez 100 euros. \n", 136);
                j->argent += 100;
                j->fortune += 100;
                break;

                void melangerCartesCommunaute(CartesCommunaute *paquet) {
                    int k = 0, enattente = 0;
                    for (int i = 0; i < NB_CARTESCOMMUNAUTE_MAX; i++) {
                        k = rand() % 9;
                        enattente = paquet[i].numero;
                        paquet[i].numero = paquet[k].numero;
                        paquet[k].numero = enattente;
                    }
                }

                void afficherLesCartesCommunaute(CartesCommunaute *tabNomCartes) {
                    printf("Voici les cartes communaut%c : \n", 130);
                    for (int i = 0; i < NB_CARTESCOMMUNAUTE_MAX; i++) {
                        printf("%s", tabNomCartes[i]);
                    }
                }

                void afficherCartePropriete(Case carte) {
                    printf("Vous avez pioch%c : %s %s \n", 130, carte.nom);
                }

// on affecte le loyer en fonction du nombre de maison. Je fais une fonction par nombre de maison
// Exemple : si numeroGroupe = 1 et emplacement = 2, on aura Zinedine Zidane


                int montantLoyerZeroMaison(int numeroGroupe, int emplacement, Case *p) {
                    int loyer = 0;
                    switch (numeroGroupe) {
                        case 1 :
                            if (emplacement = 1) {
                                p->loyer = 60;
                            } else {
                                p->loyer = 80;
                            }
                            break;
                        case 2 :
                            if (emplacement == 1) {
                                p->loyer = 100;
                            } else {
                                p->loyer = 120;
                            }
                            break;
                        case 3 :
                            if (emplacement == 1) {
                                p->loyer = 140;
                            } else {
                                p->loyer = 160;
                            }
                            break;
                        case 4 :
                            if (emplacement == 1) {
                                p->loyer = 180;
                            } else {
                                p->loyer = 200;
                            }
                            break;
                        case 5 :
                            if (emplacement == 1) {
                                p->loyer = 220;
                            } else {
                                p->loyer = 240;
                            }
                            break;
                        case 6 :
                            if (emplacement == 1) {
                                p->loyer = 260;
                            } else {
                                p->loyer = 280;
                            }
                            break;
                        case 7 :
                            if (emplacement == 1) {
                                p->loyer = 300;
                            } else {
                                p->loyer = 320;
                            }
                            break;
                        case 8 :
                            if (emplacement == 1) {
                                p->loyer = 350;
                            } else {
                                p->loyer = 400;
                            }
                    }
                    return p->loyer;
                }

                int montantLoyerUneMaison(int numeroGroupe, int emplacement, Case *p) {
                    int loyer = 0;
                    switch (numeroGroupe) {
                        case 1 :
                            if (emplacement = 1) {
                                p->loyer = 160;
                            } else {
                                p->loyer = 180;
                            }
                            break;
                        case 2 :
                            if (emplacement == 1) {
                                p->loyer = 200;
                            } else {
                                p->loyer = 220;
                            }
                            break;
                        case 3 :
                            if (emplacement == 1) {
                                p->loyer = 240;
                            } else {
                                p->loyer = 260;
                            }
                            break;
                        case 4 :
                            if (emplacement == 1) {
                                p->loyer = 280;
                            } else {
                                loyer = 300;
                            }
                            break;
                        case 5 :
                            if (emplacement == 1) {
                                p->loyer = 320;
                            } else {
                                p->loyer = 340;
                            }
                            break;
                        case 6 :
                            if (emplacement == 1) {
                                p->loyer = 360;
                            } else {
                                p->loyer = 380;
                            }
                            break;
                        case 7 :
                            if (emplacement == 1) {
                                p->loyer = 400;
                            } else {
                                p->loyer = 420;
                            }
                            break;
                        case 8 :
                            if (emplacement == 1) {
                                p->loyer = 450;
                            } else {
                                p->loyer = 500;
                            }
                    }
                    return p->loyer;
                }

                int montantLoyerDeuxMaisons(int numeroGroupe, int emplacement, Case *p) {
                    int loyer = 0;
                    switch (numeroGroupe) {
                        case 1 :
                            if (emplacement = 1) {
                                p->loyer = 260;
                            } else {
                                p->loyer = 280;
                            }
                            break;
                        case 2 :
                            if (emplacement == 1) {
                                p->loyer = 300;
                            } else {
                                p->loyer = 320;
                            }
                            break;
                        case 3 :
                            if (emplacement == 1) {
                                p->loyer = 340;
                            } else {
                                p->loyer = 360;
                            }
                            break;
                        case 4 :
                            if (emplacement == 1) {
                                p->loyer = 380;
                            } else {
                                p->loyer = 400;
                            }
                            break;
                        case 5 :
                            if (emplacement == 1) {
                                p->loyer = 420;
                            } else {
                                p->loyer = 440;
                            }
                            break;
                        case 6 :
                            if (emplacement == 1) {
                                p->loyer = 460;
                            } else {
                                p->loyer = 480;
                            }
                            break;
                        case 7 :
                            if (emplacement == 1) {
                                p->loyer = 500;
                            } else {
                                p->loyer = 520;
                            }
                            break;
                        case 8 :
                            if (emplacement == 1) {
                                p->loyer = 550;
                            } else {
                                p->loyer = 600;
                            }
                    }
                    return p->loyer;
                }

                int montantLoyerTroisMaisons(int numeroGroupe, int emplacement, Case *p) {
                    int loyer = 0;
                    switch (numeroGroupe) {
                        case 1 :
                            if (emplacement = 1) {
                                p->loyer = 360;
                            } else {
                                p->loyer = 380;
                            }
                            break;
                        case 2 :
                            if (emplacement == 1) {
                                p->loyer = 400;
                            } else {
                                p->loyer = 420;
                            }
                            break;
                        case 3 :
                            if (emplacement == 1) {
                                p->loyer = 440;
                            } else {
                                p->loyer = 460;
                            }
                            break;
                        case 4 :
                            if (emplacement == 1) {
                                p->loyer = 480;
                            } else {
                                p->loyer = 500;
                            }
                            break;
                        case 5 :
                            if (emplacement == 1) {
                                p->loyer = 520;
                            } else {
                                p->loyer = 540;
                            }
                            break;
                        case 6 :
                            if (emplacement == 1) {
                                p->loyer = 560;
                            } else {
                                p->loyer = 580;
                            }
                            break;
                        case 7 :
                            if (emplacement == 1) {
                                p->loyer = 600;
                            } else {
                                p->loyer = 620;
                            }
                            break;
                        case 8 :
                            if (emplacement == 1) {
                                p->loyer = 650;
                            } else {
                                p->loyer = 700;
                            }
                    }
                    return p->loyer;
                }


                int montantLoyerQuatreMaisons(int numeroGroupe, int emplacement, Case *p) {
                    int loyer = 0;
                    switch (numeroGroupe) {
                        case 1 :
                            if (emplacement = 1) {
                                p->loyer = 460;
                            } else {
                                p->loyer = 480;
                            }
                            break;
                        case 2 :
                            if (emplacement == 1) {
                                p->loyer = 500;
                            } else {
                                p->loyer = 520;
                            }
                            break;
                        case 3 :
                            if (emplacement == 1) {
                                p->loyer = 540;
                            } else {
                                p->loyer = 560;
                            }
                            break;
                        case 4 :
                            if (emplacement == 1) {
                                p->loyer = 580;
                            } else {
                                p->loyer = 600;
                            }
                            break;
                        case 5 :
                            if (emplacement == 1) {
                                p->loyer = 620;
                            } else {
                                p->loyer = 640;
                            }
                            break;
                        case 6 :
                            if (emplacement == 1) {
                                p->loyer = 660;
                            } else {
                                p->loyer = 680;
                            }
                            break;
                        case 7 :
                            if (emplacement == 1) {
                                p->loyer = 700;
                            } else {
                                p->loyer = 720;
                            }
                            break;
                        case 8 :
                            if (emplacement == 1) {
                                p->loyer = 750;
                            } else {
                                p->loyer = 800;
                            }
                    }
                    return p->loyer;
                }
        }

                int montantLoyerUnHotel(int numeroGroupe, int emplacement, Case *p) {
                    int loyer = 0;
                    switch (numeroGroupe) {
                        case 1 :
                            if (emplacement = 1) {
                                p->loyer = 560;
                            } else {
                                p->loyer = 580;
                            }
                            break;
                        case 2 :
                            if (emplacement == 1) {
                                p->loyer = 600;
                            } else {
                                p->loyer = 620;
                            }
                            break;
                        case 3 :
                            if (emplacement == 1) {
                                p->loyer = 640;
                            } else {
                                p->loyer = 660;
                            }
                            break;
                        case 4 :
                            if (emplacement == 1) {
                                p->loyer = 680;
                            } else {
                                p->loyer = 700;
                            }
                            break;
                        case 5 :
                            if (emplacement == 1) {
                                p->loyer = 820;
                            } else {
                                p->loyer = 840;
                            }
                            break;
                        case 6 :
                            if (emplacement == 1) {
                                p->loyer = 860;
                            } else {
                                p->loyer = 880;
                            }
                            break;
                        case 7 :
                            if (emplacement == 1) {
                                p->loyer = 900;
                            } else {
                                p->loyer = 920;
                            }
                            break;
                        case 8 :
                            if (emplacement == 1) {
                                p->loyer = 950;
                            } else {
                                p->loyer = 1000;
                            }
                    }
                    return p->loyer;
                }

                void affecterLoyer(int nbMaisons, int numeroGroupe, int emplacement, Case *p) {
                    int loyer = 0;
                    switch (nbMaisons) {
                        case 0 :
                            p->loyer = montantLoyerZeroMaison(numeroGroupe, emplacement, p);
                            break;
                        case 1 :
                            p->loyer = montantLoyerUneMaison(numeroGroupe, emplacement, p);
                            break;
                        case 2 :
                            p->loyer = montantLoyerDeuxMaisons(numeroGroupe, emplacement, p);
                            break;
                        case 3 :
                            p->loyer = montantLoyerTroisMaisons(numeroGroupe, emplacement, p);
                            break;
                        case 4 :
                            p->loyer = montantLoyerQuatreMaisons(numeroGroupe, emplacement, p);
                            break;
                        case 5 :
                            p->loyer = montantLoyerUnHotel(numeroGroupe, emplacement, p);
                    }
                }
        }


