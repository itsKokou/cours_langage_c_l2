/*: Ecrire un programme qui demande à l’utilisateur de saisir un nombre entier compris entre 10 et 20,
jusqu’à ce que la réponse convienne. En cas de réponse supérieure à 20, on fera apparaitre un message « Plus
petit », et inversement « Plus grand !» si le nombre est inférieur à 10.*/
#include<stdio.h>
main()
{
    int nbre;
    do{
        printf("Entrez un entier compris entre 10 et 20: ");
        scanf("%d",&nbre);
        if(nbre>20){
            printf("Plus petit !\n");
        }else{
            if(nbre<10){
               printf("Plus grand !\n");
            }
        }
    }while(!(nbre>=10 && nbre<=20));
    printf("La reponse convient");
}


