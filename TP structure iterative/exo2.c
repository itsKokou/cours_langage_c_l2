/* Ecrire un programme qui permet de saisir une s�rie de N valeurs. Le programme d�termine et affiche
le nombre de valeurs positives et le nombre de valeurs n�gatives.*/
#include<stdio.h>
main()
{
    int n,i,nbre,cpt,cpt2;
    do{
        printf("Combien de nombre voulez-vous saisir ? \n");
        scanf("%d",&n);
    }while(n<=0);
    cpt=0;
    cpt2=0;
    for(i=1;i<=n;i++){
        printf("Entrez un nombre : ");
        scanf("%d",&nbre);
        if (nbre>=0){
            cpt+=1;
        }else{
            cpt2+=1;
        }
    }
    printf("Vous avez saisi %d valeurs positive(s) et %d valeur negative(s).",cpt,cpt2);
}
