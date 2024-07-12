#include<stdio.h>
#include<math.h>
main()
{
    float x1,x2,y1,y2,dist;
    printf(" Entrez les coordonnees x1 et y1 de A : ");
    scanf("%f %f",&x1,&y1);
    printf(" Entrez les coordonnees x2 et y2 de B : ");
    scanf("%f %f",&x2,&y2);
    dist= sqrt(pow((x1-x2),2)-pow((y1-y2),2));
    printf("La distance entre A et B est %f",dist);
}
