#include<stdio.h>
#define MAX 60
int menuVente(void);
main()
{
 int x;
 x=menuVente();
 printf("%d",x);
}
int menuVente(void){
    char choix[MAX];
    int choice;
    puts("N.......................VENTE PAR NUMERO ARTICLE");
    puts("L.......................VENTE PAR LIBELLE ARTICLE");
    puts("P.......................VENTE PAR PRIX ARTICLE");
    puts("C.......................VENTE PAR COULEUR ARTICLE");
    puts("V.......................VOIR LE PANIER");
    puts("R.......................RETOUR\n");
    puts("Faites votre choix :");
    scanf("%c",&choix);
    if (strcasecmp(choix,"N")==0){
        choice=1;
    } else {
        if (strcasecmp(choix,"L")==0){
            choice=2;
        } else {
            if (strcasecmp(choix,"P")==0){
                choice=3;
            } else {
                if (strcasecmp(choix,"C")==0){
                    choice=4;
                } else {
                    if (strcasecmp(choix,"V")==0){
                        choice=5;
                    }else {
                        choice=6;
                    }
                }
            }
        }
    }
    return choice;
}
