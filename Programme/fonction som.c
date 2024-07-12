// Ecrire un programme qui prend en compte deux entiers.
// la fonction retourne leur somme
#include<stdio.h>
// int somme(int a, int b); (prototype)
int somme(int , int ); // prototype aussi
main()
{
    int a,b;
    puts("Entrez deux entiers : ");
    scanf("%d %d",&a,&b);
    printf("La somme de %d et %d est %d",a,b,somme(a,b));
}
// Implementation
int somme(int x, int y){
    int s;
    s=x+y;
    return s;
}
