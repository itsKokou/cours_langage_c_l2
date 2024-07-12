/*Ecrire un programme qui permet de tester si deux nombres sont AMIS ou pas. Deux nombres M et
N sont amis si la somme des diviseurs de N excepté 1 et lui-même est égale à M et la somme des diviseurs de M
excepté 1 et lui-même est égale à N.
Exemple : les nombres 48 et 75 sont deux nombres amis puisque :
Les diviseurs de 48 sont : 2, 3, 4, 6, 8, 12, 16, 24  2 + 3 + 4 + 6 + 8 + 12 + 16 + 24 = 75
Les diviseurs de 75 sont : 3, 5, 15, 25  3 + 5 + 15 + 25 = 48.*/
#include<stdio.h>
main()
{
    int n1,n2,i,s1,s2;
    printf("Entrez deux nombres : ");
    scanf("%d %d",&n1,&n2);
    s1=0;
    i=2;
    while(i<=n1/2){
        if(n1%i==0){
            s1+=i;
        }
        i++;
    }
    s2=0;
    i=2;
    while(i<=n2/2){
        if(n2%i==0){
            s2+=i;
        }
        i++;
    }
    if(s1==n2 && s2==n1){
        printf("%d et %d sont amis.",n1,n2);
    }else{
        printf("%d et %d ne sont pas amis.",n1,n2);
    }
}
