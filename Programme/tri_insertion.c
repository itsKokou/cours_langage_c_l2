#include<stdio.h>
main()
{
    int t[4]={21,0,-5,18};
    int i,j,n,x;
    n=4;
    puts("Avant le tri : ");
    for (i=0;i<n;i++){
            printf(" %d |",t[i]);
    }
    for(i=1;i<n;i++){
        x=t[i];
        j=i;
        while(j>0 && t[j-1]>x){
            t[j]=t[j-1];
            j=j-1;
        }
        t[j]=x;
    }
    printf(" \n");
    puts("Apres le tri : ");
    for (i=0;i<n;i++){
            printf(" %d |",t[i]);
    }
}
