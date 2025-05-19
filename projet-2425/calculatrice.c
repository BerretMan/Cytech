/** Environnement général d'une calculatrice en mode interactif
  * Implémentation
  * @author Hill Zak
  */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculatrice.h"
#include "postfixe/postfixe.h"
#include "prefixe/prefixe.h"


int selecteurMode(Notation* mode) {
  char entree[LG_MAX];
  char touche;

  do {
    printf("Veuillez selectionner le mode:\n");
    printf("(1) prefixe\n");
    printf("(2) postfixe\n");
    printf("(q) quitter\n");
    printf("> ");

    fgets(entree, LG_MAX, stdin);
    int i = 0;
    while (entree[i] == ' ' && i < strlen(entree)) {
      i++;
    }
    touche = entree[i];

    if (touche == '1' || touche == '2') {
      *mode = touche == '1' ? PREFIXE : POSTFIXE;
      return EXIT_SUCCESS;
    }

  } while (touche != 'q');

  return EXIT_FAILURE;
}

LISTE listeExpression(char *expression) {
  LISTE l = LISTE_creerVide();
  
  int len = strlen(expression);
  int nbrEspaces = 0;
  
  for (int i = 0; i < len; i++) {
    int c = expression[i];
    char* cStr = malloc(sizeof(char) * 2);
    cStr[0] = c;
    cStr[1] = '\0';

    int ajouterEspace = c == ' ' && i < len - 1 && expression[i + 1] != ' ';
    if (ajouterEspace || isdigit(c) || c == '*' || c == '+' || c == '-') {
      if (ajouterEspace) {
        nbrEspaces++;
      }
      LISTE_ajouterTete(l, cStr);
    }
  }

  return LISTE_miroir(l);
}

int estOperateur(char *element) {
  int i = 0;
  while (element[i] == ' ' && i < strlen(element)) {
    i++;
  }
  char c = element[i];
  return c == '*' || c == '+' || c == '-';
}

int calculatrice(Notation notation) {
  Notation mode = notation;
  
  while (1) {
    char expr[LG_MAX];
    int resultat;
    int code = EXIT_SUCCESS;

    printf("\n");
    printf("(m) changer de mode, (q) quitter\n");

    while (1) {
      printf("%s> ", mode == PREFIXE ? "prefixe" : "postfixe");
      
      fgets(expr, LG_MAX, stdin);
      
      for (int i = 0; i < strlen(expr); i++) {
        if (expr[i] == '\n') {
          expr[i] = '\0';
          break;
        }
      }
      
      if (strcmp(expr, "q") == 0) {
        return code;
      } else if (strcmp(expr, "m") == 0) {
        if (selecteurMode(&mode) == EXIT_FAILURE) {
          printf("Aucun mode selectionne\n");
          return EXIT_SUCCESS;
        }
        break;
      }

      switch (mode) {
        case PREFIXE:
          code = PREFIXE_evaluation(expr, &resultat);
          break;
        case POSTFIXE:
          code = POSTFIXE_evaluation(expr, &resultat);
      }
      
      switch (code) {
        case EXIT_SUCCESS:
          printf("%d\n", resultat);
          break;
        case EXIT_FAILURE:
          printf("Expression invalide\n");
      }
    }
  }

  return EXIT_SUCCESS ;
}
