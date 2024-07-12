#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"global.h"

void avantEtatCaisse(void){
    printf("%-50s"," ");
    printf("%-15s","DATE");
    printf("%-15s","HEURE");
    printf("MONTANT VENDU\n");
    ligne('-',TAILLE);
    puts("");
}
int rechercheDate(char date[MAX],int p){
    int i;
    for (i=0;i<p;i++){
        if (strcasecmp(date,t2_ventes[i].date)==0){
            return 1;
        }
    }
    return 0;
}
void afficherEtatCaisse(void){
    int i,j,montant;
    for (i=0;i<nbre2Vente;i++){
        montant= t2_ventes[i].montant;
        for (j=i+1;j<nbre2Vente;j++){
            if (strcasecmp(t2_ventes[i].date,t2_ventes[j].date)==0){
                montant+=t2_ventes[j].montant;
            }
        }
        if (rechercheDate(t2_ventes[i].date,i)==0){
            printf("%50s %-15s %-15s %d\n"," ",t2_ventes[i].date,t2_ventes[i].heure,montant);
            ligne('-',TAILLE);
            puts("");
        }
    }
}
void avantVentes(void){
    printf("%-50s","POSITION");
    printf("%-15s","DATE");
    printf("%-15s","HEURE");
    printf("MONTANT\n");
    ligne('-',TAILLE);
    puts("");
}
void afficherVentes(char date[MAX]){
   int i;
   for (i=0;i<nbre2Vente;i++){
        if (strcasecmp(date,t2_ventes[i].date)==0){
            printf("%-50d",i);
            printf("%-15s",t2_ventes[i].date);
            printf("%-15s",t2_ventes[i].heure);
            printf("%d\n",t2_ventes[i].montant);
            ligne('-',TAILLE);
            puts("");
            tab2[nbretab2++]=i;
        }
   }
}
void lireFichier(char nom[MAX]){
    FILE *f;
    char c;
    f=fopen(nom,"rt");
    if(f){
        while((c=fgetc(f))!=EOF){
            printf("%c",c);
        }
        fclose(f);
    }else{
        puts("\n\n FACTURE NON TROUVEE\n\n");
    }
}
void chargerVente2(void){
    int i;
    if (connectedUser.role==1){
        for (i=0;i<nbreVente;i++){
            t2_ventes[i]=t_ventes[i];
        }
        nbre2Vente=nbreVente;
    }else {
        for (i=0;i<nbreVente;i++){
            if (connectedUser.id==t_ventes[i].iduser){
                t2_ventes[nbre2Vente++]=t_ventes[i];
            }
        }
    }
}
int checkTab2(int x){
    int i=0, cpt=0;
    while(i<nbretab2){
        if(x==tab2[i]){
            cpt=1;
            break;
        }
        i++;
    }
    return cpt;
}
