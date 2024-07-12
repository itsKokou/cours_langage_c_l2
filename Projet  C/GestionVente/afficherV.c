#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"global.h"

void avantArticle(void){
    printf("POSITION  ");
    printf("ID        ");
    printf("LIBELLE                       ");
    printf("COULEUR        ");
    printf("MARQUE         ");
    printf("PRIX      ");
    puts("STOCK");
}
int menuVente(void){
    fflush(stdin);
    char choix[MAX];
    int choice;
    puts("N.......................VENTE PAR NUMERO ARTICLE");
    puts("L.......................VENTE PAR LIBELLE ARTICLE");
    puts("P.......................VENTE PAR PRIX ARTICLE");
    puts("C.......................VENTE PAR COULEUR ARTICLE");
    puts("V.......................VOIR LE PANIER");
    puts("R.......................RETOUR\n");
    puts("Faites votre choix :");
    scanf("%s",&choix);
    if (strcasecmp(choix,"n")==0){
        choice=1;
    } else {
        if (strcasecmp(choix,"l")==0){
            choice=2;
        } else {
            if (strcasecmp(choix,"p")==0){
                choice=3;
            } else {
                if (strcasecmp(choix,"c")==0){
                    choice=4;
                } else {
                    if (strcasecmp(choix,"v")==0){
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
void afficherArticles(int i){
    int x,y,z;
    x=nombreCharInt(i);
    y=nombreCharInt(t_articles[i].id);
    z=nombreCharInt(t_articles[i].prix);
    printf("%d",i);
    espace(10-x);
    printf("%d",t_articles[i].id);
    espace(10-y);
    afficherLibelle(t_articles[i].libelle);
    espace(30-strlen(t_articles[i].libelle));
    afficherLibelle(t_articles[i].couleur);
    espace(15-strlen(t_articles[i].couleur));
    afficherLibelle(t_articles[i].marque);
    espace(15-strlen(t_articles[i].marque));
    printf("%d",t_articles[i].prix);
    espace(10-z);
    printf("%d",t_articles[i].qt);
    puts("");
    ligne('-',TAILLE);
    puts("");
}
void afficherLibelle(char libelle[]){
    int i,n;
    n=strlen(libelle);
    i=0;
    while(i<n){
        if (libelle[i]=='_'){
            printf(" ");
        } else{
            printf("%c",libelle[i]);
        }
        i++;
    }
}


int detailsArticle(void){
    CLS;
    printf("Details de l'article:");
    ligne('-',100-strlen("Details de l'article:"));
    puts("");
    espace(51-strlen("LIBELLE : "));
    printf("LIBELLE : ");
    afficherLibelle(t_articles[pos].libelle);
    puts("");
    espace(51-strlen("MARQUE : "));
    printf("MARQUE : ");
    afficherLibelle(t_articles[pos].marque);
    puts("");
    espace(51-strlen("COULEUR : "));
    printf("COULEUR : ");
    afficherLibelle(t_articles[pos].couleur);
    puts("");
    espace(51-strlen("PRIX : "));
    printf("PRIX : ");
    printf("%d",t_articles[pos].prix);
    puts("");
    espace(51-strlen("STOCK : "));
    printf("STOCK : ");
    printf("%d",t_articles[pos].qt);
    puts("");
    ligne('-',TAILLE);
    puts("");
    int choix;
    fflush(stdin);
    do{
        puts("Ajouter au panier ? [1 => OUI / 0 => NON]");
        scanf("%d",&choix);
    }while(choix!=0 && choix!=1);
    return choix;
}

int afficherArticlesTrouvesCouleur(char couleur[MAX]){
    int i,n,cpt;
    n=strlen(couleur);
    i=0;
    while (i<n){
        if (couleur[i]==' '){
            couleur[i]='_';
        }
        i++;
    }
    puts("");
    avantArticle();
    ligne('-',TAILLE);
    puts("");
    i=0;
    cpt=0;
    while(i<nbreArticle){
        if(strcasecmp(couleur,t_articles[i].couleur)==0){
            cpt=1;
            afficherArticles(i);
            tab[nbretab++]=i;
        }
        i++;
    }
    if (cpt==0){
        puts("\n\n       LA LISTE EST VIDE!!!\n\n");
    }
    return cpt;
}
int afficherArticlesTrouvesPrix(int prix){
    int i,cpt;
    i=0;
    cpt=0;
    puts("");
    avantArticle();
    ligne('-',TAILLE);
    puts("");
    while(i<nbreArticle){
        if(prix==t_articles[i].prix){
            cpt=1;
            afficherArticles(i);
            tab[nbretab++]=i;
        }
        i++;
    }
    if (cpt==0){
        puts("\n\n       LA LISTE EST VIDE!!!\n\n");
    }
    return cpt;
}
int afficherArticlesTrouvesLibelle(char libelle[]){
    int i,n,cpt=0;
    n=strlen(libelle);
    i=0;
    while (i<n){
        if (libelle[i]==' '){
            libelle[i]='_';
        }
        i++;
    }
    puts("");
    avantArticle();
    ligne('-',TAILLE);
    puts("");
    for(i=0;i<nbreArticle;i++){
        if(strcasecmp(libelle,t_articles[i].libelle)==0){
            afficherArticles(i);
            tab[nbretab++]=i;
            cpt=1;
        }
    }
    if (cpt==0){
        puts("\n\n       LA LISTE EST VIDE!!!\n\n");
    }
    return cpt;
}
int verifierPos(void){
    int i=0, cpt=0;
    puts("Saisir la POSITION de l'article : ");
    scanf("%d",&pos);
    while(i<nbretab){
        if(pos==tab[i]){
            cpt=1;
            break;
        }
        i++;
    }
    if(cpt==0){
        puts("\n\n       Cette position n'existe pas!!! \n\n");
    }
    return cpt;
}
