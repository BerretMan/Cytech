#ifndef ARBRE_H
#define ARBRE_H

/* RAPPEL */
typedef struct noeud {
  int val;
  struct noeud* filsG;
  struct noeud* filsD;
}noeud;

typedef noeud* arbre;

/* Le prototype/signature de toutes mes fonctions/procédures */
/* Auteur :  */
/* Date :  */
/* Résumé : créer un arbre binaire */
/* Entrée(s) : la racine que l'on veut incérer ainsi que son fils gauche et droit */
/* Sortie(s) : l'arbre créé  */
arbre creerArbreBinaire (int val, arbre filsG, arbre filsD);

/* Auteur :  */
/* Date :  */
/* Résumé : donne la taille d'un arbre */
/* Entrée(s) : arbre */
/* Sortie(s) : cpt */
int taille(arbre a);

/* Auteur :  */
/* Date :  */
/* Résumé : indique si un noeud est une feuille */
/* Entrée(s) : arbre  */
/* Sortie(s) : vrai ou faux */
int estFeuille(arbre a);

/* Auteur :  */
/* Date :  */
/* Résumé : donne la hauteur d'un arbre */
/* Entrée(s) : arbre  */
/* Sortie(s) : entier */
int hauteur(arbre a);



/* Auteur :  */
/* Date :  */
/* Résumé : donne le nombre de feuille d'un arbre */
/* Entrée(s) : arbre, cpt */
/* Sortie(s) : cpt */
int nbFeuilles(arbre a);

/* Auteur :  */
/* Date :  */
/* Résumé : Met l'affichage en forme  d'un arbre via le parcours infixe */
/* Entrée(s) : l'arbre que l'on souhaite afficher */
/* Sortie(s) : none */
void parcoursInfixe(arbre a);

/* Auteur :  */
/* Date :  */
/* Résumé : affiche un arbre via le parcours infixe */
/* Entrée(s) : l'arbre que l'on souhaite afficher */
/* Sortie(s) : none */
void afficherInfixe(arbre a);

/* Auteur :  */
/* Date :  */
/* Résumé : affiche un arbre via le parcours Postfixe */
/* Entrée(s) : l'arbre que l'on souhaite afficher */
/* Sortie(s) : none */
void afficherPostfixe(arbre a);

/* Auteur :  */
/* Date :  */
/* Résumé : Met l'affichage en forme  d'un arbre via le parcours Postfixe */
/* Entrée(s) : l'arbre que l'on souhaite afficher */
/* Sortie(s) : none */
void parcoursPostfixe(arbre a);


/* Auteur :  */
/* Date :  */
/* Résumé : Met l'affichage en forme  d'un arbre via le parcours prefixe */
/* Entrée(s) : l'arbre que l'on souhaite afficher */
/* Sortie(s) : none */
void parcoursPrefixe(arbre a);


/* Auteur :  */
/* Date :  */
/* Résumé : affiche un arbre via le parcours Prefixe */
/* Entrée(s) : l'arbre que l'on souhaite afficher */
/* Sortie(s) : none */
void afficherPrefixe(arbre a);

#endif