#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Fonctions.h"
#include "Structures.h"
#include "Macro.h"



void perteOuGainArgent(Joueurs* joueur)
{
    if(joueur->placement == 3)
    {
        printf("Vous payez une place de foot 100euros, vous allez au match, sauf que le match est annule car un joueur se prend une bouteille cristaline dans la tete et meurt soudainement.. Vous perdez 100euros. \n");
        joueur->argent -= 100;
        joueur->fortune -= 100;
    }
    else if (joueur->placement == 11)
    {
        printf("Vous cassez une voiture de golf en faisant une course contre votre grand pere qui lui est en deambulateur, vous gagnez la course mais perdez 100euros pour reparer la voiture de golf. \n");
        joueur->argent -= 100;
        joueur->fortune -= 100;
    }
    else if (joueur->argent == 19)
    {
        printf("Vous apercevez Mohamed Ali dans un reve qui vous dit de vous battre avec le prochain inconnu que vous croisez. Vous rencotrez Conor McGreggor et donc vous le chauffez pour vous battre avec. Sans surprise vous perdez et donc devez payer 200euros de chirurgie estethique. \n");
        joueur->argent -= 100;
        joueur->fortune -= 100;
    }
    else if(joueur->placement == 27)
    {
        printf("Etant donne que vous etes tres petit, vous vous faites passer pour votre petit frere de 10ans pour participer a sa place a un tournoi de badminton. Vous le remportez et donc gagnez 50euros. \n");
        joueur->argent += 50;
        joueur->fortune += 50;
    }
}
