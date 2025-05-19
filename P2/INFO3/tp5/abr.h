#ifndef ABR_H
#define ABR_H

/* Le prototype/signature de toutes mes fonctions/procédures */

/* Auteur : */
/* Date :   */
/* Résumé : Insertion dans un arbre binaire de recherche */
/* Entrée(s) : la valeur et l'arbre dans lequel on souhaite  insérer la valeur*/
/* Sortie(s) : le nouvel arbre */
arbre insertionArbre(int val, arbre a);


/* Auteur : */
/* Date :   */
/* Résumé : Recherche un élement dans un arbre binaire de recherche */
/* Entrée(s) : la valeur et l'arbre dans lequel on souhaite rechercher la valeur*/
/* Sortie(s) : l'arbre dont la racine est la valeur recherchée */
arbre rechercheArbre(int val, arbre a);


/* Auteur : */
/* Date :  */
/* Résumé : Suppresion d'un élement dans un arbre binaire de recherche */
/* Entrée(s) : la valeur et l'arbre dans lequel on souhaite supprimer la valeur*/
/* Sortie(s) : l'arbre avec la valeur en moins */
arbre supprArbre(int val, arbre a);

/* Auteur : */
/* Date :  */
/* Résumé : Récupére l'élement le plus petit dans un arbre binaire de recherche */
/* Entrée(s) : l'arbre dans lequel on souhaite rechecher la valeur la plus petite*/
/* Sortie(s) : la valeur la plus petite*/
int minArbre(arbre a);

/* Auteur : */
/* Date :  */
/* Résumé : Récupére l'élement le plus grand dans un arbre binaire de recherche */
/* Entrée(s) : l'arbre dans lequel on souhaite rechecher la valeur la plus grande */
/* Sortie(s) : la valeur la plus grande*/
int maxArbre(arbre a);


/* Auteur : */
/* Date :   */
/* Résumé : supprime l'élement le plus grand dans un arbre binaire de recherche */
/* Entrée(s) : l'arbre dans lequel on souhaite supprimer la valeur la plus grande */
/* Sortie(s) : l'arbre avec la valeur en moins */
arbre supprMax(arbre a);


/* Auteur : */
/* Date :  */
/* Résumé : Réalise l'intersection de 2 arbres passés en paramètres et renvoie le résultat dans un 3ieme arbre  */
/* Entrée(s) :  3 arbres*/
/* Sortie(s) :  1 arbre*/
arbre intersection(arbre a1, arbre a2, arbre a3);





/* Auteur : */
/* Date :  */
/* Résumé : Créer un arbre binaire de recherche aléatoire. On lui passe le nombre de noeuds en paramètres */
/* Entrée(s) : entier, arbre */
/* Sortie(s) : arbre */
arbre aleatoireArbre(int nbNoeuds, arbre a);


/* Auteur : */
/* Date :  */
/* Résumé : prédicat permettant de savoir si un arbre est binaire ou non */
/* Entrée(s) :  arbre */
/* Sortie(s) : entier */
int estBinaire(arbre a);
#endif