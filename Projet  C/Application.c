#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MAX 60
#define FICHIER_USERS "users.txt"
#define FICHIER_ARTICLES "articles.txt"
#define FICHIER_VENTES "ventes.txt"
#define CLS system("cls")
#define PAUSE system("pause")
#define TAILLE 100

//facture
void ecrireFacture2(FILE *);
int nombreCharInt2(int);
void afficherLibelle2(char[],FILE *);
void ligne2(char,int,FILE *);
void espace2(int,FILE *);
void milieu2(char[], char, int,FILE *);
void netAPayer2(char motif,FILE *);
// juste pour essaie


typedef enum{ADMIN=1,CAISSIER}ROLE;
typedef struct{
    int id,etat;
    char nom[MAX],prenom[MAX],login[MAX],password[MAX];
    ROLE role;
}USER;
USER t_users[MAX];// tableau contenant les users
int nbreUser=0;
USER connectedUser;
typedef struct {
    int id,qt,prix;
    char libelle[MAX],couleur[MAX],marque[MAX];
}ARTICLE;
ARTICLE t_articles[MAX];
int nbreArticle=0;
int pos,qte,montantNet=0;
typedef struct{
    int position,qte,total;
}PANIER;
PANIER t_panier[MAX];
int nbrePanier=0;
char nomClient[MAX],prenomClient[MAX];
int numeroClient;

typedef struct {
    int montant,iduser;
    char date[MAX],heure[MAX],nomFact[MAX];
}VENTE;
VENTE t_ventes[MAX];
VENTE t2_ventes[MAX];
int nbreVente=0;
int nbre2Vente=0;
char nomFacture[MAX]="",numFacture[MAX]="FACT";
char heureA[MAX],dHeure[MAX],dateA[MAX];


//Prototypes partie 1
void chargerFichierUsers(void);
void uploadFichierUsers(void);
void chargerFichierArticles(void);
void uploadFichierArticles(void);
USER connexion(void);
void ligne(char,int);
void entete(char);
int menuGeneral(void);
void titre(char[],char,int);
void milieu(char[],char,int);
void espace(int nbre);
void afficherArticles(int); // afficher uniquement l'article a la position indiqué
void afficherLibelle(char[]); // afficher les libelles et marque sans '_'
int menuVente(void);   // menu vente par position, libelle...Preciser le choix avec l'annulation de la casse:
int nombreCharInt(int);
void avantArticle(void); // position,id, libelle,marque,couleur...
int detailsArticle(void); // demande la position puis donne details de l'article puis demande si ajouter panier
int afficherArticlesTrouvesLibelle(char[]); // affiche l'article trouvé par recherche sur libelle.
int afficherArticlesTrouvesCouleur(char[]);
int afficherArticlesTrouvesPrix(int);
void ajouterAuPanier(int); // si 1 demande la quantité si 0 retourne au
void avantPanier(void);
void netAPayer(char);
void afficherPanier(void);
void chargerPanier(int);  //met l'article dans le panier
void informationsClient(void); // entrer les infos du client
void dateAvec(void); // date avec j/m/a
void heureAvec(void);
void dateHeure(void); //date et heure tout coller jmahms
void creerFacture(char[]); // creer la facture puis remplit
void nomNumFacture(void);
int rechercheArticle(int);// rechercher article avant de l'inserer dans tableau
void chargerVente(void); // remplir le tableau de ventes
void gestionStock(void); // après vente, on met à jour le stock
void chargerFichierVentes(void);
void uploadFichierVente(void);

//Prototypes Partie 3
void avantEtatCaisse(void);
void afficherEtatCaisse(void);
int rechercheDate(char[],int); // 1 si date et 0 sinon; int pour jusqu'où il;cherche
void afficherVentes(char[]);// afficher les ventes
void avantVentes(void);
void lireFichier(char[]);
void chargerVente2(void);//remplir le tableau de ventes en fonction de admin ou caissier

//Prototypes Partie 2
int menuUser(void);
void avantUser(void);
void afficherUser(int);
void afficherRole(int);
void ajouterUser(void);
int rechercheLogin(char[]);


main()
{
    chargerFichierUsers();
    chargerFichierArticles();
    chargerFichierVentes();
    connectedUser = connexion();
    chargerVente2();
    MENUGENERAL:
    CLS;
    entete('*');
    ligne('-',TAILLE);
    puts("");
    titre("MENU GENERAL",'+',TAILLE);
    printf("\n\n");
    switch(menuGeneral()){
        case 1:
            VENTE:
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
            titre("VENTE",'+',TAILLE);
            printf("\n \n");
            switch(menuVente()){
                case 1:
                    VENTEPARNUM:
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
                    titre("VENTE PAR NUMERO DE POSITION DE L'ARTICLE",'-',TAILLE);
                    printf("\n");
                    ENTRERPOSITION:
                    puts("");
                    do{
                        puts("Saisir la POSITION de l'article : ");
                        scanf("%d",&pos);
                    }while(pos<0 || pos>nbreArticle-1);
                    int choix;
                    choix=detailsArticle();
                    if(choix==1){
                        int ch;
                        do{
                            puts("Entrer la QUANTITE de vente : ");
                            scanf("%d",&qte);
                        }while(qte<=0 || qte>t_articles[pos].qt);
                        chargerPanier(pos);
                        do{
                            puts("Voulez-vous effectuer une nouvelle vente par NUMERO? [1 => OUI / 0 => NON]");
                            scanf("%d",&ch);
                        }while(ch!=0 && ch!=1);
                        if(ch==1){
                            goto VENTEPARNUM;
                        }else{
                          goto MENUGENERAL;
                        }
                    }else{
                        PAUSE;
                        goto MENUGENERAL;
                    }
                    break;
                case 2 :
                    CLS;
                    entete('*');
                    ligne('-',TAILLE);
                    puts("");
                    titre("VENTE PAR  LIBELLE",'-',TAILLE);
                    printf("\n \n");
                    char lib[MAX];
                    puts("Saisir le LIBELLE de l'article : ");
                    fflush(stdin);
                    gets(lib);
                    if (afficherArticlesTrouvesLibelle(lib)==0){
                        goto VENTE;
                    }
                    goto ENTRERPOSITION;
                    break;
                case 3 :
                    CLS;
                    entete('*');
                    ligne('-',TAILLE);
                    puts("");
                    titre("VENTE PAR  PRIX",'-',TAILLE);
                    printf("\n \n");
                    int prix;
                    puts("Saisir le PRIX de l'article : ");
                    scanf("%d",&prix);
                    if (afficherArticlesTrouvesPrix(prix)==0){
                        goto VENTE;
                    }
                    goto ENTRERPOSITION;
                    break;
                case 4:
                    CLS;
                    entete('*');
                    ligne('-',TAILLE);
                    puts("");
                    titre("VENTE PAR  COULEUR",'-',TAILLE);
                    printf("\n \n");
                    char couleur[MAX];
                    puts("Saisir la COULEUR de l'article : ");
                    fflush(stdin);
                    gets(couleur);
                    if (afficherArticlesTrouvesCouleur(couleur)==0){
                        goto VENTE;
                    }
                    goto ENTRERPOSITION;
                    break;
                case 5:
                    CLS;
                    entete('*');
                    ligne('-',TAILLE);
                    puts("");
                    titre("LE PANIER DU CLIENT",'-',TAILLE);
                    printf("\n");
                    avantPanier();
                    ligne('-',TAILLE);
                    puts("");
                    afficherPanier();
                    if (nbrePanier!=0){
                        int ch1;
                        do{
                            puts("Voulez-vous VALIDER le panier ? [1 => OUI / 0 => NON]");
                            scanf("%d",&ch1);
                        }while(ch1!=0 && ch1!=1);
                        if(ch1==1){
                            informationsClient();
                            gestionStock();
                            nomNumFacture();
                            creerFacture(nomFacture);
                            chargerVente();
                            chargerVente2();
                            uploadFichierVente();
                            uploadFichierArticles();
                            nbrePanier=0;
                            montantNet=0;
                            PAUSE;
                            goto MENUGENERAL;
                        }else{
                            goto VENTE;
                        }
                        break;
                    }else {
                        puts("\n      AUCUN PANIER !!! \n");
                        PAUSE;
                        goto MENUGENERAL;
                    }
                default:
                    goto MENUGENERAL;
                    break;
            }
            break;
        case 2:
            CLS;
            if (connectedUser.role==2){
                printf("\n\n VOTRE ROLE NE VOUS PERMET PAS D'AVOIR CETTE OPTION!!!\n\n");
                PAUSE;
                goto MENUGENERAL;
            } else{
                PAUSE;
            }
            break;
        case 3:
            CLS;
            entete('*');
            ligne('-',TAILLE);
            puts("");
            titre("ETAT DE CAISSE",'-',TAILLE);
            printf("\n");
            avantEtatCaisse();
            afficherEtatCaisse();
            char saisi[MAX];
            puts("\nSaisir une DATE de vente pour voir les details [0 pour quitter] :");
            fflush(stdin);
            scanf("%s",&saisi);
            if (strcasecmp(saisi,"0")==0){
                PAUSE;
                goto MENUGENERAL;
            }else{
                if(rechercheDate(saisi,nbreVente)==1){
                    CLS;
                    entete('*');
                ligne('-',TAILLE);
                puts("");
                char c[MAX]="LES VENTES DU ";
                strcat(c,saisi);
                titre(c,'-',TAILLE);
                printf("\n");
                avantVentes();
                afficherVentes(saisi);
                printf("Saisir une POSITION pour voir la facture [-1 Pour quitter] :\n");
                int posi;
                scanf("%d",&posi);
                if(posi==-1){
                    PAUSE;
                    goto MENUGENERAL;
                } else{
                    if(posi>=nbreVente || posi<0){
                        puts("\n\n        AUNCUNE VENTE ENREGISTREE A CETTE POSITION !!!\n\n");
                        PAUSE;
                        goto MENUGENERAL;
                    }else{
                        CLS;
                        lireFichier(t_ventes[posi].nomFact);
                        puts("\n");
                        PAUSE;
                        goto MENUGENERAL;
                    }
                }

            }else{

            }
            }
            break;
        case 4:
            CLS;
            if (connectedUser.role==2){
                printf("\n\n VOTRE ROLE NE VOUS PERMET PAS D'AVOIR CETTE OPTION!!!\n\n");
                PAUSE;
                goto MENUGENERAL;
            } else{
                MENUUSER:
                CLS;
                entete('*');
                ligne('-',TAILLE);
                puts("");
                titre("MENU UTILISATEUR",'+',TAILLE);
                puts("\n");
                switch(menuUser()){
                    case 1:
                        CLS;
                        entete('*');
                        ligne('-',TAILLE);
                        puts("");
                        avantUser();
                        ligne('-',TAILLE);
                        puts("");
                        int i;
                        for(i=0;i<nbreUser-1;i++){
                            afficherUser(i);
                        }
                        titre(" LISTE DES UTILISATEURS ",'+',TAILLE);
                        puts("");
                        PAUSE;
                        goto MENUUSER;
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    default :
                        goto MENUGENERAL;
                        break;
                }
            }
            break;
        case 5:
            puts("Fermeture...");
            PAUSE;
            exit(1);
            break;
        default:
            CLS;
            goto MENUGENERAL;
    }
}
// Implémentations Partie 1
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
            fprintf(f,"%s %s %s %d %d\n",t_ventes[i].date,t_ventes[i].heure,t_ventes[i].nomFact,t_ventes[i].montant,t_ventes[i].iduser);
        }
        fclose(f);
    }
}
void nomNumFacture(void){
    heureAvec();
    dateHeure();
    dateAvec();
    strcat(numFacture,dHeure);
    strcat(nomFacture,numFacture);
    strcat(nomFacture,"_");
    strcat(nomFacture,prenomClient);
    strcat(nomFacture,"_");
    strcat(nomFacture,nomClient);
    strcat(nomFacture,".txt");
}
void creerFacture(char nomFichier[]){
    FILE *f = fopen(nomFichier,"w");
    if(f){
        ecrireFacture2(f);
        fclose(f);
    }else{
        puts("ERREUR LORS DE LA CREATION DU FICHIER FACTURE!!!");
    }
}

void heureAvec(void){
    time_t now= time(NULL);// lire l'heure courante
    //char heure[MAX]; // declarer variable qui va contenir l'heure
    strftime(heureA, sizeof(heureA),"%H:%M:%S", localtime(&now));
    // convertir l'heure en heure locale(localtime()) puis ecrit dans la variable l'heure avec le code format de l'heure
}
void dateHeure(void){
    time_t now= time(NULL);
    strftime(dHeure, sizeof(dHeure),"%d%m%Y%H%M%S", localtime(&now));
}
void dateAvec(void){
    time_t now= time(NULL);// lire l'heure courante
    //char date[MAX]; // declarer variable qui va contenir la date
    strftime(dateA, sizeof(dateA),"%d/%m/%Y", localtime(&now));
    // convertir l'heure en heure locale(localtime()) puis ecrit dans la variable la date avec le code format de la date
}

void avantArticle(void){
    printf("POSITION  ");
    printf("ID        ");
    printf("LIBELLE                       ");
    printf("COULEUR        ");
    printf("MARQUE         ");
    printf("PRIX      ");
    puts("STOCK");
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
        montantNet+=qte*t_articles[x].prix;;
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
void informationsClient(void){
    puts("Prenom du Client ?");
    fflush(stdin);
    scanf("%s",&prenomClient);
    puts("Nom du Client ?");
    fflush(stdin);
    scanf("%s",&nomClient);
    int n;
    do{
        puts("Telephone du Client ?");
        scanf("%d",&numeroClient);
        n=numeroClient/10000000;
    }while(!(nombreCharInt(numeroClient)==9 && (n==77 || n==78 || n==76 || n==75 || n==70)));
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
int menuGeneral(void){
    int choix;
    puts("1................................VENTE");
    puts("2................................GESTION DES ARTICLES");
    puts("3................................ETAT CAISSE");
    puts("4................................UTILISATEURS");
    puts("5................................QUITTER\n");
    puts("Faites votre choix :");
    scanf("%d",&choix);
    return choix;
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
        for (i = 0; i < nbreUser-1; i++){
            fprintf(f,"%d %s %s %s %s %d %d\n",t_users[i].id,t_users[i].nom,t_users[i].prenom,
                    t_users[i].login,t_users[i].password,t_users[i].role,t_users[i].etat);
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
            fprintf(f,"%d %s %s %s %d %d\n",t_articles[i].id,t_articles[i].libelle,
                    t_articles[i].couleur,t_articles[i].marque,t_articles[i].prix,t_articles[i].qt);
        }
        fclose(f);
    }
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
        if (u.etat==2){
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

int nombreCharInt(int x){
    int n=0;
    do{
        n++;
        x/=10;
    } while(x!=0);
    return n;
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
        }
        i++;
    }
    if (cpt==0){
        puts("\n\n       LA LISTE EST VIDE!!!\n\n");
        PAUSE;
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
        }
        i++;
    }
    if (cpt==0){
        puts("\n\n       LA LISTE EST VIDE!!!\n\n");
        PAUSE;
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
            cpt=1;
        }
    }
    if (cpt==0){
        puts("\n\n       LA LISTE EST VIDE!!!\n\n");
        PAUSE;
    }
    return cpt;
}


//Facture en soi
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

// implementation Partie 3
void avantEtatCaisse(void){
    printf("%-50s"," ");
    printf("%-15s","DATE");
    printf("%-15s","HEURE");
    printf("MONTANT VENDU\n");
    ligne('-',TAILLE);
    puts("");
}
int rechercheDate(char date[MAX],int p){
    int i,x=0;
    for (i=0;i<p;i++){
        if (strcasecmp(date,t2_ventes[i].date)==0){
            x=1;
            break;
        }
    }
    return x;
}
void afficherEtatCaisse(void){
    int i,j,tmp=0,montant;
    for (i=0;i<nbre2Vente;i++){
        montant= t2_ventes[i].montant;
        for (j=i+1;j<nbre2Vente;j++){
            if (strcasecmp(t2_ventes[i].date,t2_ventes[j].date)==0){
                montant+=t2_ventes[j].montant;
            }
        }
        if (rechercheDate(t2_ventes[i].date,i)==0){
            printf("%50s"," ");
            printf("%-15s",t2_ventes[i].date);
            printf("%-15s",t2_ventes[i].heure);
            printf("%d\n",montant);
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
        }
   }
}
void lireFichier(char nom[MAX]){
    FILE *f;
    char c;
    f=fopen(nom,"rt");
    while((c=fgetc(f))!=EOF){
        printf("%c",c);
    }
    fclose(f);
}
void chargerVente2(void){
    int i;
    if (connectedUser.role==1){
        for (i=0;i<nbreVente;i++){
            t2_ventes[i]=t_ventes[i];
            nbre2Vente=nbreVente;
        }
    }else {
        for (i=0;i<nbreVente;i++){
            if (connectedUser.id==t_ventes[i].iduser){
                t2_ventes[nbre2Vente++]=t_ventes[i];
            }
        }
    }
}
// implementation Partie 3

int menuUser(void){
    int choix;
    puts("1................................VOIR UTILISATEURS");
    puts("2................................AJOUTER UN UTILISATEUR");
    puts("3................................BLOQUER UN UTILISATEUR");
    puts("4................................RETOUR\n");
    puts("Faites votre choix : ");
    scanf("%d",&choix);
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
void ajouterUser(void){
    puts("Entrez le NOM :");
    scanf("%s",t_users[nbreUser].nom);
    puts("Entrez le PRENOM :");
    fgets(t_users[nbreUser].prenom,60,stdin);

}
//int rechercheLogin(char[]){

//}
