//
// Created by evanr on 06/12/2021.
//

#include "Cartes.h"

#define NB_CARTESCHANCE_MAX 10
#define NB_CARTESCOMMUNAUTE_MAX 10

#include "stdio.h"
#include "propriete.h"
#include "Deplacement.h"
#include "structure.h"
#include "stdlib.h"
#include "time.h"
#include "joueur.h"
#include "string.h"

int getRandomInteger1(int nbJoueurs) {
    int nombreAleatoire = (rand() % (nbJoueurs)) + 1;
    return nombreAleatoire;
}

void melangerCartesChance(CartesChance *paquet) {
    int k = 0;
    CartesChance enattente;
    for (int i = 0; i < NB_CARTESCHANCE_MAX; i++) {
        k = rand() % 9;
        enattente = paquet[i];
        paquet[i] = paquet[k];
        paquet[k] = enattente;
    }
}
// affiche la carte chance piochée

void afficherCarteChance(CartesChance *carte) {
    printf("Vous avez pioch%c : %s \n", 130, carte->nomCarte);
}

void tirageAuSortJoueurs(Joueurs *tabJoueurs, int nbJoueurs) {
    printf("C'est %c %s de jouer", 133, tabJoueurs[getRandomInteger1(nbJoueurs)].nomJ);
}

// affiche la carte chance piochée

void goPrison(Joueurs *joueur) //mettre a la carte chance et commu et double et case
{
    printf("Vous allez en prison car vous avez pris des dopants et cela s'est vu etant donne que vous avez fait le mararthon en 1h30 sans entrainement. \n");
    joueur->placement = 9;
}



// affiche ce qui est censé être écrit sur la carte chance et les conséquences de celle-ci.

void attributionCarteChance(int numero, Joueurs *j) {
    int a = 0; // Nombre de joueurs
    int nbM = 0; // Nombre de maison
    int nbH = 0; // Nombre d'hôtels
    switch (numero) {
        case 0 :
            printf("Vous vous etes fait plaqu%c par Chabal. Allez %c la case de d%cpart. (Collectez 200 euros pour les frais d'hopitaux)\n",
                   130, 133, 130);
            j->argent += 200;
            j->fortune += 200;
            break;
        case 1 :
            printf("Allez voir Zinedine Zidane. Collectez votre salaire si vous passez la case d%cpart\n", 130);
            // Si le joueur est après la case de Zidane et avant la case départ, il passe forcément
            //par la case départ. Il reçoit donc obligatoirement 200 euros.
            if (j->placement > 4 && j->placement <= 32) {
                j->argent += 200;
                j->fortune += 200;
            }
        case 2 :
            printf("Allez calmer Benoit Paire, il ne s'arrete pas d'insulter son adversaire. Collectez votre salaire si vous passez la case d%cpart\n",
                   130);
            // Même explication que pour celle de Zidane.
            if (j->placement > 26 && j->placement <= 32) {
                j->argent += 200;
                j->fortune += 200;
            }
            break;
        case 3 :
            printf("La banque vous paye 50 euros\n");
            // on ajoute 5O euros dans la structure argent et fortune.
            j->argent += 50;
            j->fortune += 50;
            break;
        case 4 :
            printf("Vous pouvez sortir de prison\n");
            // On dit que le joueur a une carte prison pour vérifier si le joueur
            // a bien la carte s'il veut l'utiliser.
            j->cartesPrison = 1;
            break;
        case 5 :
            printf("Vous avez eu peur de Mike Tyson, reculez de 3 cases\n");
            // Le joueur reucle de 3 cases. On enlève 3 au nombre de cases actuel.
            j->placement -= 3;
            printf("Vous reculez %c la case %d\n", 133, j->placement);
            break;
        case 6 :
            goPrison(j);
            break;
        case 7 :
            printf("Des portugais sont l%c pour faire des r%cparations sur vos propri%ct%cs :"
                   " Payez 25 euros/maison et 100 euros/hotel\n",
                   133, 130, 130, 130);
            nbM = j->nbMaisonsJ;
            nbH = j->nbHotelsJ;
            j->argent -= 25 * nbM + 100 * nbH;
            j->fortune -= 25 * nbM + 100 * nbH;
            break;
        case 8 :
            printf("F%clicitations, vous etes corrompu, vous avez %ct%c %clu maire !"
                   " Payez 50 euros %c chaque joueur pour feter ceci.\n", 130, 130, 130, 130, 133);
            int a = nombreJoueur();
            j->argent -= 50 * a;
            j->fortune -= 50 * a;
            break;
        case 9 :
            printf("Exces de vitesse : payez 100 euros\n");
            j->argent -= 100;
            j->fortune -= 100;
            break;
        default:
            break;
    }
}


void attributionCarteCommunaute(int numero, Joueurs *j, int nombreJ) {
    int a = 0;
    switch (numero) {
        case 1 :
            printf("Apres avoir un peu trop bu, Maradona vous a confondu avec un ballon de foot,"
                   "vous volez direction la case depart (collectez 200 euros)\n");
            j->argent += 200;
            j->fortune += 200;
            break;
        case 2 :
            printf("Vous vous etes fait tacl%c par Khalid %c la cheville,"
                   "payez 50 euros pour les frais de docteur. \n", 130, 133);
            j->argent -= 50;
            j->fortune -= 50;
            break;
        case 3 :
            printf("Vous avez une carte permettant de sortir de prison.\n");
            j->cartesPrison = 1;
            break;
        case 4 :
            j->cartesPrison = 1;
            goPrison(j);
            break;
        case 5 :
            printf("Vous avez vendu un objet vol%c %c la Guilloti%cre,"
                   "recevez 30 euros. \n", 130, 133, 130);
            j->argent += 30;
            j->fortune += 30;
            break;
        case 6 :
            printf("C'est l'heure du racket ! tous les joueurs vous donnent 10 euros chacun. \n");
            a = nombreJ -1;
            j->argent += 10 * a;
            j->fortune += 10 * a;
            break;
        case 7 :
            printf("Votre business marche plutot bien, collectez 100 euros. \n");
            j->argent += 100;
            j->fortune += 100;
            break;
        case 8 :
            printf("Vous avez un kyste tr%cs d%crangeant,"
                   " payez 100 euros pour les frais d'h%cpital. \n", 138, 130, 147);
            j->argent -= 100;
            j->fortune -= 100;
            break;
        case 9 :
            printf("Vous avez gagn%c le concours de baby foot."
                   "Bravo ! Vous gagnez (que) 10 euros. \n", 130);
            j->argent += 100;
            j->fortune += 100;
            break;
        case 10 :
            printf("Vous %ctes vraiment bg. Recevez 100 euros. \n", 136);
            j->argent += 100;
            j->fortune += 100;
            break;
        default:
            break;
    }
}

void melangerCartesCommunaute(CartesCommunaute *paquet) {
    int k = 0, enattente = 0;
    for (int i = 0; i < NB_CARTESCOMMUNAUTE_MAX; i++) {
        k = rand() % 9;
        enattente = paquet[i].numero;
        paquet[i].numero = paquet[k].numero;
        paquet[k].numero = enattente;
    }
}

void afficherLesCartesCommunaute(CartesCommunaute *tabCartes) {
    printf("Voici les cartes communaut%c : \n", 130);
    for (int i = 0; i < NB_CARTESCOMMUNAUTE_MAX; i++) {
        printf("%s", tabCartes[i].nomCarte);
    }
}

CartesChance creerChance(int numero, char* nom, int prixAPayer, int prixARecevoir)
{
    CartesChance carteChance;
    carteChance.numero = numero;
    carteChance.prixAPayer = prixAPayer;
    carteChance.prixARecevoir = prixARecevoir;
    strcpy(carteChance.nomCarte, nom);
    return carteChance;
}

CartesChance* initCarteChance()
{
    CartesChance* tabCarteChance =  calloc(NB_CARTE , sizeof(CartesChance));
    tabCarteChance[0] = creerChance(1, "AllezCaseDepart", 0, 200);
    tabCarteChance[1] = creerChance(2,"Zidane", 0, 0);
    tabCarteChance[2] = creerChance(3, "Paire", 0, 0);
    tabCarteChance[3] = creerChance(4, "BanqueKhalass", 0, 50);
    tabCarteChance[4] = creerChance(5, "CartePrison", 0, 0);
    tabCarteChance[5] = creerChance(6, "Reculez", 0, 0);
    tabCarteChance[6] = creerChance(7, "AllezPrison", 0, 0);
    tabCarteChance[7] = creerChance(8, "Reparations", 100, 0);
    tabCarteChance[8] = creerChance(9, "Maire", 50, 0);
    tabCarteChance[9] = creerChance(10, "ExcesDeVitesse", 100, 0);

    printf("Les cartes chance sont initialisees :\n");


    return tabCarteChance;
}


CartesCommunaute creerCommunaute(int numero, char* nom, int prixAPayer, int prixARecevoir)
{
    CartesCommunaute carteCommunaute;
    carteCommunaute.numero = numero;
    carteCommunaute.prixAPayer = prixAPayer;
    carteCommunaute.prixARecevoir = prixARecevoir;
    strcpy(carteCommunaute.nomCarte, nom);
    return carteCommunaute;
}

CartesCommunaute * initCarteCommunaute()
{
    CartesCommunaute * tabCarteCommunaute = (CartesCommunaute*) calloc(NB_CARTE , sizeof(CartesCommunaute));
    tabCarteCommunaute[0] = creerCommunaute(1, "AllezCaseDepart", 0, 200);
    tabCarteCommunaute[1] = creerCommunaute(2,"Docteur", 50, 0);
    tabCarteCommunaute[2] = creerCommunaute(3, "cartePrison", 0, 0);
    tabCarteCommunaute[3] = creerCommunaute(4, "AllezPrison", 0, 0);
    tabCarteCommunaute[4] = creerCommunaute(5, "VideGrenier", 0, 30);
    tabCarteCommunaute[5] = creerCommunaute(6, "Racket", 0, 0);
    tabCarteCommunaute[6] = creerCommunaute(7, "Rentes", 0, 100);
    tabCarteCommunaute[7] = creerCommunaute(8, "Hopital", 100, 0);
    tabCarteCommunaute[8] = creerCommunaute(9, "ConcoursBeaute", 0, 10);
    tabCarteCommunaute[9] = creerCommunaute(10, "Heritage", 0, 100);
    printf("Les cartes commu sont initialisees :\n");


    return tabCarteCommunaute;
}



// on affecte le loyer en fonction du nombre de maison. Je fais une fonction par nombre de maison
// Exemple : si numeroGroupe = 1 et emplacement = 2, on aura Zinedine Zidane*/