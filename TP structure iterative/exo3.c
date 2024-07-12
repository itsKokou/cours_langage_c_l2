/* Ecrire un programme qui permet de saisir un entier, le programme détermine et affiche la somme
des entiers compris entre 1 à ce nombre.*/
#include<stdio.h>
main()
{
    int n,i,s;
    do{
        printf("Saisir un nombre : ");
        scanf("%d",&n);
    }while(n<=0);
    i=1;
    s=0;
    while(i<=n){
       s=i+s;
       i=i+1;
    }
    printf("La somme vaut %d.",s);
}
