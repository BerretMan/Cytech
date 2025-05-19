/** Pile (LIFO)
  * En-têtes
  * @author Romain DUJOL
  */

#ifndef _PILE_H
#define _PILE_H

typedef struct maillonPile
  {
    int                 valeur  ;
    struct maillonPile *suivant ;
  }
MaillonPile ;

/** Pile d'entiers */
typedef MaillonPile *PILE ;

/** Crée une pile vide
  * @return une pile vide
  */
PILE PILE_creerVide() ;

/** Vérifie si une pile est vide
  * @param p pile à tester
  * @return "Vrai" si la pile est vide, "Faux" sinon
  */
int PILE_estVide(PILE p) ;

/** Modifie une pile en y empilant un entier
  * @param p *pointeur* vers la pile
  * @param x entier à empiler dans `p`
  */
void PILE_empiler(PILE *p, int x) ;

/** Modifie une pile en dépilant l'entier en haut de celle-ci
  * @param p *pointeur* vers la pile
  * @return l'entier en tête de pile
  * @pre    La pile n'est pas vide.
  * @post   La pile ne contient plus l'entier dépilé.
  */
int PILE_depiler(PILE *p) ;

/** Modifie une pile en la vidant
  * @param p *pointeur* vers la pile
  * @post La pile pointée par `p` est vide
  */
void PILE_vider(PILE *p) ;


/** Modifie une pile en la vidant
  * @param valeur la valeur d'un elt de pile
  * @post un element de pile
  */
MaillonPile* creerElementPile (int valeur);


#endif // _PILE_H
