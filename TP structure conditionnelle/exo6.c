#include<stdio.h>
main()
{
    int a,b,c,min,max,moy;
    printf("Entrez la premiere valeur : ");
    scanf("%d",&a);
    printf("Entrez la deuxieme valeur : ");
    scanf("%d",&b);
    if (b>a){
        max=b;
        min=a;
    }else {
        max=a;
        min=b;
    }
    printf("Entrez la troisieme valeur : ");
    scanf("%d",&c);
    if(c>max){
        moy=max;
        max=c;
    }else{
        if(c>min){
            moy=c;
        }else{
            moy=min;
            min=c;
        }
    }
    printf("la valeur maximale est %d\n",max);
    printf("la valeur moyenne est %d\n",moy);
    printf("la valeur minimale est %d\n",min);
}
