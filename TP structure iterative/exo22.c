/*Ecrire un programme qui permet d�imiter le jeu : � Plus petit ou plus grand � qui consiste � deviner
un nombre al�atoire compris entre 1 et 100, g�n�r� par le programme.*/
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
    printf("Bien jou�! La reponse convient");
}
