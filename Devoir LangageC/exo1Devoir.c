#include<stdio.h>
#include<stdlib.h>
#define MAX_kokou 50
#define VIN_kokou 20
#define FICHIER_PERSONNE "personne.txt"
typedef struct {
    char matricule_kokou[VIN_kokou];
    char nom_kokou[VIN_kokou];
    char prenom_kokou[30];
    char dateNaiss_kokou[11];
    char ville_kokou[VIN_kokou];
    char tel_kokou[10];
    char email_kokou[MAX_kokou];
    float moyenne_kokou;
}ETUDIANT;

void ligne(char,int);
void afficherEtudiant(void);
void chargerEtudiants(void);

ETUDIANT t_etudiants_kokou[MAX_kokou];
int nbreEtudiants_kokou=0;
main()
{
    chargerEtudiants();
    afficherEtudiant();

}

void ligne(char motif_kokou,int taille_kokou){
    int i_kokou;
    for(i_kokou=0;i_kokou<taille_kokou;i_kokou++){
        printf("%c",motif_kokou);
    }
}
void afficherEtudiant(void){
    int i_kokou;
    for (i_kokou=0;i_kokou<nbreEtudiants_kokou-1;i_kokou++){
        printf("MATRICULE : ");
        printf("%s\n",t_etudiants_kokou[i_kokou].matricule_kokou);
        printf("NOM       : ");
        printf("%s\n",t_etudiants_kokou[i_kokou].nom_kokou);
        printf("PRENOM    : ");
        printf("%s\n",t_etudiants_kokou[i_kokou].prenom_kokou);
        printf("NAISSANCE : ");
        printf("%s\n",t_etudiants_kokou[i_kokou].dateNaiss_kokou);
        printf("VILLE     : ");
        printf("%s\n",t_etudiants_kokou[i_kokou].ville_kokou);
        printf("TELEPHONE : ");
        printf("%s\n",t_etudiants_kokou[i_kokou].tel_kokou);
        printf("EMAIL     : ");
        printf("%s\n",t_etudiants_kokou[i_kokou].email_kokou);
        printf("MOYENNE   : ");
        printf("%.2f\n",t_etudiants_kokou[i_kokou].moyenne_kokou);
        ligne('-',MAX_kokou);
        puts("");
    }
}
void chargerEtudiants(void){
    FILE *f_kokou = fopen("personne.txt","r");
    ETUDIANT e_kokou;
    if(f_kokou){
       while (!feof(f_kokou)){
        fscanf(f_kokou,"{ %s %s %s %s %s %s %s %f },",&e_kokou.matricule_kokou,&e_kokou.nom_kokou,&e_kokou.prenom_kokou,&e_kokou.dateNaiss_kokou,&e_kokou.ville_kokou,&e_kokou.tel_kokou,&e_kokou.email_kokou,&e_kokou.moyenne_kokou);
        t_etudiants_kokou[nbreEtudiants_kokou] = e_kokou;
        nbreEtudiants_kokou+=1;
        }
        fclose(f_kokou);
    }
}
