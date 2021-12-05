//evan version
#include "propriete.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fonctions.h"
#include "structure.h"
#include "MACRO.h"

Case initProp(int numero, int loyer, char* nom, int prix, int type, int donne, int valeurHypotheque, int prixMaison, char* nomGroupe , int possibilite)
{
    Case p;
    p.numero = numero;
    p.loyer = loyer;
    strcpy(p.nomPro, nom);
    p.prix = prix;
    p.type = type;
    p.nbMaison = 0;
    p.valeurHypotheque = valeurHypotheque;
    p.prixMaison = prixMaison;
    strcpy(p.nomGroupe, nomGroupe);
    p.possibilite = possibilite;
    return p;
}

Case initChgt(int numero, char* nom, int type, int newCase, int donne )
{
    Case p;
    strcpy(p.nomPro, nom);
    p.type = type;
    p.numero = numero;
    p.newCase = newCase;
    p.donne = donne;
    return p;
}
//foot basket rugby boxe natation equitation tennis golf
Case* initCases()
{
    Case* tabCase =  calloc(NOMBRE_CASE , sizeof(Case)); // initialisation des cases
    tabCase[0] = initProp(1, 0, "Depart", 0, 3, 200, 0, 0, "Depart", -1 );
    tabCase[1] = initProp(2, 60, "Maradona", 60, 0, 0, 30, 50 , "foot", 0 );
    tabCase[2] = initProp(3, 100, "Taxe", 0, 5, 0, 0, 0, "Taxe", -1);
    tabCase[3] = initProp(4, 80, "Zidane", 80, 0,  0, 40 , 50 , "foot",0);
    tabCase[5] = initProp(6, 100, "Bryant", 100, 0, 0, 50, 60, "basket", 0);
    tabCase[6] = initProp(7, 0, "Communaute", 0, 2, 0, 0, 0, "commu", -1);
    tabCase[7] = initProp(8, 120, "Jordan", 120, 0, 0 , 60, 60 , "basket",0);
    tabCase[8] = initProp(9, 0, "Prison", 0, 4, 0, 0, 0,"prison", -1);
    tabCase[9] = initProp(10, 140, "Chabal", 140, 0, 0, 70 , 100, "rugby", 0 );
    tabCase[10] = initProp(11, 100, "Impot", 0, 5, 0,0, 0, "Taxe", -1);
    tabCase[11] = initProp(12, 160, "Lomu", 160, 0, 0, 80 , 100, "rugby", 0 );
    tabCase[13]= initProp(14, 180, "Tyson", 180, 0, 0, 90 , 110 ,"boxe" , 0);
    tabCase[14] = initProp(15, 0, "Chance", 0, 1, 0,0,0 , "chance" , -1);
    tabCase[15] = initProp(16, 200, "Ali", 200, 0, 0, 100, 110, "boxe", 0);
    tabCase[16] = initProp(17, 0, "Libre", 0, 7, 0, 0, 0 , "libre", -1);
    tabCase[17] =  initProp(18, 220, "Florent", 220, 0, 0, 110, 130 , "natation", 0);
    tabCase[18] =  initProp(19, 100, "Taxe", 0, 5, 0, 0, 0 , "taxe", -1);
    tabCase[19] =  initProp(20, 240, "Laure", 240, 0, 0, 120, 130 , "natation", 0);
    tabCase[21] =   initProp(22, 260, "Staut", 260, 0, 0, 130, 150 , "equitation", 0);
    tabCase[22] =   initProp(23, 0, "Communaute", 0, 2, 0, 0, 0 , "commu", -1);
    tabCase[23] =   initProp(24, 280, "Leprevost", 280 ,0, 0, 140, 150 , "equitation", 0);
    tabCase[24] =  initProp(25, 0, "Prison", 0, 4, 0, 0, 0 , "prison", -1);
    tabCase[25] =  initProp(26, 300, "Paire", 300, 0, 0, 150, 170 , "tennis", 0);
    tabCase[26] =  initProp(27, 0, "Trouver", 0, 5, 50,0, 0 , "trouver", -1);
    tabCase[27] =  initProp(28, 320, "Agassi", 320, 0, 0, 160, 170 , "tennis", 0);
    tabCase[29] =  initProp(30, 350, "Bale", 350, 0, 0, 175, 190 , "golf", 0);
    tabCase[30] =   initProp(31, 0, "Chance", 0, 1, 0, 0, 0 , "chance", -1);
    tabCase[31] =   initProp(32, 400, "Woods", 400, 0, 0, 200, 190 , "golf", 0);
    // initialisation des cases de saut
    tabCase[4] = initChgt(5, "ChgtTreize", 6, 13, 0);
    tabCase[12] = initChgt(13, "ChgtVingtDeux", 6, 22, 0);
    tabCase[20] = initChgt(21, "ChgtVingtNeuf", 6, 29, 0);
    tabCase[28] = initChgt(29, "ChgtCing", 6, 5, 200);

    printf("Les cases sont initialisees :\n");

    for ( int i = 0; i < 32; i++ ){
        printf("Case %d : %s\n", i+1 ,tabCase[i].nomPro );

    }
    return tabCase;

}


