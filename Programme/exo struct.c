#include<stdio.h>
//#define N 50
int main()
{
    int i,j;
    typedef struct{
        int j,m,a;
    }DATE;
    typedef struct{
        int id;
        char mat[10],prenom[50],nom[40];
        DATE dn;
        float moy;
    }ETUDIANT;
    ETUDIANT classe[]={
         {
          1,
          "mat001",
          "Kokou",
          "Godwin",
          {10,11,2002},
          13.5
         },
         {
          2,
          "mat002",
          "Kwaku",
          "winGod",
          {10,10,2003},
          19.5
         },
         {
          3,
          "mat003",
          "David",
          "TANGUY",
          {8,05,2006},
          10.32
         },
         {
          4,
          "mat004",
          "Abou",
          "Boutiquier",
          {9,01,2003},
          16.19
         },
         {
          5,
          "mat005",
          "Gildas",
          "MOUNT",
          {5,03,2001},
          19.78
         }
    };
    puts("Avant Tri :");
    for (i=0;i<5;i++){
        printf("ID : %d \n",classe[i].id);
        printf("MATRICULE : %s \n",classe[i].mat);
        printf("PRENOM : %s \n",classe[i].prenom);
        printf("NOM : %s \n",classe[i].nom);
        printf("NAISSANCE : %d/%d/%d \n ",classe[i].dn.j,classe[i].dn.m,classe[i].dn.a);
        printf("MOYENNE : %.2f \n \n",classe[i].moy);
    }
    ETUDIANT x;
     for(i=1;i<5;i++){
        x=classe[i];
        j=i;
        while(j>0 && classe[j-1].moy>x.moy){
            classe[j]=classe[j-1];
            j=j-1;
        }
        classe[j]=x;
    };
    puts("Apres Tri :");
    for (i=0;i<5;i++){
        printf("ID : %d \n",classe[i].id);
        printf("MATRICULE : %s \n",classe[i].mat);
        printf("PRENOM : %s \n",classe[i].prenom);
        printf("NOM : %s \n",classe[i].nom);
        printf("NAISSANCE : %d/%d/%d \n ",classe[i].dn.j,classe[i].dn.m,classe[i].dn.a);
        printf("MOYENNE : %.2f \n \n",classe[i].moy);
    };
}
