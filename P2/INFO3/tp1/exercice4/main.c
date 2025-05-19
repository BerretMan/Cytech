#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
    int choix;int a; int b;
    do {
        printf("Menu principale - sélectionner la fonction \n 1-puissanceNT\n 2-puissanceT\n 3-pgcd\n 4-sommeChiffre");
        scanf("%d",&choix);
    } while (0 >0 && choix <5);
    switch(choix) {
        case 1:
            printf("a=");
            scanf("%d",&a);
            printf("b=");
            scanf("%d",&b);
            printf("%d^%d=%d",a,b,puissanceNonTerminale(a,b));break;
        case 2:            
            printf("a=");
            scanf("%d",&a);
            printf("b=");
            scanf("%d",&b);
            printf("%d^%d=%d",a,b,puissanceTerminale(a,b,1));break;
        case 3:
            printf("a=");
            scanf("%d",&a);
            printf("b=");
            scanf("%d",&b);
            printf("pgcd(%d,%d)=%d",a,b,pgcd(a,b));break;
        case 4:            
            printf("a=");
            scanf("%d",&a);
            printf("La somme des chiffres de %d est de %d",a,sommeChiffre(a));break;
    }

    return 0;
}