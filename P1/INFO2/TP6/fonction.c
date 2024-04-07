#include "fonction.h"
#include <stdlib.h>
#include <stdio.h>
/* toutes mes signatures/prototypes de fonctions/méthodes + leur corps */


int* allouer(int taille) {
    int* t =malloc(sizeof(int)*taille);
    return t;
}
void initialiser(int* tab,int taille) {
    for (int i=0;i<taille;i++) {
        tab[i]=rand()%100;
    }
}



void afficher(int* tab,int taille) {
    printf("[");
    for (int i=0;i<taille-1;i++) {
        printf("%d,",tab[i]);
    }printf("%d]\n",tab[taille-1]);
}


void copie(int* tab1, int* tab2, int taille) {
    for (int i=0;i<taille-1;i++) {
        tab1[i]=tab2[i];
    }
}


void echange(int* tab, int i, int j) {
    int temp= tab[i];
    tab[i]=tab[j];
    tab[j]=temp;
}

int partitionner (int* tab,int pivot, int taille) {
    int nv_pivot=tab[pivot];
    int i=pivot-1;
    int j=taille+1;
    while(i<j)  {
        do {
            j-=1;
        } while(tab[j] > nv_pivot);
        do {
            i+=1;
        } while (tab[i] < nv_pivot);
        if (i<j ) {
            echange(tab,i,j);
        }
    }
    return j;
}

void fusionner(int* tab,int debut,int milieu,int fin) {
    int i=0;
    int max=fin-debut;
    int gauche = debut;
    int droite = milieu+1;
    int* tabTemp=malloc(sizeof(int)*(fin+1));

    while (gauche<=milieu && droite<= fin) {
        if (tab[gauche]< tab[droite]) {
            tabTemp[i]=tab[gauche];
            gauche++;
        } else {
            tabTemp[i]=tab[droite];
            droite++;
        }
        i++;
    }
    while (gauche <= milieu) {
        tabTemp[i]=tab[gauche];
        gauche++;
        i++;
    }
    while (droite <= fin) {
        tabTemp[i]=tab[droite];
        droite++;
        i++;
    }

    for (int i=0;i<max+1;i++) {
        tab[i+debut]=tabTemp[i];
    }
}