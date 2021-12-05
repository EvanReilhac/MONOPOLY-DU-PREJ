// evan version
#include "stdio.h"
#include "fonctions.h"
#include "structure.h"
#include "MACRO.h"
#include "string.h"
#include "propriete.h"



//player.possessionParCase[i + 3] != '\0'
void groupePossedeJoueur(Joueurs player , Case* tabCase) {
    for (int i = 1; i < NOMBRE_CASE ; i = i + 4 ) {

        switch (player.possessionParCase[i]) {
            case -1:
                printf("\n %s a %s en hypotheque", player.nomJ, tabCase[i].nomPro);
                if (tabCase[i].nomGroupe[0] == (tabCase[i + 2]).nomGroupe[0]) {
                    switch (player.possessionParCase[i + 2]) {
                        case 0:
                            printf(" et possede egalement %s donc le groupe %s dont l'une des propriete est en hypotheque\n",(tabCase[i + 2]).nomPro, (tabCase[i + 2]).nomGroupe);
                            break;
                        case -1:
                            printf(" et possede egalement %s en hypotheque donc le groupe %s en hypotheque\n",(tabCase[i + 2]).nomPro, (tabCase[i + 2]).nomGroupe);
                            break;
                    }
                }

                break;
            case 0:
                printf("\n%s possede %s qui est vierge", player.nomJ, (tabCase[i]).nomPro);
                if ((tabCase[i]).nomGroupe[0] == (tabCase[i + 2]).nomGroupe[0]){
                    switch (player.possessionParCase[i + 2]) {
                        case -1:
                            printf(" et %s en hypotheque donc le groupe %s \n",(tabCase[i + 2]).nomPro, (tabCase[i + 2]).nomGroupe);
                            break;
                        case 0:
                            printf(" et %s vierge aussi donc le groupe %s\n", (tabCase[i + 2]).nomPro,(tabCase[i + 2]).nomGroupe);
                            break;
                        case 1:
                            printf(" et %s avec 1 maison donc le groupe %s\n", (tabCase[i + 2]).nomPro,(tabCase[i + 2]).nomGroupe);
                            break;
                        case 2:
                            printf(" et %s avec 2 maisons donc le groupe %s\n", (tabCase[i + 2]).nomPro,(tabCase[i + 2]).nomGroupe);
                            break;
                        case 3 :
                            printf(" et %s avec 3 maisons donc le groupe %s\n", (tabCase[i + 2]).nomPro,(tabCase[i + 2]).nomGroupe);
                            break;
                        case 4:
                            printf(" et %s avec 4 maisons donc le groupe %s\n", (tabCase[i + 2]).nomPro,(tabCase[i + 2]).nomGroupe);
                            break;
                        case 5:
                            printf(" et %s avec 1 hotel donc le groupe %s\n", (tabCase[i + 2]).nomPro,(tabCase[i + 2]).nomGroupe);
                            break;
                    }

                }
                break;
                    case 1:
                        printf("\n%s possede %s avec 1 maison donc le groupe %s", player.nomJ, (tabCase[i]).nomPro , (tabCase[i + 2]).nomGroupe);
                    if ((tabCase[i]).nomGroupe[0] == (tabCase[i + 2]).nomGroupe[0]){
                        switch (player.possessionParCase[i + 2]) {
                            case 0:
                                printf(" avec %s vierge\n", (tabCase[i + 2]).nomPro);
                                break;
                            case 1:
                                printf(" dont %s avec 1 maison\n", (tabCase[i + 2]).nomPro);
                                break;
                            case 2:
                                printf(" dont %s avec 2 maisons\n", (tabCase[i + 2]).nomPro);
                                break;
                            case 3 :
                                printf(" dont %s avec 3 maisons\n", (tabCase[i + 2]).nomPro);
                                break;
                            case 4:
                                printf(" dont %s avec 4 maisons\n", (tabCase[i + 2]).nomPro);
                                break;
                            case 5:
                                printf(" dont %s avec 1 hotel\n", (tabCase[i + 2]).nomPro);
                                break;

                        }

                }
                break;
                        case 2:
                            printf("\n%s possede %s avec 2 maison donc le groupe %s", player.nomJ, (tabCase[i]).nomPro , (tabCase[i + 2]).nomGroupe);
                        if ((tabCase[i]).nomGroupe[0] == (tabCase[i + 2]).nomGroupe[0]){
                            switch (player.possessionParCase[i + 2]) {
                                case 0:
                                    printf(" avec %s vierge\n", (tabCase[i + 2]).nomPro);
                                    break;
                                case 1:
                                    printf(" dont %s avec 1 maison\n", (tabCase[i + 2]).nomPro);
                                    break;
                                case 2:
                                    printf(" dont %s avec 2 maisons\n", (tabCase[i + 2]).nomPro);
                                    break;
                                case 3 :
                                    printf(" dont %s avec 3 maisons\n", (tabCase[i + 2]).nomPro);
                                    break;
                                case 4:
                                    printf(" dont %s avec 4 maisons\n", (tabCase[i + 2]).nomPro);
                                    break;
                                case 5:
                                    printf(" dont %s avec 1 hotel\n", (tabCase[i + 2]).nomPro);
                                    break;
                            }

                }
                break;
                            case 3:
                                printf("\n%s possede %s avec 3 maisons donc le groupe %s", player.nomJ, (tabCase[i]).nomPro , (tabCase[i + 2]).nomGroupe);
                            if ((tabCase[i]).nomGroupe[0] == (tabCase[i + 2]).nomGroupe[0]) {
                                switch (player.possessionParCase[i + 2]) {
                                    case 0:
                                        printf(" avec %s vierge\n", (tabCase[i + 2]).nomPro);
                                        break;
                                    case 1:
                                        printf(" dont %s avec 1 maison\n", (tabCase[i + 2]).nomPro);
                                        break;
                                    case 2:
                                        printf(" dont %s avec 2 maisons\n", (tabCase[i + 2]).nomPro);
                                        break;
                                    case 3 :
                                        printf(" dont %s avec 3 maisons\n", (tabCase[i + 2]).nomPro);
                                        break;
                                    case 4:
                                        printf(" dont %s avec 4 maisons\n", (tabCase[i + 2]).nomPro);
                                        break;
                                    case 5:
                                        printf(" dont %s avec 1 hotel\n", (tabCase[i + 2]).nomPro);
                                        break;
                                }

                            }
                break;
                                case 4:
                                    printf("\n%s possede %s avec 4 maisons donc le groupe %s", player.nomJ, (tabCase[i]).nomPro , (tabCase[i + 2]).nomGroupe);
                                if ((tabCase[i]).nomGroupe[0] == (tabCase[i + 2]).nomGroupe[0]) {
                                    switch (player.possessionParCase[i + 2]) {
                                        case 0:
                                            printf(" avec %s vierge\n", (tabCase[i + 2]).nomPro);
                                            break;
                                        case 1:
                                            printf(" dont %s avec 1 maison\n", (tabCase[i + 2]).nomPro);
                                            break;
                                        case 2:
                                            printf(" dont %s avec 2 maisons", (tabCase[i + 2]).nomPro);
                                            break;
                                        case 3 :
                                            printf(" dont %s avec 3 maisons\n", (tabCase[i + 2]).nomPro);
                                            break;
                                        case 4:
                                            printf(" dont %s avec 4 maisons\n", (tabCase[i + 2]).nomPro);
                                            break;
                                        case 5:
                                            printf(" dont %s avec 1 hotel\n", (tabCase[i + 2]).nomPro);
                                            break;
                                    }

                                }
                break;
                                    case 5:
                                        printf("\n%s possede %s avec 1 hotel donc le groupe %s", player.nomJ,(tabCase[i]).nomPro, (tabCase[i + 2]).nomGroupe);
                                    if ((tabCase[i]).nomGroupe[0] == (tabCase[i + 2]).nomGroupe[0]) {
                                        switch (player.possessionParCase[i + 2]) {
                                            case 0:
                                                printf(" avec %s vierge\n", (tabCase[i + 2]).nomPro);
                                                break;
                                            case 1:
                                                printf(" dont %s avec 1 maison\n", (tabCase[i + 2]).nomPro);
                                                break;
                                            case 2:
                                                printf(" dont %s avec 2 maisons\n", (tabCase[i + 2]).nomPro);
                                                break;
                                            case 3 :
                                                printf(" dont %s avec 3 maisons\n", (tabCase[i + 2]).nomPro);
                                                break;
                                            case 4:
                                                printf(" dont %s avec 4 maisons\n", (tabCase[i + 2]).nomPro);
                                                break;
                                            case 5:
                                                printf(" dont %s avec 1 hotel\n", (tabCase[i + 2]).nomPro);
                                                break;
                                        }
                                        break;
                                        default:
                                            switch (player.possessionParCase[i + 2]){
                                                case -1:
                                                    printf("\n%s a %s en hypotheque\n",player.nomJ, tabCase[i+2].nomPro );
                                                    break;
                                                case 0:
                                                    printf("\n%s possssssede %s qui est vierge\n", player.nomJ, tabCase[i+2].nomPro);
                                                    break;
                                            }

                                    }
                break;
                                }


    }



        }


