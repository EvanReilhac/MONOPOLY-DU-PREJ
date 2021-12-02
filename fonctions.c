// evan version
#include "stdio.h"
#include "fonctions.h"
#include "structure.h"
#include "MACRO.h"
#include "string.h"
#include "propriete.h"




void groupePossedeJoueur(Joueurs* player , Case** tabCase) {
    for (int i = 0; player->possessionParCase[i + 3] != '\0'; i++) {
        switch (player->possessionParCase[i]) {
            case -1:
                printf("\n %s a %s en hypotheque  ", player->nomJ, (*tabCase[i]).nomPro);
                if ((*tabCase[i]).nomGroupe[0] == (*tabCase[i + 2]).nomGroupe[0]) {
                    switch (player->possessionParCase[i + 2]) {
                        case 0:
                            printf("\t et possede egalement %s donc le groupe %s dont l'une des propriete est en hypotheque \n",(*tabCase[i + 2]).nomPro, (*tabCase[i + 2]).nomGroupe);
                            break;
                        case -1:
                            printf("\t et possede egalement %s en hypotheque donc le groupe %s en hypotheque \n",(*tabCase[i + 2]).nomPro, (*tabCase[i + 2]).nomGroupe);
                    }
                }

                break;
            case 0:
                printf(" %s possede %s qui est vierge\n", player->nomJ, (*tabCase[i]).nomPro);
                if ((*tabCase[i]).nomGroupe[0] == (*tabCase[i + 2]).nomGroupe[0]){
                    switch (player->possessionParCase[i + 2]) {
                        case -1:
                            printf("\t et possede egalement %s en hypotheque donc le groupe %s dont l'une des propriete est en hypotheque \n",
                                   (*tabCase[i + 2]).nomPro, (*tabCase[i + 2]).nomGroupe);
                            break;
                        case 0:
                            printf("\t et possede %s vierge aussi donc le groupe %s ", (*tabCase[i + 2]).nomPro,
                                   (*tabCase[i + 2]).nomGroupe);
                            break;
                        case 1:
                            printf("et possede %s avec 1 maison donc le groupe %s", (*tabCase[i + 2]).nomPro,
                                   (*tabCase[i + 2]).nomGroupe);
                            break;
                        case 2:
                            printf("et possede %s avec 2 maisons donc le groupe %s", (*tabCase[i + 2]).nomPro,
                                   (*tabCase[i + 2]).nomGroupe);
                            break;
                        case 3 :
                            printf("et possede %s avec 3 maisons donc le groupe %s", (*tabCase[i + 2]).nomPro,
                                   (*tabCase[i + 2]).nomGroupe);
                            break;
                        case 4:
                            printf("et possede %s avec 4 maisons donc le groupe %s", (*tabCase[i + 2]).nomPro,
                                   (*tabCase[i + 2]).nomGroupe);
                            break;
                        case 5:
                            printf("et possede %s avec 1 hotel donc le groupe %s", (*tabCase[i + 2]).nomPro,
                                   (*tabCase[i + 2]).nomGroupe);
                            break;
                    }
                }
                    case 1:
                        printf(" %s possede %s avec 1 maison donc le groupe %s \n", player->nomJ, (*tabCase[i]).nomPro , (*tabCase[i + 2]).nomGroupe);
                    if ((*tabCase[i]).nomGroupe[0] == (*tabCase[i + 2]).nomGroupe[0]){
                        switch (player->possessionParCase[i + 2]) {
                            case 0:
                                printf("\t et possede %s vierge ", (*tabCase[i + 2]).nomPro);
                                break;
                            case 1:
                                printf("\tet possede %s avec 1 maison", (*tabCase[i + 2]).nomPro);
                                break;
                            case 2:
                                printf("\tet possede %s avec 2 maisons", (*tabCase[i + 2]).nomPro);
                                break;
                            case 3 :
                                printf("\tet possede %s avec 3 maisons", (*tabCase[i + 2]).nomPro);
                                break;
                            case 4:
                                printf("\tet possede %s avec 4 maisons", (*tabCase[i + 2]).nomPro);
                                break;
                            case 5:
                                printf("\tet possede %s avec 1 hotel", (*tabCase[i + 2]).nomPro);
                                break;

                        }
                }
                        case 2:
                            printf(" %s possede %s avec 2 maison donc le groupe %s \n", player->nomJ, (*tabCase[i]).nomPro , (*tabCase[i + 2]).nomGroupe);
                        if ((*tabCase[i]).nomGroupe[0] == (*tabCase[i + 2]).nomGroupe[0]){
                            switch (player->possessionParCase[i + 2]) {
                                case 0:
                                    printf("\t et possede %s vierge ", (*tabCase[i + 2]).nomPro);
                                    break;
                                case 1:
                                    printf("\tet possede %s avec 1 maison", (*tabCase[i + 2]).nomPro);
                                    break;
                                case 2:
                                    printf("\tet possede %s avec 2 maisons", (*tabCase[i + 2]).nomPro);
                                    break;
                                case 3 :
                                    printf("\tet possede %s avec 3 maisons", (*tabCase[i + 2]).nomPro);
                                    break;
                                case 4:
                                    printf("\tet possede %s avec 4 maisons", (*tabCase[i + 2]).nomPro);
                                    break;
                                case 5:
                                    printf("\tet possede %s avec 1 hotel", (*tabCase[i + 2]).nomPro);
                                    break;
                            }
                }
                            case 3:
                                printf(" %s possede %s avec 3 maisons donc le groupe %s \n", player->nomJ, (*tabCase[i]).nomPro , (*tabCase[i + 2]).nomGroupe);
                            if ((*tabCase[i]).nomGroupe[0] == (*tabCase[i + 2]).nomGroupe[0]) {
                                switch (player->possessionParCase[i + 2]) {
                                    case 0:
                                        printf("\t et possede %s vierge ", (*tabCase[i + 2]).nomPro);
                                        break;
                                    case 1:
                                        printf("\tet possede %s avec 1 maison", (*tabCase[i + 2]).nomPro);
                                        break;
                                    case 2:
                                        printf("\tet possede %s avec 2 maisons", (*tabCase[i + 2]).nomPro);
                                        break;
                                    case 3 :
                                        printf("\tet possede %s avec 3 maisons", (*tabCase[i + 2]).nomPro);
                                        break;
                                    case 4:
                                        printf("\tet possede %s avec 4 maisons", (*tabCase[i + 2]).nomPro);
                                        break;
                                    case 5:
                                        printf("\tet possede %s avec 1 hotel", (*tabCase[i + 2]).nomPro);
                                        break;
                                }
                            }
                                case 4:
                                    printf(" %s possede %s avec 4 maisons donc le groupe %s \n", player->nomJ, (*tabCase[i]).nomPro , (*tabCase[i + 2]).nomGroupe);
                                if ((*tabCase[i]).nomGroupe[0] == (*tabCase[i + 2]).nomGroupe[0]) {
                                    switch (player->possessionParCase[i + 2]) {
                                        case 0:
                                            printf("\t et possede %s vierge ", (*tabCase[i + 2]).nomPro);
                                            break;
                                        case 1:
                                            printf("\tet possede %s avec 1 maison", (*tabCase[i + 2]).nomPro);
                                            break;
                                        case 2:
                                            printf("\tet possede %s avec 2 maisons", (*tabCase[i + 2]).nomPro);
                                            break;
                                        case 3 :
                                            printf("\tet possede %s avec 3 maisons", (*tabCase[i + 2]).nomPro);
                                            break;
                                        case 4:
                                            printf("\tet possede %s avec 4 maisons", (*tabCase[i + 2]).nomPro);
                                            break;
                                        case 5:
                                            printf("\tet possede %s avec 1 hotel", (*tabCase[i + 2]).nomPro);
                                            break;
                                    }
                                }
                                    case 5:
                                        printf(" %s possede %s avec 1 hotel donc le groupe %s \n", player->nomJ,
                                               (*tabCase[i]).nomPro, (*tabCase[i + 2]).nomGroupe);
                                    if ((*tabCase[i]).nomGroupe[0] == (*tabCase[i + 2]).nomGroupe[0]) {
                                        switch (player->possessionParCase[i + 2]) {
                                            case 0:
                                                printf("\t et possede %s vierge ", (*tabCase[i + 2]).nomPro);
                                                break;
                                            case 1:
                                                printf("\tet possede %s avec 1 maison", (*tabCase[i + 2]).nomPro);
                                                break;
                                            case 2:
                                                printf("\tet possede %s avec 2 maisons", (*tabCase[i + 2]).nomPro);
                                                break;
                                            case 3 :
                                                printf("\tet possede %s avec 3 maisons", (*tabCase[i + 2]).nomPro);
                                                break;
                                            case 4:
                                                printf("\tet possede %s avec 4 maisons", (*tabCase[i + 2]).nomPro);
                                                break;
                                            case 5:
                                                printf("\tet possede %s avec 1 hotel", (*tabCase[i + 2]).nomPro);
                                                break;
                                        }
                                    }
                                }


    }

}