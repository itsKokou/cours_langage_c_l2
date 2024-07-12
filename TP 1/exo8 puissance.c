#include<stdio.h>
#include<math.h>
main()
{
   int n;
   float x,puis;
   printf("Entrez la valeur du reel x : ");
   scanf("%f",&x);
   printf("Entre la valeur de l'entier n : ");
   scanf("%d",&n);
   puis=pow(x,n);
   printf("%f puissance %d vaut %f",x,n,puis);
}
