/*Ecrire un programme qui permet de saisir un nombre positif N. le programme détermine et affiche
tous les nombre premiers compris entre un N.*/
#include<stdio.h>
main()
{
     int n,i,j,s;
     do{
        printf("Entrez un nombre positif : ");
        scanf("%d",&n);
     }while(n<=0);
     for(j=1;j<=n;j++){
        s=j;
        i=1;
        while(i<=j/2){
           if(j%i==0){
              s+=i;
           }
           i++;
        }
        if (s==j+1){
            printf("%d est premier\n",j);
        }else{
            printf("%d n'est pas premier\n",j);
        }
     }
}
