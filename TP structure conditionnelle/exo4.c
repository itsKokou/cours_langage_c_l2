#include<stdio.h>
main()
{
    int a,b;
    printf("Entrez le premier nombre : ");
    scanf("%d",&a);
    printf("Entrez le second nombre : ");
    scanf("%d",&b);
    if (a>0 && b>0 || a<0 && b<0){
        printf("Le produit de %d et %d est positif.",a,b);
    }else{
        if(a>0 && b<0 || a<0 && b>0){
            printf("Le produit de %d et %d est negatif.",a,b);
        }else{
                printf("Le produit de %d et %d est nul.",a,b);
        }
    }


}

