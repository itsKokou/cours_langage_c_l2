/*Ecrire un programme qui permet de saisir un entier. Le programme détermine et affiche le factoriel
de l’entier saisi. */
#include<stdio.h>
main()
{
    int n,i,p;
    do{
        printf("Entrez un entier : ");
        scanf("%d",&n);
    }while(n<=0);
    p=1;
    i=1;
    while(i<=n){
        p=p*i;
        i=i+1;
    }
    printf("le factoriel de %d est %d",n,p);
}
