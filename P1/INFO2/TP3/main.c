#include "puissance4.h"

#define N 7
int main(){
    int** grille=allouer(N);
    int i=1;
    initialiser(grille,N);
    afficher(grille,N);
    while (1) {
        jouer(grille,N,i%2+1);
        afficher(grille,N);  
        i++;
    }
    
    return 0;
}