/*Ecrire un programme qui permet de saisir une date (jour, mois et année). Le programme
détermine et affiche s’il s’agit d’une date valide.*/
#include<stdio.h>
main()
{
    int an,m,j;
    printf("Entrez une date sous le format jour mois annee : ");
    scanf("%d %d %d",&j,&m,&an);
    if ((j>=1&&j<=31)&&(m>=1&&m<=12)&&(an>0)){
            switch(m){
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if(j>=1&&j<=31){
                    printf("%d/%d/%d est valide.",j,m,an);
                }
                break;
            case 2:
                if(an%4==0 && an%100!=0 || an%400==0){
                    if (j>=1&&j<=29){
                        printf("%d/%d/%d est valide.",j,m,an);
                    }else{printf("%d/%d/%d est invalide.",j,m,an);}
                }else{
                    if (j>=1&&j<=28){
                        printf("%d/%d/%d est valide.",j,m,an);
                    }else{printf("%d/%d/%d est invalide.",j,m,an);}
                }
            break;
            case 4:
            case 6:
            case 9:
            case 11:
                if(j>=1&&j<=30){
                    printf("%d/%d/%d est valide.",j,m,an);
                }else{printf("%d/%d/%d est valide.",j,m,an);}
                break;
                }
    }else{
        printf("%d/%d/%d est invalide.",j,m,an);
    }
}
