#include "file.h"
#include <stdlib.h>

Personne* creerElementFile(char* valeur) {
    Personne* p= (Personne*)malloc(sizeof(Personne));
    p->donnee=malloc(sizeof(char)*20);
    p->donnee=valeur;
    p->precedent=NULL;
    return p;
}

void enfiler(File* f, char* valeur) {
    Personne* elt;
    if (*f==NULL) {
        elt=creerElementFile(valeur);
        f=elt;
    } else {
        f.precedent = enfiler(f.precedent,valeur);
    }
}

void afficherF (File f) {
    if (*f == NULL) {
        printf("---");
    } else {
        printf("%s",f.valeur);
        afficherF(f.precedent);
    }
}

char* defilerF (File* f) {
    if (*f==NULL) {
        printf("file vide");
        return EXIT_FAILURE;
    } else {
        
    }
}