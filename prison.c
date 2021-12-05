#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Fonctions.h"
#include "Structures.h"
#include "Macro.h"


int getRandomInteger() {

    int nombrealeatoire = (rand() % (MAX - MIN + 1)) + MIN;
    return nombrealeatoire;
}

int jeuDes(int* desUn, int* desDeux) {
    *desUn = getRandomInteger();
    *desDeux = getRandomInteger();
    printf("%d  %d", *desUn, *desDeux);
    return (*desUn + *desDeux);
}

void dooble(int* desUn, int* desDeux, int* total)
{
    Joueurs* player;
    int choixDouble = 0;
    if (*desUn == *desDeux)
    player->nbDouble = 1;
    {
        printf(" \nDOUBLE!!! Vous pouvez relancer.\n");
        printf("Appuyer sur 1 pour relancer:\n>");
        scanf("%d", &choixDouble);
        if (choixDouble == 1)
        {
            *total = jeuDes(desUn, desDeux);
            printf("Le total est de %d.", total);
            if (*desUn == *desDeux)
                player->nbDouble = 2;
            {
                printf(" \nDOUBLE!!! Vous pouvez relancer.\n");
                printf("Appuyer sur 1 pour relancer:\n>");
                scanf("%d", &choixDouble);
                if (choixDouble == 1)
                {
                    *total = jeuDes(desUn, desDeux);
                    if (*desUn == *desDeux)
                        player->nbDouble = 3;
                    {
                        printf("PAS DE CHANCE!!! Vous venez de faire 3 doubles de suite.\nDirection la prison...");
                    }
                }
            }
        }
        else
        {
            *total = 0;
        }
    }
}

/*int nombreJoueur() {
    int nbJoueurs = 0;
    while ((nbJoueurs < 2) || (nbJoueurs > 6))
    {
        printf("Bonjour a tous, bienvenue dans le monopoly des LEGENDES DU SPORT.\nVeuillez saisir le nombre de participant:\n>");
        scanf("%d", &nbJoueurs);
        if (nbJoueurs < 2)
        {
            printf("Vous ne pouvez pas jouer tout seule... Allez chercher un amis!!\n");
        }
        else if (nbJoueurs > 6)
        {
            printf("Vous etes trop nombreux...Jouez seulement entre vrais amis. :)\n");
        }
    }
    return nbJoueurs;
}*/

void goPrison(Joueurs* joueur) //mettre a la carte chance et commu et double et case
{
    printf("Vous allez en prison car vous avez pris des dopants et cela s'est vu etant donne que vous avez fait le mararthon en 1h30 sans entrainement. \n");
    joueur->placement = 9;
}

/*void allezPrison(Joueurs* joueur)
{
    srand(time(NULL));
    int nbJoueur = nombreJoueur();
    int desUn = 0, desDeux = 0, tour = nbJoueur;
    int a = 0, total = 0;
    while (tour <= 3 * nbJoueur)
    {
        if(joueur->placement == 25)
        {
            printf("Vous faites une intrusion sur un terrain de foot pour prendre une photo avec Karim Benzema. Superrrr vous avez votre photo mais vous vous faites plaquer par la securite et malheureusement, ils vous emmenent en prison...\n");
            joueur->placement = 9;
        }
        else if(joueur->cartesAllezPrison == 1)
        {
            printf("Vous faites une intrusion sur un terrain de foot pour prendre une photo avec Karim Benzema. Superrrr vous avez votre photo mais vous vous faites plaquer par la securite et malheureusement, ils vous emmenent en prison...\n");
            joueur->placement = 9;
        }
        else if (joueur->nbDouble == 3)
        {
            joueur->placement = 9;
        }
        else if(joueur->cartesSortirPrison == 0)
        {
            sortirPrison(joueur);
        }
        tour = tour + nbJoueur;
    }
    printf("Deja 3 tours en prison ?? Gros coup de chance, Bruce Lee arrive vous sauver !! Mais vous lui devez 50 euros pour cette aide..  ");
    joueur->argent -= 50;
    a = jeuDes(&desUn, &desDeux);
    printf("Le total est de %d.", a);
    dooble(&desUn, &desDeux, &total);
    joueur->placement = joueur->placement + a;
    printf("Déplacer vous à la case %d", joueur->placement);
    joueur->placement = joueur->placement + total;
}*/

void sortirPrison(Joueurs* joueur, int* tourPrison)
{
    srand(time(NULL));
    int total = 0;
    int choix = 0;
    int ouiOuNon;
    while (*tourPrison <= 3)
    {
        printf("Comment voulez vous sortir de prison ? \n 1) Faire un double pour sortir \n 2) Utilisez une carte sortie de prison (si vous en avez une) \n 3) Payez 50 euros pour sortir \n 4) Achetez une carte prison qui vient d'un autre joueur \n >");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                printf("Vous avez choisi d'essayer le double !\n");
                int desUn = 0, desDeux = 0;
                int a = jeuDes(&desUn, &desDeux);
                if (desUn == desDeux) {
                    printf("\nBingoooo, vous avez fait un double, vous avancez du nombre de votre double\n");
                    joueur->placement = joueur->placement + desUn + desDeux;
                } else {
                    printf("\n Dommage c'est rate, restez en prison. \n");
                    *tourPrison++;
                }
                if (*tourPrison == 3)
                {
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
                    a = jeuDes(&desUn, &desDeux);
                    printf("Le total est de %d.", a);
                    dooble(&desUn, &desDeux, &total);
                    joueur->placement = joueur->placement + a;
                    printf("Déplacer vous à la case %d", joueur->placement);
                    joueur->placement = joueur->placement + total;
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
        tourPrison ++;
    }
}









    /*if(desUn == desDeux)
        {
            printf("Yessss vous avez fait un double, vous pouvez sortir de prison !! Et vous avancez selon le total de vos des mais pas de tour en plus pour vous.\n");
            joueur->placement = joueur->placement + desUn + desDeux;
        }
        else if(joueur->cartesSortirPrison == 1)
        {
            printf("Voulez vous utiliser votre carte pour sortir de prison ? si oui tapez 1 sinon tapez 0.\n");
            scanf("%d", &ouiOuNon);
            if(ouiOuNon == 1)
            {
                printf("Higuita vous aide a sortir de prison. Pour cela il diverti les gardes en faisant un concours de limbo. Les des sont lances.\n");
                a = jeuDes(&desUn, &desDeux);
                printf("Le total est de %d.", a);
                dooble(&desUn, &desDeux, &total);
                joueur->placement = joueur->placement + a;
                printf("Déplacer vous à la case %d", joueur->placement);
                joueur->placement = joueur->placement + total;
            }
        }
        else if (joueur->cartesSortirPrison == 0)
        {
            printf("Vous voulez sortir de prison ? Tres bien, les gardes vous demandent 50 euros pour sortir. Voulez vous payer ? Si oui tapez 1 sinon tapez 0.\n");
            scanf("%d", &ouiOuNon);
            if(ouiOuNon == 1)
            {
                printf("Bingooo vous sortez de prison, mais vous perdez egalement 50 euros... Les des sont relances\n");
                joueur->argent -= 50;
                a = jeuDes(&desUn, &desDeux);
                printf("Le total est de %d.", a);
                dooble(&desUn, &desDeux, &total);
                joueur->placement = joueur->placement + a;
                printf("Déplacer vous à la case %d", joueur->placement);
                joueur->placement = joueur->placement + total;
            }
        }
}*/


//carte chance 5 : sortez de prison  et 7 : allez en prison
//carte commu 3 : sortez de prison et 4  : allez en prison