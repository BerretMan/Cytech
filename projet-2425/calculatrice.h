/** Environnement général d'une calculatrice en mode interactif
  * En-têtes
  * @author Romain DUJOL
  */

#include "liste.h"

#ifndef _CALCULATRICE_H
#define _CALCULATRICE_H

/** Type de notation (préfixe, postfixe, ...) */
typedef enum notation { PREFIXE, POSTFIXE } Notation ;

/** Longueur maximale de la chaîne contenant l'expression */
#define LG_MAX 1023

/** Lance le selecteur de notation */
int selecteurMode(Notation* mode);

/** Convertit une expression en une liste de ses éléments constitutifs, *dans l'ordre dans lequel ils ont été saisis* */
LISTE listeExpression(char *expression) ;

/** Teste si un élément est un opérateur valide
  * @param element élément de l'expression à tester
  * @return "Vrai" si l'élément est un des trois opérateurs (+, -, *), "Faux" sinon
  */
int estOperateur(char *element) ;

/** Lancer une calculatrice en mode interactif
  * @param notation type de notation utililsée (préfixe ou postfixe)
  * @return EXIT_SUCCESS si tout s'est bien passé
  *         EXIT_FAILURE sinon
  */ 
int calculatrice(Notation notation) ;

#endif // _CALCULATRICE_H
