#ifndef LISTES_H
#define LISTES_H


typedef struct maillon{
  int donnee;
  struct maillon* suivant;
}maillon;
typedef maillon* Liste;

/* Le prototype/signature de toutes mes fonctions/procédures */
maillon* creerMaillon(int donnee);

Liste ajouterTete(Liste maListe, int donnee);

void afficher(Liste maListe);

Liste ajouterFin(Liste maListe, int donnee);

Liste ajouterPos(Liste maListe,int valeur,int pos);

Liste supprimerDebut(Liste maListe);

Liste supprimerFin(Liste maListe);

Liste supprimerPos(Liste maListe,int pos);

Liste viderListe(Liste maListe);

Liste supFirst(Liste maListe, int elt);

Liste supAllOccurence(Liste maListe, int elt);


#endif