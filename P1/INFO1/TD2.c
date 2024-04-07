/**
 * @file TD4_EX4_(algo).c
 * @author Bixente HIRIART--DICHARRY <hiriartdic@cy-tech.fr>
 * @version 0.1
 * @date 11 décembre 2023 - 11:47
 * @brief TD4 (algo) EX4
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @struct joueur
 * @author Bixente HIRIART--DICHARRY <hiriartdic@cy-tech.fr>
 * @version 0.1
 * @date 14 décembre 2023 - 16:25
 * @brief garde l'age, le prénom et le symbole d'un joueur
 */
struct joueur{
    int age;
    char nom;
    char symbole;
    int tour;
};
typedef struct joueur jr;

/**
 * @fn jr mkjr(int age, char nom)
 * @author Bixente HIRIART--DICHARRY <hiriartdic@cy-tech.fr>
 * @version 0.1
 * @date 11 décembre 2023 - 11:01
 * @brief définit un joueur
 *
 * @return un joueur
 */
jr mkjr(int a, char n){
  jr joueur;
  char s
  joueur.age = a;
  joueur.nom = n;
  return joueur;
}
jr cmpjr(jr a, jr b)

/**
 * @fn void affGrille(char tab[3][3])
 * @author Bixente HIRIART--DICHARRY <hiriartdic@cy-tech.fr>
 * @version 0.1
 * @date 19 décembre 2023 - 09:52
 * @brief affiche la grille
 */
void affGrille(char tab[3][3]) {
    for (int i = 0; i < 3; i++) {
        printf(" %c ", tab[i][0]);
        for (int j = 1; j < 3; j++) {
            printf("│ %c ", tab[i][j]);
        }
        printf("\n");
        if (i < 2) {
            printf("───┼───┼───\n");
        }
    }
}

/**
 * @fn int main (void)
 * @author Bixente HIRIART--DICHARRY <hiriartdic@cy-tech.fr>
 * @version 0.1
 * @date 11 décembre 2023 - 12:17
 * @brief Fonction principale
 *
 * @return EXIT_SUCCESS : le programme doit se terminer normalement
 *
 * @remarks
 */
int main(void){
    char tab[3][3];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            tab[i][j] = ('○');
        }
    }
    affGrille(tab);
    exit(EXIT_SUCCESS);
}