#include<stdio.h>
#include<math.h>
main()
{
    const float PI = 3.14;
    float r;
    printf("Entrez le rayon du cercle : ");
    scanf("%f",&r);
    printf("le perimetre de ce cercle vaut : %f\n",2*r*PI);
    printf("La surface de ce cercle est : %f\n",r*r*PI);
}
