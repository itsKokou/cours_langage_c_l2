/*Ecrire un programme qui permet de saisir une s�rie de nombre. Le programme d�termine et
affiche tous les nombre saisie ainsi que leur somme et leur produit.
 la saisie est conditionn�e par une question � Voulez-vous saisir un nombre [O/N] ? �.
 Si la r�ponse est � N � alors la saisie s�arr�te.*/
 #include<stdio.h>
main()
{
    int nbre,s,p;
    char rep,x;
    s=0;
    p=1;
    x='O';
    while(x!='N'){
        printf("Entrez un nombre : ");
        scanf("%d",&nbre);
        s+=nbre;
        p*=nbre;
        printf("Entrez 'N' pour arreter ou 'O' pour continuer :\n");
        scanf("%c",&rep);
        x=rep;
    }
    printf("La somme vaut %d et le produit vaut %d",s,p);
}
