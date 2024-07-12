#ifndef GLOBAL_H
#define GLOBAL_H
#define MAX 60
#define FICHIER_USERS "users.txt"
#define FICHIER_ARTICLES "articles.txt"
#define FICHIER_VENTES "ventes.txt"
#define CLS system("cls")
#define PAUSE system("pause")
#define TAILLE 100

// structures
typedef enum{ADMIN=1,CAISSIER}ROLE;
typedef struct{
    int id,etat;
    char nom[MAX],prenom[MAX],login[MAX],password[MAX];
    ROLE role;
}USER;
USER t_users[MAX];// tableau contenant les users
int nbreUser;
USER connectedUser;
typedef struct {
    int id,qt,prix;
    char libelle[MAX],couleur[MAX],marque[MAX];
}ARTICLE;
ARTICLE t_articles[MAX];
int nbreArticle;
int pos,qte,montantNet;
typedef struct{
    int position,qte,total;
}PANIER;
PANIER t_panier[MAX];
int nbrePanier;
char nomClient[MAX],prenomClient[MAX];
int numeroClient;

typedef struct {
    int montant,iduser;
    char date[MAX],heure[MAX],nomFact[MAX];
}VENTE;
VENTE t_ventes[MAX];
VENTE t2_ventes[MAX];
int nbreVente;
int nbre2Vente;
char nomFacture[MAX],numFacture[MAX];
char heureA[MAX],dHeure[MAX],dateA[MAX];
int tab[MAX];
int tab2[MAX];
int nbretab;
int nbretab2;

#endif // GLOBAL_H
