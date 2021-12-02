#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Fonctions.h"
#include "Structures.h"

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

int dooble(int* desUn, int* desDeux){
    int choixDouble = 0;
    if (*desUn == *desDeux){
        for (int i = 1; i < NOMBRE_DOUBLE; i++){
            printf(" DOUBLE!!! Vous pouvez relancer.\n");
            printf("Appuyer sur 1 pour relancer, 0 si vous shouaiter quitter la partie:\n>");
            scanf("%d", &choixDouble);
            if (choixDouble == 1){
                jeuDes(desUn, desDeux);
                return (*desUn + *desDeux)
            }
            else{
                printf("vous quittez la partie.");
            }

        }
        printf(" PAS DE CHANCE!!! Vous venez de faire 3 doubles de suite.\nDirection la prison...");
    }
    else{
        printf(" Joueur suivant");
    }
    return
}

void prison()
{
    des =
    Condition p;
    if(p.numeroCase == 25)
    {
        printf("Vous etes sur la case 25.. Dommage pour vous, direction la pris");
    }
}