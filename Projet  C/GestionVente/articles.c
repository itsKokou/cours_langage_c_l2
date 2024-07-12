#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"global.h"

char menuArticle(void){
    char choix;
    puts("1................................VOIR ARTICLES");
    puts("2................................MODIFIER STOCK");
    puts("3................................MODIFIER PRIX");
    puts("4................................AJOUTER ARTICLES");
    puts("5................................RETOUR\n");
    puts("Faites votre choix : ");
    scanf("%c",&choix);
    return choix;
}
void detailsProduct(int x){
    CLS;
    printf("Details de l'article:");
    ligne('-',100-strlen("Details de l'article:"));
    puts("");
    espace(51-strlen("LIBELLE : "));
    printf("LIBELLE : ");
    afficherLibelle(t_articles[x].libelle);
    puts("");
    espace(51-strlen("MARQUE : "));
    printf("MARQUE : ");
    afficherLibelle(t_articles[x].marque);
    puts("");
    espace(51-strlen("COULEUR : "));
    printf("COULEUR : ");
    afficherLibelle(t_articles[x].couleur);
    puts("");
    espace(51-strlen("PRIX : "));
    printf("PRIX : ");
    printf("%d",t_articles[x].prix);
    puts("");
    espace(51-strlen("STOCK : "));
    printf("STOCK : ");
    printf("%d",t_articles[x].qt);
    puts("");
    ligne('-',TAILLE);
    puts("");
}
void modifierStock(void){
    int p,n,c;
    do{
        puts("Entrez la position :");
        scanf("%d",&p);
    }while(p<0 || p>=nbreArticle);
    CLS;
    detailsProduct(p);
    do{
        puts("Entrez le nouveau STOCK :");
        scanf("%d",&n);
    }while(n<=0);
    do{
        puts("Confirmer ? [1 => OUI / 0 => NON]");
        scanf("%d",&c);
    }while(c!=0 && c!=1);
    CLS;
    if(c==1){
        t_articles[p].qt=n;
        uploadFichierArticles();
        puts("\n\n     STOCK MODIFIE AVEC SUCCES!!!\n\n");
    }else{
        puts("\n\n     MODIFICATION DE STOCK ANNULEE!!!\n\n");
    }
}
void modifierPrix(void){
    int p,n,c;
    do{
        puts("Entrez la position :");
        scanf("%d",&p);
    }while(p<0 || p>=nbreArticle);
    CLS;
    detailsProduct(p);
    do{
        puts("Entrez le nouveau PRIX :");
        scanf("%d",&n);
    }while(n<500);
    do{
        puts("Confirmer ? [1 => OUI / 0 => NON]");
        scanf("%d",&c);
    }while(c!=0 && c!=1);
    CLS;
    if(c==1){
        t_articles[p].prix=n;
        uploadFichierArticles();
        puts("\n\n     PRIX MODIFIE AVEC SUCCES!!!\n\n");
    }else{
       puts("\n\n      MODIFICATION DE PRIX ANNULEE!!!\n\n");
    }
}
void ajouterArticle(void){
    ARTICLE a;
    int c;
    fflush(stdin);
    a.id=t_articles[nbreArticle-1].id+1;
    puts("Entrez le LIBELLE :");
    gets(a.libelle);
    saisiPrenom(a.libelle);
    puts("Entrez la MARQUE :");
    gets(a.marque);
    saisiPrenom(a.marque);
    puts("Entrez la COULEUR :");
    gets(a.couleur);
    saisiPrenom(a.couleur);
    do{
        puts("Entrez le PRIX :");
        scanf("%d",&a.prix);
    }while(a.prix<=500);
    do{
        puts("Entrez le STOCK :");
        scanf("%d",&a.qt);
    }while(a.qt<=0);
    do{
        puts("Confirmer l'ajout de cet article ? [1 => OUI / 0 => NON]");
        scanf("%d",&c);
    }while(c!=0 && c!=1);
    CLS;
    if (c==1){
        t_articles[nbreArticle++]=a;
        uploadFichierArticles();
        puts("\n\n     ARTICLE AJOUTE AVEC SUCCES!!!\n\n");
    }else{
        puts("\n\n     AJOUT D'UTILISATEUR ANNULE !!!\n\n");
    }

}
void afficherCompletArticle(char ch[]){
    CLS;
    entete('*');
    ligne('-',TAILLE);
    puts("");
    avantArticle();
    ligne('-',TAILLE);
    puts("");
    int i;
    for(i=0;i<nbreArticle;i++){
        afficherArticles(i);
    }
    titre(ch,'+',TAILLE);
    printf("\n");
}
