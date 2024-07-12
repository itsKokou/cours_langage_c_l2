// Ecrire un programme qui affiche les
// caracteres et leur code ASCII. Un caractere est code sur 1 octet
#include<stdio.h>
main()
{
    int i;
    for(i=0;i<=256;i++){      // on peut mettre 256,500...
            printf(" %c => %d\n",i,i);
    }
}
