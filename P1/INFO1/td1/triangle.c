#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
// precondition: prends un nombre de ligne en entier
// postcondition : renvoit un triangle d'étoile
void triangle(int n) {
    for (int i=0;i<n;i++) {
        for (int j=0;j<i;j++) {
            printf("*");
        }
    printf("\n");
    }
}


//dessine un sapin
void sapin_1(int n) {
    srand((unsigned int)time(NULL));
    for (int z=0; z<n-1;z++) { // place l'étoile 
        printf("  ");
    }
    printf("🌟");
    printf("\n");
    for (int i=1;i<=n;i++) { // centre le sapin
        for (int j=1;j<=n-i;j++) {
            printf("  ");
        }
        for (int k=1;k<=2*i-1 ;k++) { // dessine les branches
            float alea = (float)rand()/RAND_MAX;
            if (alea < 0.9) {
                printf("🍀");
            }
            else if (alea > 0.9 && alea < 0.95){
                printf("🔴");
            }
            else if (alea > 0.95 && alea < 0.99) {
                printf("🟡");
            }
            else 
            {
                printf("🔵");
            }
        }
        printf("\n");
    }
    for (int p=0;p<2;p++) {
        for (int z=0; z<n-1;z++) { // tronc 
        printf("  ");
    }
    printf("🪵\n");
    }
}
void sapin_2(int n) {

    for (int z=0; z<n-1;z++) { // place l'étoile 
        printf("  ");
    }
    printf("\e[0;93m⭐\033[0m");
    printf("\n");
    for (int i=1;i<=n;i++) { // centre le sapin
        for (int j=1;j<=n-i;j++) {
            printf("  ");
        }
        for (int k=1;k<=2*i-1 ;k++) { // dessine les branches
            printf("🍀");
        }
        printf("\n");
    }
    for (int p=0;p<2;p++) {
        for (int z=0; z<n-1;z++) { // tronc 
        printf("  ");
    }
    printf("🪵\n");
    }
}


int main(int argc,char** argv) {
    for (int i=0; i<1000;i++) {
        sapin_1(8);
        usleep(300000);
        system("clear");
        sapin_2(8);  
        usleep(300000);
        system("clear");
    }
}
