/*. Les élections législatives obéissent à la règle suivante :
- Lorsque l’un des candidats obtient plus de 50% des suffrages, il est élu dès le premier tour ;
- En cas de deuxièmetour, peuvent participer uniquement les candidats ayant obtenu au moins
12,5% des voix au premier tour.
Ecrire un programme qui permet de saisir des scores de quatre (4) candidats au premier tour.
Le programme traitera ensuite le candidat numéro 1 (et uniquement lui) : il dira s’il est élu,
battu, s’il se trouve en ballotage favorable (s’il participe au second tour en étant arrivé en tête
à l’issue du premier tour) ou défavorable (il participe au second tour sans avoir été en tête au
premier tour).*/
#include<stdio.h>
main()
{
    float score1,score2,score3,score4;
    printf("Entrez les scores des quatres candidats : ");
    scanf("%f %f %f %f",&score1,&score2,&score3,&score4);
    if (score1>=50){
        printf("Le candidat 1 est elu.");
    }else{
        if(score1>=12.5){
            if (score1>=score2 && score1>=score3 && score1>=score4){
                printf("Le candidat 1 est en ballotage favorable");
            }else{
               printf("Le candidat 1 est en ballotage defavorable");
            }
        }else{
            printf("Le candidat 1 est battu.");
        }
    }
}
