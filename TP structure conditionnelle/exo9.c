#include<stdio.h>
main()
{
    char x;
    int y;
    do {
        printf("Entrez une lettre : ");
        scanf("%c",&x);
    }while(!(x>='A' && x<='Z' || x>='a' && x<='z'));
    if (x>=65 && x<=90){
       y=x+32;
    }else {
        y=x-32;
    }
    printf(" %c ==> %c",x,y);
}
