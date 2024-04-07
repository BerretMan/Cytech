
#ifndef __puissance4_H_
#define __puissance4_H_
/* toutes mes signatures/prototypes de fonctions/procédures */
/* Auteur : ... */
/* Date :  ... */
/* Résumé :  ... */
/* Entrée(s) :  ... */
/* Sortie(s) :  ... */
int** allouer(int taille);
/* Auteur : ... */
/* Date :  ... */
/* Résumé :  ... */
/* Entrée(s) :  ... */
/* Sortie(s) :  ... */
void initialiser(int** matrice,int taille);
/* Auteur : ... */
/* Date :  ... */
/* Résumé :  ... */
/* Entrée(s) :  ... */
/* Sortie(s) :  ... */
void afficher(int** matrice,int taille);
/* Auteur :  */
/* Date :  ...*/
/* Résumé :  ...*/
/* Entrée(s) :  ...*/
/* Sortie(s) :  ...*/
void jouer(int** matrice,int taille, int joueur);
/* Auteur :  */
/* Date :  ...*/
/* Résumé :  ...*/
/* Entrée(s) :  ...*/
/* Sortie(s) :  ...*/
int VerificationLignes(int** matrice,int ligne, int taille);
/* Auteur :  */
/* Date :  ...*/
/* Résumé :  ...*/
/* Entrée(s) :  ...*/
/* Sortie(s) :  ...*/
int VerificationColonnes(int** m,int c, int taille);
/* Auteur :  */
/* Date :  ...*/
/* Résumé :  ...*/
/* Entrée(s) :  ...*/
/* Sortie(s) :  ...*/
int Verificationdiag1(int** grille, int taille);

/* Auteur :  */
/* Date :  ...*/
/* Résumé :  ...*/
/* Entrée(s) :  ...*/
/* Sortie(s) :  ...*/
int Verificationdiag2(int** grille, int taille);
/* Auteur : ... */
/* Date :  ... */
/* Résumé :  ... */
/* Entrée(s) :  ... */
/* Sortie(s) :  ... */
int aGagne(int** maGrille,int taille);
#endif