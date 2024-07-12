/*Ecrire un programme qui permet de saisir un nombre. Le programme détermine et affiche si le
nombre est un nombre parfait ou pas. Un nombre est parfait si la somme de ses diviseurs excepté lui-même est
égale à lui-même.*/
 #include<stdio.h>
main()
{
    int nbre,i,s;
    printf("Entrez un nombre : ");
    scanf("%d",&nbre);
    s=0;
    i=1;
    while(i<=nbre/2){
        if(nbre%i==0){
            s+=i;
        }
        i++;
    }
    if (s==nbre){
        printf("%d est parfait",nbre);
    }else{
         printf("%d n'est pas parfait",nbre);
    }

}
