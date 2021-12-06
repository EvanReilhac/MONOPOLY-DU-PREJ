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
//Fonction qui permet de simuler un lancement de dés
int jeuDes(int* desUn, int* desDeux) {
    *desUn = getRandomInteger();
    *desDeux = getRandomInteger();
    printf("%d  %d\n", *desUn, *desDeux);
    return (*desUn + *desDeux);

}

//
void dooble(int* desUn, int* desDeux, int* total) {
    int choixDouble = 0;
    if (*desUn == *desDeux) {
        //printf("le total est de %d", *desUn + *desDeux);
        //for (int i = 1; i < NOMBRE_DOUBLE; i++) {
        printf(" \nDOUBLE!!! Vous pouvez relancer.\n");
        printf("Appuyer sur 1 pour relancer:\n>");
        scanf("%d", &choixDouble);
        if (choixDouble == 1) {
            *total = jeuDes(desUn, desDeux);
            printf("Le total est de %d.", *total);
            if (*desUn == *desDeux) {
                printf(" \nDOUBLE!!! Vous pouvez relancer.\n");
                printf("Appuyer sur 1 pour relancer:\n>");
                scanf("%d", &choixDouble);
                if (choixDouble == 1) {
                    *total = jeuDes(desUn, desDeux);
                    if (*desUn == *desDeux){
                        printf("PAS DE CHANCE!!! Vous venez de faire 3 doubles de suite.\nDirection la prison...");
                }
                    }
                }

            }


    } else {

        *total = 0;
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


/*Joueurs* creer(char* nom, int placement, int argent, int nbProprietes, int nbGroupes , int nbMaisons, int nbHotels, int cartesPrison, int faillite, int hypotheque) {
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

void afficher(Joueurs* c) {
    printf("\"%s\", case numero %d, %d euros, %d proprietes, %d groupes, %d maisons, %d hotels, %d cartes prison, %d faillite, %d hypotheques.\n", c->nom, c->argent, c->nbProprietes, c->nbGroupes, c->nbMaisons, c->nbHotels, c->cartesPrison, c->faillite, c->hypotheque);
}

void afficherTous(Joueurs** tablNom, int taille) {
    int i = 0;
    for (i = 0; i < taille; i++) {
        afficher((tablNom[i]));
    }
}*/

void achatRue(Case* prop, Joueurs* pAcheteur, Joueurs* pProprio){

    if (pAcheteur->possessionParCase[prop->numero-1] == - 2){
        if (prop->hypotheque == 1){
            printf("La rue %s n'est pas disponible a l'achat.", prop->nomPro);
        }
        else if (prop->dispo == 0) {
            prixLoyer(prop, pAcheteur, pProprio);
        }
        else if (prop->dispo == 1){
            if (pAcheteur->argent < prop->prix){
                printf("Vous etes pauvres...Enrichissez vous pour esperer aquerir de tel biens.\n");
            }
            else {
                printf("La rue %s est disponible a l'achat, pour l'acheter taper 0 sinon taper 1:\n>", prop->nomPro);
                scanf("%d", &prop->dispo);
                if (prop->dispo == 0) {
                    pAcheteur->possessionParCase[prop->numero] = 0;
                    pAcheteur->nbProprietes = pAcheteur->nbProprietes +1;
                    pAcheteur->possessionParGroupe[prop->numeroGroupes] += 1;
                    pAcheteur->argent = pAcheteur->argent - prop->prix;
                    pAcheteur->fortune = pAcheteur->fortune - prop->prix / 2;
                }
                else if (pAcheteur->argent >= prop->prix) {
                    printf("Petit joueur!!! Vous risquez de vous en mordre les doigts...\n");
                }
            }
        }

    }
    else if  (pAcheteur->possessionParCase[prop->numero] == 0){
        printf("Vous etes chez vous...Que sa fait du bien de retrouver le parfum de la maison.\n");
        if (pAcheteur->possessionParGroupe[prop->numeroGroupes] == 2){
            achatMaison(prop, pAcheteur);
        }
    }
    else if (pAcheteur->possessionParCase[prop->numero] == -1) {
        printf("Malheuresement votre maison est hypothequer apres vos deboirs financiers...Esperer vous refaire la cerise pour pouvoir apporter des modifs a votre rue.\n");
    }
}



int placement( Joueurs* p){

    int choix = 0, a= 0;
    int desUn = 0, desDeux = 0;
    int total = 0;
    printf("veuillez choisir parmis les options suivantes:\n 1) Lancez votre des.\n 2) quittez la partie.\n>");
    scanf("%d", &choix);
    switch(choix){
        case 1:
            a = jeuDes(&desUn, &desDeux);
            printf("Le total est de %d.", a);
            dooble(&desUn, &desDeux, &total);
            p->placement = p->placement + a;
            printf("Déplacer vous à la case %d", p->placement);
            p->placement = p->placement + total;
            break;
        case 2:
            printf("Vous avez quitter la partie.");
            break;
        default:
            return 0;
    }


}

void caseDepart(Joueurs* p) {
    printf("YOUPI!!! Vous passez par la case depart, vous gagnez 200 euros.\n");
    p->argent = p->argent + 200;
    p->fortune = p->fortune +200;
}

void perteOuGainArgent(Joueurs* joueur, Case* tabCase)
{
    if(joueur->placement == 3)
    {
        printf("Vous payez une place de foot 100euros, vous allez au match, sauf que le match est annule car un joueur se prend une bouteille cristaline dans la tete et meurt soudainement.. Vous perdez 100euros. \n");
        if (joueur->argent < 100){
            fonctionHypoteque(&tabCase[18], joueur, 100);
        }
        else {
            joueur->argent -= 100;
            joueur->fortune -= 100;
        }
    }
    else if (joueur->placement == 11)
    {
        printf("Vous cassez une voiture de golf en faisant une course contre votre grand pere qui lui est en deambulateur, vous gagnez la course mais perdez 100euros pour reparer la voiture de golf. \n");
        if (joueur->argent < 100){
            fonctionHypoteque(&tabCase[18], joueur, 100);
        }
        else {
            joueur->argent -= 100;
            joueur->fortune -= 100;
        }

    }
    else if (joueur->argent == 19)
    {
        printf("Vous apercevez Mohamed Ali dans un reve qui vous dit de vous battre avec le prochain inconnu que vous croisez. Vous rencotrez Conor McGreggor et donc vous le chauffez pour vous battre avec. Sans surprise vous perdez et donc devez payer 200euros de chirurgie estethique. \n");
        if (joueur->argent < 100){
            fonctionHypoteque(&tabCase[18], joueur, 100);
        }
        else {
            joueur->argent -= 100;
            joueur->fortune -= 100;
        }


    }
    else if(joueur->placement == 27)
    {
        printf("Etant donne que vous etes tres petit, vous vous faites passer pour votre petit frere de 10ans pour participer a sa place a un tournoi de badminton. Vous le remportez et donc gagnez 50euros. \n");
        joueur->argent += 50;
        joueur->fortune +=50;
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
        p->placement = 22;
    }
    else if (p->placement == 22){
        printf("Attention!!! Un sasae de Teddy RINNER vous fait voler jusqu'a la case 29.\n");
        p->placement = 29;
    }

}

void melangerCartesChance(CartesChance* paquet) {
    int k = 0, enattente = 0;
    for(int i = 0; i < NB_CARTESCHANCE_MAX; i++) {
        srand(time(NULL));
        k = rand() % 9;
        enattente = paquet[i].numero;
        paquet[i].numero = paquet[k].numero;
        paquet[k].numero = enattente;
    }
}

// affiche la carte chance piochée

void afficherCarteChance(CartesChance* carte) {
    printf("Vous avez pioch%c : %s \n" , 130, carte->nomCarte);
}

// affiche ce qui est censé être écrit sur la carte chance et les conséquences de celle-ci.

/*void allezPrison(Joueurs* joueur)
{
    srand(time(NULL));
    int nbJoueur = nombreJoueur();
    int desUn = 0, desDeux = 0, tour = nbJoueur;
    int a = 0, total = 0;
    while (tour <= 3 * nbJoueur)
    {
        if(joueur->placement == 25)
        {
            printf("Vous faites une intrusion sur un terrain de foot pour prendre une photo avec Karim Benzema. Superrrr vous avez votre photo mais vous vous faites plaquer par la securite et malheureusement, ils vous emmenent en prison...\n");
            joueur->placement = 9;
        }
        else if(joueur->cartesAllezPrison == 1)
        {
            printf("Vous faites une intrusion sur un terrain de foot pour prendre une photo avec Karim Benzema. Superrrr vous avez votre photo mais vous vous faites plaquer par la securite et malheureusement, ils vous emmenent en prison...\n");
            joueur->placement = 9;
        }
        else if (joueur->nbDouble == 3)
        {
            joueur->placement = 9;
        }
        else if(joueur->cartesSortirPrison == 0)
        {
            sortirPrison(joueur);
        }
        tour = tour + nbJoueur;
    }
    printf("Deja 3 tours en prison ?? Gros coup de chance, Bruce Lee arrive vous sauver !! Mais vous lui devez 50 euros pour cette aide..  ");
    joueur->argent -= 50;
    joueur->argent-= 50;
    a = jeuDes(&desUn, &desDeux);
    printf("Le total est de %d.", a);
    dooble(&desUn, &desDeux, &total);
    joueur->placement = joueur->placement + a;
    printf("Déplacer vous à la case %d", joueur->placement);
    joueur->placement = joueur->placement + total;
}*/

/*void attributionCarteChance(int numero, Joueurs* j) {
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
            printf("La légende Zinedine Zidane vous veux dans son equipe. Vous signerer un contrat de 200 euros uniquement si vous passer par la case depart\n");
            // Si le joueur est après la case de Zidane et avant la case départ, il passe forcément
            //par la case départ. Il reçoit donc obligatoirement 200 euros.
            if(j->placement > 4 && j->placement <= 32) {
                j->argent += 200;
                j->fortune += 200;
            }
        case 2 :
            printf("Allez calmer Benoit Paire, il ne s'arrete pas d'insulter son adversaire. Recuperer sa prime de match si vous passez la case d%cpart\n", 130);
            // Même explication que pour celle de Zidane.
            if(j->placement > 26 && j->placement <= 32) {
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
            j->cartesSortirPrison = 1;
            break;
        case 5 :
            printf("Vous avez eu peur de Mike Tyson, reculez de 3 cases\n");
            // Le joueur reucle de 3 cases. On enlève 3 au nombre de cases actuel.
            j->placement -= 3;
            printf("Vous reculez %c la case %d\n", 133,j->placement);
            break;
        case 6 :
            allerPrison(j);
            break;
        case 7 :
            printf("Des portugais sont l%c pour faire des r%cparations sur vos propri%ct%cs :"
                   " Payez 25 euros/maison et 100 euros/hotel\n",
                   133, 130, 130, 130);
            int nbM = j->nbMaisonsJ;
            int nbH = j->nbHotelsJ;
            j->argent -= 25 * nbM + 100 * nbH;
            j->fortune -= 25 * nbM + 100 * nbH;
            break;
        case 8 :
            printf("F%clicitations, vous etes corrompu, vous avez %ct%c %clu maire !"
                   " Payez 50 euros %c chaque joueur pour feter ceci.\n",130, 130, 130, 130, 133);
            int a = nombreJoueur();
            j->argent -= 50 * a;
            j->fortune -= 50 * a;
            break;
        case 9 :
            printf("Exces de vitesse : payez 100 euros\n");
            j->argent -= 100;
            j->fortune -= 100;
            break;
    }
}*/


void typeCartes(Case* prop, Joueurs* player, Joueurs* pProprio, CartesChance* paquetChance){


    prop->numero = player->placement;
    switch(prop->type) {
        case 0:
            achatRue(prop, player, pProprio);
            break;
        case 1:
            melangerCartesChance(paquetChance);
            int nbCartesPioches = 0;
            attributionCarteChance(paquetChance[nbCartesPioches].numero, player);
            nbCartesPioches++;
            if(nbCartesPioches == 10) {
                nbCartesPioches = 0;
                melangerCartesChance(paquetChance);
            }
            break;

        case 2:
        //fonction jm cartes communauté
           break;
        case 3:
        caseDepart(player);
            break;
        case 4:
        printf("Quel grand coeur!!!Vous rendez visite à Oscar Pistorius pour le soutenir\n");
            break;
        case 5:
        perteOuGainArgent(player, prop);
            break;
        case 6:
            changement(player);
            break;
    }
    }






Joueurs creerJoueur(int i){
    Joueurs player;
    printf("Veuillez rentrer le pseudo du joueur %d \n >:", i+1 );
    fflush(stdin);
    fgets(player.nomJ,TAILLE_NOM_MAX, stdin );
    player.fortune = 1500;
    player.argent = 1500;
    player.placement = 1;
    player.numeroJ = i+1;
    player.nbGroupes = 0;
    player.nbProprietes = 0;
    player.nbHotelsJ = 0;
    player.nbMaisonsJ = 0;
    player.nbDouble = 0;
    player.faillite = 0;
    player.cartesPrison = 0;
    player.nbHypotheque = 0;
    player.possessionParCase = (int*) calloc(NOMBRE_CASE, sizeof (int));
    for ( int h = 1 ;  h < NOMBRE_CASE/2 ; h++){
        player.possessionParCase[2*h] = -2;
        player.possessionParCase[2*h-1] = -3;
    }
    player.possessionParGroupe = (int*) calloc(NOMBRE_GROUPES, sizeof(int));
    for (int k = 1;  k < NOMBRE_GROUPES; k++ ){
        player.possessionParGroupe[k] = 0;
    }
    return player;
}
void initJoueur(int nbJoueurs){
    Joueurs* tabJoueur  = (Joueurs*) calloc(nbJoueurs, sizeof (Joueurs));
    printf("La liste des joueurs s'affichera quand vous aurez rentre vos pseudos: \n");
    for ( int i = 0 ; i < nbJoueurs ; i++){
        tabJoueur[i] = creerJoueur(i);
    }
    for ( int  i = 0 ; i< nbJoueurs ; i++){
        printf("Le joueur %d est %s! Sa fortune est de %d, son argent est de %d il se trouve a la case depart,"
               " possede %d maison et %d hotel, avec %d propriete et %d groupe de legendes de sport\n", tabJoueur[i].numeroJ , tabJoueur[i].nomJ,
               tabJoueur[i].fortune, tabJoueur[i].argent , tabJoueur[i].nbMaisonsJ, tabJoueur[i].nbHotelsJ, tabJoueur[i].nbProprietes, tabJoueur[i].nbGroupes  );

    }
}


Case initProp(int numero, int numeroGroupes, int loyer, char* nom, int prix, int type, int donne, int valeurHypotheque, int prixMaison, char* nomGroupe , int possibilite)
{
    Case p;
    //strcpy(p.nomPro, nom);
    //p.dispo = 1;
    //p.valeurHypotheque = 0;
    //p.type = type;
    p.numero = numero;
    p.loyer = loyer;
    p.numeroProprio = 0;
    strcpy(p.nomPro, nom);
    p.prix = prix;
    //p.nbMaison = nbMaison;
    p.numeroGroupes = numeroGroupes;
    p.type = type;
    p.nbMaison = 0;
    p.donne = donne;
    p.valeurHypotheque = valeurHypotheque;
    //p.hypotheque = 0;
    p.prixMaison = prixMaison;
    strcpy(p.nomGroupe, nomGroupe);
    p.possibilite = possibilite;
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
Case* initCases()
{
    Case* tabCase =  calloc(NOMBRE_CASE , sizeof(Case)); // initialisation des cases
    tabCase[0] = initProp(1, 0,  0, "Depart", 0, 3, 200, 0, 0, "Depart", -1 );
    tabCase[1] = initProp(2, 1, 60, "Maradona", 60, 0, 0, 30, 50 , "foot", 0 );
    tabCase[2] = initProp(3, 0,100, "Taxe", 0, 5, 0, 0, 0, "Taxe", -1);
    tabCase[3] = initProp(4, 1, 80, "Zidane", 80, 0,  0, 40 , 50 , "foot",0);
    tabCase[5] = initProp(6, 2, 100, "Bryant", 100, 0, 0, 50, 60, "basket", 0);
    tabCase[6] = initProp(7, 0, 0, "Communaute", 0, 2, 0, 0, 0, "commu", -1);
    tabCase[7] = initProp(8, 2, 120, "Jordan", 120, 0, 0 , 60, 60 , "basket",0);
    tabCase[8] = initProp(9, 0, 0, "Prison", 0, 4, 0, 0, 0,"prison", -1);
    tabCase[9] = initProp(10, 3, 140, "Chabal", 140, 0, 0, 70 , 100, "rugby", 0 );
    tabCase[10] = initProp(11, 0, 100, "Impot", 0, 5, 0,0, 0, "Taxe", -1);
    tabCase[11] = initProp(12, 3, 160, "Lomu", 160, 0, 0, 80 , 100, "rugby", 0 );
    tabCase[13]= initProp(14,4, 180, "Tyson", 180, 0, 0, 90 , 110 ,"boxe" , 0);
    tabCase[14] = initProp(15,0, 0, "Chance", 0, 1, 0,0,0 , "chance" , -1);
    tabCase[15] = initProp(16,4, 200, "Ali", 200, 0, 0, 100, 110, "boxe", 0);
    tabCase[16] = initProp(17,0, 0, "Libre", 0, 7, 0, 0, 0 , "libre", -1);
    tabCase[17] =  initProp(18,5, 220, "Florent", 220, 0, 0, 110, 130 , "natation", 0);
    tabCase[18] =  initProp(19, 0, 100, "Taxe", 0, 5, 0, 0, 0 , "taxe", -1);
    tabCase[19] =  initProp(20,5, 240, "Laure", 240, 0, 0, 120, 130 , "natation", 0);
    tabCase[21] =   initProp(22,6, 260, "Staut", 260, 0, 0, 130, 150 , "equitation", 0);
    tabCase[22] =   initProp(23,0, 0, "Communaute", 0, 2, 0, 0, 0 , "commu", -1);
    tabCase[23] =   initProp(24,6, 280, "Leprevost", 280 ,0, 0, 140, 150 , "equitation", 0);
    tabCase[24] =  initProp(25,0, 0, "Prison", 0, 4, 0, 0, 0 , "prison", -1);
    tabCase[25] =  initProp(26,7, 300, "Paire", 300, 0, 0, 150, 170 , "tennis", 0);
    tabCase[26] =  initProp(27,0, 0, "Trouver", 0, 5, 50,0, 0 , "trouver", -1);
    tabCase[27] =  initProp(28,7, 320, "Agassi", 320, 0, 0, 160, 170 , "tennis", 0);
    tabCase[29] =  initProp(30,8, 350, "Bale", 350, 0, 0, 175, 190 , "golf", 0);
    tabCase[30] =   initProp(31,0, 0, "Chance", 0, 1, 0, 0, 0 , "chance", -1);
    tabCase[31] =   initProp(32,8, 400, "Woods", 400, 0, 0, 200, 190 , "golf", 0);
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

void prixLoyer(Case* prop, Joueurs* pAcheteur, Joueurs* pProprio){
    int choix = 0;
    if (pProprio->possessionParCase[prop->numero] == 0){
        printf("La rue %s n'est pas disponible à l'achat, merci de bien vouloir payer %d euros.", prop->nomPro,
               prop->loyer);
        if (pAcheteur->argent < prop->loyer){
                fonctionHypoteque(prop, pAcheteur, prop->loyer);

            }



        pAcheteur->argent = pAcheteur->argent - prop->loyer;
        pAcheteur->fortune = pAcheteur->fortune - prop->loyer;
        pProprio->argent = pProprio->argent + prop->loyer;
        pProprio->fortune = pProprio->fortune + prop->loyer;
    }
    else if (pProprio->possessionParCase[prop->numero] == 1){
        printf("La rue %s n'est pas disponible à l'achat, une maison a ete construite... merci de bien vouloir payé %d euros.", prop->nomPro,
               prop->loyer + prop->loyer/4);
        if (pAcheteur->argent < prop->loyer){
            fonctionHypoteque(prop, pAcheteur, prop->loyer+prop->loyer/4);
        }
        else {
        pAcheteur->argent = pAcheteur->argent - prop->loyer + prop->loyer/4;
        pAcheteur->fortune = pAcheteur->fortune - prop->loyer + prop->loyer/4;
        pProprio->argent = pProprio->argent + prop->loyer + prop->loyer/4;
        pProprio->fortune = pProprio->fortune + prop->loyer + prop->loyer/4;


        }

    }
    else if (pProprio->possessionParCase[prop->numero] == 2){
        printf("La rue %s n'est pas disponible à l'achat, deux maisons ont ete construite... merci de bien vouloir payé %d euros.", prop->nomPro,
               prop->loyer + prop->loyer/2);
        if (pAcheteur->argent < prop->loyer){
            fonctionHypoteque(prop, pAcheteur, prop->loyer+prop->loyer/2);

        }
        else{
        pAcheteur->argent = pAcheteur->argent - prop->loyer + prop->loyer/2;
        pAcheteur->fortune = pAcheteur->fortune - prop->loyer + prop->loyer/2;
        pProprio->argent = pProprio->argent + prop->loyer + prop->loyer/2;
        pProprio->fortune = pProprio->fortune + prop->loyer + prop->loyer/2;

        }
    }
    else if (pProprio->possessionParCase[prop->numero] == 3){
        printf("La rue %s n'est pas disponible à l'achat. Aie!! trois maisons ont ete construite... merci de bien vouloir payé %d euros.", prop->nomPro,
               prop->loyer + prop->loyer*3/4);
        if (pAcheteur->argent < prop->loyer){
            fonctionHypoteque(prop, pAcheteur, prop->loyer+prop->loyer*3/4);

        }
        else{
        pAcheteur->argent = pAcheteur->argent - prop->loyer + prop->loyer*3/4;
        pAcheteur->fortune = pAcheteur->fortune - prop->loyer + prop->loyer*3/4;
        pProprio->argent = pProprio->argent + prop->loyer + prop->loyer*3/4;
        pProprio->fortune = pProprio->fortune + prop->loyer + prop->loyer*3/4;

        }

    }
    else if (pProprio->possessionParCase[prop->numero] == 4){
        printf("La rue %s n'est pas disponible à l'achat. Sa commence a piquer, quatres maisons ont ete construite... merci de bien vouloir payé %d euros.", prop->nomPro,
               prop->loyer + prop->loyer);
        if (pAcheteur->argent < prop->loyer){
            fonctionHypoteque(prop, pAcheteur, prop->loyer+prop->loyer);

        }
        else {
            pAcheteur->argent = pAcheteur->argent - prop->loyer + prop->loyer;
            pAcheteur->fortune = pAcheteur->fortune - prop->loyer + prop->loyer;
            pProprio->argent = pProprio->argent + prop->loyer + prop->loyer;
            pProprio->fortune = pProprio->fortune + prop->loyer + prop->loyer;
        }

    }
    else if (pProprio->possessionParCase[prop->numero] == 5){
        printf("La rue %s n'est pas disponible à l'achat. Coup dur!!! un hotel a ete construit... merci de bien vouloir payé %d euros.", prop->nomPro,
               3*prop->loyer);
        if (pAcheteur->argent < prop->loyer){
            fonctionHypoteque(prop, pAcheteur, prop->loyer+prop->loyer+3*prop->loyer);

        }
        else {
            pAcheteur->argent = pAcheteur->argent - 3 * prop->loyer;
            pAcheteur->fortune = pAcheteur->fortune - 3 * prop->loyer;
            pProprio->argent = pProprio->argent + 3 * prop->loyer;
            pProprio->fortune = pProprio->fortune + 3 * prop->loyer;
        }


    }
}

void achatMaison(Case* prop, Joueurs* pAcheteur){
    int choix = 0;


    if (pAcheteur->argent < prop->prixMaison ){
        printf("Vous n'avez pas le sous... Vous ne pouvez donc pas acheter de maisons.\n");
    }
    else if (pAcheteur->possessionParCase[prop->numero] == 5){
        printf("Il n'est pas possible d'obtenir plus qu'un hotel, reposez vous tranquilement dans votre somptueuse propriete.\n");
    }
    else{
        if (pAcheteur->possessionParCase[prop->numero] == 4){
            printf("Souhaitez vous acheter un hotel a %d pour embellir votre rue? Si oui tapez 1 sinon tapez 0:\n>");
            scanf("%f", &choix);
            if (choix == 0){
                printf("Vous etes petit joueur...");
            }
            else if (choix == 1){
                printf("Mais quel joueur!!! vous faites l'acquisition d'un hotel.\n");
                pAcheteur->nbHotelsJ += 1;
                pAcheteur->possessionParCase[prop->numero] = pAcheteur->possessionParCase[prop->numero] + 1;
                pAcheteur->argent += - prop->prixMaison;
                pAcheteur->fortune += - prop->prixMaison;
        }
        else {
                printf("Souhaitez vouz acheter une maison a %d pour embellir votre rue? Si oui tapez 1 sinon tapez 0:\n>",
                       prop->prixMaison);

                scanf("%f", &choix);
                if (choix == 0) {
                    printf("Vous etes petit joueur...");
                } else if (choix == 1) {
                    printf(" Vous faites l'acquisition d'une nouvelle maison.\n");
                    pAcheteur->possessionParCase[prop->numero] = pAcheteur->possessionParCase[prop->numero] + 1;
                    pAcheteur->argent += - prop->prixMaison;
                    pAcheteur->fortune += - prop->prixMaison;

                }
            }

        }

    }

}

 void fonctionHypoteque(Case* prop, Joueurs* pAcheteur, int prix) {
     int choix = 1;
     int choixBis = 1;
     int choixBisBis = 0;
     printf("Aie aie aie, sa sent le sapin. Vous devez hypothequer.\n");
     while (pAcheteur->argent < prix) {
         printf("Vous avez différent choix qui s'offre a vous:\n1)Vendre une maison.\n 2)Vendre un hotel.\n3)Hypothequer une propriete.\n>");
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
                                    prop->prixMaison / 2);
                             pAcheteur->argent += prop->prixMaison / 2;
                             pAcheteur->fortune += prop->prixMaison / 2;
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
                             printf("Vous vendez cet hotel ce qui vous rapporte une coquette somme de %d",
                                    prop->prixMaison / 2);
                             pAcheteur->argent += prop->prixMaison / 2;
                             pAcheteur->fortune += prop->prixMaison / 2;
                             pAcheteur->nbMaisonsJ += -1;
                             pAcheteur->possessionParCase[prop->numero] += -1;

                         }
                     }
                 }
                 break;
             case 3:
                 for (int i = 0; i < NOMBRE_CASE; i++) {
                     if (pAcheteur->possessionParCase[i] == 0) {
                         printf("Voulez vous hypothequer la case %d?", prop->numero);
                         printf("Si oui tapez 1, sinon tapez 0");
                         scanf("%d", &choixBisBis);
                         if (choixBisBis == 1) {
                             printf("Vous hypotequer cette propriete ce qui vous rapporte une coquette somme de %d",
                                    prop->prix / 2);
                             pAcheteur->argent += prop->prix / 2;
                             pAcheteur->fortune += prop->prix / 2;
                             pAcheteur->possessionParCase[prop->numero] += -1;
                             prop->hypotheque = 1;

                         }
                     }
                 }
                 break;

             default:
                 printf("Votre QI est deficient...Veuillez taper une valeur entre 1 et 3");

         }

     }
 }