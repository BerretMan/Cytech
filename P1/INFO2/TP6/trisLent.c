#include "trisLent.h"
#include "fonction.h"
/* toutes mes signatures/prototypes de fonctions/méthodes + leur corps */

void triSelection(int* tab, int taille) {
    for(int j=0;j<taille-1;j++) {
        int min=j;
        for (int i=j+1;i<taille;i++) {
            if (tab[min]>tab[i]) {
                min=i;
            }
        } 
        echange(tab,j,min);        
    }
}

void triBulles(int* tab, int taille) {
    for (int j=0;j<taille-1;j++) {
        for (int i=j;i<taille-1;i++) {
            if (tab[i]>tab[i+1]) {
                echange(tab,i,i+1);
            }  
        }
    }
}

void triInsertion(int* tab, int taille) {
    for (int i=1; i<taille; i++) {
        int j=i;
        while ((j>=0)&&(tab[j-1]>tab[j])) {
            echange(tab, j-1, j);
            j--;
        }
    }
}