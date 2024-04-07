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
            printf("tab[%d][%d]=",i,j);
            scanf("%d",&tab[i][j]);
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
            printf("%d,",tab[i][j]);
        }
        printf("%d]\n[",tab[i][nb_colonnes-1]);
    } 
}
/* Auteur : SerranoLucas */
/* Date :  09/01 */
/* Résumé :  Fait la somme d'une ligne d'une matrice */
/* Entrée(s) :  une ligne , un nb de colonne */
/* Sortie(s) :  la somme de la ligne */
int SommeLigne(int** tab,int ligne,int nb_colonnes) {
    int somme=0;
    for (int j=0;j<nb_colonnes;j++) {
        somme+=tab[ligne][j];
    } 
    return somme;
}
/* Auteur : SerranoLucas */
/* Date :  09/01 */
/* Résumé :  Fait la somme d'une ligne d'une matrice */
/* Entrée(s) :  une colonne,un nb ligne  */
/* Sortie(s) :  la somme de la colonne */
int SommeColonne(int** tab,int colonne ,int nb_ligne) {
    int somme=0;
    for (int i=0;i<nb_ligne;i++) {
        somme+=tab[i][colonne];
    } 
    return somme;
}

/* Auteur : SerranoLucas */
/* Date :  09/01 */
/* Résumé :  Fait la somme de la diago de droite à gauche */
/* Entrée(s) :  une matrice,un nb de ligne */
/* Sortie(s) :  la somme de la colonne */
int SommeDiag1(int** tab,int nb_ligne) {
    int somme=0;
    for (int i=0;i<nb_ligne;i++) {
        somme+=tab[nb_ligne-i-1][i];
    } 
    return somme;
}
/* Auteur : SerranoLucas */
/* Date :  09/01 */
/* Résumé :  Fait la somme de la diago de gauche à droite */
/* Entrée(s) :  une matrice,un nb de ligne */
/* Sortie(s) :  la somme de la colonne */
int SommeDiag2(int** tab,int nb_ligne) {
    int somme=0;
    for (int i=0;i<nb_ligne;i++) {
        somme+=tab[i][i];
    } 
    return somme;
}
/* Auteur : SerranoLucas */
/* Date :  09/01 */
/* Résumé :  Dit si la matrice est magique */
/* Entrée(s) :  une matrice,un nb de ligne, un nb de colonne */
/* Sortie(s) :  0 si pas magique, 1 si magique */
int estMagique(int** tab,int nb_lignes,int nb_colonnes) {
    //return SommeLigne(tab,0,3)==SommeLigne(tab,1,3)==SommeLigne(tab,2,3)==SommeColonne(tab,0,3)==SommeColonne(tab,1,3)==SommeColonne(tab,2,3)==SommeDiag1(tab,3)==SommeDiag2(tab,3));
} 
int main(){
    int n=3;
    int** tab=allouerTableau(n,n);
    initTableau(tab,n,n);
    ShowTab(tab,n,n);
    printf("hello world!");
    printf("somme ligne 0 =%d\n",SommeLigne(tab,0,3));
    printf("somme colonne 0 =%d\n",SommeColonne(tab,0,3));
    printf("somme diag1=%d\n",SommeDiag1(tab,3));
    printf("somme diag2=%d\n",SommeDiag2(tab,3));
    printf("est il magique? %d",estMagique(tab,3,3));
    return 0;
}