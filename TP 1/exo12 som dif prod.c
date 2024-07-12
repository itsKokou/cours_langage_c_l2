#include<stdio.h>
main()
{
    float x,y;
    printf("Entrez le premier nombre : ");
    scanf("%f",&x);
    printf("Entrez le second nombre : ");
    scanf("%f",&y);
    printf("La somme de %f et %f est %f \n",x,y,(x+y));
    printf("La difference de %f et %f est %f \n",x,y,(x-y));
    printf("La produit de %f et %f est %f \n",x,y,(x*y));
}
