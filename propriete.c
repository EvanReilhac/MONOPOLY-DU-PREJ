//evan version
#include "propriete.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fonctions.h"
#include "structure.h"
#include "MACRO.h"

Case initProp(int numero, int loyer, char* nom, int prix, int type, int donne, int valeurHypotheque, int prixMaison, char* nomGroupe , int possibilite, int hypoteque)
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
    tabCase[0] = initProp(1, 0, "case Depart", 0, 3, 200, 0, 0, "Depart", -1 , 0 );
    tabCase[1] = initProp(2, 60, "rue Maradona", 60, 0, 0, 30, 50 , "foot", 0 ,0);
    tabCase[2] = initProp(3, 100, "Taxe", 0, 5, 0, 0, 0, "Taxe", -1,0);
    tabCase[3] = initProp(4, 80, "rue Zidane", 80, 0,  0, 40 , 50 , "foot",0,0);
    tabCase[5] = initProp(6, 100, "rue Bryant", 100, 0, 0, 50, 60, "basket", 0,0);
    tabCase[6] = initProp(7, 0, "case Communaute", 0, 2, 0, 0, 0, "commu", -1,0);
    tabCase[7] = initProp(8, 120, "rue Jordan", 120, 0, 0 , 60, 60 , "basket",0,0);
    tabCase[8] = initProp(9, 0, "case Prison", 0, 4, 0, 0, 0,"prison", -1,0);
    tabCase[9] = initProp(10, 140, "rue Chabal", 140, 0, 0, 70 , 100, "rugby", 0 ,0);
    tabCase[10] = initProp(11, 100, "case Impot", 0, 5, 0,0, 0, "Taxe", -1,0);
    tabCase[11] = initProp(12, 160, "rue Lomu", 160, 0, 0, 80 , 100, "rugby", 0 ,0);
    tabCase[13]= initProp(14, 180, "rue Tyson", 180, 0, 0, 90 , 110 ,"boxe" , 0,0);
    tabCase[14] = initProp(15, 0, "case Chance", 0, 1, 0,0,0 , "chance" , -1,0);
    tabCase[15] = initProp(16, 200, "rue Ali", 200, 0, 0, 100, 110, "boxe", 0,0);
    tabCase[16] = initProp(17, 0, "case Libre", 0, 7, 0, 0, 0 , "libre", -1,0);
    tabCase[17] =  initProp(18, 220, "rue Florent", 220, 0, 0, 110, 130 , "natation", 0,0);
    tabCase[18] =  initProp(19, 100, "case Taxe", 0, 5, 0, 0, 0 , "taxe", -1,0);
    tabCase[19] =  initProp(20, 240, "rue Laure", 240, 0, 0, 120, 130 , "natation", 0,0);
    tabCase[21] =   initProp(22, 260, "rue Staut", 260, 0, 0, 130, 150 , "equitation", 0,0);
    tabCase[22] =   initProp(23, 0, "case Communaute", 0, 2, 0, 0, 0 , "commu", -1,0);
    tabCase[23] =   initProp(24, 280, "rue Leprevost", 280 ,0, 0, 140, 150 , "equitation", 0,0);
    tabCase[24] =  initProp(25, 0, "case aller en Prison", 0, 4, 0, 0, 0 , "prison", -1,0);
    tabCase[25] =  initProp(26, 300, "rue Paire", 300, 0, 0, 150, 170 , "tennis", 0,0);
    tabCase[26] =  initProp(27, 0, "case trouver 50 euros", 0, 5, 50,0, 0 , "trouver", -1,0);
    tabCase[27] =  initProp(28, 320, "rue Agassi", 320, 0, 0, 160, 170 , "tennis", 0,0);
    tabCase[29] =  initProp(30, 350, "rue Bale", 350, 0, 0, 175, 190 , "golf", 0,0);
    tabCase[30] =   initProp(31, 0, "case Chance", 0, 1, 0, 0, 0 , "chance", -1,0);
    tabCase[31] =   initProp(32, 400, "rue Woods", 400, 0, 0, 200, 190 , "golf", 0,0);
    // initialisation des cases de saut
    tabCase[4] = initChgt(5, "case raccourci Treize", 6, 13, 0);
    tabCase[12] = initChgt(13, "case raccourci Vingt-et-un", 6, 22, 0);
    tabCase[20] = initChgt(21, "case raccourci VingtNeuf", 6, 29, 0);
    tabCase[28] = initChgt(29, "case raccourci Cinq", 6, 5, 200);

    printf("Les cases sont initialisees :\n");
    return tabCase;

}

void fonctionHypotheque(Case* prop, Joueurs* pAcheteur, int prix , int nombreJoueur, Joueurs* tablJ) {


    int choix = 1;
    int choixBis = 1;
    int choixBisBis = 0;


    printf("Aie aie aie, ca sent le sapin. Vous devez hypothequer.\n");
    while (pAcheteur->argent < prix) {
        printf("Vous avez differents choix qui s'offrent a vous:\n1)Vendre une maison.\n 2)Vendre un hotel.\n3)Hypothequer une propriete.\n>");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                for (int i = 0; i < NOMBRE_CASE; i++) {
                    if (pAcheteur->possessionParCase[i] > 0 && pAcheteur->possessionParCase[i] <= 4) {
                        printf("Voulez vous vendre une maison de la case %d?\n", prop->numero);
                        printf("Si oui tapez 1 sinon tapez 0:\n>");
                        scanf("%d", &choixBis);
                        if (choixBis == 1) {
                            printf("Vous vendez cette maison ce qui vous rapporte une coquette somme de %d",
                                   prop->valeurHypotheque);
                            pAcheteur->argent += prop->valeurHypotheque;
                            pAcheteur->fortune += prop->valeurHypotheque;
                            pAcheteur->nbMaisonsJ += -1;
                            pAcheteur->possessionParCase[prop->numero] += -1;

                        }
                    }
                    else{
                        printf("Vous n'avez pas de maison...\n");

                    }
                }
                break;
            case 2:
                for (int i = 0; i < NOMBRE_CASE; i++) {
                    if (pAcheteur->possessionParCase[i] == 5) {
                        printf("Voulez vous vendre un hotel de la case %d?\n", prop->numero);
                        printf("Si oui tapez 1 sinon tapez 0:\n>");
                        scanf("%d", &choixBis);
                        if (choixBis == 1) {
                            printf("Vous vendez cet hotel ce qui vous rapporte une coquette somme de %d\n",
                                   prop->valeurHypotheque);
                            pAcheteur->argent += prop->valeurHypotheque;
                            pAcheteur->fortune += prop->valeurHypotheque;
                            pAcheteur->nbMaisonsJ -= 1;
                            pAcheteur->possessionParCase[prop->numero] -= 1;

                        }
                    }
                    else {
                        printf("Vous n'avez pas d'hotel... ( NOOB )\n");


                    }
                }
                break;
            case 3:
                for (int i = 0; i < NOMBRE_CASE; i++) {
                    if (pAcheteur->possessionParCase[i] == 0) {
                        printf("Voulez vous hypothequer la case %d?\n", prop->numero);
                        printf("Si oui tapez 1, sinon tapez 0 : \n >");
                        scanf("%d", &choixBisBis);
                        if (choixBisBis == 1) {
                            printf("Vous hypotequeZ cette propriete ce qui vous rapporte une coquette somme de %d\n",
                                   prop->prix / 2);
                            pAcheteur->argent += prop->valeurHypotheque;
                            pAcheteur->fortune += prop->valeurHypotheque;
                            pAcheteur->possessionParCase[prop->numero] -= 1;
                            prop->hypotheque = 1;
                            pAcheteur->nbHypotheque += 1;
                            int a  = pAcheteur->nbProprietes - pAcheteur->nbHypotheque;
                            if (a == 0 ){
                                printf("Aie aie ouille, la fete est finie , pliez bagage et partez tres loin, vous etes honteux %s !!!!!!!!! \n", pAcheteur->nomJ);
                                pAcheteur->faillite = 1;
                                for ( int j = 0; j < nombreJoueur ; j++ ){
                                    tablJ[j].nbJoueursVivant -= 1;
                                }
                            }

                        }
                    }

                }
                break;

            default:
                printf("Votre QI est deficient...Veuillez taper une valeur entre 1 et 3\n");

        }

    }
}



void prixLoyer(Case* prop, Joueurs* pAcheteur, Joueurs* pProprio, int nombreJoueur, Joueurs* tablJ){
    int choix = 0;
    if (pProprio->possessionParCase[prop->numero] == 0){
        printf("La rue %s n'est pas disponible à l'achat, merci de bien vouloir payer %d euros.", prop->nomPro,
               prop->loyer);
        if (pAcheteur->argent < prop->loyer){
            printf("Aie aie aie, sa sent le sapin. Voulez vous hypothequer une de vos proprietes? Si oui tapez 1 sinon tapez 0 et vous faites faillite\n");
            scanf("%d", &choix);
            if (choix == 1){
                fonctionHypotheque(prop , pAcheteur , 100 , nombreJoueur , tablJ);

            }

        }

        pAcheteur->argent = pAcheteur->argent - prop->loyer;
        pAcheteur->fortune = pAcheteur->fortune - prop->loyer;
        pProprio->argent = pProprio->argent + prop->loyer;
        pProprio->fortune = pProprio->fortune + prop->loyer;
    }
    else if (pProprio->possessionParCase[prop->numero] == 1){
        printf("La rue %s n'est pas disponible à l'achat, une maison a ete construite... merci de bien vouloir payé %d euros.", prop->nomPro,
               prop->loyer + prop->loyer/4);
        pAcheteur->argent = pAcheteur->argent - prop->loyer + prop->loyer/4;
        pAcheteur->fortune = pAcheteur->fortune - prop->loyer + prop->loyer/4;
        pProprio->argent = pProprio->argent + prop->loyer + prop->loyer/4;
        pProprio->fortune = pProprio->fortune + prop->loyer + prop->loyer/4;

    }
    else if (pProprio->possessionParCase[prop->numero] == 2){
        printf("La rue %s n'est pas disponible à l'achat, deux maisons ont ete construite... merci de bien vouloir payé %d euros.", prop->nomPro,
               prop->loyer + prop->loyer/2);
        pAcheteur->argent = pAcheteur->argent - prop->loyer + prop->loyer/2;
        pAcheteur->fortune = pAcheteur->fortune - prop->loyer + prop->loyer/2;
        pProprio->argent = pProprio->argent + prop->loyer + prop->loyer/2;
        pProprio->fortune = pProprio->fortune + prop->loyer + prop->loyer/2;
    }
    else if (pProprio->possessionParCase[prop->numero] == 3){
        printf("La rue %s n'est pas disponible à l'achat. Aie!! trois maisons ont ete construite... merci de bien vouloir payé %d euros.", prop->nomPro,
               prop->loyer + prop->loyer*3/4);
        pAcheteur->argent = pAcheteur->argent - prop->loyer + prop->loyer*3/4;
        pAcheteur->fortune = pAcheteur->fortune - prop->loyer + prop->loyer*3/4;
        pProprio->argent = pProprio->argent + prop->loyer + prop->loyer*3/4;
        pProprio->fortune = pProprio->fortune + prop->loyer + prop->loyer*3/4;

    }
    else if (pProprio->possessionParCase[prop->numero] == 4){
        printf("La rue %s n'est pas disponible à l'achat. Sa commence a piquer, quatres maisons ont ete construite... merci de bien vouloir payé %d euros.", prop->nomPro,
               prop->loyer + prop->loyer);
        pAcheteur->argent = pAcheteur->argent - prop->loyer + prop->loyer;
        pAcheteur->fortune = pAcheteur->fortune - prop->loyer + prop->loyer;
        pProprio->argent = pProprio->argent + prop->loyer + prop->loyer;
        pProprio->fortune = pProprio->fortune + prop->loyer + prop->loyer;
    }
    else if (pProprio->possessionParCase[prop->numero] == 5){
        printf("La rue %s n'est pas disponible à l'achat. Coup dur!!! un hotel a ete construit... merci de bien vouloir payé %d euros.", prop->nomPro,
               3*prop->loyer);
        pAcheteur->argent = pAcheteur->argent - 3*prop->loyer;
        pAcheteur->fortune = pAcheteur->fortune - 3*prop->loyer;
        pProprio->argent = pProprio->argent + 3*prop->loyer;
        pProprio->fortune = pProprio->fortune + 3*prop->loyer;

    }
}




