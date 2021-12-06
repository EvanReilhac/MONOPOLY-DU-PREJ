#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Fonctions.h"
#include "Structures.h"
#include "Macro.h"

int placement( Joueurs* p)
{
    int choix = 0, a = 0;
    int desUn = 0, desDeux = 0;
    int total = 0;
    printf("veuillez choisir parmis les options suivantes:\n 1) Lancez votre des.\n 2) quittez la partie.\n>");
    scanf("%d", &choix);
    switch (choix)
    {
        case 1:
            a = jeuDes(&desUn, &desDeux);
            printf("Le total est de %d.", a);
            dooble(&desUn, &desDeux, &total);
            p->placement = p->placement + a;
            printf("Déplacer vous à la case %d", p->placement);
            p->placement = p->placement + total;
            break;
        case 2:
            printf("Vous avez quitter la partie.");
            break;
        default:
            return 0;
    }
}