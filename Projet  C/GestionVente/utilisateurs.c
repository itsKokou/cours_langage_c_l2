#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <ctype.h>
#include <stdbool.h>
#include"global.h"

char menuUser(void){
    char choix;
    puts("1................................VOIR UTILISATEURS");
    puts("2................................AJOUTER UN UTILISATEUR");
    puts("3................................BLOQUER/DEBLOQUER UN UTILISATEUR");
    puts("4................................CHANGER ROLE DE UTILISATEUR");
    puts("5................................CHANGER PASSWORD DE UTILISATEUR");
    puts("6................................RETOUR\n");
    puts("Faites votre choix : ");
    scanf("%c",&choix);
    return choix;
}
void afficherRole(int x){
    if (x==1){
        printf("ADMIN");
        espace(10-strlen("ADMIN"));
    }else {
        printf("CAISSIER");
        espace(10-strlen("CAISSIER"));
    }
}

void avantUser(void){
    printf("%-10s","POSITION");
    printf("%-8s","ID");
    printf("%-22s","PRENOM(S)");
    printf("%-15s","NOM");
    printf("%-15s","LOGIN");
    printf("%-10s","PASSWORD");
    printf("%-10s","ROLE");
    puts("ETAT");
}

void afficherUser(int i){
    printf("%-10d",i);
    printf("%-8d",t_users[i].id);
    afficherLibelle(t_users[i].prenom);
    espace(22-strlen(t_users[i].prenom));
    afficherLibelle(t_users[i].nom);
    espace(15-strlen(t_users[i].nom));
    printf("%-15s",t_users[i].login);
    printf("%-10s",t_users[i].password);
    afficherRole(t_users[i].role);
    printf("%d\n",t_users[i].etat);
    ligne('-',TAILLE);
    puts("");
}

void saisirLogin(char msg[],char nom[]){
    bool isCorrect;
    int length;
    do{
        printf("Entrez le %s : \n",msg);
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

void saisirNom(char msg[],char nom[]){
    bool isCorrect;
    int length;
    do{
        printf("Entrez le %s : \n",msg);
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

void ajouterUser(void){
    USER u;
    int n,c;
    fflush(stdin);
    u.id=t_users[nbreUser-1].id+1;
    saisirNom("NOM",u.nom);
    fflush(stdin);
    saisirNom("PRENOM",u.prenom);
    saisiPrenom(u.prenom); // remplace les espaces par underscore
    puts("Entrez le LOGIN :");
    gets(u.login);
    while(rechercheLogin(u.login)==1){
        puts("Ce LOGIN n'est pas disponible!!!");
        puts("Entrez un autre LOGIN :");
        fflush(stdin);
        gets(u.login);
    }
    puts("Entrez le PASSWORD :");
    fflush(stdin);
    scanf("%s",u.password);
    n=strlen(u.password);
    while(n<4){
        puts("MOT DE PASSE INVALIDE!!");
        fflush(stdin);
        scanf("%s",u.password);
        n=strlen(u.password);
    }
    do{
        puts("Entrez le ROLE [1=>ADMINISTRATEUR / 2=>CAISSIER] :");
        fflush(stdin);
        scanf("%d",&u.role);
    }while(u.role!=1 && u.role!=2);
    do{
        puts("Entrez l'ETAT [1=>OPERATIONNEL / 0=>SUSPENDU] :");
        fflush(stdin);
        scanf("%d",&u.etat);
    }while(u.etat!=1 && u.etat!=0);
    do{
        puts("Confirmer l'ajout de cet utilisateur ? [1 => OUI / 0 => NON]");
        scanf("%d",&c);
    }while(c!=0 && c!=1);
    CLS;
    if (c==1){
        t_users[nbreUser++]=u;
        uploadFichierUsers();
        puts("\n\n     UTILISATEUR AJOUTEE AVEC SUCCES !!!\n\n");
    }else{
        puts("\n\n     AJOUT D'UTILISATEUR ANNULE !!!\n\n");
    }

}

void saisiPrenom(char ch[]){
    int i,n;
    n=strlen(ch);
    i=0;
    while(i<n){
        if(ch[i]==' '){
            ch[i]='_';
        }
        i++;
    }
}
int rechercheLogin(char log[]){
    int i=0, tmp=0;
    while(i<nbreUser){
        if(strcmp(log,t_users[i].login)==0){
            tmp=1;
            break;
        }
        i++;
    }
    return tmp;
}
int detailsUser(int x){
    CLS;
    printf("Details de l'utilisateur:");
    ligne('-',100-strlen("Details de l'utilisateur:"));
    puts("");
    espace(51-strlen("NOM : "));
    printf("NOM : ");
    afficherLibelle(t_users[x].nom);
    puts("");
    espace(51-strlen("PRENOM : "));
    printf("PRENOM : ");
    afficherLibelle(t_users[x].prenom);
    puts("");
    espace(51-strlen("LOGIN : "));
    printf("LOGIN : ");
    afficherLibelle(t_users[x].login);
    puts("");
    espace(51-strlen("PASSWORD : "));
    printf("PASSWORD : ");
    afficherLibelle(t_users[x].password);
    puts("");
    espace(51-strlen("ROLE : "));
    printf("ROLE : ");
    afficherRole(t_users[x].role);
    puts("");
    espace(51-strlen("ETAT : "));
    printf("ETAT :");
    printf("%d\n",t_users[x].etat);
    ligne('-',TAILLE);
    puts("");
}

void bloquerUser(void){
    int p;
    do{
        puts("Entrez la POSITION de l'utilisateur à SUSPENDRE :");
        scanf("%d",&p);
    }while(p<0 || p>=nbreUser);
    detailsUser(p);
    int choix;
    fflush(stdin);
    do{
        puts("Confirmer la suspension ? [1 => OUI / 0 => NON]");
        scanf("%d",&choix);
    }while(choix!=0 && choix!=1);
    CLS;
    if (choix==1){
        t_users[p].etat=0;
        uploadFichierUsers();
        puts("\n\n     UTILISATEUR BLOQUE AVEC SUCCES!!!\n\n");
    }else{
        puts("\n\n      SUSPENSION D'UTILISATEUR ANNULEE!!!\n\n");
    }
}
void deBloquerUser(void){
    int p;
    do{
        puts("Entrez la POSITION de l'utilisateur à RESTITUER :");
        scanf("%d",&p);
    }while(p<0 || p>=nbreUser);
    detailsUser(p);
    int choix;
    fflush(stdin);
    do{
        puts("Confirmer la restitution ? [1 => OUI / 0 => NON]");
        scanf("%d",&choix);
    }while(choix!=0 && choix!=1);
    CLS;
    if (choix==1){
        t_users[p].etat=1;
        uploadFichierUsers();
        puts("\n\n     UTILISATEUR RESTITUE AVEC SUCCES!!!\n\n");
    }else{
        puts("\n\n      RESTITUTION D'UTILISATEUR ANNULEE!!!\n\n");
    }
}
void changerRole(void){
    int p;
    do{
        puts("Entrez la POSITION de l'utilisateur :");
        scanf("%d",&p);
    }while(p<0 || p>=nbreUser);
    detailsUser(p);
    int choix;
    fflush(stdin);
    do{
        puts("Confirmer le changement de ROLE ? [1 => OUI / 0 => NON]");
        scanf("%d",&choix);
    }while(choix!=0 && choix!=1);
    CLS;
    if (choix==1){
        if(t_users[p].role==1){
            t_users[p].role=2;
        }else{
            t_users[p].role=1;
        }
        uploadFichierUsers();
        puts("\n\n     ROLE CHANGEE AVEC SUCCES!!!\n\n");
    }else{
        puts("\n\n     CHANGEMENT DE ROLE ANNULE!!!\n\n");
    }
}
void changerPass(void){
    int p;
    do{
        puts("Entrez la POSITION de l'utilisateur :");
        scanf("%d",&p);
    }while(p<0 || p>=nbreUser);
    detailsUser(p);
    char ch[MAX];
    do{
        puts("Entrez le nouveau mot de passe :");
        scanf("%s",&ch);
    }while(strlen(ch)<4 || strcasecmp(ch,t_users[p].password)==0);
    int choix;
    fflush(stdin);
    do{
        puts("Confirmer le changement de PASSWORD ? [1 => OUI / 0 => NON]");
        scanf("%d",&choix);
    }while(choix!=0 && choix!=1);
    CLS;
    if(choix==1){
        strcpy(t_users[p].password,"");
        strcat(t_users[p].password,ch);
        uploadFichierUsers();
        puts("\n\n     PASSWORD CHANGE AVEC SUCCES!!!\n\n");
    }else{
         puts("\n\n     CHANGEMENT DE PASSWORD ANNULE!!!\n\n");
    }
}
void afficherCompletUser(char ch[]){
    CLS;
    entete('*');
    ligne('-',TAILLE);
    puts("");
    avantUser();
    ligne('-',TAILLE);
    puts("");
     int i;
    for(i=0;i<nbreUser;i++){
        afficherUser(i);
    }
    titre(ch,'+',TAILLE);
    puts("");
}

