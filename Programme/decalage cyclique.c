#include<stdio.h>
main()
{
     int t[4]={21,0,-5,18};
     int i,tmp,n;
     n=4;
     puts("Avant le decalage : ");
     for (i=0;i<n;i++){
            printf(" %d |",t[i]);
     }
     tmp=t[0];
     for(i=0;i<n;i++){
        t[i]=t[i+1];
     }
     t[n-1]=tmp;
     puts("Apres le decalage : ");
     for (i=0;i<4;i++){
            printf(" %d |",t[i]);
     }
}
