#include <stdio.h>
#include <stdlib.h>

/* Auteur : SerranoLucas */
/* Date :  09/01 */
/* Résumé :  alloue une matrice */
/* Entrée(s) :  un nb de ligne, un nb de colonne */
/* Sortie(s) :  la matrice */
int** allouerTableau(int nb_lignes,int nb_colonnes) {
    int** tab=malloc(nb_lignes * sizeof(int*));
    for(int i=0;i<nb_colonnes;i++) {
        tab[i]=malloc(nb_colonnes * sizeof(int));
    }
    return tab;
}
/* Auteur : SerranoLucas */
/* Date :  09/01 */
/* Résumé :  initialise une matrice */
/* Entrée(s) :  la matrice, un nb de ligne, un nb de colonne */
void initTableau(int** tab,int nb_lignes,int nb_colonnes) {
    for (int i=0;i<nb_lignes;i++) {
        for (int j=0;j<nb_colonnes;j++) {
            tab[i][j]=0;
        }
    } 
}
/* Auteur : SerranoLucas */
/* Date :  09/01 */
/* Résumé :  affiche la matrice */
/* Entrée(s) :  la matrice, un nb de ligne, un nb de colonne */
void ShowTab(int** tab,int nb_lignes,int nb_colonnes) {
    printf("[");
    for (int i=0;i<nb_lignes;i++) {
        for (int j=0;j<nb_colonnes-1;j++) {
            switch(tab[i][j]) {
                case 0:printf(" ,");break;
                case 1:printf("X,");break;
                case 2:printf("O,");break;
            }
        }
        switch(tab[i][nb_colonnes-1]) {
            case 0:printf(" ]\n[");break;
            case 1:printf("X]\n[");break;
            case 2:printf("O]\n[");break;
        }
    } 
}
/* Auteur : SerranoLucas */
/* Date :  09/01 */
/* Résumé :  joue le coup  */
/* Entrée(s) :  la matrice, un numéro de joueur, coord i, coord j*/
void joue(int** tab, int numeroJoueur,int i,int j) {
        tab[i][j]=numeroJoueur;
    }
}

/* Auteur : SerranoLucas */
/* Date :  09/01 */
/* Résumé :  saisie utilisateur de la coord  */
/* Entrée(s) :  la matrice, le joueur*/
void tour2jeu(int** tab,int joueur) {
    int choix=0;
    int n=3;
    printf("Joueur Saisie la case où tu veux jouer entre 1 et 9 (regarde le pavé tactile)");
    scanf("%d",&choix);
    switch(choix) {
        case 1:joue(tab,joueur,2,0);ShowTab(tab,n,n);break;
        case 2:joue(tab,joueur,2,1);ShowTab(tab,n,n);break;
        case 3:joue(tab,joueur,2,2);ShowTab(tab,n,n);break;
        case 4:joue(tab,joueur,1,0);ShowTab(tab,n,n);break;
        case 5:joue(tab,joueur,1,1);ShowTab(tab,n,n);break;
        case 6:joue(tab,joueur,1,2);ShowTab(tab,n,n);break;
        case 7:joue(tab,joueur,0,0);ShowTab(tab,n,n);break;
        case 8:joue(tab,joueur,0,1);ShowTab(tab,n,n);break;
        case 9:joue(tab,joueur,0,2);ShowTab(tab,n,n);break;
    }
}

int main(int argc, char** argv) {
    int n=3;
    int** tab=allouerTableau(n,n);
    initTableau(tab,n,n);
    ShowTab(tab,n,n);
    for (int i=0;i<9;i++) {
        tour2jeu(tab,1+i%2);
    }
}