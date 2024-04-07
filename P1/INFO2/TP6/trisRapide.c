#include "trisRapide.h"
#include "fonction.h"
void triRapide(int* tab, int pivot, int taille) {
    if (pivot<taille) {
        int q = partitionner(tab,pivot,taille);
        triRapide(tab,pivot,q);
        triRapide(tab,q+1,taille);
    }
}

void triFusion(int* tab, int debut,int taille) {
    if (debut<taille ) {
        int milieu = (debut+taille)/2;
        triFusion(tab,debut,milieu);
        triFusion(tab,milieu+1,taille);
        fusionner(tab,debut,milieu,taille);
    }
}