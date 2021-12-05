#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Fonctions.h"
#include "Structures.h"
#include "Macro.h"

void faillitte(Joueurs* joueurEnAction, Joueurs* joueurPossedantLaCase, Case* cases)
{
    while(cases->loyer >= joueurEnAction->argent)
    {

        if(cases->type == 0)
        {
            printf("Vous n'avez plus assez d'argent pour payer le loyer.\n");
            if(joueurEnAction->nbHotelsJ > 0)
            {
                printf("Cependant vous avez au moins un hotel sur le plateau, vous allez devoir les vendre a la banque pour la moitie de ce que vous avez paye. \n");
                printf("Vous voulez enlever l'hotel de quel groupe ?\n");
                scanf("%d", &cases->numeroGroupes);
                printf("Vous avez choisi le groupe %d", cases->numeroGroupes);
                if(joueurEnAction->possessionParGroupe[cases->numeroGroupes] = 0)
                {
                    printf("Vous avez du vous tromper car vous n'en avez pas. Reesayer.\n");
                }
                else
                {
                    printf("Comme convenu, l'hotel du groupe que vous avez siter sera enleve et vous allez recevoir la moitie de sa valeur.");
                    joueurEnAction->possessionParGroupe[cases->numeroGroupes] -= 1;
                    joueurEnAction->nbHotelsJ -= 1;
                    joueurEnAction->argent += cases->prixMaison[cases->numeroGroupes] /2;
                }
            }
            else if(joueurEnAction->nbMaisonsJ > 0)
            {
                printf("Cependant vous avez au moins une maison sur le plateau, vous allez devoir les vendre a la banque pour la moitie de ce que vous avez paye. \n");
                printf("Vous voulez enlever la maison de quel groupe ?\n");
                scanf("%d", &cases->numeroGroupes);
                printf("Vous avez choisi le groupe %d", cases->numeroGroupes);
                if(joueurEnAction->possessionParGroupe[cases->numeroGroupes] = 0)
                {
                    printf("Vous avez du vous tromper car vous n'en avez pas. Reesayer.\n");
                }
                else
                {
                    printf("Comme convenu, la maison du groupe que vous avez site sera enleve et vous allez recevoir la moitie de sa valeur.");
                    joueurEnAction->possessionParGroupe[cases->numeroGroupes] -= 1;
                    joueurEnAction->nbMaisonsJ -= 1;
                    joueurEnAction->argent += cases->prixMaison[cases->numeroGroupes] /2;
                }
            }
            else
            {
                printf("Vous n'avez plus de maison ni d'hotel. Et vous n'avez pas assez pour payer le loyer. Vous allez devoir faire faillite et votre reste d'argent sera au loyer. Fin du game pour vous. \n");
                joueurEnAction->argent = 0;
                joueurEnAction->faillite = 1;
                joueurPossedantLaCase += joueurEnAction->argent;
            }
        }
        /*else if(cases->type == 1)
        {

        }
        else if(cases->type == 2)
        {
        }
        else if(cases->type == 5)
        {
        }*/
    }
}
