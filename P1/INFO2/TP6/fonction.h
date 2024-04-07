#ifndef __fonction_H_
#define __fonction_H_
/* toutes mes signatures/prototypes de fonctions/méthodes */
/* Auteur : Lucas Serrano */
/* Date :   21/03/2024 */
/* Résumé : ... */
/* Entrée(s) : ... */
/* Sortie(s) :  ...  */

int* allouer(int taille);
/* Auteur : Lucas Serrano */
/* Date :   21/03/2024 */
/* Résumé : ... */
/* Entrée(s) : ... */
/* Sortie(s) :  ...  */
void initialiser(int* monTab,int taille);

void afficher(int* monTab,int taille);
/* Auteur : ... */
/* Date :   ... */
/* Résumé : ... */
/* Entrée(s) : ... */
/* Sortie(s) :  ...  */
void copie(int* tableauOriginal, int* tableauCopie, int tailleTableau);
/* Auteur : ... */
/* Date :   ... */
/* Résumé : ... */
/* Entrée(s) : ... */
/* Sortie(s) :  ...  */
void echange(int* monTab, int i, int j);

int partitionner (int* tab,int pivot, int taille);

void fusionner(int* tab,int debut,int milieu,int fin);
#endif