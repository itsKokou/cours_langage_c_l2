#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <ctype.h>
#include <stdbool.h>
#include "global.h"
#include "facture.h"
#include "fichier.h"
#include "dateHeure.h"
#include "apport.h"
#include "etatCaisse.h"
#include "panierVente.h"
#include "afficherV.h"
#include "utilisateurs.h"
#include "articles.h"
#include "global.h"
main()
{
    system("color 1");
    nbreUser=0;
    nbreArticle=0;
    montantNet=0;
    nbrePanier=0;
    nbreVente=0;
    nbre2Vente=0;
    nbretab=0;
    nbretab2=0;
    chargerFichierUsers();
    chargerFichierArticles();
    chargerFichierVentes();
    connectedUser = connexion();
    chargerVente2();
    MENUGENERAL:
    enteteComplet();
    titre("MENU GENERAL",'+',TAILLE);
    printf("\n\n");
    switch(menuGeneral()){
        case '1':
            VENTE:
            enteteComplet();
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
                    enteteComplet();
                    avantArticle();
                    ligne('-',TAILLE);
                    puts("");
                    int i;
                    for(i=0;i<nbreArticle;i++){
                        afficherArticles(i);
                    }
                    titre("VENTE PAR NUMERO DE POSITION DE L'ARTICLE",'-',TAILLE);
                    printf("\n\n");
                    do{
                        puts("Saisir la POSITION de l'article : ");
                        scanf("%d",&pos);
                    }while(pos<0 || pos>=nbreArticle);
                    ENTRERPOSITION:
                    if(detailsArticle()==1){
                        int ch;
                        do{
                            puts("Entrer la QUANTITE de vente : ");
                            scanf("%d",&qte);
                        }while(qte<=0 || qte>t_articles[pos].qt);
                        chargerPanier(pos);
                        do{
                            puts("Voulez-vous effectuer une nouvelle vente par NUMERO ? [1 => OUI / 0 => NON]");
                            scanf("%d",&ch);
                        }while(ch!=0 && ch!=1);
                        if(ch==1){
                            goto VENTEPARNUM;
                        }else{
                          goto VENTE;
                        }
                    }else{
                        PAUSE;
                        goto MENUGENERAL;
                    }
                    break;
                case 2 :
                    enteteComplet();
                    titre("VENTE PAR  LIBELLE",'-',TAILLE);
                    printf("\n \n");
                    char lib[MAX];
                    puts("Saisir le LIBELLE de l'article : ");
                    fflush(stdin);
                    gets(lib);
                    if (afficherArticlesTrouvesLibelle(lib)==0 || verifierPos()==0){
                        PAUSE;
                        goto VENTE;
                    }
                    nbretab=0;
                    goto ENTRERPOSITION;
                    break;
                case 3 :
                    enteteComplet();
                    titre("VENTE PAR  PRIX",'-',TAILLE);
                    printf("\n \n");
                    int prix;
                    puts("Saisir le PRIX de l'article : ");
                    scanf("%d",&prix);
                    if (afficherArticlesTrouvesPrix(prix)==0 || verifierPos()==0){
                        PAUSE;
                        goto VENTE;
                    }
                    nbretab=0;
                    goto ENTRERPOSITION;
                    break;
                case 4:
                    enteteComplet();
                    titre("VENTE PAR  COULEUR",'-',TAILLE);
                    printf("\n \n");
                    char couleur[MAX];
                    puts("Saisir la COULEUR de l'article : ");
                    fflush(stdin);
                    gets(couleur);
                    if (afficherArticlesTrouvesCouleur(couleur)==0 || verifierPos()==0){
                        PAUSE;
                        goto VENTE;
                    }
                    nbretab=0;
                    goto ENTRERPOSITION;
                    break;
                case 5:
                    enteteComplet();
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
                            nomFacture[MAX]="";
                            numFacture[MAX]="";
                            nomNumFacture();
                            creerFacture(nomFacture);
                            chargerVente();
                            chargerVente2();
                            uploadFichierVente();
                            uploadFichierArticles();
                            nbrePanier=0;
                            montantNet=0;
                            nomFacture[MAX]="";
                            numFacture[MAX]="";
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
        case '2':
            CLS;
            if (connectedUser.role==2){
                printf("\n\n VOTRE ROLE NE VOUS PERMET PAS D'AVOIR CETTE OPTION!!!\n\n");
                PAUSE;
                goto MENUGENERAL;
            }else{
                MENUARTICLE:
                enteteComplet();
                titre("MENU ARTICLE",'+',TAILLE);
                puts("\n");
                switch(menuArticle()){
                    case '1':
                        afficherCompletArticle("LISTE DES ARTICLES");
                        PAUSE;
                        goto MENUARTICLE;
                        break;
                    case '2':
                        afficherCompletArticle("MODIFIER STOCK");
                        modifierStock(); // upload est dedans
                        PAUSE;
                        goto MENUARTICLE;
                        break;
                    case '3':
                        afficherCompletArticle("MODIFIER PRIX");
                        modifierPrix(); // upload y est
                        PAUSE;
                        goto MENUARTICLE;
                        break;
                    case '4':
                        enteteComplet();
                        titre("AJOUTER ARTICLE",'+',TAILLE);
                        printf("\n");
                        ajouterArticle(); //upload y est
                        PAUSE;
                        goto MENUARTICLE;
                        break;
                    case '5':
                        goto MENUGENERAL;
                        break;
                    default:
                        goto MENUARTICLE;
                        break;
                }
            }
            break;
        case '3':
            enteteComplet();
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
                    enteteComplet();
                    char c[MAX]="LES VENTES DU ";
                    strcat(c,saisi);
                    titre(c,'-',TAILLE);
                    printf("\n");
                    avantVentes();
                    afficherVentes(saisi);
                    printf("Saisir une POSITION pour voir la facture [-1 Pour quitter] :\n");
                    int posi;
                    scanf("%d",&posi);
                    if(checkTab2(posi)==1){
                        CLS;
                        lireFichier(t_ventes[posi].nomFact);
                        puts("\n");
                    }else{
                        if(posi!=-1){
                            printf("\n\n        AUNCUNE VENTE ENREGISTREE A CETTE POSITION !!!\n\n");
                        }
                    }
                    PAUSE;
                    goto MENUGENERAL;
                }else{
                    puts("\n\n        AUNCUNE VENTE ENREGISTREE A CETTE DATE !!!\n\n");
                    PAUSE;
                    goto MENUGENERAL;
                }
            }
            break;
        case '4':
            CLS;
            if (connectedUser.role==2){
                printf("\n\n VOTRE ROLE NE VOUS PERMET PAS D'AVOIR CETTE OPTION!!!\n\n");
                PAUSE;
                goto MENUGENERAL;
            } else{
                MENUUSER:
                enteteComplet();
                titre("MENU UTILISATEUR",'+',TAILLE);
                puts("\n");
                switch(menuUser()){
                    case '1':
                        afficherCompletUser("LISTE DES UTILISATEURS");
                        PAUSE;
                        goto MENUUSER;
                        break;
                    case '2':
                        enteteComplet();
                        titre("AJOUT D'UN UTILISATEUR",'+',TAILLE);
                        puts("");
                        ajouterUser(); // upload y est
                        PAUSE;
                        goto MENUUSER;
                        break;
                    case '3':
                        afficherCompletUser("BLOQUER/DEBLOQUER UTILISATEUR");
                        int y;
                        do{
                            puts("Que voulez-vous faire ?[1=>BLOQUER / 2=>DEBLOQUER]");
                            scanf("%d",&y);
                        }while(y!=1 && y!=2);
                        if(y==1){
                            bloquerUser();   // upload y est
                        }else{
                            deBloquerUser();  // upload y est
                        }
                        PAUSE;
                        goto MENUUSER;
                        break;
                    case '4':
                        afficherCompletUser("CHANGER ROLE UTILISATEUR");
                        changerRole(); // upload y est
                        PAUSE;
                        goto MENUUSER;
                        break;
                    case '5':
                        afficherCompletUser("CHANGER PASSWORD UTILISATEUR");
                        changerPass(); // upload y est
                        PAUSE;
                        goto MENUUSER;
                        break;
                    case '6':
                        goto MENUGENERAL;
                        break;
                    default :
                        goto MENUUSER;
                        break;
                }
            }
            break;
        case '5':
            puts("Fermeture...");
            PAUSE;
            exit(1);
            break;
        default:
            goto MENUGENERAL;
            break;
    }

}
