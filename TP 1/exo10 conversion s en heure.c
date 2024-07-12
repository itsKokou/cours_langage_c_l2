#include<stdio.h>
main()
{
    int sec,h,m,s,t;
    do{
        printf("Entrez le nombre de seconde à convertir : ");
        scanf("%d",&sec);
    }while(sec<=0);
    t=sec;
    if (sec>=3600){
        h=sec/3600;
        sec=sec%3600;
        if (sec>=60){
            m=sec/60;
            s=sec%60;
        }else{
            m=0;
            s=sec;
        }

    }else {
        h=0;
        m=sec/60;
        s=sec%60;
    }
    printf("%d = %d h : %d m : %d s",t,h,m,s);
}
