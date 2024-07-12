/*Ecrire un programme qui permet de saisir une série de nombre. Le programme détermine et
affiche tous les nombre saisie ainsi que leur somme et leur produit. La saisie s’arrête lorsque l’utilisateur entre la
valeur 0.*/
#include<stdio.h>
main()
{
    int nbre,s,p;
    s=0;
    p=1;
    do{
        printf("Entrez un nombre : ");
        scanf("%d",&nbre);
        if (nbre!=0){
           s+=nbre;
           p*=nbre;
           printf("Vous avez saisi %d.\n",nbre);
        }
    }while(nbre!=0);
    printf("La somme vaut %d et le produit vaut %d",s,p);
}
