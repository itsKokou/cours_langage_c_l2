/*Ecrire un programme qui permet de saisir un entier. Le programme détermine et affiche si le
nombre est un nombre premier ou pas. Un nombre est premier s’il a deux diviseurs : 1 et lui-même*/
#include<stdio.h>
main()
{
    int nbre,i,s;
    printf("Entrez un nombre : ");
    scanf("%d",&nbre);
    s=nbre;
    i=1;
    while(i<=nbre/2){
        if(nbre%i==0){
            s+=i;
        }
        i++;
    }
    if (s==nbre+1){
        printf("%d est premier",nbre);
    }else{
         printf("%d n'est pas premier",nbre);
    }
}
