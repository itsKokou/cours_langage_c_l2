/* Ecrire un programme qui permet de saisir une suite de N réels, le programme affiche tous les réels
saisis ainsi que leur somme et leur produit.*/
#include<stdio.h>
main()
{
    int n,i;
    float nbre,s,p;
    do{
        printf("Combien de reels voulez-vous saisir ? ");
        scanf("%d",&n);
    }while(n<=0);
    s=0;
    p=1;
    for(i=1;i<=n;i++){
       printf("Entrez une valeur : ");
       scanf("%f",&nbre);
       s+=nbre;
       p*=nbre;
    }
    printf("Leur somme vaut %f et le produit vaut %f",s,p);
}
