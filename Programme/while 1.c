// Ecrire un programme qui permet de saisir n entiers positifs, le programme calcule et affiche leur somme.
#include<stdio.h>
main()
{
    int s,i,n,nbre;
    do{
        printf("Entrez le nombre d'entiers à saisir : ");
        scanf("%d",&n);
    }while(n<=0);
    i=1;
    s=0;
    while(i<=n){
        do{
            printf("Entrez un entier positif : ");
            scanf("%d",&nbre);
       }while(nbre<=0);
       s+=nbre;
        i++;
    }
    printf("La somme de ces entiers vaut : %d",s);
}
