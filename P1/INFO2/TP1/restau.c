#include <stdio.h>
#include <stdlib.h>

int VerifierStock(int indice,int s[6]) {
    if (indice <0 || indice>=6) {
        return -1;  
    }
    else {
        return s[indice]; 
    }
}

int main(int argc, char** argv) {
    int s[6]={0,1,2,3,4,5};
    int i;
    printf("Quels produit voulez vous connaître le stock?\n -Tranche d’emmental 0\n -Steak 1\n -Steak vegan 2\n -Tranche de tomate 3\n -Tranche de salade 4\n -Feuille de salade 5\n -Cornichon 6\n");
    scanf("%d",&i);
    switch(i) {
        case 0:
            printf("Nombre de tranche d'emmental: %d\n",VerifierStock(i,s));break;
        case 1:
            printf("Nombre de tranche d'emmental: %d\n",VerifierStock(i,s));break;
        case 2:
            printf("Nombre de tranche d'emmental: %d\n",VerifierStock(i,s));break;
        case 3:
            printf("Nombre de tranche d'emmental: %d\n",VerifierStock(i,s));break;
        case 4:
            printf("Nombre de tranche d'emmental: %d\n",VerifierStock(i,s));break;
        case 5:
            printf("Nombre de tranche d'emmental: %d\n",VerifierStock(i,s));break;
    }
    return 0;
}