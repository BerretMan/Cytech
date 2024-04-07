#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10

typedef enum {NORD,SUD,EST,OUEST} direction;

// prends aucun paramètre
// retourne une direction
direction bouge() {
    srand(time(NULL));
    direction d=rand()%4;
    return d;
}

void initialise_champ(char champ[N][N]) {
    int m_x,m_y;
    srand(time(NULL));
    for (int i=0;i<12;i++) {
        m_x=rand()%N;
        m_y=rand()%N;
        champ[m_x][m_y]='M';
    }
}

void affChamp(char champ[N][N]) {
    for (int i=0;i<N;i++) {
       for (int j=0;j<N;j++) {
            printf("%c ,",champ[N][N]);
        }
        printf("\n");
    }
}
/*
void evolue(char champ[N][N]) {

}
*/
int main(int argc, char** argv) {
    char champ[N][N];
    int tour=0;
    initialise_champ(champ);
    affChamp(champ);
    return 0;
}