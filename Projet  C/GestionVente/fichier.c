#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"global.h"

void chargerFichierVentes(void){
    VENTE v;
    FILE *p = fopen(FICHIER_VENTES,"r");
    if (p){
        while (!feof(p)){
            fscanf(p,"%s %s %s %d %d",v.date,v.heure,v.nomFact,&v.montant,&v.iduser);
            t_ventes[nbreVente++]=v;
        }
        fclose(p);
    } else {
        printf("Aucun fichier  Ventes !");
    }
}
void uploadFichierVente(void){
    FILE *f = fopen(FICHIER_VENTES,"w");
    int i;
    if(f){

        for (i = 0; i < nbreVente; i++){
            if(i==0){
                fprintf(f,"%s %s %s %d %d",t_ventes[i].date,t_ventes[i].heure,t_ventes[i].nomFact,t_ventes[i].montant,t_ventes[i].iduser);
            }else{
                fprintf(f,"\n%s %s %s %d %d",t_ventes[i].date,t_ventes[i].heure,t_ventes[i].nomFact,t_ventes[i].montant,t_ventes[i].iduser);
            }
        }
        fclose(f);
    }
}
void chargerFichierUsers (void){
    USER u; // variable utilisateur
    FILE *f = fopen(FICHIER_USERS,"r");
    if(f){
        while(!feof(f)){
            fscanf(f,"%d %s %s %s %s %d %d",&u.id,&u.nom,&u.prenom,&u.login,&u.password,&u.role,&u.etat);
            t_users[nbreUser++]=u; //mettre l'utilisateur dans le tableau
        }
        fclose(f);
    }else {
        printf("Aucun fichier utilisateur !");
    }
}
void uploadFichierUsers(void){
    FILE *f = fopen(FICHIER_USERS,"w");
    int i;
    if(f){
        for (i = 0; i < nbreUser; i++){
            if(i==0){
                fprintf(f,"%d %s %s %s %s %d %d",t_users[i].id,t_users[i].nom,t_users[i].prenom,
                    t_users[i].login,t_users[i].password,t_users[i].role,t_users[i].etat);
            }else{
                fprintf(f,"\n%d %s %s %s %s %d %d",t_users[i].id,t_users[i].nom,t_users[i].prenom,
                    t_users[i].login,t_users[i].password,t_users[i].role,t_users[i].etat);
            }
        }
        fclose(f);
    }
}
void chargerFichierArticles(void){
    ARTICLE ar; // variable fichier
    FILE *p = fopen(FICHIER_ARTICLES,"r");
    if (p){
        while (!feof(p)){
            fscanf(p,"%d %s %s %s %d %d",&ar.id,ar.libelle,ar.couleur,ar.marque,&ar.prix,&ar.qt);
            t_articles[nbreArticle++]=ar; // on met dans tableau des articles puis incrémentation
        }
        fclose(p);
    } else {
        printf("Aucun fichier  articles !");
    }
}
void uploadFichierArticles(void){
    FILE *f = fopen(FICHIER_ARTICLES,"w");
    int i;
    if(f){
        for (i = 0; i < nbreArticle; i++){
            if(i==0){
                fprintf(f,"%d %s %s %s %d %d",t_articles[i].id,t_articles[i].libelle,
                    t_articles[i].couleur,t_articles[i].marque,t_articles[i].prix,t_articles[i].qt);
            }else{
                fprintf(f,"\n%d %s %s %s %d %d",t_articles[i].id,t_articles[i].libelle,
                    t_articles[i].couleur,t_articles[i].marque,t_articles[i].prix,t_articles[i].qt);
            }
        }
        fclose(f);
    }
}
