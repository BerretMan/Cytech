#include <stdio.h>
#include <math.h>
int main(int argc , char** argv) { 
    int nb;
    char prenom[100],nom[100];
    printf("\nEntrez votre prénom ");
    scanf("%s",&prenom);
    printf("Entrer votre nom ");
    scanf("%s",&nom);
    do {
        printf("Entrer votre age ");
        scanf("%d",&nb);
        printf("%d",nb);
    }
    while(nb >pow(2,7) || nb <0);
    printf("Voilà ce que vous avez entré: \nNom: %s\nPrénom: %s\nAge: %d ans\n",prenom,nom,nb);
    return 0;
}