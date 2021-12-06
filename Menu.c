
#include "structure.h"
#include "Menu.h"
#include "time.h"
#include "stdlib.h"
#include "stdio.h"
#include "joueur.h"
#include "Deplacement.h"

void menuPrinc() {
    srand(time(NULL));
    int choix = 0;
    int nbJoueurs = 0;
    Joueurs **tablNom = NULL;
    int taille = 0;
    char *nom;
    printf("Veuillez choisir parmis l'ensemble des options suivantes:\n1)Lancer une nouvelle partie.\n2)Sauvegarder la partie en cours.\n3)Charger une ancienne partie.\n4)Afficher les noms de l'equipe du projet.\n5)Afficher les regles du jeu.\n6)Quitter ce jeu.\n>");
    scanf("%d", &choix);
    switch (choix) {
        case 1:
            nbJoueurs = nombreJoueur();


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


