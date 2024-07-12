/*Ecrire un programme qui demande un nombre de départ, et qui ensuite affiche les dix nombres
suivants. Exemple : si l’utilisateur saisi 4, le programme affichera les nombres de 5 à 14. */
#include<stdio.h>
main()
{
    int nbre,i;
    printf("Entrez un nombre de depart : ");
    scanf("%d",&nbre);
    for(i=1;i<=10;i++){
        printf("%d ",nbre+i);
    }
}
