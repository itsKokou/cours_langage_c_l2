/*Ecrire un programme qui permet de saisir un nombre positif N.
le programme détermine et affiche les N premiers nombres premiers.*/
#include<stdio.h>
void main()
{
    int n,i,j,s,nbre;
    do{
        printf("Entrez un nombre positif : ");
        scanf("%d",&n);
    }while(n<=0);
    printf("Les %d premiers nombres premiers sont : \n",n);
    i=1;
    nbre=2;
    while(i<=n){
        j=1;
        s=nbre;
        while(j<=nbre/2){
            if(nbre%j==0){
                s+=j;
            }
            j++;
        }
        if (s==nbre+1){
            printf(" %d \n",nbre);
            nbre+=1;
            i++;
        }else{
            nbre+=1;
        }
    }

}
