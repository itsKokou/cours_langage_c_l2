// faire une fonction qui saisit une date et la retourne
#include<stdio.h>
typedef struct{
    int j,m,a;
}DATE;

DATE saisirDate(void){
    DATE d;
    do{
        puts("Entrez une date : ");
        scanf("%d %d %d",&d.j,&d.m,&d.a);
    }while(d.j<1 || d.j>31 ||d.m<1 || d.m>12 || d.a<1);
    return d;
}
void afficherDate(DATE d){
    printf("La date est : %d/%d/%d",d.j,d.m,d.a);
}
main()
{
   afficherDate(saisirDate());
}
