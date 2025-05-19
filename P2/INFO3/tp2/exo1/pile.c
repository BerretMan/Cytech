#include "pile.h"
#include <stdio.h>
#include <stdlib.h>

maillonPile* creerElementPile (int valeur) {
    maillonPile* m = (maillonPile*)malloc(sizeof(maillonPile));
    m->valeur = valeur;
    m->suivant = NULL;
    return m;
}


void emPiler(Pile* p, int valeur) {
    maillonPile* elt = creerElementPile(valeur);
    elt->suivant = *p; 
    *p = elt; 
}


int depiler(Pile* p) {
    if (*p == NULL) {
        printf("Dépiler une pile vide\n");
        exit(EXIT_FAILURE);
    } else {
        maillonPile* tmp = *p; 
        int valeur = tmp->valeur;
        *p = tmp->suivant; 
        free(tmp);
        return valeur;
    }
}


void afficherP(Pile p) {
    maillonPile* curseur = p;
    while (curseur != NULL) {
        printf("%d\n", curseur->valeur);
        curseur = curseur->suivant; 
    }
}


int compterP(Pile p, int acc) {
    if (p == NULL) {
        return acc;
    } else {
        return compterP(p->suivant, acc + 1);
    }
}


Pile inverserP(Pile p1, Pile p2) {
    while (compterP(p1, 0) != 0) {
        emPiler(&p2, depiler(&p1));
    }
    return p2;
}


void viderP(Pile* p) {
    while (compterP(*p, 0) != 0) {
        depiler(p);
    }
}