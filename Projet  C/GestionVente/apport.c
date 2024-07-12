#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"global.h"

char menuGeneral(void){
    char choix;
    puts("1................................VENTE");
    puts("2................................GESTION DES ARTICLES");
    puts("3................................ETAT CAISSE");
    puts("4................................UTILISATEURS");
    puts("5................................QUITTER\n");
    puts("Faites votre choix :");
    scanf("%c",&choix);
    return choix;
}
void milieu(char msg[], char motif, int taille){
    int tailleMsg = strlen(msg);
    int reste = taille - tailleMsg;
    int nbreCar = reste/2;
    ligne(motif,nbreCar);
    printf("%s",msg);
    if(reste%2 == 1){
        ligne(motif,nbreCar+1);
    }else{
        ligne(motif,nbreCar);
    }
    puts("");
}

void titre(char msg[], char motif, int taille){
    ligne(motif,taille);//La premiere ligne
    puts("");
    milieu(msg,motif,taille);
    ligne(motif,taille);//La Dernieres ligne
    puts("");
}
void entete(char motif){
    int taille,tail;
    int role=connectedUser.role;
    ligne(motif,100);
    puts("");
    if (role==1){
        tail=5;
        taille = 100 -(7*2+strlen(connectedUser.login)+tail);
        ligne(motif,3);
        printf("  %s  ",connectedUser.login);
        ligne(motif,taille);
        printf("  ADMIN  ");
        ligne(motif,3);

    } else{
        tail=8;
        taille = 100 -(7*2+strlen(connectedUser.login)+tail);
        ligne(motif,3);
        printf("  %s  ",connectedUser.login);
        ligne(motif,taille);
        printf("  CAISSIER  ");
        ligne(motif,3);
       }
     puts("");
     ligne(motif,100);
     puts("");
}
USER connexion(void){
    USER u;
    int trouve=0;
    int i;
    char log[MAX],pass[MAX];
    CONN:
    puts("***** CONNEXION *****");
    puts("---------------------");
    puts("LOGIN : ");
    gets(log);
    puts("PASSWORD : ");
    gets(pass);
    for(i=0;i<nbreUser;i++){
            // tester si le login et le pass existent
        if(strcmp(t_users[i].login,log)==0 && strcmp(t_users[i].password,pass)==0){
                u=t_users[i];
                trouve = 1;
                break;
        }
    }
    if (trouve==0){
        _sleep(50);
        CLS;
        puts("\n \nLOGIN ET/OU MOT DE PASSE INVALIDE!!!\n \n");
        PAUSE;
        CLS;
        goto CONN;
    }else {
        if (u.etat==0){
            _sleep(50);
            CLS;
            puts("\n \nVOTRE ACCES A ETE RESTRREINT PAR UN ADMINISTRATEUR DU SYSTEME!!!\n \n");
            PAUSE;
            CLS;
            goto CONN;
        }
    }
    return u;
}
void ligne(char motif,int taille){
    int i;
    for(i=0;i<taille;i++){
        printf("%c",motif);
    }
}
void espace(int nbre){
    int i;
    for (i=1;i<=nbre;i++){
        printf(" ");
    }
}
int nombreCharInt(int x){
    int n=0;
    do{
        n++;
        x/=10;
    } while(x!=0);
    return n;
}
void enteteComplet(void){
    CLS;
    entete('*');
    ligne('-',TAILLE);
    puts("");
}
