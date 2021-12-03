#include <stdio.h>
#include "propriete.h"
#include "joueur.h"
int main() {
    initCases();
    int nb = nombreJoueur();
    initJoueur(nb);


    return 0;
}
