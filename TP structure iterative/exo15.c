/*Ecrire un programme qui permet de saisir un nombre positif N. le programme détermine et affiche
tous les nombre premiers et/ou parfaits compris entre un N.*/
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
            printf("%d ==> premier; ",j);
        }else{
            printf("%d ==> pas premier; ",j);
        }
        s=0;
        i=1;
        while(i<=j/2){
           if(j%i==0){
              s+=i;
           }
           i++;
        }
        if (s==j){
            printf("parfait\n",j);
        }else{
            printf("pas parfait\n",j);
        }

     }
}
