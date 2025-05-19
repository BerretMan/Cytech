/** Arbre binaire
  * Implémentation
  * @author Hill Zak
  */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arbre.h"

ARBRE ARBRE_creerVide() {
  return NULL;
}

int ARBRE_estVide(ARBRE a) {
  return a->gauche == NULL && a->droite == NULL && a->etiq == NULL;
}

ARBRE ARBRE_creer(char *etiquette, ARBRE gauche, ARBRE droite) {
  ARBRE a = malloc(sizeof(Noeud));
  a->etiq = etiquette;
  a->gauche = gauche;
  a->droite = droite;
  return a;
}

ARBRE ARBRE_creerFeuille(char * etiquette) {
  return ARBRE_creer(etiquette, NULL, NULL);
}

int ARBRE_estFeuille(ARBRE a) {
  return a->gauche == NULL && a->droite == NULL;
}

void ARBRE_vider(ARBRE *a) {
  ARBRE arbre = *a;
  if (arbre != NULL) {
    ARBRE_vider(&arbre->gauche);
    ARBRE_vider(&arbre->droite);
    free(arbre->etiq);
    free(arbre);
  }
}

void ARBRE_afficherPrefixe(ARBRE a) {
  if (a != NULL) {
    printf("%s ", a->etiq);
    ARBRE_afficherPrefixe(a->gauche);
    ARBRE_afficherPrefixe(a->droite);
  }
}

int ARBRE_taille(ARBRE a) {
  return a == NULL ? 0 : 1 + ARBRE_taille(a->gauche) + ARBRE_taille(a->droite);
}
