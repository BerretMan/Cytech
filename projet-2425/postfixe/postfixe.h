/** Évaluation d'une expression en notation préfixe
  * En-têtes
  * @author Romain DUJOL
  */

#ifndef _POSTFIXE_H
#define _POSTFIXE_H

/** Évalue une expression en notation postfixe
  * @param expression l'expression à évaluer
  * @param resultat (sortie uniquement) *pointeur* vers la valeur de l'expression (uniquement si la fonction retourne EXIT_SUCCESS)
  * @return EXIT_SUCCESS si l'expression est syntaxiquement correcte
  *         EXIT_FAILURE sinon
  */
int POSTFIXE_evaluation(char *expression, int *resultat) ;


/** Détermine si un char* est un nombre
  * @param c le char* à évaluer
  * @return 1 si le char* est un nombre
  *         0 sinon
  */
int isnumber(char* c) ;

/** Détermine si l'expression est valide en notation postfixe
  * @param expression le char* à évaluer
  * @return 1 si le char* est valide
  *         0 sinon
  */
int expression_valide(char *expression);

#endif // _POSTFIXE_H