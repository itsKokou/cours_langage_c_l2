#include<stdio.h>
main()
{
    int nbre,mont;
    do {
        printf("Entrez le nombre de copie : ");
        scanf("%d",&nbre);
    }while(nbre<=0);
    if (nbre<=10){
        mont=nbre*25;
    }else{
        if (nbre<=30){
            mont=10*25+15*(nbre-10);
        }else{
            mont=10*25+15*20+10*(nbre-30);
        }
    }
    printf("Le montant a payer est %d",mont);
}
