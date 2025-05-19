/** Liste chaînée
  * En-têtes
  * @author Romain DUJOL
  */

#ifndef _LISTE_H
#define _LISTE_H

typedef struct maillonListe
  {
    char                *valeur  ;
    struct maillonListe *suivant ;
  }
MaillonListe ;

/** Liste d'entiers */
typedef MaillonListe *LISTE ;

/** Crée une liste vide
  * @return une liste vide
  */
LISTE LISTE_creerVide() ;

/** Vérifie si une liste est vide
  * @param p liste à tester
  * @return "Vrai" si la liste est vide, "Faux" sinon
  */
int LISTE_estVide(LISTE l) ;

/** Renvoie une liste obtenue en ajoutant un élément en tête
  * @param l liste
  * @param e élément à ajouter
  * @return la liste obtenue en ajoutant `e` en tête de `l`
  */
LISTE LISTE_ajouterTete(LISTE l, char *e) ;

/** Renvoie la liste miroir
  * @param l liste
  * @return la liste miroir de `l`
  */
LISTE LISTE_miroir(LISTE l) ;

/** Modifie une liste en la vidant
  * @param l *pointeur* vers la liste
  * @post La liste pointée par `l` est vide
  */
void LISTE_vider(LISTE *l) ;

/** Crée un élément maillon de liste
  * @param valeur Le contenu du maillion
  * @post Le maillon
  */
MaillonListe* creerMaillon(char* valeur);

#endif // _LISTE_H

