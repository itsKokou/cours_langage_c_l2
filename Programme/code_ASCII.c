// Ecrire un programme qui donne le code ASCII du caractere saisi
#include<stdio.h>
main()
{
   char x;
   printf("appuyez sur un caractere : ");
   scanf("%c",&x);
   printf("Le code ASCII de %c est %d",x,x); // Pour afficher on utilise le code format d'un entier pour afficher le caractere
/*
   int c
   printf("Entrez le code ASCII : ");
   scanf("%d",&x);
   printf("Le code ASCII %d correspond au caractere %c",x,x);
*/
}
