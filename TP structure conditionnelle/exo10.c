#include<stdio.h>
main()
{
    char x;
    printf("saisissez un caractere : ");
    scanf("%c",&x);
    if (x>='A' && x<='Z' || x>='a' && x<='z'){
        printf(" %c est une lettre",x);
    }else{
        if(x>='0'&& x<='9'){
           printf(" %c est un chiffre",x);
        }else{
            printf(" %c est un caractere special",x);
        }
    }
}
