/** Évaluation d'une expression en notation préfixe
  * Implémentation
  * @author Hill Zak
  */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prefixe.h"

int estNombre(char* expression) {
  int estNombre = 1;
  for (int i = 0; estNombre && i < strlen(expression); i++) {
    if (!isdigit(expression[i])) {
      estNombre = 0;
    }
  }
  return estNombre;
}

int PREFIXE_arbre(char *expression, ARBRE *a) {
  int len = strlen(expression);
  if (len <= 0) {
    return EXIT_FAILURE;
  }

  char premier = expression[0];
  if (isdigit(premier)) {
    char* nombre = malloc(sizeof(char));
    int i = 0;
    while (isdigit(expression[i])) {
      nombre = realloc(nombre, sizeof(char) * (i + 2));
      nombre[i] = expression[i];
      i++;
    }
    nombre[i] = '\0';

    *a = ARBRE_creerFeuille(nombre);
  
  } else {
    ARBRE g = NULL;
    ARBRE d = NULL;

    int nbrEspaces = 0;
    for (int i = 0; nbrEspaces < 2; i++) {
      if (len <= i) {
        return EXIT_FAILURE;
      }
      if (expression[i] == ' ') {
        nbrEspaces++;
        if (PREFIXE_arbre(expression + (i + 1), nbrEspaces == 1 ? &g : &d) == EXIT_FAILURE) {
          return EXIT_FAILURE;
        }
      }
    } 

    char* operateurStr = malloc(sizeof(char) * 2);
    operateurStr[0] = premier;
    operateurStr[1] = '\0';
    
    *a = ARBRE_creer(operateurStr, g, d);
  }

  return EXIT_SUCCESS ;
}

int PREFIXE_evaluationArbre(ARBRE a) {
  if (estNombre(a->etiq)) {
    return atoi(a->etiq);
  }

  char* etiqG = a->gauche->etiq;
  char* etiqD = a->droite->etiq;
  int valeurG = estNombre(etiqG) ? atoi(etiqG) : PREFIXE_evaluationArbre(a->gauche);
  int valeurD = estNombre(etiqD) ? atoi(etiqD) : PREFIXE_evaluationArbre(a->droite);

  switch (a->etiq[0]) {
    case '*':
      return valeurG * valeurD;
    case '+':
      return valeurG + valeurD;
    case '-':
      return valeurG - valeurD;
  }
  
  // Ne devrait jamais arriver
  ARBRE_vider(&a);
  exit(EXIT_FAILURE);
}

int PREFIXE_evaluation(char *expression, int *resultat) {
  ARBRE a = NULL;
  char* expressionPropre = malloc(sizeof(char));

  int len = strlen(expression);
  int nbrEspaces = 0;
  int j = 0;
  for (int i = 0; i < len; i++) {
    char c = expression[i];
    int ajouterEspace = c == ' ' && i < len - 1 && expression[i + 1] != ' ';
    if (ajouterEspace || isdigit(c) || c == '*' || c == '+' || c == '-') {
      if (ajouterEspace) {
        nbrEspaces++;
      }
      expressionPropre = realloc(expressionPropre, sizeof(char) * (j + 2));
      expressionPropre[j] = c;
      j++;
    }
  }
  expressionPropre[j] = '\0';

  int codeArbre = PREFIXE_arbre(expressionPropre, &a);
  free(expressionPropre);
  
  if (codeArbre == EXIT_FAILURE || (ARBRE_estFeuille(a) && nbrEspaces != 0) || ARBRE_taille(a) != (nbrEspaces + 1) ) {
    ARBRE_vider(&a);
    return EXIT_FAILURE;
  }
  
  *resultat = PREFIXE_evaluationArbre(a);
  ARBRE_vider(&a);
  
  return EXIT_SUCCESS ;
}

