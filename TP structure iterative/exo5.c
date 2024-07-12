/*  Ecrire un programme qui permet de saisir un entier N positif. Le programme détermine et affiche les
tous les nombre pairs compris entre 1 et nombre saisi.*/
#include<stdio.h>
main()
{
    int n,i;
    do{
        printf("Entrez un entier positif : ");
        scanf("%d",&n);
    }while(n<=0);
    for(i=1;i<=n;i++){
        if(i%2==0){
            printf("%d est pair\n",i);
        }
    }
}
