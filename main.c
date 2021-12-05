#include <stdio.h>
#include "propriete.h"
#include "joueur.h"
#include "fonctions.h"
int main() {
    Case* tabCase = initCases();

    int nb = nombreJoueur();
    Joueurs * tabJoueur = NULL;
    tabJoueur = initJoueur(nb);
    tabJoueur[0].possessionParCase[1] = 0;
    tabJoueur[0].possessionParCase[3] = -1;
    tabJoueur[0].possessionParCase[5] = -1;
    tabJoueur[0].possessionParCase[7] = 0;
    tabJoueur[0].possessionParCase[9] = 1;
    tabJoueur[0].possessionParCase[11] = 2;
    tabJoueur[0].possessionParCase[13] = 5;
    tabJoueur[0].possessionParCase[15] = 0;
    tabJoueur[0].possessionParCase[17] = 0;
    tabJoueur[1].possessionParCase[19] = 0;
    tabJoueur[1].possessionParCase[21] = 3;
    tabJoueur[1].possessionParCase[23] = 0;
    tabJoueur[1].possessionParCase[25] = 4;
    tabJoueur[1].possessionParCase[27] = 5;
    tabJoueur[1].possessionParCase[29] = 1;
    tabJoueur[1].possessionParCase[31] = 1;
    groupePossedeJoueur(tabJoueur[0],tabCase);
    groupePossedeJoueur(tabJoueur[1], tabCase);
    for (int i = 0 ; i < nb ; i++){
        printf(" affichage relation par case de %s : ", tabJoueur[i].nomJ);
        for ( int j = 0 ; j < NOMBRE_CASE ; j++){
            printf("%d \t ", tabJoueur[i].possessionParCase[j]);
            printf("/");
        }
    }






    return 0;
}
