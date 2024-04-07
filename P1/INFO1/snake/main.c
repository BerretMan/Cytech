#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonction.h"
#define N 15


int main(int argc, char** agrv) {
    srand(time(NULL));
    nonblock(0);
    int** tab=allouer(N);
    fill_tab(tab,N);
    int p_x=2;int p_y=2;
    printf("\e[1;1H\e[2J");
    for (int i=0;i<100;i++) {
        show_tab(tab,N);
        swap(tab,p_x,p_y,p_x+1,p_y);
        p_x+=1;
        usleep(1000000);
        printf("\e[1;1H\e[2J");
    }
    return 0;
}