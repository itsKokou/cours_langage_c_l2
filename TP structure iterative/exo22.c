/*Ecrire un programme qui permet d’imiter le jeu : « Plus petit ou plus grand » qui consiste à deviner
un nombre aléatoire compris entre 1 et 100, généré par le programme.*/
#include<stdio.h>
main()
{
    int n,nbre;
    n=68;
    do{
        printf("Devinez un nombre compris entre 1 et 100: ");
        scanf("%d",&nbre);
        if(nbre>n){
            printf("Plus petit !\n");
        }else{
            if(nbre<n){
               printf("Plus grand !\n");
            }
        }
    }while(!(nbre>=n && nbre<=n));
    printf("Bien joué! La reponse convient");
}
