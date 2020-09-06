#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct {
	char nom[50];
   long cne;
   float note[3];
   }etudiant;

//**********menu***************
char menuprincipal()
{
char c;
fflush(stdin);// libérer de la mémoire tampon
printf("\n\n----------------------MENU PRINCIPAL------------------------\n");
printf("a>                   Ajouter un nouvel etudiant.\n");
printf("b>                   Lister les etudiants.\n");
printf("c>                   Modifier.\n");
printf("q>                   Quitter.\n");
printf("-----------------------------------------------------------------\n");
printf("Saisissez votre choix: ");
scanf("%c",&c);
return(c);
}
//**********programmes**********************
void afficher(etudiant e)
{
 	printf("Nom : %s\n",e.nom);
   printf("cne : %ld \n",e.cne);
   printf("note physique: %f \n\n", e.note[0]);
   printf("note math:  %f \n\n", e.note[1]);
   printf("note chimie: %f \n\n", e.note[2]);
}
//*******chercher********
int cherchercne(etudiant *e,int n,long numero)
{
	int i;
 	for(i=0;i<n;i++)
  	if(e[i].cne == numero)
  	return(i);
 	return(-1);
}
//**********saisir etudiant****************
void saisir(etudiant e[] , int n)
{
   printf("donner le nom de l'etudiant : ");
   fflush(stdin);
   gets(e[n].nom);
   printf("donner CNE : ");
   scanf("%ld",&e[n].cne);
   while(cherchercne(e,n,e[n].cne) != -1)
        {
        printf("Ce cne existe deja.. : ");
		  scanf("%ld",&e[n].cne);
        }
   printf("donner la note :  physique \n");
   scanf("%f",&e[n].note[0]);
   printf("donner la note : math \n");
   scanf("%f",&e[n].note[1]);
   printf("donner la note : chimie \n");
   scanf("%f",&e[n].note[2]);
}
//******lister************
void lister(etudiant e[] , int n)
{
	for(int i=0; i<n; i++)
   	afficher(e[i]);
}
//*******************modifier******************
void modifier(etudiant e[] ,int n)
{
    printf("donner la note :  physique \n");
   scanf("%f",&e[n].note[0]);
   printf("donner la note : maths \n");
   scanf("%f",&e[n].note[1]);
   printf("donner la note : chimie \n");
   scanf("%f",&e[n].note[2]);
}
//*********************main()******************
main()
{
etudiant b[100];
int nbr=0,cne,i;
char YN;
debut:

char choix;
choix = menuprincipal();
while (choix != 'q')
{

	switch (choix) {
   case 'a' :
   			printf("-ajouter un etudiant\n\n");
            saisir(b,nbr);
            nbr+=1;
            break;

   case 'b' :
   			printf("-Liste des  etudiants\n\n");
            lister(b,nbr);
            printf("-> Menu Principal");
            getch();
            break;

     case 'c' :
   			printf("-modification\n\n");
   			fflush(stdin);
            printf("Donner le cne de l'etudiant : ");
            scanf("%d",&cne);
            modifier(b,i);
            break;


       }
choix = menuprincipal();
}

              fflush(stdin);
              printf("Voulez vous vraiment quitter (y/n)");
              scanf("%c",&YN);
              if(YN=='y')
                exit(0);
                else
                 goto debut;
                 return 0;


}
