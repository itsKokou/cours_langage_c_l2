/*Ecrire un programme qui demande � l�utilisateur un nombre entier compris entre 1 et 5 jusqu�� ce
que la r�ponse convienne.*/
#include<stdio.h>
main()
{
    int nbre,i;
    do{
        printf("Entrez un entier compris entre 1 et 5: ");
        scanf("%d",&nbre);
    }while(!(nbre>=1 && nbre<=5));
    printf("La reponse convient");
}
