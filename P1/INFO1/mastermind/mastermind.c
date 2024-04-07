#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define LONGEUR_LIGNE 4
#define NOMBRE_LIGNE 12

typedef enum {JAUNE,BLEU,ROUGE,VERT,ORANGE,VIOLET,SANS_COULEUR} couleur;
typedef enum {VIDE,BLANC,NOIR} placement;

void encode(couleur t[LONGEUR_LIGNE]) {
    srand(time(NULL)); 
    for(int i=0;i<=3;i++) {
        t[i]=rand()%6;
    }
}

void  afficheCode(couleur t[LONGEUR_LIGNE]) {
    printf("[");
    for(int i =0;i<=2;i++) {
        printf("%d, ",t[i]);
    }
    printf("%d]\n",t[3]);
}

void afficher(couleur game[LONGEUR_LIGNE][NOMBRE_LIGNE],placement p[LONGEUR_LIGNE][NOMBRE_LIGNE], int tour) {
    printf("[");
    for (int i=0;i<=3;i++) {
        switch(game[i][tour]){
        case JAUNE: printf("🟡");break;
        case BLEU: printf("🔵");break;
        case ROUGE: printf("🔴");break;
        case VERT: printf("🟢");break;
        case ORANGE: printf("🟠");break;
        case VIOLET: printf("🟣");break;
        case SANS_COULEUR: printf(" ");break;
        default: printf(" ");break;
        }
    printf(" ");
    }
    printf("] [");
    for (int i=0;i<=3;i++) {
        switch(p[i][tour]){
        case VIDE: printf(" ");break;
        case NOIR: printf("⚫");break;
        case BLANC: printf("⚪");break;
        default: printf(" ");break;
    }
        printf(" ");
    }
    printf("]\n");
}

void saisie(int tour,couleur code[LONGEUR_LIGNE],couleur game[LONGEUR_LIGNE][NOMBRE_LIGNE]) {
    printf("Jouez vos couleurs: 🟡 0, 🔵 1,🔴 2, 🟢 3, 🟠 4, 🟣 5\n");
    int UserInput; 
    int i=0;
    while(i<4) {
        scanf("%d",&UserInput); 
        switch(UserInput){
            case JAUNE: game[i][tour]=JAUNE;break;
            case BLEU: game[i][tour]=BLEU;break;
            case ROUGE: game[i][tour]=ROUGE;break;
            case VERT: game[i][tour]=VERT;break;
            case ORANGE: game[i][tour]=ORANGE;break;
            case VIOLET: game[i][tour]=VIOLET;break;
            default:
                printf("Couleur incorrect");
                i--;
        }
        i++;
    }
}

void decode(couleur game[LONGEUR_LIGNE][NOMBRE_LIGNE],placement p[LONGEUR_LIGNE][NOMBRE_LIGNE], couleur code[LONGEUR_LIGNE], int tour) {
    int j=0;
    couleur temporaire[LONGEUR_LIGNE];
    // remplire la liste temporaire
    for (int i=0;i<LONGEUR_LIGNE;i++) {
        temporaire[i] = game[i][tour];
        p[i][tour]=VIDE;
    }
    for (int i=0;i<LONGEUR_LIGNE;i++) {
        //fiche noire
        if (temporaire[i]==code[i]) {
            p[j][tour]= NOIR;
            temporaire[i]=SANS_COULEUR;
            j++;
        }
        // fiche blanche
        for (int k =0;k<LONGEUR_LIGNE;k++) {
            if (temporaire[i]==code[k]) {
                p[j][tour]= BLANC; 
                temporaire[i]=SANS_COULEUR;
                j++;
            }
        }
    }
}

int main(int argc, char** argv) {
    printf("              ┌──────────────┐ \n              │  Mastermind  │\n              └──────────────┘ \n");
    int tour=0;
    couleur code[LONGEUR_LIGNE];
    couleur game[LONGEUR_LIGNE][NOMBRE_LIGNE];
    placement p[LONGEUR_LIGNE][NOMBRE_LIGNE];
    encode(code);
    while (tour !=12) {
        saisie(tour,code,game);
        decode(game,p,code,tour);
        for(int i =0;i<=tour;i++){
            afficher(game,p,i);
        }
        tour++;
    }
    return 0;
}
