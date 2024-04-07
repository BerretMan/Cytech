#include <stdio.h>
#include <stdlib.h>

#define N 11

int* allouer(int n_case) {
    int* tab=malloc(n_case * sizeof(int));
    return tab;
}

void init_random(int* tab,int n_case) {
    for(int i=0;i<n_case;i++) {
        tab[i]=rand()%101;
    }
}


char* a(int n_case) {
    char* tab=malloc(n_case * sizeof(char));
    return tab;
}

void init_Harry(char* tab,int n_case) {
    tab="HARRYPOTER";
}

int main(int argc, char** argv) {
    
 
    return 0;

}