
#include "propriete.h"
#include "Deplacement.h"
#include "structure.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "Cartes.h"

int getRandomInteger() {
    //srand(time(NULL));
    int nombrealeatoire = (rand() % (MAX - MIN + 1)) + MIN;
    return nombrealeatoire;
}

//Fonction qui permet de simuler un lancement de dés
int jeuDes(int *desUn, int *desDeux, Joueurs *pplayer) {
    int choix = 0;
    printf("Taper 1 pour lancer les des : \n >");
    scanf("%d", &choix);
    if (choix == 1) {
        *desUn = getRandomInteger();
        *desDeux = getRandomInteger();
        printf("%d  %d\n", *desUn, *desDeux);
        int total = *desUn + *desDeux;
        printf("Vous avez fait %d.\n", total);
        pplayer->placement = (pplayer->placement + total) % 32;


        return pplayer->placement;
    }


}

//
int dooble(int *desUn, int *desDeux, Joueurs *pPlayer) {
    if (*desUn == *desDeux) {
        pPlayer->nbDouble += 1;
        printf("Vous avez fait un double ! Il faut rejouer ! Mais gare a vous le danger est partout il vous reste %d double a faire avant le placard...\n",
               3 - pPlayer->nbDouble);
        return 1;
    } else {
        return 0;
    }
}

void achatRue(Case *prop, Joueurs *pAcheteur, Joueurs *pProprio, int nombreJoueur, Joueurs *tablJ) {
    int choix = 0;
    if (pAcheteur->possessionParCase[prop->numero - 1] == -2) {
        if (prop->hypotheque == 1) {
            printf("La rue %s n'est pas disponible a l'achat.", prop->nomPro);
            return;
        } else if (prop->possibilite > 0 && prop->possibilite != pAcheteur->numeroJ) {
            prixLoyer(prop, pAcheteur, pProprio, nombreJoueur, tablJ);
            return;
        } else if (prop->possibilite == 0) {
            if (pAcheteur->argent < prop->prix) {
                printf("Vous etes pauvres...Enrichissez vous pour esperer aquerir de tels biens.\n");
                return;
            } else {
                printf("La %s est disponible a l'achat, pour l'acheter il vous suffit de taper vote numero \n(et pas de telephone coquinou:/) c'est a dire taper %d sinon taper 0:\n>",
                       prop->nomPro, pAcheteur->numeroJ);
                scanf("%d", &prop->possibilite);
                if (prop->possibilite == pAcheteur->numeroJ) {
                    printf("Felicitation, vous faites l'aquisition de la %s.\n", prop->nomPro);
                    pAcheteur->possessionParCase[prop->numero - 1] = 0;
                    pAcheteur->nbProprietes += 1;
                    pAcheteur->possessionParGroupe[prop->numeroGroupes] += 1;
                    pAcheteur->argent -= prop->prix;
                    pAcheteur->fortune -= prop->prix / 2;
                    return;
                } else {
                    printf("Petit joueur!!! Vous risquez de vous en mordre les doigts...\n");
                    return;
                }
            }
        }

    } else if (pAcheteur->possessionParCase[prop->numero - 1] > 0) {
        printf("Vous etes chez vous...Que ca fait du bien de retrouver le parfum de la maison.\n");
        if (pAcheteur->possessionParGroupe[prop->numeroGroupes] == 2) {
            achatMaison(prop, pAcheteur);
            return;
        }
    } else if (pAcheteur->possessionParCase[prop->numero - 1] == -1) {
        printf("Malheuresement votre maison est hypothequer apres vos deboirs financiers...Esperer vous refaire la cerise pour pouvoir apporter des modifs a votre rue.\n");
        return;
    }
}


void
typeCartes(Case *prop, Joueurs *player, Joueurs *pProprio, CartesChance *paquetChance, CartesCommunaute *paquetCommu,
           int nombreJoueur, Joueurs *tablJ) {


    switch (prop->type) {
        case 0:
            achatRue(prop, player, pProprio, nombreJoueur, tablJ);
            break;
        case 1:
            printf("Vous etes tombe sur la case carte chance, vous allez piocher une carte :\n");

            int nbCartesPioche = 0;

            attributionCarteChance(paquetChance[nbCartesPioche].numero, player);
            nbCartesPioche++;

            nbCartesPioche = 0;
            melangerCartesChance(paquetChance);
            break;


        case 2:
            printf("Vous etes tombe sur la case carte communaute, vous allez piocher une carte :\n");
            melangerCartesCommunaute(paquetCommu);
            int nbCartesPioches = 0;

            attributionCarteCommunaute(paquetChance[nbCartesPioches].numero, player, nombreJoueur);
            nbCartesPioches++;

            nbCartesPioches = 0;
            melangerCartesCommunaute(paquetCommu);
            break;
        case 3:
            caseDepart(player);
            break;
        case 4:
            printf("Quel grand coeur!!!Vous rendez visite a Oscar Pistorius pour le soutenir\n");
            break;
        case 5:
            perteOuGainArgent(player, prop, nombreJoueur, tablJ);
            break;
        case 6:
            changement(player);
            break;
        case 7:
            printf("Vous n'avez rien a faire, on croirai voir un prof d'info... \n");
            break;
    }
}

void achatMaison(Case *prop, Joueurs *pAcheteur) {
    int choix = 0;


    if (pAcheteur->argent < prop->prixMaison) {
        printf("Vous n'avez pas le sous... Vous ne pouvez donc pas acheter de maison.\n");
        return;
    } else if (pAcheteur->possessionParCase[prop->numero] == 5) {
        printf("Il n'est pas possible d'obtenir plus qu'un hotel, reposez vous tranquilement dans votre somptueuse propriete.\n");
        return;
    } else {
        if (pAcheteur->possessionParCase[prop->numero] == 4) {
            printf("Souhaitez vous acheter un hotel a %d pour embellir votre rue? Si oui tapez 1 sinon tapez 0:\n>",
                   prop->prixMaison);
            scanf("%d", &choix);
            if (choix == 0) {
                printf("Vous etes petit joueur...");
                return;
            } else if (choix == 1) {
                printf("Mais quel joueur!!! vous faites l'acquisition d'un hotel.\n");
                pAcheteur->nbHotelsJ += 1;
                pAcheteur->possessionParCase[prop->numero] += 1;
                pAcheteur->argent -= prop->prixMaison;
                pAcheteur->fortune -= prop->prixMaison;
                return;
            } else {
                printf("Souhaitez vouz acheter une maison a %d pour embellir votre rue? Si oui tapez 1 sinon tapez 0:\n>",
                       prop->prixMaison);

                scanf("%d", &choix);
                if (choix == 0) {
                    printf("Vous etes petit joueur...");
                    return;
                } else if (choix == 1) {
                    printf(" Vous faites l'acquisition d'une nouvelle maison.\n");
                    pAcheteur->possessionParCase[prop->numero] += 1;
                    pAcheteur->argent -= prop->prixMaison;
                    pAcheteur->fortune -= prop->prixMaison;
                    return;

                }
            }

        }

    }

}

void perteOuGainArgent(Joueurs *joueur, Case *tabCase, int nombreJoueur, Joueurs *tablJ) {
    if (joueur->placement == 3) {
        printf("Vous payez une place de foot 100 euros, vous allez au match, sauf que le match est annule car un joueur se prend \n une bouteille cristaline dans la tete et meurt soudainement.. Vous perdez 100 euros. \n");
        if (joueur->argent < 100) {
            fonctionHypotheque(&tabCase[2], joueur, 100, nombreJoueur, tablJ);
            return;
        } else {
            joueur->argent -= 100;
            joueur->fortune -= 100;
        }
    } else if (joueur->placement == 11) {
        printf("Vous cassez une voiture de golf en faisant une course contre votre grand pere qui lui est en deambulateur, vous gagnez\n "
               "la course mais perdez 100 euros pour reparer la voiture de golf. \n");
        if (joueur->argent < 100) {
            fonctionHypotheque(&tabCase[10], joueur, 100, nombreJoueur, tablJ);
        } else {
            joueur->argent -= 100;
            joueur->fortune -= 100;
        }

    } else if (joueur->argent == 19) {
        printf("Vous apercevez Mohamed Ali dans un reve qui vous dit de vous battre avec le prochain inconnu que vous croisez. "
               "\nVous rencontrez Conor McGreggor et donc vous le chauffez pour vous battre avec."
               "\n Sans surprise vous perdez et donc devez payer 200 euros de chirurgie esthetique. \n");
        if (joueur->argent < 100) {
            fonctionHypotheque(&tabCase[18], joueur, 100, nombreJoueur, tablJ);
        } else {
            joueur->argent -= 100;
            joueur->fortune -= 100;
        }


    } else if (joueur->placement == 27) {
        printf("Etant donne que vous etes tres petit, vous vous faites passer pour votre petit frere de 10 ans pour \n"
               "participer a sa place a un tournoi de badminton. Vous le remportez et donc gagnez 50 euros. \n");
        joueur->argent += 50;
        joueur->fortune += 50;
    }
}

void caseDepart(Joueurs *p) {
    printf("YOUPI!!! Vous passez par la case depart, vous gagnez 200 euros.\n");
    p->argent = p->argent + 200;
    p->fortune = p->fortune + 200;
}


void changement(Joueurs *p) {
    switch (p->placement) {
        case 5:
            printf("Attention!!!Un moroter de Teddy RINNER vous fait voler jusqu'a la case 13.\n");
            p->placement = 13;
            break;
        case 13:
            printf("Attention!!! Un arai de Teddy RINNER vous fait voler jusqu'a la case 22.\n");
            p->placement = 21;
            break;
        case 21:
            printf("Attention!!! Un sasae de Teddy RINNER vous fait voler jusqu'a la case 29.\n");
            p->placement = 29;
            break;
        case 29:
            printf("Attention!!! Un uchimata de Teddy RINNER vous fait voler jusqu'a la case 5.\n");
            p->placement = 5;
            printf("Vous passez par la case  depart , vous recevez 200 euros");
            p->argent += 200;
            p->fortune += 200;
            break;
    }
}

void sortirPrison(Joueurs *joueur, int *tourPrison) {
    srand(time(NULL));
    int total = 0;
    int choix = 0;
    int ouiOuNon;
    int doooble = 0;
    int desUn = 0, desDeux = 0;
    while (*tourPrison <= 3) {
        printf("Comment voulez vous sortir de prison ? \n 1) Faire un double pour sortir \n 2) Utilisez une carte sortie de prison (si vous en avez une) \n 3) Payez 50 euros pour sortir \n 4) Achetez une carte prison qui vient d'un autre joueur \n >");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                printf("Vous avez choisi d'essayer le double !\n");

                int a = jeuDes(&desUn, &desDeux, joueur);
                if (desUn == desDeux) {
                    printf("\nBingoooo, vous avez fait un double, vous avancez du nombre de votre double\n");
                    joueur->placement = joueur->placement + desUn + desDeux;
                } else {
                    printf("\n Dommage c'est rate, restez en prison. \n");
                    *tourPrison++;
                }
                if (*tourPrison == 3) {
                    printf("Quoi ?? Deja 3 tours en prison, Bruce Lee arrive te ssauver et te sort de prison. Cependant il te demande 50 euros \n");
                    joueur->argent -= 50;
                    joueur->fortune -= 50;
                    *tourPrison = 0;
                }
                break;
            case 2:
                if (joueur->cartesPrison >= 1) {
                    printf("Vous sortez de prison. Lancez les des. \n");
                    joueur->cartesPrison -= 1;
                    a = jeuDes(&desUn, &desDeux, joueur);
                    printf("Le total est de %d.", a);
                    doooble = dooble(&desUn, &desDeux, joueur);
                    if (doooble == 1) {
                        printf("Bravo , vous avez braver les danger des douches de la prison, vous etes enfin libre !\n");
                        joueur->placement = joueur->placement + a;
                        printf("Déplacer vous à la case %d", joueur->placement);
                        joueur->placement = joueur->placement + total;
                    }
                } else if (joueur->cartesPrison == 0) {
                    printf("Vous avez menti !! C'est pas du joli joli dit donc. Allez rester en prison pour la peine. Et vous perdez 50euros pour tentative de tricherie \n");
                    joueur->argent -= 50;
                }
                break;
            case 3:
                printf("Vous avez decide de payer 50 euros pour sortir de prison. Vous jouerez au prochain tour . \n");
                joueur->argent -= 50;
                break;
            case 4:
                printf("Vous avez decide d'acheter la carte d'un autre joueur \n");
                break;
        }
        tourPrison++;
    }
}






