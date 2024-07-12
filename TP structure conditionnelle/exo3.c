#include<stdio.h>
main()
{
    int nbre;
    printf("Entrez un nombre : ");
    scanf("%d",&nbre);
    if (nbre<0){
        printf("la valeur absolue de %d est %d",nbre,-nbre);
    }else {
        printf("la valeur absolue de %d est %d",nbre,nbre);
    }
}


