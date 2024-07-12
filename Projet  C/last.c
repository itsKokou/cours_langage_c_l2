#include<stdio.h>
#include<string.h>
#define CLS printf("\33c\e[3J");
#define FLUSH fflush(stdin);

#define SCREEN_WIDTH 100


typedef struct
{
    char nom[30];
    char pnom[30];
    float moyenne;
}ETUDIANT;

void titre(char[],char,int);
void ligne(char, int);
void creerFichier(char[]);
float saisirMoyenne(void);
ETUDIANT saisirEtudiant(void);
int yesNoQuestion(char[]);
void uploadFichier(void);
void afficheTab(void);
void chargerFichier(void);
ETUDIANT etudiants[100];
int nbreEtudiants = 0; // le nombre reel d'etudiants dans le tableau


int main(){
    int i;
    CLS
    // creerFichier("BREUKH.txt");
    // while (yesNoQuestion("Voulez-vous ajouter un etudiant?") == 1)
    // {
    //     etudiants[nbreEtudiants++] = saisirEtudiant();
    // }
    
    // afficheTab();
    // uploadFichier();
    int pos;
    chargerFichier();
    afficheTab();
    puts("Entrer la position de l'etudiant a modifier ?");
    scanf("%d",&pos);
    //Controler la saisie de pos : >0 et <nbreEtudiants
    etudiants[pos].moyenne = saisirMoyenne();
    //
    uploadFichier();
    return 0;
}

void uploadFichier(void){
    FILE *f = fopen("BREUKH.txt","w");
    int i;
    if(f){
        for (i = 0; i < nbreEtudiants; i++)
        {
            fprintf(f,"%s %s %.2f\n",etudiants[i].nom,etudiants[i].pnom,etudiants[i].moyenne);
        }
        
        fclose(f);
    }
}

void chargerFichier(void){
    FILE *f = fopen("BREUKH.txt","r");
    ETUDIANT e;
    nbreEtudiants = 0;
    while (!feof(f))
    {
        fscanf(f,"%s %s %f\n",e.nom,e.pnom,&e.moyenne);
        //Mettre l'etudiant dans le tableau
        etudiants[nbreEtudiants++] = e;
    }
    
}

void afficheTab(void){
    int i;
    for (i = 0; i < nbreEtudiants; i++)
    {
       printf("%d %s %s %.2f\n",i,etudiants[i].nom,etudiants[i].pnom,etudiants[i].moyenne);
    }
}
int yesNoQuestion(char question[]){
    int rep;
    do{
        printf("%s [0 => NON et 1 => OUI]\n",question);
        scanf("%d",&rep);
    }while(rep!=0 && rep!=1);
    return rep;
}

ETUDIANT saisirEtudiant(void){
    ETUDIANT e;
    FLUSH
    do{
    puts("ENtrer le nom : ");
    gets(e.nom);
    }while (strlen(e.nom) == 0);
    
    puts("ENtrer le prenom : ");
    gets(e.pnom);
    e.moyenne = saisirMoyenne();
    return e;
}
float saisirMoyenne(void){
    float m;
    do{
        puts("Entrer une moyenne : ");
        scanf("%f",&m);
    }while(m<0 || m>20);
    return m;
}
void creerFichier(char nomFichier[]){
    FILE *f = fopen(nomFichier,"w");
    if(f){
        puts("LE FICHIER A ETE CREE AVEC SUCCES");
        fclose(f);
    }else{
        puts("ERREUR LORS DE LA CREATION DU FICHIER!!!");
    }

}
/**
 * Cette fonction permet d'afficher un titre.
 */
void titre(char msg[], char motif, int taille){
    int tailleMsg = strlen(msg);
    int reste = taille - tailleMsg;
    int nbreCar = reste/2;
    ligne(motif,taille);//La premiere ligne
    puts("");
    ligne(motif,nbreCar);
    printf("%s",msg);
    if(reste%2 == 1){
        ligne(motif,nbreCar+1);
    }else{
        ligne(motif,nbreCar);
    }
    puts("");
    ligne(motif,taille);//La Dernieres ligne
}

/**
 * Cette fonction permet de tracer une ligne, si on lui donne en param le motif et la taille.
 */
void ligne(char motif, int taille){
    int i;
    for (i = 0; i < taille; i++)
    {
        printf("%c",motif);
    }
}