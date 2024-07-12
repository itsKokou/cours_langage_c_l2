
#include<stdio.h>
main()
{
    int nbre;
    printf("entrez un entier : ");
    scanf("%d",&nbre);
    printf("%d vient avant %d et %d juste apres \n",(nbre-1),nbre,(nbre+1));
}
