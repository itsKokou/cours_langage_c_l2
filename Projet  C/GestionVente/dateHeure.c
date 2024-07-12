#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"global.h"

void heureAvec(void){
    time_t now= time(NULL);// lire l'heure courante
    //char heure[MAX]; // declarer variable qui va contenir l'heure
    strftime(heureA, sizeof(heureA),"%H:%M:%S", localtime(&now));
    // convertir l'heure en heure locale(localtime()) puis ecrit dans la variable l'heure avec le code format de l'heure
}
void dateAvec(void){
    time_t now= time(NULL);// lire l'heure courante
    //char date[MAX]; // declarer variable qui va contenir la date
    strftime(dateA, sizeof(dateA),"%d/%m/%Y", localtime(&now));
    // convertir l'heure en heure locale(localtime()) puis ecrit dans la variable la date avec le code format de la date
}
void dateHeure(void){
    time_t now= time(NULL);
    strftime(dHeure, sizeof(dHeure),"%d%m%Y%H%M%S", localtime(&now));
}
