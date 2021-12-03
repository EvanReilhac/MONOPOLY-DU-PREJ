//evan version
#include "propriete.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fonctions.h"
#include "structure.h"
#include "MACRO.h"

Case initProp(int numero, int loyer, char* nom, int prix, int type, int donne, int nbMaison)
{
    Case p;
    strcpy(p.nomPro, nom);
    p.dispo = 1;
    p.valeurHypotheque = 0;
    p.type = type;
    p.numero = numero;
    p.loyer = loyer;
    p.prix = prix;
    p.nbMaison = nbMaison;
    return p;
}

Case initChgt(int numero, char* nom, int type, int newCase, int donne)
{
    Case p;
    strcpy(p.nomPro, nom);
    p.dispo = 1;
    p.valeurHypotheque = 0;
    p.type = type;
    p.numero = numero;
    p.newCase = newCase;
    p.donne = donne;
    return p;
}
//foot basket rugby boxe natation equitation tennis golf
void initCases()
{
    Case* tabCase =  calloc(NOMBRE_CASE , sizeof(Case)); // initialisation des cases
    tabCase[0] = initProp(1, 0, "Depart", 0, 3, 200, 0 );
    tabCase[1] = initProp(2, 60, "Maradona", 60, 0, 0, 0);
    tabCase[2] = initProp(3, 100, "Taxe", 0, 5, 0, 0);
    tabCase[3] = initProp(4, 80, "Zidane", 80, 0, 0, 0);
    tabCase[5] = initProp(6, 100, "Bryant", 100, 0, 0, 0);
    tabCase[6] = initProp(7, 0, "Communaute", 0, 2, 0, 0);
    tabCase[7] = initProp(8, 120, "Jordan", 120, 0, 0 , 0);
    tabCase[8] = initProp(9, 0, "Prison", 0, 4, 0, 0);
    tabCase[9] = initProp(10, 140, "Chabal", 140, 0, 0, 0);
    tabCase[10] = initProp(11, 100, "Impot", 0, 5, 0, 0);
    tabCase[11] = initProp(12, 160, "Lomu", 160, 0, 0, 0);
    tabCase[13]= initProp(14, 180, "Tyson", 180, 0, 0, 0);
    tabCase[14] = initProp(15, 0, "Chance", 0, 1, 0, 0);
    tabCase[15] = initProp(16, 200, "Ali", 200, 0, 0, 0);
    tabCase[16] = initProp(17, 0, "Libre", 0, 7, 0, 0);
    tabCase[17] =  initProp(18, 220, "Florent", 220, 0, 0, 0);
    tabCase[18] =  initProp(19, 100, "Taxe", 0, 5, 0, 0);
    tabCase[19] =  initProp(20, 240, "Laure", 240, 0, 0, 0);
    tabCase[21] =   initProp(22, 260, "Staut", 260, 0, 0, 0);
    tabCase[22] =   initProp(23, 0, "Communaute", 0, 2, 0, 0);
    tabCase[23] =   initProp(24, 280, "Leprevost", 280 ,0, 0, 0);
    tabCase[24] =  initProp(25, 0, "Prison", 0, 4, 0, 0);
    tabCase[25] =  initProp(26, 300, "Paire", 300, 0, 0, 0);
    tabCase[26] =  initProp(27, 0, "Trouver", 0, 5, 50, 0);
    tabCase[27] =  initProp(28, 320, "Agassi", 320, 0, 0, 0);
    tabCase[29] =  initProp(30, 350, "Bale", 350, 0, 0, 0);
    tabCase[30] =   initProp(31, 0, "Chance", 0, 1, 0, 0);
    tabCase[31] =   initProp(32, 400, "Woods", 400, 0, 0, 0);
    // initialisation des cases de saut
    tabCase[4] = initChgt(5, "ChgtTreize", 6, 13, 0);
    tabCase[12] = initChgt(13, "ChgtVingtDeux", 6, 22, 0);
    tabCase[20] = initChgt(21, "ChgtVingtNeuf", 6, 29, 0);
    tabCase[28] = initChgt(29, "ChgtCing", 6, 5, 200);

    printf("Les cases sont initialisees :\n");

    for ( int i = 0; i < 32; i++ ){
        printf("Case %d : %s\n", i+1 ,tabCase[i].nomPro );




    }

}

void initCaseChangement()
{
    initChgt(5, "ChgtTreize", 6, 13, 0);
    initChgt(13, "ChgtVingtDeux", 6, 22, 0);
    initChgt(21, "ChgtVingtNeuf", 6, 29, 0);
    initChgt(29, "ChgtCing", 6, 5, 200);
}