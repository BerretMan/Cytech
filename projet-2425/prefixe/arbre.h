/** Arbre binaire
  * En-têtes
  * @author Romain DUJOL
  */

#ifndef _ARBRE_H
#define _ARBRE_H

typedef struct noeud
  {
    char         *etiq   ;
    struct noeud *gauche ;
    struct noeud *droite ;
  }
Noeud ;

/** Arbre d'une expression */
typedef Noeud *ARBRE ;

/** Crée un arbre binaire vide
  * @return un arbre binaire vide
  */
ARBRE ARBRE_creerVide() ;

/** Vérifie l'arbre est vide
  * @param a l'arbre à tester
  * @return "Vrai" si l'arbre est vide, "Faux" sinon
  */
int ARBRE_estVide(ARBRE a) ;

/** Crée un noeud
  * @param etiquette étiquette du noeud
  * @param gauche sous-arbre gauche
  * @param droite sous-arbre droite
  * @return le nouveau noeud
  */
ARBRE ARBRE_creer(char *etiquette, ARBRE gauche, ARBRE droite) ;

/** Crée une feuille
  * @param etiquette étiquette de la feuille
  * @return la nouvelle feuille
  */
ARBRE ARBRE_creerFeuille(char * etiquette) ;

/** Vérifie l'arbre est une feuille
  * @param a l'arbre à tester
  * @return "Vrai" si l'arbre est une feuille, "Faux" sinon
  */
int ARBRE_estFeuille(ARBRE a) ;

/** Détruit tous les noeuds d'un arbre
  * @param a *pointeur* vers l'arbre à détruire
  * @post a est vide
  */
void ARBRE_vider(ARBRE *a) ;

/** Affiche un arbre de manière prefixe
  * @param a l'arbre à afficher
  */
void ARBRE_afficherPrefixe(ARBRE a) ;

/** Calcule la taille d'un arbre
  * @param a l'arbre
  * @return La taille de l'arbre
  */
int ARBRE_taille(ARBRE a);

#endif // _ARBRE_H
