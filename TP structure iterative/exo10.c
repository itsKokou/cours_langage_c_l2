/* Ecrire un programme qui permet de saisir une suite de N nombres. Le programme détermine et
affiche le plus grand des nombres saisis.*/
#include<stdio.h>
main()
{
    int n,i;
    float max,nbre;
    do{
        printf("Combien de nombres voulez-vous saisir ?\n");
        scanf("%d",&n);
    }while(n<=0);
    i=1;
    max=0;
    while(i<=n){
        printf("Entrez un nombre : ");
        scanf("%f",&nbre);
        if (nbre>max){
            max=nbre;
        }
        i++;
    }
    printf("Le plus grand nombre saisi est %f",max);
}
