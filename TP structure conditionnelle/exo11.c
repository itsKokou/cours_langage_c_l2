#include<stdio.h>
main()
{
    int h,m,s;
    do {
            printf("Entrez l'heure sous format h : min : s : ") ;
            scanf("%d %d %d",&h,&m,&s);
    }while (!(h>=0&&h<=23 && m>=0&&m<=59 && s>=0 && s<=59));
    s=s+1;
    if (s==60){
        if (m<59){
            m=m+1;
            s=0;
        }else{
            if (h<23){
                h=h+1;
                m=0;
                s=0;
            }else{
                h=0;
                m=0;
                s=0;
            }
        }
    }
    printf("Dans une seconde, il sera %dh: %dmn: %ds",h,m,s);
}
