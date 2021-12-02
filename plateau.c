#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Fonctions.h"
#include "Structures.h"

Condition laConditionDeLaCase(int cases)
{
    Condition enFonctionDeLaCase;
    int ouiOuNon;
    int maisonFoot1 = 0, maisonFoot2 = 0, maisonBasket1 = 0, maisonBasket2 = 0, maisonRugby1 = 0, maisonRugby2 = 0, maisonBoxe1 = 0, maisonBoxe2 = 0, maisonNatation1 = 0, maisonNatation2 = 0, maisonEquitation1 = 0, maisonEquitation2 = 0, maisonTennis1 = 0, maisonTennis2 = 0, maisonGolf1 = 0, maisonGolf2 = 0;
    argent = enFonctionDeLaCase.argentDuJoueur;
    if(cases==1)
    {
        printf("\nVous etes sur la case depart, vous recevez 200euros.\n");
        argent = argent + 200;
    }
    if(cases==2)
    {
        printf("\nVous etes sur la case 02, celle de Diego Maradona\n");
        if(maisonFoot1 >= 1)
        {
            printf("\nDommage.. Vous allez devoir payer 60euros\n");
            argent = argent - 60;
        }
        if(maisonFoot1==0)
        {
            printf("\nSouhaitez vous acheter Diego Maradona pour 60euros ? Si oui tapez 1 sinon tapez 0.\n");
            scanf("%d", &ouiOuNon);
            if(ouiOuNon==1)
            {
                printf("\nVous avez achete Diego Maradona!!\n");
                argent = argent - 60;
                maisonFoot1 = maisonFoot1 + 1;
            }
            if(ouiOuNon==0)
            {
                printf("\nVous n'avez pas achete Diego Maradona...\n");
            }
        }
    }
    if(cases==3)
    {
        printf("\nVous etes sur la case 03, vous payez une taxe d habitation de 100euros.\n");
        argent = argent - 100;
    }
    if(cases==4)
    {
        printf("\nVous etes sur la case 04, celle de Zinedine Zidane\n");
        if(maisonFoot2 >= 1)
        {
            printf("\nDommage.. Vous allez devoir payer 80euros\n");
            argent = argent - 80;
        }
        if(maisonFoot2==0)
        {
            printf("\nSouhaitez vous acheter Zinedine Zidane pour 80euros ? Si oui tapez 1 sinon tapez 0.\n");
            scanf("%d", &ouiOuNon);
            if(ouiOuNon==1)
            {
                printf("\nVous avez achete Zinedine Zidane !!\n");
                argent = argent - 80;
                maisonFoot2 = maisonFoot2 + 1;
            }
            if(ouiOuNon==0)
            {
                printf("\nVous n'avez pas achete Zinedine Zidane...\n");
            }
        }
    }
    if(cases==5)
    {
        printf("\nVous etes sur la case 05, vous avancez a la case 13\n");
        cases = 13;
    }
    if(cases==6)
    {
        printf("\nVous etes sur la case 06, celle de Kobe Bryant\n");
        if(maisonBasket1 >= 1)
        {
            printf("\nDommage.. Vous allez devoir payer 100euros\n");
            argent = argent - 100;
        }
        if(maisonBasket1==0)
        {
            printf("\nSouhaitez vous acheter Kobe Bryant pour 100euros ? Si oui tapez 1 sinon tapez 0.\n");
            scanf("%d", &ouiOuNon);
            if(ouiOuNon==1)
            {
                printf("\nVous avez achete Kobe Bryant !!\n");
                argent = argent - 100;
                maisonBasket1 = maisonBasket1 + 1;
            }
            if(ouiOuNon==0)
            {
                printf("\nVous n'avez pas achete Kobe Bryant...\n");
            }
        }
    }
    if(cases==7)
    {
        printf("\nVous etes sur la case 07, vous tirez une carte communaute\n");
        //Mettre le truc de JM
    }
    if(cases==8)
    {
        printf("\nVous etes sur la case 08, celle de Michael Jordan\n");
        if(maisonBasket2 >= 1)
        {
            printf("\nDommage.. Vous allez devoir payer 120euros\n");
            argent = argent - 120;
        }
        if(maisonBasket2==0)
        {
            printf("\nSouhaitez vous acheter Michael Jordan pour 120euros ? Si oui tapez 1 sinon tapez 0.\n");
            scanf("%d", &ouiOuNon);
            if(ouiOuNon==1)
            {
                printf("\nVous avez achete Michael Jordan!!\n");
                argent = argent - 120;
                maisonBasket2 = maisonBasket2 + 1;
            }
            if(ouiOuNon==0)
            {
                printf("\nVous n'avez pas achete Michael Jordan...\n");
            }
        }
    }
    if(cases==9)
    {
        printf("\nVous etes sur la case 09. Faites une petite visite de la prison, en esperant ne pas vous retrouvez a l'interieur ;)\n");
    }
    if(cases==10)
    {
        printf("\nVous etes sur la case 10, celle de Sebastien Chabal\n");
        if(maisonRugby1 >= 1)
        {
            printf("\nDommage.. Vous allez devoir payer 140euros \n");
            argent = argent - 140;
        }
        if(maisonRugby1==0)
        {
            printf("\nSouhaitez vous acheter Sebastien Chabal pour 140euros ? Si oui tapez 1 sinon tapez 0.\n");
            scanf("%d", &ouiOuNon);
            if(ouiOuNon==1)
            {
                printf("\nVous avez achete Sebastien Chabal!!\n");
                argent = argent - 140;
                maisonRugby1 = maisonRugby1 + 1;
            }
            if(ouiOuNon==0)
            {
                printf("\nVous n'avez pas achete Sebastien Chabal...\n");
            }
        }
    }
    if(cases==11)
    {
        printf("\nVous etes sur la case 11. Vous payez une impot sur la fortune et perdez 100euros\n");
        argent = argent - 100;
    }
    if(cases==12)
    {
        printf("\nVous etes sur la case 12, celle de Jonah Lomu\n");
        if(maisonRugby2 >= 1)
        {
            printf("\nDommage.. Vous allez devoir payer 160euros\n");
            argent = argent - 160;
        }
        if(maisonRugby2==0)
        {
            printf("\nSouhaitez vous acheter Jonah Lomu pour 160euros ? Si oui tapez 1 sinon tapez 0.\n");
            scanf("%d", &ouiOuNon);
            if(ouiOuNon==1)
            {
                printf("\nVous avez achete Jonah Lomu !!\n");
                argent = argent - 160;
                maisonRugby2 = maisonRugby2 + 1;
            }
            if(ouiOuNon==0)
            {
                printf("\nVous n'avez pas achete Jonah Lomu...\n");
            }
        }
    }
    if(cases==13)
    {
        printf("\nVous etes sur la case 13. Vous avancez a la case 22.\n");
        cases = 22;
    }
    if(cases==14)
    {
        printf("\nVous etes sur la case 14, celle de Mike Tyson\n");
        if(maisonBoxe1 >= 1)
        {
            printf("\nDommage.. Vous allez devoir payer 180euros\n");
            argent = argent - 180;
        }
        if(maisonBoxe1==0)
        {
            printf("\nSouhaitez vous acheter Mike Tyson pour 180euros ? Si oui tapez 1 sinon tapez 0.\n");
            scanf("%d", &ouiOuNon);
            if(ouiOuNon==1)
            {
                printf("\nVous avez achete Mike Tyson !!\n");
                argent = argent - 180;
                maisonBoxe1 = maisonBoxe1 + 1;
            }
            if(ouiOuNon==0)
            {
                printf("\nVous n'avez pas achete Mike Tyson...\n");
            }
        }
    }
    if(cases==15)
    {
        printf("\nVous etes sur la case 15. Vous obtenez une carte chance.");
        //mettre le truc carte chance de JM
    }
    if(cases==16)
    {
        printf("\nVous etes sur la case 16, celle de Mohamed Ali\n");
        if(maisonBoxe2 >= 1)
        {
            printf("\nDommage.. Vous allez devoir payer 200euros\n");
            argent = argent - 200;
        }
        if(maisonBoxe2==0)
        {
            printf("\nSouhaitez vous acheter Mohamed Ali pour 200euros ? Si oui tapez 1 sinon tapez 0.\n");
            scanf("%d", &ouiOuNon);
            if(ouiOuNon==1)
            {
                printf("\nVous avez achete Mohamed Ali !!\n");
                argent = argent - 200;
                maisonBoxe2 = maisonBoxe2 + 1;
            }
            if(ouiOuNon==0)
            {
                printf("\nVous n'avez pas achete Mohamed Ali...\n");
            }
        }
    }
    if(cases==17)
    {
        printf("\nVous etes sur la case 17. Detendez vous et prenez une ptite biere, on est ici pour chill!!\n");
    }
    if(cases==18)
    {
        printf("\nVous etes sur la case 16, celle de Flaurent Manaudou\n");
        if(maisonNatation1 >= 1)
        {
            printf("\nDommage.. Vous allez devoir payer 220euros\n");
            argent = argent - 220;
        }
        if(maisonNatation1==0)
        {
            printf("\nSouhaitez vous acheter Flaurent Manaudou pour 220euros ? Si oui tapez 1 sinon tapez 0.\n");
            scanf("%d", &ouiOuNon);
            if(ouiOuNon==1)
            {
                printf("\nVous avez achete Flaurent Manaudou !!\n");
                argent = argent - 220;
                maisonNatation1 = maisonNatation1 + 1;
            }
            if(ouiOuNon==0)
            {
                printf("\nVous n'avez pas achete Flaurent Manaudou...\n");
            }
        }
    }
    if(cases==19)
    {
        printf("\nVous etes sur la case 19. Vous etes riche tous ce passe bien.. Et cheh une taxe de produit de luxe, moins 200euros sur ton compte.\n");
        argent = argent - 200;
    }
    if(cases==20)
    {
        printf("\nVous etes sur la case 20, celle de Laure Manaudou\n");
        if(maisonNatation2 >= 1)
        {
            printf("\nDommage.. Vous allez devoir payer 240euros\n");
            argent = argent - 240;
        }
        if(maisonNatation2==0)
        {
            printf("\nSouhaitez vous acheter Laure Manaudou pour 240euros ? Si oui tapez 1 sinon tapez 0.\n");
            scanf("%d", &ouiOuNon);
            if(ouiOuNon==1)
            {
                printf("\nVous avez achete Laure Manaudou !!\n");
                argent = argent - 240;
                maisonNatation2 = maisonNatation2 + 1;
            }
            if(ouiOuNon==0)
            {
                printf("\nVous n'avez pas achete Laure Manaudou...\n");
            }
        }
    }
    if(cases==21)
    {
        printf("\nVous etes sur la case 21. Avancez a la case 29\n");
        cases = 29;
    }
    if(cases==22)
    {
        printf("\nVous etes sur la case 22, celle de Kevin Staut\n");
        if(maisonEquitation1 >= 1)
        {
            printf("\nDommage.. Vous allez devoir payer 260euros\n");
            argent = argent - 260;
        }
        if(maisonEquitation1==0)
        {
            printf("\nSouhaitez vous acheter Kevin Staut pour 260euros ? Si oui tapez 1 sinon tapez 0.\n");
            scanf("%d", &ouiOuNon);
            if(ouiOuNon==1)
            {
                printf("\nVous avez achete Kevin Staut !!\n");
                argent = argent - 260;
                maisonEquitation1 = maisonEquitation1 + 1;
            }
            if(ouiOuNon==0)
            {
                printf("\nVous n'avez pas achete Kevin Staut...\n");
            }
        }
    }
    if(cases==23)
    {
        printf("\nVous etes sur la case 23, vous tirez une carte communaute\n");
        //Mettre le truc de JM
    }
    if(cases==24)
    {
        printf("\nVous etes sur la case 24, celle de Penelope Leprevost\n");
        if(maisonEquitation2 >= 1)
        {
            printf("\nDommage.. Vous allez devoir payer 280euros\n");
            argent = argent - 280;
        }
        if(maisonEquitation2==0)
        {
            printf("\nSouhaitez vous acheter Penelope Leprevost pour 280euros ? Si oui tapez 1 sinon tapez 0.\n");
            scanf("%d", &ouiOuNon);
            if(ouiOuNon==1)
            {
                printf("\nVous avez achete Kevin Staut !!\n");
                argent = argent - 280;
                maisonEquitation2 = maisonEquitation2 + 1;
            }
            if(ouiOuNon==0)
            {
                printf("\nVous n'avez pas achete Penelope Leprevost...\n");
            }
        }
    }
    if(cases==25)
    {
        printf("\nVous etes sur la case 25 :( Vous allez directement en prison sans gagner d'argent avec la case depart...Cheh.\n");
        cases = 9;
        //a faire
    }
    if(cases==26)
    {
        printf("\nVous etes sur la case 26, celle de Benoit Paire\n");
        if(maisonTennis1 >= 1)
        {
            printf("\nDommage.. Vous allez devoir payer 300euros\n");
            argent = argent - 300;
        }
        if(maisonTennis1==0)
        {
            printf("\nSouhaitez vous acheter Benoit Paire pour 300euros ? Si oui tapez 1 sinon tapez 0.\n");
            scanf("%d", &ouiOuNon);
            if(ouiOuNon==1)
            {
                printf("\nVous avez achete Benoit Paire !!\n");
                argent = argent - 300;
                maisonTennis1 = maisonTennis1 + 1;
            }
            if(ouiOuNon==0)
            {
                printf("\nVous n'avez pas achete Benoit Paire...\n");
            }
        }
    }
    if(cases==27)
    {
        printf("\nVous etes sur la case 27. Et par chance vous trouvez 50euros par terre, benef au max !");
        argent = argent + 50;
    }
    if(cases==28)
    {
        printf("\nVous etes sur la case 28, celle de Andre Agassi\n");
        if(maisonTennis2 >= 1)
        {
            printf("\nDommage.. Vous allez devoir payer 320euros\n");
            argent = argent - 320;
        }
        if(maisonTennis2==0)
        {
            printf("\nSouhaitez vous acheter Andre Agassi pour 320euros ? Si oui tapez 1 sinon tapez 0.\n");
            scanf("%d", &ouiOuNon);
            if(ouiOuNon==1)
            {
                printf("\nVous avez achete Andre Agassi !!\n");
                argent = argent - 320;
                maisonTennis2 = maisonTennis2 + 1;
            }
            if(ouiOuNon==0)
            {
                printf("\nVous n'avez pas achete Andre Agassi...\n");
            }
        }
    }
    if(cases==29)
    {
        printf("\nVous etes sur la case 29. Vous avancez a la case 05, vous passez donc sur la case depart et recevez 200euros !\n");
        cases = 5;
        argent = argent + 200;
    }
    if(cases==30)
    {
        printf("\nVous etes sur la case 30, celle de Gareth Bale\n");
        if(maisonGolf1 >= 1)
        {
            printf("\nDommage.. Vous allez devoir payer 350euros\n");
            argent = argent - 350;
        }
        if(maisonGolf1==0)
        {
            printf("\nSouhaitez vous acheter Gareth Bale pour 350euros ? Si oui tapez 1 sinon tapez 0.\n");
            scanf("%d", &ouiOuNon);
            if(ouiOuNon==1)
            {
                printf("\nVous avez achete Gareth Bale !!\n");
                argent = argent - 350;
                maisonGolf1 = maisonGolf1 + 1;
            }
            if(ouiOuNon==0)
            {
                printf("\nVous n'avez pas achete Gareth Bale...\n");
            }
        }
    }
    if(cases==31)
    {
        printf("\nVous etes sur la case 31. Vous obtenez une carte chance.");
        //mettre le truc carte chance de JM
    }
    if(cases==32)
    {
        printf("\nVous etes sur la case 32, celle de Tiger Woods\n");
        if(maisonGolf2 >= 1)
        {
            printf("\nDommage.. Vous allez devoir payer 400euros\n");
            argent = argent - 400;
        }
        if(maisonGolf2==0)
        {
            printf("\nSouhaitez vous acheter Tiger Woods pour 400euros ? Si oui tapez 1 sinon tapez 0.\n");
            scanf("%d", &ouiOuNon);
            if(ouiOuNon==1)
            {
                printf("\nVous avez achete Tiger Woods !!\n");
                argent = argent - 400;
                maisonGolf2 = maisonGolf2 + 1;
            }
            if(ouiOuNon==0)
            {
                printf("\nVous n'avez pas achete Tiger Woods...\n");
            }
        }
    }
    printf("-----------------------------------JOUEUR SUIVANT-----------------------------------");
}