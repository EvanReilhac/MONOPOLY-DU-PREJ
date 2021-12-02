#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "MACRO.h"
#include "EXO.h"
#include "FONCTION.h"

void menuPrinc(){
    int choix = 0;
    int nbJoueurs = 0;
    Joueurs** tablNom = NULL;
    int taille = 0;
    char* nom;
    printf("Veuillez choisir parmis l'ensemble des options suivantes:\n1)Lancer une nouvelle partie.\n2)Sauvegarder la partie en cours.\n3)Charger une ancienne partie.\n4)Afficher les noms de l'equipe du projet.\n5)Afficher les regles du jeu.\n6)Quitter ce jeu.\n>");
    scanf("%d", &choix);
    switch (choix) {
        case 1:
            nbJoueurs = nombreJoueur();
            //tablNom = (Joueurs*) calloc(nbJoueurs, sizeof(Joueurs));
            for (int i = 0; i < nbJoueurs; i++){
                printf("Rentrez le nom du joueur %d:\n>", i+1);
                scanf("%s", nom);
                tablJoueurs(&tablNom, &taille, &nbJoueurs,  nom, 1500,0, 0, 0, 0, 0, 0, 0, 0);

            }
            afficherTous(tablNom, taille);




            break;
        case 2:
            //Sauvegarder partie en cours
            break;
        case 3:
            //charger une ancienne partie
            break;
        case 4:
            printf("Les devellopeurs de ce jeu sont:\n>Evan RHEILAC-AUPRETRE\n>Pierre ALLOUCHERIE\n>Jean-Marc COLLEGIA\n>Romain BOUCHER");
            break;
        case 5:
            //règles du jeu
            break;
        case 6:
            //quitter le jeu
            break;

    }
}
void monop(){
    srand(time(NULL));
    int choix = 0;
    int a = 0, b = 0;
    int desUn = 0, desDeux = 0;
    printf("veuillez choisir parmis les options suivantes:\n 1) Lancez votre des.\n 2) quittez la partie.\n>");
    scanf("%d", &choix);
    switch(choix){
        case 1:
            a =  jeuDes(&desUn, &desDeux);
            printf("Le total est de %d", a);
            b = dooble(&desUn, &desDeux);
            printf("%d", b);

            break;
        case 2:
            printf("Vous avez quitter la partie.");
    }
}