/** Pile (LIFO)
  * Implémentation
  * @author Serrano Lucas
  */

#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

MaillonPile* creerElementPile (int valeur) {
    MaillonPile* m = (MaillonPile*)malloc(sizeof(MaillonPile));
    m->valeur = valeur;
    m->suivant = NULL;
    return m;
}


PILE PILE_creerVide() {
  return NULL ;
}

int PILE_estVide(PILE p) {
  return p==NULL;
}

void PILE_empiler(PILE *p, int x) {
  MaillonPile* elt= creerElementPile(x);
  elt->suivant=*p;
  *p=elt;
}

int PILE_depiler(PILE *p) {
  if (PILE_estVide(*p)) {
    printf("ERROR: pile vide, impossible de dépiler");
    return EXIT_FAILURE;
  } else {
      MaillonPile* tmp = *p; 
      int valeur = tmp->valeur;
      *p = tmp->suivant; 
      free(tmp);
      return valeur;
  }
}

void PILE_vider(PILE *p) {
  if (!PILE_estVide(*p)) {
    PILE_depiler(p);
    PILE_vider(&(*p)->suivant);
  }
}

