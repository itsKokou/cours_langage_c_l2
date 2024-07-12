#include<stdio.h>
main()
{
    float r1,r2,r3,req;
    do{
        printf("Entrez la valeur de la reistance R1 : ");
        scanf("%f",&r1);
    }while(r1<=0);
     do{
        printf("Entrez la valeur de la reistance R2 : ");
        scanf("%f",&r2);
    }while(r2<=0);
     do{
        printf("Entrez la valeur de la reistance R3 : ");
        scanf("%f",&r3);
    }while(r3<=0);
    printf("La resistance equivalente en serie vaut %f\n",(r1+r2+r3));
    req= ((r1*r2*r3)/(r1*r2+r2*r3+r1*r3));
    printf("La resistance equivalente en parallele vaut %f",req);
}
