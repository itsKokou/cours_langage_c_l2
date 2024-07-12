#include<stdio.h>
main()
{
    float prix;
    int nbre;
    const float TVA=0.18;
    do{
        printf("Entrez le prix de l'article : ");
        scanf("%f",&prix);
    }while(prix<=0);

    do{
        printf("Entrez le nombre d'articles : ");
        scanf("%d",&nbre);
    }while(nbre<=0);
    printf("Le prix total TTC est : %f",prix*TVA*nbre);
}
