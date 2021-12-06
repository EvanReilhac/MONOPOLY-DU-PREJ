#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Fonctions.h"
#include "Structures.h"
#include "Macro.h"

void fonctionHypoteque(Case* prop, Joueurs* pAcheteur, int prix) {
    int choix = 1;
    int choixBis = 1;
    int choixBisBis = 0;
    printf("Aie aie aie, sa sent le sapin. Vous devez hypothequer.\n");
    while (pAcheteur->argent < prix) {
        printf("Vous avez différent choix qui s'offre a vous:\n1)Vendre une maison.\n 2)Vendre un hotel.\n3)Hypothequer une propriete.\n>");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                for (int i = 0; i < NOMBRE_CASE; i++) {
                    if (pAcheteur->possessionParCase[i] > 0 && pAcheteur->possessionParCase[i] <= 4) {
                        printf("Voulez vous vendre une maison de la case %d?\n", prop->numero);
                        printf("Si oui tapez 1 sinon tapez 0:\n>");
                        scanf("%d", &choixBis);
                        if (choixBis == 1) {
                            printf("Vous vendez cette maison ce qui vous rapporte une coquette somme de %d",
                                   prop->prixMaison / 2);
                            pAcheteur->argent += prop->prixMaison / 2;
                            pAcheteur->fortune += prop->prixMaison / 2;
                            pAcheteur->nbMaisonsJ += -1;
                            pAcheteur->possessionParCase[prop->numero] += -1;

                        }
                    }
                    else{
                        printf("Vous n'avez pas de maison...\n");
                    }
                }
                break;
            case 2:
                for (int i = 0; i < NOMBRE_CASE; i++) {
                    if (pAcheteur->possessionParCase[i] == 5) {
                        printf("Voulez vous vendre un hotel de la case %d?\n", prop->numero);
                        printf("Si oui tapez 1 sinon tapez 0:\n>");
                        scanf("%d", &choixBis);
                        if (choixBis == 1) {
                            printf("Vous vendez cet hotel ce qui vous rapporte une coquette somme de %d",
                                   prop->prixMaison / 2);
                            pAcheteur->argent += prop->prixMaison / 2;
                            pAcheteur->fortune += prop->prixMaison / 2;
                            pAcheteur->nbMaisonsJ += -1;
                            pAcheteur->possessionParCase[prop->numero] += -1;

                        }
                    }
                }
                break;
            case 3:
                for (int i = 0; i < NOMBRE_CASE; i++) {
                    if (pAcheteur->possessionParCase[i] == 0) {
                        printf("Voulez vous hypothequer la case %d?", prop->numero);
                        printf("Si oui tapez 1, sinon tapez 0");
                        scanf("%d", &choixBisBis);
                        if (choixBisBis == 1) {
                            printf("Vous hypotequer cette propriete ce qui vous rapporte une coquette somme de %d",
                                   prop->prix / 2);
                            pAcheteur->argent += prop->prix / 2;
                            pAcheteur->fortune += prop->prix / 2;
                            pAcheteur->possessionParCase[prop->numero] += -1;
                            prop->hypotheque = 1;

                        }
                    }
                }
                break;

            default:
                printf("Votre QI est deficient...Veuillez taper une valeur entre 1 et 3");

        }

    }
}