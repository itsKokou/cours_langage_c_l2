#include<stdio.h>

typedef struct{
    char matricule[20];
    char nom[20];
    char prenom[30];
    char dateNaiss[11];
    char ville[50];
    char tel[10];
    char email[50];
    float moyenne;
}Etudiant;
void uploadFichier(Etudiant[]);
void remplirTab(void);
void affichage(Etudiant[]);
Etudiant t_etudiants_kokou[18];

Etudiant p = {"MAT00001","DIOP", "Idrissa_Maoudo","12-10-1960","Dakar","771435465","imaou@gmail.com", 19.5};
Etudiant p1 = {"MAT00034","FALL", "Aliou_Demba","19-12-1961","Thies","771435465","aloubi@yahoo.fr", 12};
Etudiant p2 = {"MAT00676","SY", "Mademba_Ndiaye","18-10-2007","Guediawaye","771435465","mademba@yahoo.fr", 12.54};
Etudiant p3 = {"MAT00577","NIANG", "Aly","21-22-2009","Thies","771435465","msd@yahoo.fr", 12};
Etudiant p4 = {"MAT00055","FAYE", "Madeleine","12-10-1999","Louga","771435465","faye@yahoo.fr", 10};
Etudiant p5 = {"MAT00656","DIENG", "Awa","23-10-1961","Darou","771435465","eve@live.fr", 11.33};
Etudiant p6 = {"MAT00008","FAYE", "Fatoumata","11-10-1893","Thies","771435465","mademba@yahoo.fr", 17.5};
Etudiant p7 = {"MAT05656","GUEYE", "Adama","30-10-1093","Dakar","771435465","adama@yahoo.fr", 15.55};
Etudiant p8 = {"MAT00010","SAMB", "Alioune","12-12-2001","Thies","771435465","mademba@yahoo.fr", 13.13};
Etudiant p9 = {"MAT00011","DIALLO", "Mactar","12-10-1934","Pout","771435465","dialmac@yahoo.fr", 15.15};
Etudiant p10 = {"MAT00012","DIA", "Oumar","12-10-1943","Thies","771435465","diao@yahoo.fr", 16.44};
Etudiant p11 = {"MAT00013","SY", "Alassane","12-16-1961","France","771435465","alou@hotmail.fr", 17};
Etudiant p12 = {"MAT00014","KA", "Fatou","01-11-1988","Thies","771435465","mademba@yahoo.fr", 12};
Etudiant p13 = {"MAT00345","LY", "Yaya","02-19-2002","Tambacounda","771435465","yaya@gmail.com", 11};
Etudiant p14 = {"MAT00015","DIAKHATE", "Aicha","12-10-2001","Thies","771435465","diakh@yahoo.fr", 10.33};
Etudiant p15 = {"MAT00017","NIANG", "Maguette","23-03-1944","Fatick","771435465","max@yahoo.fr", 14.3};
Etudiant p16 = {"MAT00444","DIALLO", "Mbene","05-10-1999","Dakar","771435465","mbene92@yahoo.fr", 13.13};
Etudiant p17 = {"MAT00036","BA", "Sidi","03-12-2000","Dagana","771435465","basidi@yahoo.fr", 12.5};
main()
{
    remplirTab();
    uploadFichier( t_etudiants_kokou);
    affichage(t_etudiants_kokou);
}
void remplirTab(void){
    t_etudiants_kokou[0]=p;
    t_etudiants_kokou[1]=p1;
    t_etudiants_kokou[2]=p2;
    t_etudiants_kokou[3]=p3;
    t_etudiants_kokou[4]=p4;
    t_etudiants_kokou[5]=p5;
    t_etudiants_kokou[6]=p6;
    t_etudiants_kokou[7]=p7;
    t_etudiants_kokou[8]=p8;
    t_etudiants_kokou[9]=p9;
    t_etudiants_kokou[10]=p10;
    t_etudiants_kokou[11]=p11;
    t_etudiants_kokou[12]=p12;
    t_etudiants_kokou[13]=p13;
    t_etudiants_kokou[14]=p14;
    t_etudiants_kokou[15]=p15;
    t_etudiants_kokou[16]=p16;
    t_etudiants_kokou[17]=p17;
}
void uploadFichier(Etudiant x_kokou[]){
    FILE *f_kokou = fopen("etudiants.txt","w");
    int i_kokou;
    if(f_kokou){
        for (i_kokou = 0; i_kokou < 18; i_kokou++){
            fprintf(f_kokou,"%s %s %s %s %s %s %s %f\n",x_kokou[i_kokou].matricule,
                    x_kokou[i_kokou].nom,x_kokou[i_kokou].prenom,x_kokou[i_kokou].dateNaiss,
                    x_kokou[i_kokou].ville,x_kokou[i_kokou].tel,x_kokou[i_kokou].email,x_kokou[i_kokou].moyenne);
        }
        fclose(f_kokou);
    }
}
void affichage(Etudiant x_kokou[]){
    int i_kokou;
    puts("Voici les informations des etudiants : \n");
    for (i_kokou=0;i_kokou<18;i_kokou++){
        printf(" %d==> %s - %s - %s - %s - %s - %s - %s - %f\n",(i_kokou+1),x_kokou[i_kokou].matricule,
               x_kokou[i_kokou].nom,x_kokou[i_kokou].prenom,x_kokou[i_kokou].dateNaiss,x_kokou[i_kokou].ville,
               x_kokou[i_kokou].tel,x_kokou[i_kokou].email,x_kokou[i_kokou].moyenne);
    }
}
