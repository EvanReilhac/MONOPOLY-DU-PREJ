#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Fonctions.h"
#include "Structures.h"

Case* initProp(int numero, int loyer, char* nom, int prix, int type, int donne, int nbMaison)
{
    Case* p;
    strcpy(p->nom, nom);
    p->dispo = 1;
    p->hypotheque = 0;
    p->type = type;
    p->numero = numero;
    p->loyer = loyer;
    p->prix = prix;
    p->nbMaison = nbMaison;
    return p;
}

Case* initChgt(int numero, char* nom, int type, int newCase, int donne)
{
    Case* p;
    strcpy(p->nom, nom);
    p->dispo = 1;
    p->hypotheque = 0;
    p->type = type;
    p->numero = numero;
    p->newCase = newCase;
    p->donne = donne;
}

void initCases()
{
    initProp(1, 0, "Depart", 0, 3, 200, 0 );
    initProp(2, 60, "Maradona", 60, 0, 0, 0);
    initProp(3, 100, "Taxe", 0, 5, 0, 0);
    initProp(4, 80, "Zidane", 80, 0, 0, 0);
    initProp(6, 100, "Bryant", 100, 0, 0, 0);
    initProp(7, 0, "Communaute", 0, 2, 0, 0);
    initProp(8, 120, "Jordan", 120, 0, 0 , 0);
    initProp(9, 0, "Prison", 0, 4, 0, 0);
    initProp(10, 140, "Chabal", 140, 0, 0, 0);
    initProp(11, 100, "Impot", 0, 5, 0, 0);
    initProp(12, 160, "Lomu", 160, 0, 0, 0);
    initProp(14, 180, "Tyson", 180, 0, 0, 0);
    initProp(15, 0, "Chance", 0, 1, 0, 0);
    initProp(16, 200, "Ali", 200, 0, 0, 0);
    initProp(17, 0, "Libre", 0, 7, 0, 0);
    initProp(18, 220, "Florent", 220, 0, 0, 0);
    initProp(19, 100, "Taxe", 0, 5, 0, 0);
    initProp(20, 240, "Laure", 240, 0, 0, 0);
    initProp(22, 260, "Staut", 260, 0, 0, 0);
    initProp(23, 0, "Communaute", 0, 2, 0, 0);
    initProp(24, 280, "Leprevost", 280 ,0, 0, 0);
    initProp(25, 0, "Prison", 0, 4, 0, 0);
    initProp(26, 300, "Paire", 300, 0, 0, 0);
    initProp(27, 0, "Trouver", 0, 5, 50, 0);
    initProp(28, 320, "Agassi", 320, 0, 0, 0);
    initProp(30, 350, "Bale", 350, 0, 0, 0);
    initProp(31, 0, "Chance", 0, 1, 0, 0);
    initProp(32, 400, "Woods", 400, 0, 0, 0);
}

void initCaseChangement()
{
    initChgt(5, "ChgtTreize", 6, 13, 0);
    initChgt(13, "ChgtVingtDeux", 6, 22, 0);
    initChgt(21, "ChgtVingtNeuf", 6, 29, 0);
    initChgt(29, "ChgtCing", 6, 5, 200);
}
