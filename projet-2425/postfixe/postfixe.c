/** Évaluation d'une expression en notation postfixe
 * Implémentation
 * @author Serrano Lucas
 */
#include "postfixe.h"
#include "pile.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1023

int isnumber(char *c) {
  int isnumber = 1;
  for (int i = 0; i < strlen(c); i++) {
    if (!isdigit(c[i])) {
      isnumber = 0;
    }
  }
  return isnumber;
}

int expression_valide(char *expression) {
  int is_valid = 1;
  int compteur = 0;
  int len = strlen(expression);
  char temp[N] = "";
  int temp_index = 0;

  // couper le char* en fonction des espaces
  for (int i = 0; i < len; i++) {
    if (expression[i] != ' ') {
      temp[temp_index++] = expression[i];
    }
    // si espace et que i est le dernier indice de la chaine
    if (expression[i] == ' ' || i == len - 1) {
      if (temp_index > 0) {
        //caractère de fin de chaine
        temp[temp_index] = '\0';
        if (isnumber(temp)) {
          compteur++;
        } else {
          compteur--;
          if (compteur < 1) {
            is_valid = 0;
          }
        }
        temp_index = 0;
        temp[0] = '\0';
      }
    }
  }
  if (compteur !=1) {is_valid=0;} 
  return is_valid;
}

int POSTFIXE_evaluation(char *expression, int *resultat) {
  if (!expression_valide(expression)) {
    return EXIT_FAILURE;
  }

  PILE p = PILE_creerVide();
  int len = strlen(expression);
  char temp[N] = "";
  int temp_index = 0;

  
  for (int i = 0; i < len; i++) {
    if (expression[i] != ' ') {
      temp[temp_index++] = expression[i];
    }

    if (expression[i] == ' ' || i == len - 1) {
      if (temp_index > 0) {
        temp[temp_index] = '\0';

        if (isnumber(temp)) {
          PILE_empiler(&p, atoi(temp));
        } else {
          int b = PILE_depiler(&p);
          int a = PILE_depiler(&p);

          int result;
          switch (temp[0]) {
          case '+':
            result = a + b;
            break;
          case '-':
            result = a - b;
            break;
          case '*':
            result = a * b;
            break;
          case '/':
            if (b==0) {
              printf("ERROR: division par zero\n");
              return EXIT_FAILURE;
            }
            result = a / b;
            break;
          default:
            printf("%c caractère indésirable\n",temp[0]);
            return EXIT_FAILURE;
          }


          PILE_empiler(&p, result);
        }
        temp_index = 0;
        temp[0] = '\0';
      }
    }
  }
  *resultat = PILE_depiler(&p);
  return EXIT_SUCCESS;
}