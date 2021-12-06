#include <stdio.h>
#include "propriete.h"
#include "joueur.h"
#include "fonctions.h"
#include "Menu.h"
#include "time.h"
#include "stdlib.h"
#include "joueur.h"
#include "Cartes.h"
#include "Deplacement.h"

int main() {
    afficherplateau();
    srand(time(NULL));
    int choix = 0;
    int nbJ = 0;
    int desUn = 0;
    int desDeux = 0;
    int nbCarteChance = 0;
    int nbCarteCommu = 0;
    int compteurDouble = 0;

    printf("Veuillez choisir parmi l'ensemble des options suivantes:\n1)Lancer une nouvelle partie.\n2)Sauvegarder la partie en cours.\n3)Charger une ancienne partie.\n4)Afficher les noms de l'equipe du projet.\n5)Afficher les regles du jeu.\n6)Quitter ce jeu.\n>");
    scanf("%d", &choix);
    switch (choix) {
        case 1:
            nbJ = nombreJoueur();
            Case* tabCase = initCases();
            Joueurs* tabJoueur = NULL;
            tabJoueur = initJoueur(nbJ);
            CartesCommunaute* tabCommu = NULL;
            CartesChance* tabChance = NULL;
            tabCommu = initCarteCommunaute();
            tabChance = initCarteChance();
            melangerCartesChance(tabChance);
            melangerCartesCommunaute(tabCommu);
            
            int jDebut = getRandomInteger1(nbJ);
            printf("La partie peut commencer, choisi avec le plus grand des hasard ! %s lance les hostilites !\n\n",
                   tabJoueur[jDebut - 1].nomJ);
            for (int i = 0; i < i + 1 ; i++) {
                int choixBis = 0;
                while (choixBis != 1){
                printf("\nC'est a %s de faire un choix ! Et plus vite que sa !\n", tabJoueur[((jDebut + i - 1) % nbJ)].nomJ);
                printf("Choisir parmi les options suivantes : \n 1/ Lancer les des.\n 2/ Voir le recapitulatif de vos possessions."
                       "\n 3/ Quitter la partie si vous etes un rageux. Attention elle se sera jamais sauvegardee. :)\n >");
                scanf("%d", &choixBis);



                switch (choixBis) {
                    case 1:


                        if (tabJoueur[i].nbJoueursVivant == 1) {
                            for (int k = 0; k < nbJ; k++) {
                                if (tabJoueur[k].faillite == 0) {
                                    printf("%s A GAGNE BRAVO !!!", tabJoueur[k].nomJ);
                                    return 0;
                                }
                            }
                        }


                        tabJoueur[(jDebut + i - 1) % nbJ].placement = jeuDes(&desUn, &desDeux,
                                                                             &tabJoueur[(jDebut + i - 1) % nbJ]);
                        tabJoueur[(jDebut + i - 1) % nbJ].placementSur32 = tabJoueur[(jDebut + i - 1) % nbJ].placement;
                        printf("Vous avez avance jusqu'a la %s.\n",
                               tabCase[(tabJoueur[(jDebut + i - 1) % nbJ].placement) - 1].nomPro);
                        if (tabJoueur[(jDebut + i - 1) % nbJ].placementSur32 > 32) {
                            tabJoueur[(jDebut + i - 1) % nbJ].placementSur32 = 0;
                            printf("Vous etes passez par la case depart , vous recevez 200 euros");
                            tabJoueur[(jDebut + i - 1) % nbJ].argent += 200;
                            tabJoueur[(jDebut + i - 1) % nbJ].fortune += 200;

                        }
                        typeCartes(&tabCase[tabJoueur[(jDebut + i - 1) % nbJ].placement - 1],
                                   &tabJoueur[(jDebut + i - 1) % nbJ],
                                   &tabJoueur[tabCase[tabJoueur[(jDebut + i - 1) % nbJ].placement].possibilite],
                                   tabChance, tabCommu, nbJ, tabJoueur);
                        int doooble = dooble(&desUn, &desDeux, &tabJoueur[(jDebut + i - 1) % nbJ] );
                        if (doooble == 1){

                            if (tabJoueur[i].nbJoueursVivant == 1) {
                                for (int k = 0; k < nbJ; k++) {
                                    if (tabJoueur[k].faillite == 0) {
                                        printf("%s A GAGNE BRAVO !!!", tabJoueur[k].nomJ);
                                        return 0;
                                    }
                                }
                            }


                            tabJoueur[(jDebut + i - 1) % nbJ].placement = jeuDes(&desUn, &desDeux,
                                                                                 &tabJoueur[(jDebut + i - 1) % nbJ]);
                            tabJoueur[(jDebut + i - 1) % nbJ].placementSur32 = tabJoueur[(jDebut + i - 1) % nbJ].placement;
                            printf("Vous avez avance jusqu'a la %s.\n",
                                   tabCase[(tabJoueur[(jDebut + i - 1) % nbJ].placement) - 1].nomPro);
                            if (tabJoueur[(jDebut + i - 1) % nbJ].placementSur32 > 32) {
                                tabJoueur[(jDebut + i - 1) % nbJ].placementSur32 = 0;
                                printf("Vous etes passez par la case depart , vous recevez 200 euros");
                                tabJoueur[(jDebut + i - 1) % nbJ].argent += 200;
                                tabJoueur[(jDebut + i - 1) % nbJ].fortune += 200;

                            }
                            typeCartes(&tabCase[tabJoueur[(jDebut + i - 1) % nbJ].placement - 1],
                                       &tabJoueur[(jDebut + i - 1) % nbJ],
                                       &tabJoueur[tabCase[tabJoueur[(jDebut + i - 1) % nbJ].placement].possibilite],
                                       tabChance, tabCommu, nbJ, tabJoueur);
                             doooble = dooble(&desUn, &desDeux, &tabJoueur[(jDebut + i - 1) % nbJ] );

                        }
                        if (doooble == 1){

                            if (tabJoueur[i].nbJoueursVivant == 1) {
                                for (int k = 0; k < nbJ; k++) {
                                    if (tabJoueur[k].faillite == 0) {
                                        printf("%s A GAGNE BRAVO !!!", tabJoueur[k].nomJ);
                                        return 0;
                                    }
                                }
                            }


                            tabJoueur[(jDebut + i - 1) % nbJ].placement = jeuDes(&desUn, &desDeux,
                                                                                 &tabJoueur[(jDebut + i - 1) % nbJ]);
                            tabJoueur[(jDebut + i - 1) % nbJ].placementSur32 = tabJoueur[(jDebut + i - 1) % nbJ].placement;
                            printf("Vous avez avance jusqu'a la %s.\n",
                                   tabCase[(tabJoueur[(jDebut + i - 1) % nbJ].placement) - 1].nomPro);
                            if (tabJoueur[(jDebut + i - 1) % nbJ].placementSur32 > 32) {
                                tabJoueur[(jDebut + i - 1) % nbJ].placementSur32 = 0;
                                printf("Vous etes passez par la case depart , vous recevez 200 euros");
                                tabJoueur[(jDebut + i - 1) % nbJ].argent += 200;
                                tabJoueur[(jDebut + i - 1) % nbJ].fortune += 200;

                            }
                            typeCartes(&tabCase[tabJoueur[(jDebut + i - 1) % nbJ].placement - 1],
                                       &tabJoueur[(jDebut + i - 1) % nbJ],
                                       &tabJoueur[tabCase[tabJoueur[(jDebut + i - 1) % nbJ].placement].possibilite],
                                       tabChance, tabCommu, nbJ, tabJoueur);
                            doooble = dooble(&desUn, &desDeux, &tabJoueur[(jDebut + i - 1) % nbJ] );


                        }
                        if (doooble == 1){
                            printf("\n ET Bah non !! EN fait s'il vous reste 0 double a faire, vous aller en prison jeune chenapans...\n Les regles sont pourtant afficher en debut de jeu !\n");
                        }

                        break;
                    case 2:
                        recapPossessionJoueur(tabJoueur[((jDebut + i - 1) % nbJ)], tabCase);
                        break;
                    case 3:
                        printf("Fin de partie , vous ne la retrouverez JAMAIS , c'est CIAO");
                        return 0;
                        break;

                    default:
                        printf("IL FAUT CHOISIR UN NUMERO ENTRE 1 ET 3 ESPECE DE TOCARD !\n");
                        break;


                }
                }
            }

            break;
        case 2:
            printf("Gros c'est mort j'ai pas le temps");
            break;
        case 3:
            printf("LOL je ne suis pas un chargeur !");
            break;
        case 4:
            printf("Les developpeurs de ce jeu sont:\n>Evan RHEILAC-AUPRETRE\n>Pierre ALLOUCHERIE\n>Jean-Marc COLLEGIA\n>Romain BOUCHER");
            break;
        case 5:
            printf(" RESUME EXPLICATIF :\n"
                   "\n"
                   "Ce jeu consiste a ACHETER, a LOUER ou a VENDRE diverses proprietes de facon si profitable que l’on puisse devenir le plus riche des joueurs et eventuellement, le GAGNANT\n"
                   "La premiere case est le point de départ, et l’on fait avancer les jetons sur le plateau de jeu d’apres le chiffre indiqué en lancant les des.\n"
                   "Si le jeton d’un joueur se place sur une case qui n’appartient encore a personne, le joueur pourra l’acheter de la BANQUE, sinon, cette case sera vendue au plus offrant et dernier enchérisseur.\n"
                   "Devenir proprietaire a pour OBJECTIF la perception de loyers des adversaires loges sur la case qui represente la propriete. Ces loyers sont fortement augmentes par la construction de maisons et d’hotels;\n"
                   "il sera donc judicieux d’en eriger sur ses terrains.\n"
                   "On pourra pour se procurer des fonds, hypothequer ces terrains en faveur de la banque, les cases « Caisse Commune » et « Chance » obligent le joueur a tirer une carte, dont les indications devront être observees.\n"
                   "les joueurs vont quelquefois en prison !\n"
                   "Somme toute, c’est un jeu amusant, plein de surprises, et ou l’on peut deployer son habilete.");
            break;
        case 6:
            return 0;
            break;
        default:
            break;

    }


    return 0;
}
