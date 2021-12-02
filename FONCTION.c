#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fonction.h"
#include "STRUCTURE.h"
#include "MACRO.h"




#include "FONCTION.h"


int getRandomInteger() {

    int nombrealeatoire = (rand() % (MAX - MIN + 1)) + MIN;
    return nombrealeatoire;
}

int jeuDes(int* desUn, int* desDeux) {
    *desUn = getRandomInteger();
    *desDeux = getRandomInteger();
    printf("%d  %d\n", *desUn, *desDeux);
    return (*desUn + *desDeux);

}

int dooble(int* desUn, int* desDeux){
    int choixDouble = 0;
    int b = 0;
    if (*desUn == *desDeux){
        for (int i = 1; i < NOMBRE_DOUBLE; i++){
            printf(" \nDOUBLE!!! Vous pouvez relancer.\n");
            printf("Appuyer sur 1 pour relancer, 0 si vous shouaiter quitter la partie:\n>");
            scanf("%d", &choixDouble);
            if (choixDouble == 1){
                b = jeuDes(desUn, desDeux);
                printf("Le total est de %d.", b);
                return (*desUn + *desDeux);

            }
            else{
                printf("vous quittez la partie.");
            }

        }
        printf(" PAS DE CHANCE!!! Vous venez de faire 3 doubles de suite.\nDirection la prison...");
    }
    else{
        printf(" Joueur suivant");
        return 0;
    }
}

int nombreJoueur() {
    int nbJoueurs = 0;
    while ((nbJoueurs < 2) || (nbJoueurs > 6)) {
        printf("Bonjour a tous, bienvenue dans le monopoly des LEGENDES DU SPORT.\nVeuillez saisir le nombre de participant:\n>");
        scanf("%d", &nbJoueurs);
        if (nbJoueurs < 2) {
            printf("Vous ne pouvez pas jouer tout seule... Allez chercher un amis!!\n");
        } else if (nbJoueurs > 6) {
            printf("Vous etes trop nombreux...Jouez seulement entre vrais amis. :)\n");

        }
    }
    return nbJoueurs;
}



/*Joueurs* saisirNoms(){
    //char motEnAttente[NOMBRE_MAX];
    Joueurs* p = (Joueurs*) malloc(sizeof(Joueurs));
    //char **tableau = (char **) calloc(nbJoueurs, sizeof(char *));
    //for (int i = 0; i < nbJoueurs; i++) {
    printf("Rentrez le nom du joueur %d:\n>");
    scanf("%s",p->nom);
    /*p->argent = 1500;
    p->nbPropriétés = 0;
    p->nbGroupes = 0;
    p->nbMaisons = 0;
    p->nbHotels = 0;
    p->cartesPrison = 0;
    p->faillite = 0;
    p->hypothèque = 0;
    //longueur = strlen(motEnAttente);
    //tableau[i] = (char *) calloc(longueur, sizeof(char));
    //strcpy(tableau[i], motEnAttente);

return p;
}*/


Joueurs* creer(char* nom, int placement, int argent, int nbProprietes, int nbGroupes , int nbMaisons, int nbHotels, int cartesPrison, int faillite, int hypotheque) {
    Joueurs* p = (Joueurs*) malloc(sizeof(Joueurs));
    strcpy(p->nom, nom);
    p->placement = placement;
    p->argent = argent;
    p->nbProprietes = nbProprietes;
    p->nbGroupes = nbGroupes;
    p->nbMaisons = nbMaisons;
    p->nbHotels = nbHotels;
    p->cartesPrison = cartesPrison;
    p->faillite = faillite;
    p->hypotheque = hypotheque;
    return p;
}



void tablJoueurs(Joueurs*** tabNom, int* taille, int* nbJoueurs, char* nom, int placement, int argent, int nbProprietes, int nbGroupes , int nbMaisons, int nbHotels, int cartesPrison, int faillite, int hypotheque) {
    while (*taille < *nbJoueurs) {
        if (*taille == 0) {
            *tabNom = malloc(sizeof(Joueurs*));
        }
        else {
            *tabNom = (Joueurs**) realloc(*tabNom, ((*taille) + 1) * sizeof(Joueurs*));
        }
        (*tabNom)[*taille] = creer(nom, placement, argent, nbProprietes, nbGroupes, nbMaisons, nbHotels, cartesPrison, faillite,
                                   hypotheque);
        (*taille)++;
    }
}

void afficher(Joueurs** c) {
    printf("\"%s\", case numero %d, %d euros, %d proprietes, %d groupes, %d maisons, %d hotels, %d cartes prison, %d faillite, %d hypotheques.\n", (*c)->nom, (*c)->argent, (*c)->nbProprietes, (*c)->nbGroupes, (*c)->nbMaisons, (*c)->nbHotels, (*c)->cartesPrison, (*c)->faillite, (*c)->hypotheque);
}

void afficherTous(Joueurs** tablNom, int taille) {
    int i = 0;
    for (i = 0; i < taille; i++) {
        afficher((tablNom[i]));
    }
}

void achatRue(Propriete* p, Joueurs* pAcheteur, Joueurs* pProprio){

    if (p->dispo == 0){
        if (p->hypotheque == 1){
            printf("La rue %s n'est pas disponible à l'achat.", p->nom);
        }
        else {
            printf("La rue %s n'est pas disponible à l'achat, merci de bien vouloir payé %d euros.", p->nom, p->loyer);
            pAcheteur->argent = pAcheteur->argent - p->loyer;
            pProprio->argent = pProprio->argent + p->loyer;
        }

    }
    else {
        printf("La rue %s est disponible à l'achat, pour l'acheter taper 0 sinon taper 1:\n>", p->nom);
        scanf("%d", &p->dispo);
        pAcheteur->argent = pAcheteur->argent - p->prix;


    }
}

Propriete* initProp(int numero, int loyer, char* nom, int prix, int type, int donne){
    Propriete* p;
    strcpy(p->nom, nom);
    p->dispo = 1;
    p->hypotheque = 0;
    p->type = type;
    p->numero = numero;
    p->loyer = loyer;
    p->prix = prix;
    return p;

}

int placement(int* placement, Joueurs* p){

    int choix = 0, a= 0;
    int desUn = 0, desDeux = 0;
    printf("veuillez choisir parmis les options suivantes:\n 1) Lancez votre des.\n 2) quittez la partie.\n>");
    scanf("%d", &choix);
    switch(choix){
        case 1:
            a =  jeuDes(&desUn, &desDeux);
            printf("Le total est de %d.", a);
            //pas oublié de mettre un truc
            dooble(&desUn, &desDeux);
            p->placement = p->placement + jeuDes(&desUn, &desDeux);
            p->placement = p->placement + dooble(&desUn, &desDeux);
            break;
        case 2:
            printf("Vous avez quitter la partie.");
    }
}

void caseDepart(Joueurs* p) {
    printf("YOUPI!!! Vous passez par la case depart, vous gagnez 200 euros.\n");
    p->argent = p->argent + 200;
}

void perteOuGainArgent(Joueurs* joueur)
{
    if(joueur->placement == 3)
    {
        printf("Vous payez une place de foot 100euros, vous allez au match, sauf que le match est annule car un joueur se prend une bouteille cristaline dans la tete et meurt soudainement.. Vous perdez 100euros. \n");
        joueur->argent -= 100;
    }
    else if (joueur->placement == 11)
    {
        printf("Vous cassez une voiture de golf en faisant une course contre votre grand pere qui lui est en deambulateur, vous gagnez la course mais perdez 100euros pour reparer la voiture de golf. \n");
        joueur->argent -= 100;
    }
    else if (joueur->argent == 19)
    {
        printf("Vous apercevez Mohamed Ali dans un reve qui vous dit de vous battre avec le prochain inconnu que vous croisez. Vous rencotrez Conor McGreggor et donc vous le chauffez pour vous battre avec. Sans surprise vous perdez et donc devez payer 200euros de chirurgie estethique. \n");
        joueur->argent -= 100;
    }
    else if(joueur->placement == 27)
    {
        printf("Etant donne que vous etes tres petit, vous vous faites passer pour votre petit frere de 10ans pour participer a sa place a un tournoi de badminton. Vous le remportez et donc gagnez 50euros. \n");
        joueur->argent += 50;
    }
}


void changement(Joueurs* p){
    if (p->placement == 5){
        printf("Attention!!!Un moroter de Teddy RINNER vous fait voler jusqu'a la case 13.\n");
        p->placement = 13;
    }
    else if (p->placement == 29){
        printf("Attention!!! Un uchimata de Teddy RINNER vous fait voler jusqu'a la case 5.\n");
        p->placement = 5;
    }
    else if (p->placement == 13){
        printf("Attention!!! Un arai de Teddy RINNER vous fait voler jusqu'a la case 22.\n");
        p->placement = 22
    }
    else if (p->placement == 22){
        printf("Attention!!! Un sasae de Teddy RINNER vous fait voler jusqu'a la case 29.\n");
        p->placement = 29;
    }

}


void typeCartes(int placement, Propriete* prop, Joueurs* p){
    prop->numero = p->placement;
    if (prop->type == 0){
        //fonction evan propr
    }
    else if (prop->type == 1){
        //fonction jm cartes chances
    }
    else if (prop->type == 2){
        //fonction jm cartes communauté
    }
    else if (prop->type == 3){
        caseDepart();
    }
    else if (prop->type == 4){
        printf("Visite guider de la cellule de d'Oscar Pistorius\n");
    }
    else if (prop->type == 5){

    }
    else if (prop->type == 6){
        changement();
    }


}



