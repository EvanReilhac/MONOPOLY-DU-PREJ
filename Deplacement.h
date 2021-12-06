

#ifndef MONOP_EVAN_DEPLACEMENT_H
#define MONOP_EVAN_DEPLACEMENT_H
int dooble(int* desUn, int* desDeux, Joueurs* pPlayer);
void achatRue(Case* prop, Joueurs* pAcheteur, Joueurs* pProprio,int nombreJoueur, Joueurs* tablJ);
int placement( Joueurs* p);
void caseDepart(Joueurs* p);
void perteOuGainArgent(Joueurs* joueur, Case* prop, int nombreJoueur, Joueurs* tablJ);
void changement(Joueurs* p);
int jeuDes(int* desUn, int* desDeux, Joueurs* pplayer);
void typeCartes(Case* prop, Joueurs* player, Joueurs* pProprio , CartesChance* paquetChance, CartesCommunaute* paquetCommu, int nombreJoueur, Joueurs* tablJ);
void achatMaison(Case* prop, Joueurs* pAcheteur);
void sortirPrison(Joueurs* joueur, int* tourPrison);
#endif //MONOP_EVAN_DEPLACEMENT_H
