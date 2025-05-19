#include "arbre.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    arbre a_un=creerArbreBinaire(42,NULL,NULL);
    arbre a_deux= creerArbreBinaire(42,creerArbreBinaire(24,NULL,NULL),NULL);
    arbre a_trois=creerArbreBinaire(42,creerArbreBinaire(24,NULL,NULL),creerArbreBinaire(53,creerArbreBinaire(21,NULL,NULL),creerArbreBinaire(55,NULL,NULL)));
    printf("Taille arbre 1: %d\nTaille arbre 2: %d\nTaille arbre 3: %d\n",taille(a_un),taille(a_deux),taille(a_trois));
    printf("-----\n");  
    printf("Hauteur arbre 1: %d\nHauteur arbre 2: %d\nHauteur arbre 3: %d\n",hauteur(a_un),hauteur(a_deux),hauteur(a_trois));
    printf("-----\n");  
    printf("NbFeuilles arbre 1: %d\nNbFeuilles arbre 2: %d\nNbFeuilles arbre 3: %d\n",nbFeuilles(a_un),nbFeuilles(a_deux),nbFeuilles(a_trois));
    printf("------\n");
    afficherInfixe(a_trois);
    printf("]\n");
    return 0;
}