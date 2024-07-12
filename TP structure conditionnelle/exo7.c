#include<stdio.h>
main()
{
    float a,b;
    printf("Entrez le coefficient a : ");
    scanf("%f",&a);
    printf("Entrez le coefficient b : ");
    scanf("%f",&b);
    if (a!=0){
        printf("la solution de l'equation %fx + %f =0 est %f",a,b,(-b/a));
    }else{
        printf("impossible");
    }
}
