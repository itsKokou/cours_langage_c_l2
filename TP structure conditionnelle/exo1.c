#include<stdio.h>
main()
{
    int nbre;
    printf("Entrez un nombre : ");
    scanf("%d",&nbre);
    if (nbre>0){
        printf("%d est positif.",nbre);
    }else {
        printf("%d est negatif.",nbre);
    }
}
