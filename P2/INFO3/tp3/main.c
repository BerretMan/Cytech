#include <stdio.h>
#include "liste.h"

int main(){
    printf("C'est la liste !\n");

    Liste l;
    for (int i=0;i<10;i++) {
        l=ajouterTete(l,i);
    }
    l=ajouterFin(l,-1);
    l=ajouterPos(l,7,5);
    afficher(l);
    l=supprimerDebut(l); 
    afficher(l);
    l=supprimerFin(l);
    afficher(l);
    l=supprimerPos(l,2);
    afficher(l);
    //l=viderListe(l);
    printf("test sup 6 \n");
    l=supFirst(l,6);
    afficher(l);
    l=viderListe(l);

    for (int i=0;i<10;i++) {
        l=ajouterTete(l,3);
    }
    l=ajouterTete(l,2);
    l=supAllOccurence(l,3);
    afficher(l);

    return 0;
}