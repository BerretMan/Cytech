#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"
#include "trisLent.h"
#include "trisRapide.h"
#include <time.h>

int main(int argc, char** argv){
    srand(time(NULL));
    clock_t t1,t2;
    double temps;
    printf("\nC'est le TP7 !\n");
    printf("N=?");
    int N,i;
    scanf("%d",&N);
    int*tab=allouer(N);
    printf("Quel tris voulez vous choisir? \n0-tous \n1-Bulle\n2-Insertion\n3-Selection\n4-Rapide\n5-Fusion\n");
    scanf("%d",&i);
    printf("TEST VITESSE %d élément ----\n",N);
    switch(i) {
        case 1:
            initialiser(tab,N);
            t1=clock();
            triBulles(tab,N);
            t2=clock();
            printf("Bulle     -> %f s\n",(float)(t2-t1)/CLOCKS_PER_SEC);break;
        case 2:
            initialiser(tab,N);
            t1=clock();
            triInsertion(tab,N);
            t2=clock();
            printf("Insertion -> %f s\n",(float)(t2-t1)/CLOCKS_PER_SEC);break;
        case 3:
            initialiser(tab,N);
            t1=clock();
            triSelection(tab,N);
            t2=clock();
            printf("Selection -> %f s\n",(float)(t2-t1)/CLOCKS_PER_SEC);break;
        case 4:
            initialiser(tab,N);
            t1=clock();
            triRapide(tab,0,N);
            t2=clock();
            printf("QuickSort -> %f s\n",(float)(t2-t1)/CLOCKS_PER_SEC);break;
        case 5:
            initialiser(tab,N);
            t1=clock();
            triFusion(tab,0,N);
            t2=clock();
            printf("Fusion    -> %f s\n",(float)(t2-t1)/CLOCKS_PER_SEC);break;
        default:
            t1=clock();
            triBulles(tab,N);
            t2=clock();
            printf("Bulle     -> %f s\n",(float)(t2-t1)/CLOCKS_PER_SEC);

            initialiser(tab,N);
            t1=clock();
            triInsertion(tab,N);
            t2=clock();
            printf("Insertion -> %f s\n",(float)(t2-t1)/CLOCKS_PER_SEC);

            initialiser(tab,N);
            t1=clock();
            triInsertion(tab,N);
            t2=clock();
            printf("Insertion -> %f s\n",(float)(t2-t1)/CLOCKS_PER_SEC);

            initialiser(tab,N);
            t1=clock();
            triSelection(tab,N);
            t2=clock();
            printf("Selection -> %f s\n",(float)(t2-t1)/CLOCKS_PER_SEC);

            initialiser(tab,N);
            t1=clock();
            triRapide(tab,0,N);
            t2=clock();
            printf("QuickSort -> %f s\n",(float)(t2-t1)/CLOCKS_PER_SEC);
    }
    
    
    return 0;
}