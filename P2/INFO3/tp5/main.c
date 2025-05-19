#include "arbre.h"
#include "abr.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    arbre a_un=creerArbreBinaire(42,NULL,NULL);
    arbre a_deux= creerArbreBinaire(42,creerArbreBinaire(24,NULL,NULL),NULL);
    arbre a_trois=creerArbreBinaire(42,creerArbreBinaire(24,NULL,NULL),creerArbreBinaire(53,creerArbreBinaire(21,NULL,NULL),creerArbreBinaire(55,NULL,NULL)));
    
    a_un=insertionArbre(43,a_un);
    afficherInfixe(a_un);

    return 0;
}