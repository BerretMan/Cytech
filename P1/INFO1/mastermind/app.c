#include <stdio.h>
#include <stdlib.h>
#include <time.h>
enum couleur {JAUNE,BLEU,ROUGE,VERT,ORANGE,VIOLET};
enum placement {VIDE,BLANC,NOIR}

void fill_tab(int[4] tab) {
    srand(time(NULL))
    for(int i=0; i<=4;i++) {
        tab[i]=4*rand();
    }
    
}
int main(int argc , char** argv) { 
    enum couleur couleur=orange;
    printf("%d\n",couleur);
    
    return 0;
}