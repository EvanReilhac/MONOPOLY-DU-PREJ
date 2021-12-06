// evan version
#include "stdio.h"
#include "fonctions.h"
#include "structure.h"
#include "MACRO.h"
#include "string.h"
#include "propriete.h"


//player.possessionParCase[i + 3] != '\0'
void recapPossessionJoueur(Joueurs player, Case *tabCase) {
    if (player.faillite == 1) {
        printf("%s a s'est fait la tragique blessure des ligaments croiser , sa partie dans le pantheon des legendes du sport est termine",
               player.nomJ);
    } else {

        printf("\nVoici le recapitulatif du joueur %d :\n ", player.numeroJ);
        printf("%s , le fin stratege , se trouve a l'emplacement numero %d du plateau, il peut compter sur une fortune estimee a %d euros,"
               " son argent lui s'eleve a la modique somme de %d euros. \n Il possede %d legende(s), avec %d discipline(s) entiere(s) dont %d hypotheque(s).\n",
               player.nomJ, player.placement, player.fortune, player.argent, player.nbProprietes, player.nbGroupes,
               player.nbHypotheque);
        if (player.cartesPrison == 1) {
            printf("Il possede la carte sortie de prison a ne pas oublier !");
        }
        if (player.nbProprietes > 0) {
            printf("Voici maintenant le recap de ses proprietes :\n");

            for (int i = 1; i < NOMBRE_CASE; i = i + 4) {


                switch (player.possessionParCase[i]) {
                    case -1:
                        printf("\n Il fait le mariol mais %s a %s en hypotheque", player.nomJ, tabCase[i].nomPro);
                        if (tabCase[i].nomGroupe[0] == (tabCase[i + 2]).nomGroupe[0]) {
                            switch (player.possessionParCase[i + 2]) {
                                case 0:
                                    printf(" et possede egalement %s donc le groupe %s dont l'une des propriete est en hypotheque\n",
                                           (tabCase[i + 2]).nomPro, (tabCase[i + 2]).nomGroupe);
                                    break;
                                case -1:
                                    printf(" et possede egalement %s en hypotheque donc son groupe %s est en hypotheque\n",
                                           (tabCase[i + 2]).nomPro, (tabCase[i + 2]).nomGroupe);
                                    break;
                            }
                        }

                        break;
                    case 0:
                        printf("\n%s possede %s qui est vierge", player.nomJ, (tabCase[i]).nomPro);
                        if ((tabCase[i]).nomGroupe[0] == (tabCase[i + 2]).nomGroupe[0]) {
                            switch (player.possessionParCase[i + 2]) {
                                case -1:
                                    printf(" et %s en hypotheque donc le groupe %s \n", (tabCase[i + 2]).nomPro,
                                           (tabCase[i + 2]).nomGroupe);
                                    break;
                                case 0:
                                    printf(" et %s vierge aussi donc le groupe %s\n", (tabCase[i + 2]).nomPro,
                                           (tabCase[i + 2]).nomGroupe);
                                    break;
                                case 1:
                                    printf(" et %s avec 1 maison donc le groupe %s\n", (tabCase[i + 2]).nomPro,
                                           (tabCase[i + 2]).nomGroupe);
                                    break;
                                case 2:
                                    printf(" et %s avec 2 maisons donc le groupe %s\n", (tabCase[i + 2]).nomPro,
                                           (tabCase[i + 2]).nomGroupe);
                                    break;
                                case 3 :
                                    printf(" et %s avec 3 maisons donc le groupe %s\n", (tabCase[i + 2]).nomPro,
                                           (tabCase[i + 2]).nomGroupe);
                                    break;
                                case 4:
                                    printf(" et %s avec 4 maisons donc le groupe %s\n", (tabCase[i + 2]).nomPro,
                                           (tabCase[i + 2]).nomGroupe);
                                    break;
                                case 5:
                                    printf(" et %s avec 1 hotel donc le groupe %s\n", (tabCase[i + 2]).nomPro,
                                           (tabCase[i + 2]).nomGroupe);
                                    break;
                            }

                        }
                        break;
                    case 1:
                        printf("\n%s possede %s avec 1 maison donc le groupe %s", player.nomJ, (tabCase[i]).nomPro,
                               (tabCase[i + 2]).nomGroupe);
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
                    case 2:
                        printf("\n%s possede %s avec 2 maison donc le groupe %s", player.nomJ, (tabCase[i]).nomPro,
                               (tabCase[i + 2]).nomGroupe);
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
                    case 3:
                        printf("\n%s possede %s avec 3 maisons donc le groupe %s", player.nomJ, (tabCase[i]).nomPro,
                               (tabCase[i + 2]).nomGroupe);
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
                        printf("\n%s possede %s avec 4 maisons donc le groupe %s", player.nomJ, (tabCase[i]).nomPro,
                               (tabCase[i + 2]).nomGroupe);
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
                        printf("\n%s possede %s avec 1 hotel donc le groupe %s", player.nomJ, (tabCase[i]).nomPro,
                               (tabCase[i + 2]).nomGroupe);
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
                                switch (player.possessionParCase[i + 2]) {
                                    case -1:
                                        printf("\n%s a %s en hypotheque\n", player.nomJ, tabCase[i + 2].nomPro);
                                        break;
                                    case 0:
                                        printf("\n%s possssssede %s qui est vierge\n", player.nomJ,
                                               tabCase[i + 2].nomPro);
                                        break;
                                }

                        }
                        break;
                }


            }
        }
    }

}
void afficherplateau() {

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


}
