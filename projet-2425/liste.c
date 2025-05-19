/** Liste chaînée
  * Implémentation
  * @author Serrano Lucas
  */

#include <stdlib.h>
#include "liste.h"

LISTE LISTE_creerVide() {
  return NULL ;
}

int LISTE_estVide(LISTE l) {
  return  l==NULL;
}

LISTE LISTE_ajouterTete(LISTE l, char *e) {
  MaillonListe* m = creerMaillon(e);
  m->suivant=l;
  l=m;
  return l ;
}

LISTE LISTE_miroir(LISTE l) {
  LISTE temp_l = LISTE_creerVide();
  while (l != NULL) {
    temp_l = LISTE_ajouterTete(temp_l,l->valeur);
    l=l->suivant;
  }

  return NULL ;
}

void LISTE_vider(LISTE *l) {
  while (LISTE_estVide(*l)) {
    MaillonListe* temp = *l;
    *l=(*l)->suivant;
    free(temp);
  }
}

MaillonListe* creerMaillon(char* valeur) {
    MaillonListe* m;
    m = malloc(sizeof(MaillonListe));
    m->valeur=valeur;
    m->suivant=NULL;
    return m;
}


