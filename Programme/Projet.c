#include<stdio.h>
typedef struct{
    int id;
    char libelle[50];
    int coef;
}MATIERE;
typedef struct{
    int id;
    int idMatiere;
    float note;
    int type_Eval;
}EVALUATION;
main()
{
   // enum couleur{ROUGE,VERT,BLEU}; // ce sont des constantes. ROUGE vaut 0, BLEU signifie 1 et BLEU 2
    //printf("%d",VERT);
    enum type_Eval{DEVOIR,EXAM};
    printf("%d",DEVOIR);
}
