#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int j_kokou;
    int m_kokou;
    int a_kokou;
}DATE;
typedef struct {
    int id_kokou;
    char libelle_kokou;
    int prix_kokou;
    int qte_kokou;
    DATE date_kokou;
}PRODUIT;
void creerFichier(char[]);
void ajoutProduit(char[],PRODUIT);
void afficher(char[], int);

main()
{

}
void creerFichier(char nomFichier_kokou[]){
    FILE *f_kokou = fopen(nomFichier_kokou,"w");
    if(f_kokou){
        puts("LE FICHIER A ETE CREE AVEC SUCCES");
        fclose(f_kokou);
    }else{
        puts("ERREUR LORS DE LA CREATION DU FICHIER!!!");
    }
}
void ajoutProduit(char nomFichier_kokou[],PRODUIT p_kokou){
    FILE *f_kokou=open(nomFichier_kokou,"a");
    if(f_kokou){
        fprintf(f_kokou,"%d %s %d %d %d %d %d\n",p_kokou.id_kokou,p_kokou.libelle_kokou,
                p_kokou.prix_kokou,p_kokou.qte_kokou,p_kokou.date_kokou.j_kokou,
                p_kokou.date_kokou.m_kokou,p_kokou.date_kokou.a_kokou);
        fclose(f_kokou);
    }
}
void afficher(char nomFichier_kokou[], int n_kokou){
   PRODUIT p_kokou;
   FILE *f_kokou=open(nomFichier_kokou,"r");
   int i_kokou=1;
    if(f_kokou){
        while (!feof(f_kokou) && i_kokou<=n_kokou){
            fscanf(f_kokou,"%d %s %d %d %d %d %d",&p_kokou.id_kokou,&p_kokou.libelle_kokou,
                &p_kokou.prix_kokou,&p_kokou.qte_kokou,&p_kokou.date_kokou.j_kokou,
                &p_kokou.date_kokou.m_kokou,&p_kokou.date_kokou.a_kokou);

            printf("%d %s %d %d %d %d %d \n",p_kokou.id_kokou,p_kokou.libelle_kokou,
                p_kokou.prix_kokou,p_kokou.qte_kokou,p_kokou.date_kokou.j_kokou,
                p_kokou.date_kokou.m_kokou,p_kokou.date_kokou.a_kokou);

                i_kokou++;
        }
        fclose(f_kokou);
    }
}
