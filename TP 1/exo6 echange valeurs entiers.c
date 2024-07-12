#include<stdio.h>
main()
{
    int a,b,c;
    printf("Entrez la valeur de a : ");
    scanf("%d",&a);
    printf("Entrez la valeur de b : ");
    scanf("%d",&b);
    c=a;
    a=b;
    b=c;
    printf("on a donc a = %d et b = %d",a,b);
}
