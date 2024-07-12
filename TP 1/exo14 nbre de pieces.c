#include<stdio.h>
main()
{
    int mont,x,cent=0,dix=0,cinqt=0, cinq=0,un=0, vingt=0;
    do{
        printf("Entrez le montant : ");
        scanf("%d",&mont);
    }while(mont<=0);
    x=mont;
    if (mont>=100){
        cent=mont/100;
        mont=mont%100;
        if (mont>=50){
            cinqt=mont/50;
            mont=mont%50;
            if (mont>=25){
                vingt=mont/25;
                mont=mont%25;
                if (mont>=10){
                    dix=mont/10;
                    mont=mont%10;
                    if (mont>=5){
                        cinq=mont/5;
                        mont=mont%5;
                        if (mont>=1){
                            un=mont;
                        }
                    }else{
                        if (mont>=1){
                            un=mont;
                        }
                    }
                } else{
                    if (mont>=5){
                        cinq=mont/5;
                        mont=mont%5;
                        if (mont>=1){
                            un=mont;
                        }
                    }else{
                        if (mont>=1){
                            un=mont;
                        }
                    }
                }
            } else{
                if (mont>=10){
                    dix=mont/10;
                    mont=mont%10;
                    if (mont>=5){
                        cinq=mont/5;
                        mont=mont%5;
                        if (mont>=1){
                            un=mont;
                        }
                    }else{
                        if (mont>=1){
                            un=mont;
                        }
                    }
                } else{
                    if (mont>=5){
                        cinq=mont/5;
                        mont=mont%5;
                        if (mont>=1){
                            un=mont;
                        }
                    }else{
                        if (mont>=1){
                            un=mont;
                        }
                    }
                }
            }
        }else{
            if (mont>=25){
                vingt=mont/25;
                mont=mont%25;
                if (mont>=10){
                    dix=mont/10;
                    mont=mont%10;
                    if (mont>=5){
                        cinq=mont/5;
                        mont=mont%5;
                        if (mont>=1){
                            un=mont;
                        }
                    }else{
                        if (mont>=1){
                            un=mont;
                        }
                    }
                } else{
                    if (mont>=5){
                        cinq=mont/5;
                        mont=mont%5;
                        if (mont>=1){
                            un=mont;
                        }
                    }else{
                        if (mont>=1){
                            un=mont;
                        }
                    }
                }
            } else{
                if (mont>=10){
                    dix=mont/10;
                    mont=mont%10;
                    if (mont>=5){
                        cinq=mont/5;
                        mont=mont%5;
                        if (mont>=1){
                            un=mont;
                        }
                    }else{
                        if (mont>=1){
                            un=mont;
                        }
                    }
                } else{
                    if (mont>=5){
                        cinq=mont/5;
                        mont=mont%5;
                        if (mont>=1){
                            un=mont;
                        }
                    }else{
                        if (mont>=1){
                            un=mont;
                        }
                    }
                }
            }
        }

    } else{
        if (mont>=50){
            cinqt=mont/50;
            mont=mont%50;
            if (mont>=25){
                vingt=mont/25;
                mont=mont%25;
                if (mont>=10){
                    dix=mont/10;
                    mont=mont%10;
                    if (mont>=5){
                        cinq=mont/5;
                        mont=mont%5;
                        if (mont>=1){
                            un=mont;
                        }
                    }else{
                        if (mont>=1){
                            un=mont;
                        }
                    }
                } else{
                    if (mont>=5){
                        cinq=mont/5;
                        mont=mont%5;
                        if (mont>=1){
                            un=mont;
                        }
                    }else{
                        if (mont>=1){
                            un=mont;
                        }
                    }
                }
            } else{
                if (mont>=10){
                    dix=mont/10;
                    mont=mont%10;
                    if (mont>=5){
                        cinq=mont/5;
                        mont=mont%5;
                        if (mont>=1){
                            un=mont;
                        }
                    }else{
                        if (mont>=1){
                            un=mont;
                        }
                    }
                } else{
                    if (mont>=5){
                        cinq=mont/5;
                        mont=mont%5;
                        if (mont>=1){
                            un=mont;
                        }
                    }else{
                        if (mont>=1){
                            un=mont;
                        }
                    }
                }
            }
        }else{
            if (mont>=25){
                vingt=mont/25;
                mont=mont%25;
                if (mont>=10){
                    dix=mont/10;
                    mont=mont%10;
                    if (mont>=5){
                        cinq=mont/5;
                        mont=mont%5;
                        if (mont>=1){
                            un=mont;
                        }
                    }else{
                        if (mont>=1){
                            un=mont;
                        }
                    }
                } else{
                    if (mont>=5){
                        cinq=mont/5;
                        mont=mont%5;
                        if (mont>=1){
                            un=mont;
                        }
                    }else{
                        if (mont>=1){
                            un=mont;
                        }
                    }
                }
            } else{
                if (mont>=10){
                    dix=mont/10;
                    mont=mont%10;
                    if (mont>=5){
                        cinq=mont/5;
                        mont=mont%5;
                        if (mont>=1){
                            un=mont;
                        }
                    }else{
                        if (mont>=1){
                            un=mont;
                        }
                    }
                } else{
                    if (mont>=5){
                        cinq=mont/5;
                        mont=mont%5;
                        if (mont>=1){
                            un=mont;
                        }
                    }else{
                        if (mont>=1){
                            un=mont;
                        }
                    }
                }
            }
        }
    }
    printf("%d est composé de :\n",x);
    printf("%d piece(s) de 100.\n",cent);
    printf("%d piece(s) de 50.\n",cinqt);
    printf("%d piece(s) de 25.\n",vingt);
    printf("%d piece(s) de 10.\n",dix);
    printf("%d piece(s) de 5.\n",cinq);
    printf("%d piece(s) de 1.\n",un);
}
