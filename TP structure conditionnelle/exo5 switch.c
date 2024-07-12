#include<stdio.h>
main()
{
    int nbre;
    printf("Entrez un nombre : ");
    scanf("%d",&nbre);
    switch(nbre){
    case 0 :
        printf("nul");
        break;
    case 1 :
    case 2 :
        printf("Petit");
        break;
    case 3 :
        printf("Moyen");
        break;
    case 4 :
    case 5 :
        printf("Grand");
        break;
    default :
        printf("Hors norme");
        break;
    }
}
