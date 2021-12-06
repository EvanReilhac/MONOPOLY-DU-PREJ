#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Fonctions.h"
#include "Structures.h"
#include "Macro.h"

int main()
{
    printf("                                     \n"
           "                                      \n"
           "                                MONOPOLY VERSION LEGENDES DU SPORT\n"
           "-------------------------------------------------------------------------------------------------\n"
           "| 01        | 02        | 03        | 04        | 05        | 06        | 07        | 08        |\n"
           "|  case     |           |   payer   |           |  avancez  |           | carte     |           |\n"
           "|   depart  |  Diego    | match foot|  Zinedine |  case 13  |  Kobe     | communaute|  Mickael  |\n"
           "|           | Maradona  | -100euros |  Zidane   |           |  Bryant   |           |  Jordan   |\n"
           "-------------------------------------------------------------------------------------------------\n"
           "| 09        | 10        | 11        | 12        | 13        | 14        | 15        | 16        |\n"
           "| case      |           |  cassage  |           |  avancez  |           |  carte    |           |\n"
           "|   prison  | Sebastien | voiturette|   Jonah   |  case 22  |    Mike   |  chance   |  Mohamed  |\n"
           "|           |   Chabal  | -100euros |    Lomu   |           |   Tyson   |           |    Ali    |\n"
           "-------------------------------------------------------------------------------------------------\n"
           "| 17        | 18        | 19        | 20        | 21        | 22        | 23        | 24        |\n"
           "| case      |           | chirurgie |           |  avancez  |           | carte     |           |\n"
           "|   libre   | Florent   | esthetique|   Laure   |  case 29  |   Kevin   | communaute| Penelope  |\n"
           "|           | Manaudou  | -200euros |  Manaudou |           |   Staut   |           | Leprevost |\n"
           "-------------------------------------------------------------------------------------------------\n"
           "| 25        | 26        | 27        | 28        | 29        | 30        | 31        | 32        |\n"
           "|   aller   |           |  tournoi  |           |  avancez  |           | carte     |           |\n"
           "| en prison | Benoit    | badminton |   Andre   |  case 05  |  Gareth   | chance    |   Tiger   |\n"
           "|           |  Paire    | +50euros  |   Agassi  |(+200euros)|   Bale    |           |   Woods   |\n"
           "-------------------------------------------------------------------------------------------------\n"
           "\n"
           "");


void menuPrinc()
{
    srand(time(NULL));
    int choix = 0;
    int nbJoueurs = 0;
    Joueurs** tablNom = NULL;
    int taille = 0;
    char* nom;
    printf("Veuillez choisir parmis l'ensemble des options suivantes:\n1)Lancer une nouvelle partie.\n2)Sauvegarder la partie en cours.\n3)Charger une ancienne partie.\n4)Afficher les noms de l'equipe du projet.\n5)Afficher les regles du jeu.\n6)Quitter ce jeu.\n>");
    scanf("%d", &choix);
    switch (choix)
    {
        case 1:
            initCases();
            nbJoueurs = nombreJoueur();
            initJoueur(nbJoueurs);
            //fonction random JM NN
            //fonction jeu NN
              //boucle for commenceant aux 1er joueur tiré NN
                 //lancé vos dés OUI
                 //fonction placement OUI
                 //fonction qui récapitule l'ensembles des caractéristiques du joueur NN EVAN
                 //fonction type NN EC
                    //execution des différents case JM->cartes chances et commu NN/
                    //fonction prison OUI
                 //si double   OUi
                    //lancé vos dés
                    //fonction placement
                    //fonction qui récapitule l'ensembles des caractéristiques du joueur
                    //fonction type
                     //execution des différents case JM->cartes chances et commu/
                     //fonction prison
            //si double
                //lancé vos dés
                //fonction placement
                //fonction qui récapitule l'ensembles des caractéristiques du joueur
                //fonction type
                    //execution des différents case JM->cartes chances et commu/
                    //fonction prison
               //go prison
        // fonction qui annonce le joueur suivant   NN
        //fonction faillite NN PIERRE
        //fonction hypotèque NN ROMAIN
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
    /*int i = 0;
    printf("Que voulez vous faire : \n 1) Jouez au Monopoly \n 2) Sauvegarder une partie \n 3) Charger une partie \n 4) Les regles du jeu \n 5) Les createurs de ce jeu \n");
    switch(i >= 5)
    {

        case 1:

            break;

        case 2:

            break;

        case 3:

            break;

        case 4:

            break;

        case 5:

            break;
    initCases();
    int nbJoueurs;
    nbJoueurs = nombreJoueur();
    for(int i = 0; i < nbJoueurs; i++)
    {
        initJoueur(i);
    }*/
    //initJoueur(nbJoueurs);

    //fonction random JM NN
    //fonction jeu NN
    //boucle for commenceant aux 1er joueur tiré NN
    //lancé vos dés OUI
    //fonction placement OUI
    //fonction qui récapitule l'ensembles des caractéristiques du joueur NN EVAN
    //fonction type NN EC
    //execution des différents case JM->cartes chances et commu NN/ ROM ou Evan->achat prop NN
    //fonction prison OUI
    //si double   OUi
    //lancé vos dés
    //fonction placement
    //fonction qui récapitule l'ensembles des caractéristiques du joueur
    //fonction type
    //execution des différents case JM->cartes chances et commu/ ROM ou Evan->achat prop
    //fonction prison
    //si double
    //lancé vos dés
    //fonction placement
    //fonction qui récapitule l'ensembles des caractéristiques du joueur
    //fonction type
    //execution des différents case JM->cartes chances et commu/ ROM ou Evan->achat prop
    //fonction prison
    //go prison
    // fonction qui annonce le joueur suivant   NN
    //fonction faillite NN PIERRE
    //fonction hypotèque NN ROMAIN
}