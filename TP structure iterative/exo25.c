/*Ecrire un programme qui permet de saisir un nombre entier supérieur à 10. Le programme affiche :
- La somme des nombres pairs compris entre un et la valeur saisie,
- Le produit des nombres impairs compris entre un et la valeur saisie,
- La moyenne des nombres premiers compris entre un et la valeur saisie
- Le nombre de nombres parfaits entre un et la valeur saisie*/
#include<stdio.h>
main()
{
    int n,i,s,s1,s2,p,j,cpt,cpt2;
    float som;
    do{
        printf("Entrez un nombre positif : ");
        scanf("%d",&n);
    }while(n<=10);
    s=0;
    p=1;
    som=0;
    cpt=0;
    cpt2=0;
    for(i=1;i<=n;i++){
       if(i%2==0){
        s+=i;
       }else{
          p*=i;
       }
       j=1;
       s1=i;
       s2=0;
       while(j<=i/2){
          if(i%j==0){
             s1+=j;
             s2+=j;
          }
          j++;
      }
      if (s1==i+1){
            cpt=cpt+1;
            som+=i;
      }
      if(s2==i){
        cpt2+=1;
      }
    }
    printf("La somme des nombres pairs est %d\n",s);
    printf("Le produit des nombres impairs est %d\n",p);
    printf("La moyenne des nombres premiers est %f\n",(som/cpt));
    printf("Le nombre de nombres parfaits est %d\n",cpt2);
}
