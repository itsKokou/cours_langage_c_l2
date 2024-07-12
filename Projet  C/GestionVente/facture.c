#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"global.h"

void creerFacture(char nomFichier[]){
    FILE *f = fopen(nomFichier,"w");
    if(f){
        ecrireFacture2(f);
        fclose(f);
    }else{
        puts("ERREUR LORS DE LA CREATION DU FICHIER FACTURE!!!");
    }
}
void nomNumFacture(void){
    heureAvec();
    dateHeure();
    dateAvec();
    strcat(numFacture,"FACT");
    strcat(numFacture,dHeure);
    strcat(nomFacture,numFacture);
    strcat(nomFacture,"_");
    strcat(nomFacture,prenomClient);
    strcat(nomFacture,"_");
    strcat(nomFacture,nomClient);
    strcat(nomFacture,".txt");
}
void ecrireFacture2(FILE *f){
    ligne2('-',TAILLE,f);
    fprintf(f,"\n");
    ligne2('*',TAILLE,f);
    fprintf(f,"\n");
    milieu2("  .GOAT SHOP.  ",'*',TAILLE,f);
    milieu2("  GOLF - GUEDIAWAYE EN FACE H. DALAL JAMM.  ",'*',TAILLE,f);
    milieu2("  (+221) 77 815 90 24  ",'*',TAILLE,f);
    milieu2("  goat-shop@exemple.com  ",'*',TAILLE,f);
    ligne2('*',TAILLE,f);
    fprintf(f,"\n");
    ligne2('-',TAILLE,f);
    fprintf(f,"\n");
    fprintf(f,"Information du CLIENT");
    ligne2('-',TAILLE-strlen("Information du CLIENT"),f);
    fprintf(f,"\n");
    fprintf(f,"Nom       : %s\n",nomClient);
    fprintf(f,"Prenom    : %s\n",prenomClient);
    fprintf(f,"Telephone : %d\n",numeroClient);
    ligne2('-',TAILLE,f);
    fprintf(f,"\nFACTURE N : %s",numFacture);
    ligne2('-',TAILLE-(strlen("FACTURE N : ")+strlen(numFacture)),f);
    fprintf(f,"\n");
    ligne2('-',TAILLE,f);
    fprintf(f,"\nARTICLE");
    espace2(30-strlen("ARTICLE"),f);
    fprintf(f,"MARQUE");
    espace2(15-strlen("MARQUE"),f);
    fprintf(f,"COULEUR");
    espace2(15-strlen("COULEUR"),f);
    fprintf(f,"PRIX");
    espace2(15-strlen("PRIX"),f);
    fprintf(f,"QTE");
    espace2(10-strlen("QTE"),f);
    fprintf(f,"TOTAL\n");
    ligne2('-',TAILLE,f);
    fprintf(f,"\n");
    int i=0,p;
    while (i<nbrePanier){
        p=t_panier[i].position;
        afficherLibelle2(t_articles[p].libelle,f);
        espace2(30-strlen(t_articles[p].libelle),f);
        afficherLibelle2(t_articles[p].marque,f);
        espace2(15-strlen(t_articles[p].marque),f);
        afficherLibelle2(t_articles[p].couleur,f);
        espace2(15-strlen(t_articles[p].couleur),f);
        fprintf(f,"%d",t_articles[p].prix);
        espace2(15-nombreCharInt(t_articles[p].prix),f);
        fprintf(f,"%d",t_panier[i].qte);
        espace2(10-nombreCharInt(t_panier[i].qte),f);
        fprintf(f,"%d\n",t_panier[i].total);
        i++;
        ligne2('-',TAILLE,f);
        fprintf(f,"\n");
    }
    netAPayer2('-',f);
    ligne2('*',TAILLE,f);
    fprintf(f,"\nCAISSIER : ");
    afficherLibelle2(connectedUser.prenom,f);
    fprintf(f," ");
    afficherLibelle2(connectedUser.nom,f);
    fprintf(f,"\n");
    ligne2('*',TAILLE-strlen("  MERCI ET A BIENTOT :)"),f);
    fprintf(f,"  MERCI ET A BIENTOT :)");
}

int nombreCharInt2(int x){
    int n=0;
    do{
        n++;
        x/=10;
    } while(x!=0);
    return n;
}
void afficherLibelle2(char libelle[], FILE *f){
    int i,n;
    n=strlen(libelle);
    i=0;
    while(i<n){
        if (libelle[i]=='_'){
            fprintf(f," ");
        } else{
            fprintf(f,"%c",libelle[i]);
        }
        i++;
    }
}
void ligne2(char motif,int taille, FILE *f){
    int i;
    for(i=0;i<taille;i++){
        fprintf(f,"%c",motif);
    }
}
void espace2(int nbre, FILE *f){
    int i;
    for (i=1;i<=nbre;i++){
        fprintf(f," ");
    }
}
void milieu2(char msg[], char motif, int taille, FILE *f){
    int tailleMsg = strlen(msg);
    int reste = taille - tailleMsg;
    int nbreCar = reste/2;
    ligne2(motif,nbreCar,f);
    fprintf(f,"%s",msg);
    if(reste%2 == 1){
        ligne2(motif,nbreCar+1,f);
    }else{
        ligne2(motif,nbreCar,f);
    }
    fprintf(f,"\n");
}
void netAPayer2(char motif, FILE *f){
    ligne2(motif,TAILLE,f);
    fprintf(f,"\n");
    espace2(90-strlen("NET A PAYER:"),f);
    fprintf(f,"NET A PAYER:");
    espace2(10-nombreCharInt(montantNet),f);
    fprintf(f,"%d\n",montantNet);
    ligne2(motif,TAILLE,f);
    fprintf(f,"\n");
}
