#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <ctype.h>
#include <stdbool.h>
#include"global.h"

void gestionStock(void){
    int i=0,p;
    while(i<nbrePanier){
        p=t_panier[i].position;
        t_articles[p].qt=t_articles[p].qt-t_panier[i].qte;
        i++;
    }
}
void chargerVente(void){
    t_ventes[nbreVente].iduser=connectedUser.id;
    strcat(t_ventes[nbreVente].nomFact,nomFacture);
    strcat(t_ventes[nbreVente].date,dateA);
    strcat(t_ventes[nbreVente].heure,heureA);
    t_ventes[nbreVente].montant=montantNet;
    nbreVente++;
}

void avantPanier(void){
    printf("  POSITION");
    espace(26-strlen("LIBELLE"));
    printf("LIBELLE");
    espace(17-strlen("MARQUE"));
    printf("MARQUE");
    espace(17-strlen("COULEUR"));
    printf("COULEUR");
    espace(10-strlen("PRIX"));
    printf("PRIX");
    espace(10-strlen("QUANTITE"));
    printf("QUANTITE");
    espace(10-strlen("TOTAL"));
    puts("TOTAL");
}
void netAPayer(char motif){
    ligne(motif,TAILLE);
    puts("");
    espace(90-strlen("NET A PAYER:"));
    printf("NET A PAYER:");
    espace(10-nombreCharInt(montantNet));
    printf("%d\n",montantNet);
    ligne(motif,TAILLE);
    puts("");
}
void afficherPanier(void){
    int i,p;
    for(i=0;i<nbrePanier;i++){
        p=t_panier[i].position;
        espace(10-nombreCharInt(p));
        printf("%d",t_panier[i].position);
        espace(26-strlen(t_articles[p].libelle));
        afficherLibelle(t_articles[p].libelle);
        espace(17-strlen(t_articles[p].marque));
        afficherLibelle(t_articles[p].marque);
        espace(17-strlen(t_articles[p].couleur));
        afficherLibelle(t_articles[p].couleur);
        espace(10-nombreCharInt(t_articles[p].prix));
        printf("%d",t_articles[p].prix);
        espace(10-nombreCharInt(t_panier[i].qte));
        printf("%d",t_panier[i].qte);
        espace(10-nombreCharInt(t_panier[i].total));
        printf("%d",t_panier[i].total);
        puts("");
        ligne('-',TAILLE);
        puts("");
    }
    netAPayer('=');
}
void chargerPanier(int x){
    int c;
    c= rechercheArticle(x);
    if (c==0){
        t_panier[nbrePanier].position=x;
        t_panier[nbrePanier].qte=qte;
        t_panier[nbrePanier].total= qte*t_articles[x].prix;
        montantNet+=t_panier[nbrePanier].total;
        nbrePanier++;
    } else{
        t_panier[x].qte+=qte;
        t_panier[x].total+=qte*t_articles[x].prix;
        montantNet+=qte*t_articles[x].prix;
    }

}
int rechercheArticle(int p){
    int i=0,cpt=0;
    while (i<nbrePanier){
        if(t_panier[i].position==p){
            cpt=1;
            break;
        }
        i++;
    }
    return cpt;
}

void saisirClient(char msg[],char nom[]){
    bool isCorrect;
    int length;
    do{
        printf("%s du Client ? \n",msg);
        gets(nom);
        isCorrect = true;
        length = strlen( nom );
        for( int i=0; i<length; i++ ) {
            if ( isalpha( nom[i] ) == false) {
                isCorrect = false;
            }
        }
        if(length<2){
            isCorrect=false;
        }
    }while(!isCorrect);
}

void informationsClient(void){
    fflush(stdin);
    saisirClient("Prenom",prenomClient);
    saisirClient("Nom",nomClient);
    int n;
    do{
        puts("Telephone du Client ?");
        scanf("%d",&numeroClient);
        n=numeroClient/10000000;
    }while(!(nombreCharInt(numeroClient)==9 && (n==77 || n==78 || n==76 || n==75 || n==70)));
}
