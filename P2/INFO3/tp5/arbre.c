#include "arbre.h"
#include <stdlib.h>
#include <stdio.h>

#define monMax(a,b) (a > b ? a : b)
/* corps des différentes fonctions/procédures */
arbre creerArbreBinaire (int val, arbre filsG, arbre filsD) {
    arbre a=(arbre)malloc(sizeof(noeud));
    a->val=val;
    a->filsG=filsG;
    a->filsD=filsD;
    return a;
}

int taille(arbre a) {
    if (a==NULL) {
        return 0;
    } 
    return 1+taille(a->filsG)+taille(a->filsD);
}

int estFeuille(arbre a) {
    return (a->filsG==NULL && a->filsD==NULL);
}

int hauteur(arbre a) {
    if (a== NULL) {
        return -1;
    } 
    return 1+monMax(taille(a->filsG),taille(a->filsD));
}

int nbFeuilles(arbre a) {
    if (a==NULL) {
        return 0;
    } else if (estFeuille(a)){
        return 1;
    }
    return nbFeuilles(a->filsG)+nbFeuilles(a->filsD);
}

void afficherInfixe(arbre a) {
    if (a==NULL) {
        printf("[]");
    } 
    printf("[");
    parcoursInfixe(a);
}

void parcoursInfixe(arbre a) {
    if (a!=NULL) {
        parcoursInfixe(a->filsG);
        printf("%d,",a->val);
        parcoursInfixe(a->filsD);
    }
}

void afficherPostfixe(arbre a) {
    if (a==NULL) {
        printf("[]");
    } 
    printf("[");
    parcoursPostfixe(a);
}

void parcoursPostfixe(arbre a) {
    parcoursPostfixe(a->filsG);
    parcoursPostfixe(a->filsD);
    printf("%d,",a->val);

}

void afficherPrefixe(arbre a) {
    if (a==NULL) {
        printf("[]");
    } 
    printf("[");
    parcoursPrefixe(a);
}

void parcoursPrefixe(arbre a){
    printf("%d,",a->val);
    parcoursPrefixe(a->filsG);
    parcoursPrefixe(a->filsD);
}

