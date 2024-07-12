#include<stdio.h>
#include<math.h>
main()
{
    float a,b,c,delta;
    printf("Entrez le coefficient a : ");
    scanf("%f",&a);
    printf("Entrez le coefficient b : ");
    scanf("%f",&b);
    printf("Entrez le coefficient c : ");
    scanf("%f",&c);
    delta=pow(b,2)-4*a*c;
    if  (delta<0){
        printf("Pas de solution reel");
    }else {
        if(delta==0){
            printf("la solution est %f",(-b/(2*a)));
        }else{
            float x,y;
            x= (-b+sqrt(delta))/(2*a);
            y= (-b-sqrt(delta))/(2*a);
            printf("les solutions sont %f et %f",x,y);
        }
    }
}
