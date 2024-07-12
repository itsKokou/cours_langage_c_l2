/* Ecrire un programme qui permet d'insérer les données d'un produit.
Le programme affiche les données du produit. Le produit est caractérisé
par : libelle, prix, quantité*/
#include<stdio.h>
  struct  PRODUIT{
        char libelle[50];
        char marque[80];
        int prix,qte;
    };
main()
{
    struct PRODUIT p;
    printf("Entrez le libelle : ");
    gets(p.libelle);
    do{
        printf("Entrez le prix : ");
        scanf("%d",&p.prix);
    }while(p.prix<=0);
    do{
        printf("Entrez la quantite : ");
        scanf("%d",&p.qte);
    }while(p.qte<=0);
    fflush(stdin);
    puts("Entrez la marque : ");
    gets(p.marque);
    printf(" LIBELLE : %s \n",p.libelle);
    printf(" PRIX : %d \n",p.prix);
    printf(" QUANTITE : %d \n",p.qte);
    printf(" MARQUE : %s",p.marque);

}
