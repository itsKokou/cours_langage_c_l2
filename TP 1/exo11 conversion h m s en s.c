#include<stdio.h>
main()
{
    int h,m,s,sec;
    do{
        printf("Entrez l'heure sous format heure min sec : ");
        scanf("%d %d %d",&h,&m,&s);
    }while(h<0 || m<0 || s<0 || m>=60 || s>=60 );
    sec= h*3600+m*60+s;
    printf("%d h : %d mn : %d s = %d s",h,m,s,sec);
}
