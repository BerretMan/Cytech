#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

int** allouer(int N) {
    int** tab =malloc(sizeof(int*)*N);
    for (int i=0;i<N;i++) {
        tab[i] = malloc(sizeof(int)*N); 
    }
    return tab;
}
// 0: void
// 1: pomme
// 2: snake's head
void fill_tab(int** tab, int N)  {
    int p_x = rand()%N;
    int p_y = rand()%N;
    for (int i=0; i<N;i++) {
        for (int j=0;j<N;j++) {
            if (p_x==i && p_y==j) {
                tab[i][j]=1;
            }else {
                tab[i][j]=0;
            }
        }
    }
    tab[2][2]=2;
}

void show_tab(int** tab, int N) {
    for (int i=0; i<N;i++) {
        for (int j=0;j<N;j++) {
            switch(tab[i][j]) {
                case 1:printf("🍎");break;
                case 2:printf("🟩");break;
                default:printf("⬛");break;
            }
        }
        printf("\n");
    }
}

void swap(int** tab, int x,int y,int i, int j) {
    int temp =tab[x][y];
    tab[x][y]=tab[i][j];
    tab[i][j]=temp;

}
