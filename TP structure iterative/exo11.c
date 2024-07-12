/*  Ecrire un programme qui permet de saisir une suite de N nombres. Le programme détermine et
affiche le plus grand et le plus petit de la série.*/
#include<stdio.h>
main()
{
    int n,i;
    float maxi,mini,nbre;
    do{
        printf("Combien de nombres voulez-vous saisir ?\n");
        scanf("%d",&n);
    }while(n<=0);
    i=1;
    maxi=0;
    mini=0;
    while(i<=n){
        printf("Entrez un nombre : ");
        scanf("%f",&nbre);
        if (nbre>maxi){
            maxi=nbre;
        }
        if (nbre<mini){
            mini=nbre;
        }
        i++;
    }
    printf("Le plus grand nombre saisi est %f et le plus petit est %f",maxi,mini);
}
