//evan version
#include "joueur.h"
#include "structure.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"



int nombreJoueur() {
    int nbJoueurs = 0;
    while ((nbJoueurs < 2) || (nbJoueurs > 6)) {
        printf("Bonjour a tous, bienvenue dans le monopoly des LEGENDES DU SPORT.\nVeuillez saisir le nombre de participant:\n>");
        scanf("%d", &nbJoueurs);
        if (nbJoueurs < 2) {
            printf("Vous ne pouvez pas jouer tout seul... Allez chercher un amis!!\n");
        } else if (nbJoueurs > 6) {
            printf("Vous etes trop nombreux...Jouez seulement entre vrais amis. :)\n");

        }
    }
    return nbJoueurs;
}

Joueurs creerJoueur(int i, int nbJ){
    Joueurs player;
    printf("Veuillez rentrer le pseudo du joueur %d :\n >", i+1 );
    fflush(stdin);
    fgets(player.nomJ,TAILLE_NOM_MAX, stdin );
    player.nomJ[strlen(player.nomJ)-1] = '\0';
    player.fortune = 1500;
    player.argent = 1500;
    player.placement = 1;
    player.numeroJ = i+1;
    player.nbGroupes = 0;
    player.nbProprietes = 0;
    player.nbHotelsJ = 0;
    player.nbMaisonsJ = 0;
    player.nbDouble = 0;
    player.faillite = 0;
    player.cartesPrison = 0;
    player.nbHypotheque = 0;
    player.enPrison = 0;
    player.placementSur32 = 0;
    player.nbJoueursVivant = nbJ;
    player.possessionParCase = (int*) calloc(NOMBRE_CASE, sizeof (int));
    for ( int h = 1 ;  h < NOMBRE_CASE ; h = h + 2 ){
        player.possessionParCase[h] = -2;
        player.possessionParCase[h-1] = -3;
    }
    return player;
}

Joueurs* initJoueur(int nbJoueurs){
    Joueurs* tabJoueur  = (Joueurs*) calloc(nbJoueurs, sizeof (Joueurs));

    printf("La liste des joueurs s'affichera quand vous aurez rentre vos pseudos: \n\n");
    for ( int i = 0 ; i < nbJoueurs ; i++){
        tabJoueur[i] = creerJoueur(i , nbJoueurs);
    }
    /*for ( int  i = 0 ; i< nbJoueurs ; i++){
        printf("Le joueur %d est %s! Sa fortune est de %d, son argent est de %d il se trouve a la case depart,"
               " possede %d maison et %d hotel, avec %d propriete et %d groupe de legendes de sport\n\n", tabJoueur[i].numeroJ , tabJoueur[i].nomJ,
               tabJoueur[i].fortune, tabJoueur[i].argent , tabJoueur[i].nbMaisonsJ, tabJoueur[i].nbHotelsJ, tabJoueur[i].nbProprietes, tabJoueur[i].nbGroupes  );

    }*/
    return tabJoueur;
}






