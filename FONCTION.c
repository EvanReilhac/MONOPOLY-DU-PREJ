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

void jeuDes(int* desUn, int* desDeux) {
    *desUn = getRandomInteger();
    *desDeux = getRandomInteger();
    printf("%d  %d", *desUn, *desDeux);
}

void dooble(int* desUn, int* desDeux){
    int choixDouble = 0;
    if (*desUn == *desDeux){
        for (int i = 1; i < NOMBRE_DOUBLE; i++){
            printf(" DOUBLE!!! Vous pouvez relancer.\n");
            printf("Appuyer sur 1 pour relancer, 0 si vous shouaiter quitter la partie:\n>");
            scanf("%d", &choixDouble);
            if (choixDouble == 1){
                jeuDes(desUn, desDeux);
            }
            else{
                printf("vous quittez la partie.");
            }

        }
        printf(" PAS DE CHANCE!!! Vous venez de faire 3 doubles de suite.\nDirection la prison...");
    }
    else{
        printf(" Joueur suivant");
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


Joueurs* creer(char* nom, int argent, int nbProprietes, int nbGroupes , int nbMaisons, int nbHotels, int cartesPrison, int faillite, int hypotheque) {
    Joueurs* p = (Joueurs*) malloc(sizeof(Joueurs));
    strcpy(p->nom, nom);
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


void tablJoueurs(Joueurs*** tabNom, int* taille, int* nbJoueurs, char* nom, int argent, int nbProprietes, int nbGroupes , int nbMaisons, int nbHotels, int cartesPrison, int faillite, int hypotheque) {
    while (*taille < *nbJoueurs) {
        if (*taille == 0) {
            *tabNom = malloc(sizeof(Joueurs*));
        }
        else {
            *tabNom = (Joueurs**) realloc(*tabNom, ((*taille) + 1) * sizeof(Joueurs*));
        }
        (*tabNom)[*taille] = creer(nom, argent, nbProprietes, nbGroupes, nbMaisons, nbHotels, cartesPrison, faillite,
                                   hypotheque);
        (*taille)++;
    }
}

void afficher(Joueurs* c) {
    printf("\"%s\", %d euros, %d proprietes, %d groupes, %d maisons, %d hotels, %d cartes prison, %d faillite, %d hypotheques.\n", c->nom, c->argent, c->nbProprietes, c->nbGroupes, c->nbMaisons, c->nbHotels, c->cartesPrison, c->faillite, c->hypotheque);
}

void afficherTous(Joueurs** tablNom, int taille) {
    int i = 0;
    for (i = 0; i < taille; i++) {
        afficher((tablNom[i]));
    }
}

void achatRue(char* nom, int* dispo, int loyer, int hypotheque, int argent){
    Rue* p;
    Joueurs* pAcheteur;
    Joueurs* pProprio;
    if (p.dispo == 0){
        if (p.hypotheque == 0){
            printf("La rue %s n'est pas disponible à l'achat.", p.nom);
        }
        else {
            printf("La rue %s n'est pas disponible à l'achat, merci de bien vouloir payé %d", p.nom, p.loyer);
            pAcheteur.argent = pAcheteur.argent - p.loyer;
            pProprio.argent = pProprio->argent + p.loyer;
        }

    }
    else {
        printf("La rue %s est disponible à l'achat, pour l'acheter taper 1 sinon taper 0:\n>", p.nom);
        scanf("%d", &p.dispo);
        pAcheteur.argent = pAcheteur.argent

    }




}