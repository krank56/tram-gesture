
#include <stdio.h>//printf,scanf...
#include <conio.h>//getch,clear screen...
#include <stdlib.h>//rand...
#include <string.h>//strcpy,strlen,strstr...
#include <time.h>//initialiser le temps
char(type);
char(pm);
char(choix);
char paim[11];
int j=0;
int nbt[2];
int nb;
char a;

void dessin()
{
    printf("\n\n\n              ##########   ####          #          #       #\n");
    printf("                  ##       #   ##       ###        ###     ##\n");
    printf("                  ##       #   ##      #   #       # #    ####\n");
    printf("                  ##       # ##       #######     ##  #  #   ##\n");
    printf("                  ##       #  ##     ##     ##    #    ###    #\n");
    printf("                  ##       #    ##  ##       ##  ##           ##\n");
    printf("                  ##       #     #  #         #  #             #\n\n");
    printf("           ###     #####     ###  ##########  ##      ##     ###       #####\n");
    printf("         ##        #        #         ##      ##      ##    #   ##     #\n");
    printf("       ##          #       ##         ##      ##      ##    #    #     #\n");
    printf("      ##           ####     ###       ##      ##      ##    # ###      ####\n");
    printf("      #     ###    #           ##     ##      ##      ##    #  ##      #\n");
    printf("      ##      #    #           #      ##       ##    ##     #    ##    #\n");
    printf("        #######    #####    ###       ##        ######      #     ##   #####\n");
    printf("\n\n\n------------- Appuyez sur une touche pour acceder a l'application --------------");
    printf("\n------------- Appuyez sur la touche q pour quitter l'application ---------------");
    choix=getch();
    if (choix=='q')
    {
        exit(0);
    }

}
typedef struct
{
  int num;
  char chauf[20];
  char etat[15];
  char ligne[15];
}trm;
trm t[100];
struct
{
    char nom[10];
    char prenom[15];
    char ddn[12];
    char cin[10];
    char tel[12];
}cl;
void supprimer()
{
    int lon=77;
    char nouv[5000][100];
    char nouv1[5000];
    char nouvv[5000];
    int k=0;
    int n;
    FILE* liste2 = NULL;
    liste2=fopen("liste.tram","r+");
    while (fgets(nouv1,100,liste2)!=NULL)
    {
    fflush(stdin);
    strcpy(nouv[k],nouv1);
    k=k+1;
    }
    fclose(liste2);
    liste2=fopen("liste.tram","w");
    fclose(liste2);
    strcpy(nouvv,nouv[j]);
    while(lon>=0)
    {
    nouvv[lon]='\0';
    lon=lon-1;
    }
    strcpy(nouv[j],nouvv);
    for(n=0;n<k;n++)
    {
    liste2=fopen("liste.tram","a");
    fprintf(liste2,"%s",nouv[n]);
    fclose(liste2);
    }
    fflush(stdin);
    getch();
}
void modifier()
    {
    supprimer();
    system("cls");
    printf("\n---------------------------------- Modification -------------------------------\n\n");
    printf("Choisissez le type de votre abonnement (Tapez 1 ou 2)\n\n");
    printf("->       Abonnement 1 : IRTIYAH Public \n\n");
    printf("->       Abonnement 2 : IRTIYAH TALIB \n\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("Saisissez votre choix: \n");
    fflush(stdin);
    type = getch();
    while(type!='1' && type!='2')
    {
    printf("Veuillez saisir une valeur valable (1 , 2):\n");
    fflush(stdin);
    type = getch();
    }
    system("cls");
    switch(type)
    {
    case '1':
    printf("------------------------------- IRTIYAH Public --------------------------------\n\n");
    paiment(250,700,1350,2500);
    ajout('1');
    break;

    case '2':
    printf("-------------------------------- IRTIYAH TALIB --------------------------------\n\n");
    paiment(150,420,810,1500);
    ajout('2');
    break;
    }
    }
void inimdp()
{
    FILE* mdpp=NULL;
    mdpp=fopen("mdp.tram","a+");
    if (fseek(mdpp,0,SEEK_END)==fseek(mdpp,0,SEEK_SET))//position fin=debut
        {
    fprintf(mdpp,"0000");
        }
    fclose(mdpp);
}
int rechercher(char liste[5000],char arech[10])
{
    int trouve;

    trouve = strstr(liste,arech);
    if (trouve != NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void modi()
{
    char cin[10];
    char numcl[10];
    char ligne[5000];
    int k=0;
    int n;
    FILE* liste2 = NULL;
    liste2=fopen("liste.tram","r+");//mode lecture et ecriture
    system("cls");
    printf("\nDonnez votre CIN:");
    fflush(stdin);
    scanf("%s",&cin);
    while ((fgets(ligne,100,liste2) != NULL) && (rechercher(ligne,cin))==0)
    {
    sprintf(ligne,"%s",ligne);
    j=j+1;
    }
    if ((rechercher(ligne,cin))==0)
    {
        printf("\nVotre CIN ne figure pas dans la liste des clients!\n\nAppuyez sur n'importe quelle touche pour revenir a l'acceuil...");
        getch();
        system("cls");
        main();
    }
    else
    {
        printf("\n\nDonnez votre Numero Client:");
        fflush(stdin);
        scanf("%s",&numcl);
       while ((rechercher(ligne,numcl))==0 || strlen(numcl)!=5)
    {
        printf("\nVotre Numero Client est incorrect!\n\nEntrez le a nouveau:");
        fflush(stdin);
        scanf("%s",&numcl);
    }
    fclose(liste2);
    printf("\nVous pouvez modifier vos informations en toute securite!\n\nAppuyez sur n'importe quelle touche pour continuer...");
    modifier();
}
}

int aleatoire()
{
    srand(time(NULL));// pour l'aspect random
	int random = 0;
    random = (rand()%10000+10000);
	return random;
}
int compare(char chaine1[15],char chaine2[15])
{   int i=0;
    if( strlen(chaine1) != strlen(chaine2) )
        return 0;
    for(i=0;i<strlen(chaine1);i++)
        if( chaine1[i] != chaine2[i])
            return 0;
   return 1;

}
void ajout(char type)
{
        char information[100];
        FILE* clients1 = NULL;
        printf("Donnez votre Nom:");
        scanf("%s",&cl.nom);
        fflush(stdin);
        printf("\nDonnez votre Prenom:");
        scanf("%s",&cl.prenom);
        fflush(stdin);//PRENOM AVEC ESPACE le reste Dans le flux d'entrée standard, stdin.
        printf("\nDonnez votre Date De Naissance (jj-mm-aaaa):");
        scanf("%s",&cl.ddn);
        fflush(stdin);
        printf("\nDonnez votre CIN:");
        scanf("%s",&cl.cin);
        fflush(stdin);
        printf("\nDonnez votre Numero De TEL:");
        scanf("%s",&cl.tel);
        fflush(stdin);
        clients1 = fopen("liste.tram", "a");// a append ajouter au fichier
        fflush(stdin);
        switch(type)
        {case '1':
        sprintf(information,"%-9.9s %-9.9s %-11.11s %-8.8s %-10.10s %-11.11s Public %d\n",cl.nom,cl.prenom,cl.ddn,cl.cin,cl.tel,paim,aleatoire());
        break;
        case '2':
        sprintf(information,"%-9.9s %-9.9s %-11.11s %-8.8s %-10.10s %-11.11s TALIB  %d\n",cl.nom,cl.prenom,cl.ddn,cl.cin,cl.tel,paim,aleatoire());
        break;
        }
        fputs(information,clients1);
        fclose(clients1);
        system("cls");
        printf("\n------------------------- Merci pour votre inscription -------------------------\n\nVos informations sont:\n\n%s\n\nVous pouvez modifiez vos informations n'importe quand en utilisant votre\n\nNumClient (Les derniers 5 chiffres de vos informations)",&information);
        printf("\n\n\n\n\n--------- Appuyez sur n'importe quelle touche pour revenir a l'acceuil ---------");
        getch();
        system("cls");
        main();

}
void liste()
{
    j=0;
    char a;
    char info[100];
   FILE* clients2 = NULL;
   clients2 = fopen("liste.tram","r+");
   system("cls");
   printf("\n---------------------------- Gestion Des Abonnements ---------------------------\n");
   printf("Num Nom:      Prenom:   D.Naissance CIN:     NumTel:    Paiment:    Type:  NumCl\n");
   printf("--------------------------------------------------------------------------------\n");
   while (fgets(info,100,clients2) != NULL)
    {
    printf("%-2.2d> %-76.76s\n",j+1,info);
    j=j+1;
    }
    fclose(clients2);
    printf("Entrez le numero de la ligne du client que vous voulez modifier ou supprimer .\nAppuyez sur 0 pour revenir a l'acceuil...\n");
    fflush(stdin);
    scanf("%d",&j);
    if (j==0)
    {
        system("cls");
        main();
    }
    else if (j!=0)
    {
        j=j-1;
        printf("\nPour modifier appuyez sur (m),Pour supprimer appuyez sur (s)");
        a=getch();
        switch (a)
        {
        case'm':
        modifier();
        break;
        case's':
        supprimer();
        liste();
        }
    }
}
void tramway()
{
    char trchoix;
    system("cls");
    printf("\n------------------------------- Gestion Des Trams ------------------------------\n\n");
    printf("->Pour afficher les trams appuyez sur 1\n\n");
    printf("->Pour ajouter un tram appuyez sur 2\n\n");
    fflush(stdin);
    trchoix=getch();
    while(trchoix!='1' && trchoix!='2')
    {
    printf("Veuillez saisir une valeur valable (1 ou 2):\n");
    fflush(stdin);
    trchoix = getch();
    }
    switch(trchoix)
    {
    case'1':
    traff();
    break;
    case'2':
    trajout();
    break;
    }
}
void afftram()
{
    int m=1;
    while (m<=nb)
    {
    printf("\n->Numero : %-2.2d ",t[m].num);
    printf(" / Chauffeur : %s ",t[m].chauf);
    printf(" / Ligne : %s ",t[m].ligne);
    printf(" / Etat : %s \n",t[m].etat);
    m=m+1;
    }
}
void traff()
{
    int netat;
    int netat1;
    char trchoix1;
    system("cls");
    printf("\n------------------------------- Gestion Des Trams ------------------------------\n\n");
    if (nb!=0)
        {
    printf("Il existe %d tram(s) enregistre(s) sur le reseau.\n\nDont %d sont en panne et %d en circulation.\n",nb,nbt[1],nbt[2]);
    afftram();
    printf("\nPour declarer la panne ou la mise en marche d'un tram , entrez son numero.\n\nPour revenir a l'acceuil appuyez sur 0\n");
    fflush(stdin);
    scanf("%d",&netat);
    if (netat==0)
    {
        main();
    }
    else
    {
        netat1=compare((t[netat].etat),"En panne");
        if (netat1==1)
        {
            strcpy(t[netat].etat,"En circulation");
            nbt[2]=nbt[2]+1;
            nbt[1]=nbt[1]-1;
        }
        else
        {
            strcpy(t[netat].etat,"En panne");
            nbt[1]=nbt[1]+1;
            nbt[2]=nbt[2]-1;
        }
        printf("\nLe tram numero %d est maintenant %s\n\nAppuyez sur une touche pour continuer...",t[netat].num,t[netat].etat);
        getch();
        tramway();
    }
        }
    else
    {
    printf("Il n'y a pas de trams enregistres actuellement sur le reseau .\n\nPour ajouter un tram appuyer sur 1.\n\nPour revenir a l'acceuil appuyez sur 2.\n");
    fflush(stdin);
    trchoix1=getch();
    while(trchoix1!='1' && trchoix1!='2')
    {
    printf("Veuillez saisir une valeur valable (1 ou 2):\n");
    fflush(stdin);
    trchoix1 = getch();
    }
    system("cls");
    switch(trchoix1)
    {
    case'1':
    trajout();
    break;
    case'2':
    main();
    break;
    }
}
}
void trajout()
{
    nb=nb+1;
    system("cls");
    t[nb].num=nb;
    printf("\n------------------------------- Gestion Des Trams ------------------------------\n");
    printf("\nEntrez le nom du chauffeur du tram:\n");
    gets(t[nb].chauf);
    printf("\nPrecisez la ligne:\n----1>Rabat\n----2>Sale\n");
    a=getch();
    fflush(stdin);
    while (a!='1' && a!='2')
    {
    printf("\nVeuillez saisir une valeur valable (1 , 2):\n");
    fflush(stdin);
    a=getch();
    }
    switch(a)
    {
    case'1':
    strcpy(t[nb].ligne,"Rabat");
    break;
    case'2':
    strcpy(t[nb].ligne,"Sale");
    break;
    }
    printf("\nPrecisez son etat\n----1>En circulation\n----2>En panne\n");
    a=getch();
    while (a!='1' && a!='2')
    {
    printf("\nVeuillez saisir une valeur valable (1 , 2):\n");
    fflush(stdin);
    a=getch();
    }
    switch(a)
    {
    case'1':
    strcpy(t[nb].etat,"En circulation");
    nbt[2]=nbt[2]+1;
    break;
    case'2':
    strcpy(t[nb].etat,"En panne");
    nbt[1]=nbt[1]+1;
    break;
    }
    system("cls");
    printf("\n------------------------------- Gestion Des Trams ------------------------------\n");
    printf("\nVous venez d'ajouter un tram avec les informations suivantes:\n");
    printf("\n->Numero    : %-2.2d\n",t[nb].num);
    printf("\n->Chauffeur : %s\n",t[nb].chauf);
    printf("\n->Ligne     : %s\n",t[nb].ligne);
    printf("\n->Etat      : %s\n",t[nb].etat);
    printf("\n\nPour ajouter un autre tram appuyez sur 1.");
    printf("\n\nPour revenir au menu principal appuyez sur 2.");
    a=getch();
    while (a!='1' && a!='2')
    {
    printf("\nVeuillez saisir une valeur valable (1 , 2):\n");
    fflush(stdin);
    a=getch();
    }
    switch(a)
    {
    case'1':
    trajout();
    break;
    case'2':
    system("cls");
    main();
    break;
    }
}
void menuprincipal()
{
system("cls");
printf("\n-------------------------------- Esapce Clients --------------------------------\n\n");
printf("Choisissez le type de votre abonnement (Tapez 1 ou 2) \n\n-> Pour modifier vos informations tapez (m)\n\n");
printf("-> Et pour plus d'informations tapez (i) \n\n");
printf("->       Abonnement 1 : IRTIYAH Public \n\n");
printf("->       Abonnement 2 : IRTIYAH TALIB \n\n");
printf("--------------------------------------------------------------------------------\n");
printf("Saisissez votre choix: \n");
type = getch();
while(type!='1' && type!='2' && type!='i'&& type!='m')
{
printf("Veuillez saisir une valeur valable (1 , 2 , i , m):\n");
type = getch();
}
}
void paiment(int aa,int b,int c,int d)
{
    printf("Veuillez preciser le paiement(1 , 2 , 3 ,4)\n\n");
    printf("1> Mensuel       : %d DHS\n\n",aa);
    printf("2> Trimestriel   : %d DHS\n\n",b);
    printf("3> Semestriel    : %d DHS\n\n",c);
    printf("4> Annuel        : %d DHS\n\n",d);
    pm = getch();
    while(pm!='1' && pm!='2' && pm!='3' && pm!='4')
    {
    printf("Veuillez saisir une valeur valable (1 , 2 , 3, 4):\n");
    pm = getch();
    }
    switch(pm)
    {
    case '1':
    strcpy(paim, "Mensuel");
    break;
    case '2':
    strcpy(paim, "Trimestriel");
    break;
    case '3':
    strcpy(paim, "Semestriel");
    break;
    case '4':
    strcpy(paim, "Annuel");
    break;
    }

}
void motdepasse()
{
    char mdp1[5];
    system("cls");
    printf("\nEntrez le nouveau mot de passe (4 caracteres):");
    fflush(stdin);
    scanf("%s",&mdp1);
    FILE* mdp=NULL;
    mdp=fopen("mdp.tram","w");
    fprintf(mdp,"%s",mdp1);
    fclose(mdp);
    printf("\nMot de passe modifie avec succes !\n\n");
    printf("Appuyez sur n'importe quelle touche pour revenir a l'acceuil");
    getch();
    system("cls");
    main();

}
void client()
{
menuprincipal();
while (type=='i')
{
system("cls");
printf("\n----------Abonnement 1: IRTIYAH Public\n");
printf("La solution la plus flexible pour voyager ! \nValable sur l'ensemble du reseau Tram, cet abonnement permet la \nlibre circulation sur l'ensemble du reseau. En effet, il permet \nd'effectuer des voyages illimites durant toute la periode de \nl'abonnement.Il est charge sur une carte nominative. \n");
printf("\n-----------------------------------------------------------------\n");
printf("\n----------Abonnement 2: IRTIYAH TALIB\n");
printf("La solution pour les etudiants ! \nValable sur l'ensemble du reseau Tram, cet abonnement destine \naux etudiants de l'enseignement public permet la libre circulation \nsur l'ensemble du reseau. En effet, il permet d'effectuer des \nvoyages illimites durant toute la periode de l'abonnement.Il \nest charge sur une carte nominative.\n");
printf("\n-----------------------------------------------------------------\n");
printf("Pour revenir a la page d'acceuil appuiyez sur la touche ->Entrer<-");
getchar();
menuprincipal();
system("cls");
}
system("cls");
switch(type){
    case '1':
    printf("\n------------------------------- IRTIYAH Public --------------------------------\n\n");
    paiment(250,700,1350,2500);
    ajout('1');
    break;

    case '2':
    printf("\n-------------------------------- IRTIYAH TALIB --------------------------------\n\n");
    paiment(150,420,810,1500);
    ajout('2');
    break;
    case 'm':
    modi();
    break;
}
}
void administration()
{
    inimdp();
    char mdp2[5];
    char mdp3[5];
    system("cls");
    printf("\n----------------------------- Esapce Administartion ----------------------------\n\n");
    printf("Entrez le mot de passe pour acceder:");
    scanf("%s",&mdp3);
    FILE* mdp=NULL;
    mdp = fopen("mdp.tram","r");
    fflush(stdin);
    fgets(mdp2,5,mdp);
    while (compare(mdp2,mdp3)==0)
    {
        printf("\nMot de passe incorrect, entrez le a nouveau:");
        scanf("%s",&mdp3);
    }
    fclose(mdp);
    system("cls");
    printf("\n----------------------------- Esapce Administartion ----------------------------\n\n");
    printf("Pour gerer les abonnements appuyez sur (1)\n\n");
    printf("Pour gerer les Trams appuyez sur (2)\n\n");
    printf("Pour modifier le mot de passe appuyez sur (3)\n\n");
    fflush(stdin);
    choix = getch();
    while(choix!='1' && choix!='2' && choix!='3')
    {
    printf("Veuillez saisir une valeur valable (1 ou 2 ou 3):\n");
    fflush(stdin);
    choix = getch();
    }

    switch(choix)
    {
    case '1':
    liste();
    break;

    case '2':
    tramway();
    break;
    case '3':
    motdepasse();
    break;
    }

}
void main()
{
    system("COLOR F0");//f blanc 0 noir
    dessin();
    system("cls");
    printf("\n------------------------- Bienvenue dans TRAM GESTURE --------------------------\n\n");
    printf("-> Pour acceder a l'espace client appuyez sur la touche 1\n\n");
    printf("-> Pour acceder a l'espace administration appuyez sur la touche 2");
    printf("\n\n\n--------------------------------------------------------------------------------\n");
    choix = getch();
    while(choix!='1' && choix!='2')
    {
    printf("\nVeuillez saisir une valeur valable (1 ou 2):\n");
    choix = getch();
    }

    switch(choix)
    {
    case '1':
    client();
    break;

    case '2':
    administration();
    break;
    }
}

