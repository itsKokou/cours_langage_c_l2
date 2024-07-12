// Ecrire un programme qui permet de saisir une lettre, le prgramme affiche la lettre saisie
#include<stdio.h>
main()
{
    char x;
    printf("Veuillez entrer une lettre : ");
    scanf("%c",&x);
    if (x>='A' && x<='Z' || x>='a' && x<='z'){
         printf("La lettre saisie est '%c'",x);
    }else{
        printf("%c n'est pas une lettre",x);
    }
}
