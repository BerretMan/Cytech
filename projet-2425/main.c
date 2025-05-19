#include "postfixe/postfixe.h"
#include "prefixe/prefixe.h"
#include "calculatrice.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

const char* help = 
"calculatrice(Version 1.0)\n"
"\n"
"NOM\n"
"       calculatrice - Une simple calculatrice codée en C.\n"
"\n"
"SYNOPSIS\n"
"       calculatrice [-options] [arguments]\n"
"\n"
"DESCRIPTION\n"
"       Une calculatrice simplifié codée en C. Elle supporte la notation postfixe (polonaise) et préfixe.\n"
"       Projet d'INFO pré-ing2 (semestre1) de Cytech (ex EISTI).\n"
"       Fait par Serrano Lucas et Hill Zak\n"
"\n"
"OPTIONS\n"
"       Liste des options disponibles :\n"
"\n"
"       -?, -h, --help\n"
"	      Affiche l'aide pour utiliser le programme\n"
"	      (la page sur laquelle vous êtes actuellement)\n"
"	      Pour quitter, pressez q.\n"
"\n"
"       -e     EXPRESSION\n"
"	      Evalue une expression et renvoit le résultat de l'opération finale.\n"
"\n"
"       -i     [NOTATION]\n"
"	      Lance le mode intéractif, dans la notation donnée si elle est présente.\n"
"\n"
"       AUTEUR\n"
"	      Serrano Lucas\n"
"	      Zak Hill\n"
"\n"
"Page de Manuel\n";


/** Programme principal
  * @param argc nombre de paramètres
  * @param argv tableau des paramètres
  *  pas de paramètre : même comportement que l'option -i (sans notation)
  *  -h ou --help    : affichage une aide sur l'utilisation du programme
  *  -i prefixe      : lance la calculatrice en notation préfixée en mode interactif
  *  -i postfixe     : lance la calculatrice en notation postfixée en mode interactif
  *  -i              : demande à l'utilisateur la notation souhaitée puis lance la calculatrice en mode interactif
  *  -e <expression> : évalue l'expression donnée en paramètre et affiche le résultat
  */
int main(int argc, char *argv[]) {
  int interactif = 0;
  int evaluer = 0;
  char* expression = NULL;
  char* mode = NULL;
  int option;

  for (int i = 0; i < argc; i++) {
    if (strcmp(argv[i], "--help") == 0) {
      argv[i] = "-h";
    }
  }
  
  while ((option = getopt(argc, argv, ":?he:i:")) != -1) {
    switch (option) {
      case ':':
        switch (optopt) {
          case 'e':
            evaluer = 1;
            break;
          case 'i':
            interactif = 1;
        }
        break;
      case '?':
      case 'h':
        if (system("man ./HelpPage") != EXIT_SUCCESS) {
          printf("%s", help);
        }
        return EXIT_SUCCESS;
      case 'e':
        evaluer = 1;
        expression = optarg;
        break;
      case 'i':
        interactif = 1;
        mode = optarg;
        if (mode != NULL && strcmp(mode, "prefixe") != 0 && strcmp(mode, "postfixe") != 0) {
          printf("Mode invalide\n");
          return EXIT_FAILURE;
        }
        break;
    }
  }

  if (evaluer && interactif) {
    printf("Les options '-e' et '-i' ne peuvent pas etre utilisees en meme temps\n");
    return EXIT_FAILURE;
  }

  if (evaluer) {
    int resultat;
    
    if (expression != NULL && (PREFIXE_evaluation(expression, &resultat) == EXIT_SUCCESS || POSTFIXE_evaluation(expression, &resultat) == EXIT_SUCCESS)) {
      printf("%d\n", resultat);
      return EXIT_SUCCESS;
    } else {
      printf("Expression invalide\n");
      return EXIT_FAILURE;
    }
  }

  Notation notation;
  if (mode == NULL) {
    if (selecteurMode(&notation) == EXIT_FAILURE) {
      printf("Aucun mode selectionne\n");
      return EXIT_FAILURE;
    }
  } else if (strcmp(mode, "prefixe") == 0) {
    notation = PREFIXE;
  } else if (strcmp(mode, "postfixe") == 0) {
    notation = POSTFIXE;
  } else {
    printf("Mode invalide\n");
    return EXIT_FAILURE;
  }

  return calculatrice(notation);
}
