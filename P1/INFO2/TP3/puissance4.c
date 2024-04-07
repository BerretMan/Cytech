#include "puissance4.h"
#include <stdlib.h>
#include <stdio.h>
/* corps des différentes fonctions/procédures */
int** allouer(int taille) {
    int** tab=malloc(taille * sizeof(int*));
    for(int i=0;i<taille;i++) {
        tab[i]=malloc(taille * sizeof(int));
    }
    return tab;
}
void initialiser(int** matrice,int taille) {
    for (int i=0; i<=taille-1;i++) {
        for (int j=0; j<=taille-1;j++) {
           matrice[i][j]=-1; 
          }
    }
}

void afficher(int** matrice,int taille) {
    printf("[");
    for (int i=0; i<=taille-1;i++) {
        for (int j=0; j<=taille-2;j++) {
            switch (matrice[i][j]) {
                case -1:printf(" ,");break;
                case 1:printf("X,");break;
                case 2:printf("O,");break;
            }
          }
        switch (matrice[i][taille-1]) {
            case -1:printf(" ]\n[");break;
            case 1:printf("X]\n[");break;
            case 2:printf("O]\n[");break;
        }
    }
}


void jouer(int** matrice,int taille, int joueur) {
    int colonne=0;
    int isJouer=0;int i=0;
    printf("Choisis la colonne entre 1 et 7: ");
    scanf("%d",&colonne);
    colonne-=1;
    if (colonne>-1 && colonne<8 && matrice[0][colonne]==-1) {
        while (isJouer==0 && i<7){
            if (matrice[i][colonne]==-1) {
                i++;
            }
            else {
                break;
            }
        }
        matrice[i-1][colonne]=joueur;
    }

}


int VerificationLignes(int** m,int ligne, int taille) {
    int win=-1;
    for (int i=0;i<=taille-4;i++) {
        if (m[ligne][i]==-1 && m[ligne][i]==m[ligne][i+1] && m[ligne][i+1]==m[ligne][i+2] && m[ligne][i+2]==m[ligne][i+3] && m[ligne][i+3]==m[ligne][i+4]) {
            win=m[ligne][i];
        }
    }
    return win;
}
/* Auteur :  */
/* Date :  ...*/
/* Résumé :  ...*/
/* Entrée(s) :  ...*/
/* Sortie(s) :  ...*/
int VerificationColonnes(int** m,int c, int taille) {
    int win=-1;
    for (int i=0;i<=taille-4;i++) {
        if (m[i][c]!=-1 && m[i][c]==m[i+1][c] && m[i+1][c]==m[i+2][c] && m[i+2][c]==m[i+3][c] && m[i+3][c]==m[i+4][c]) {
            win=m[i][c];
        }
    }
    return win;
}

int Verificationdiag1(int** m, int taille) {
    int win=-1;
    for (int i=0;i<=4;i++) {
        for (int j=0;j<=4;j++) {
            if (m[i][j]==-1 &&m[i][j]==m[i+1][j+1] && m[i+1][j+1]==m[i+2][j+2] && m[i+2][j+2]==m[i+3][j+3] && m[i+3][j+3]==m[i+4][j+4]) {
            win=m[i][j];
            }
        }
    }
    return win;
} 


int Verificationdiag2(int** m, int taille) {
    int win=-1;
    for (int i=0;i<=4;i++) {
        for (int j=0;j<=4;j++) {
            if (m[i+4][j]==-1 && m[i+4][j]==m[i+3][j+1] && m[i+3][j+1]==m[i+2][j+2] && m[i+2][j+2]==m[i+1][j+3] && m[i+1][j+3]==m[i][j+4]) {
            win=m[i+4][j];
            }
        }
    }
    return win;
} 

int aGagne(int** m,int taille) {
    int d1=Verificationdiag1(m,taille);
    int d2=Verificationdiag1(m,taille);
    //if (l!=-1) {return l;}
    //if (c!=-1) {return c;}
    if (d1!=-1) {return d1;}
    if (d2!=-1) {return d2;}
}
