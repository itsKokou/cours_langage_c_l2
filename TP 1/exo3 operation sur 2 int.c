#include<stdio.h>
main()
{
    int x,y;
    printf("Entrez le premier entier : ");
    scanf("%d",&x);
    printf("Entrez le second entier : ");
    scanf("%d",&y);
    printf("Le quotient entier de %d par %d est : %d\n",x,y,x/y);
    printf("le reste de la division de %d par %d est : %d\n",x,y,x%y);
    float t=x;
    printf("le quotient reel de %d par %d est : %f\n",x,y,t/y);

}
