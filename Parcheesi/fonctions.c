#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "fonctions.h"


#define N 30


/**
 * @fn bool verifArgs(int argc, char *argv[])
 * @date 2024-05-23 10:02:31
 * @brief Fonction qui vérifie les arguments passés en paramètre
 * 
 * @param argc Nombre d'arguments
 * @param argv Tableau d'arguments
*/
bool verifArgs(int argc, char *argv[]){
    if (argc < 3){
        return true;
    }else{
        return false;
    }
}

void emptyBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
  }
/**
 * @fn int nombreJoueurs(char *argv[])
 * @date 2024-05-23 10:22:19
 * @brief Fonction qui demande le nombre de joueurs
 * 
 * @param argv Tableau d'arguments

*/
int nombreJoueurs(int argc, char *argv){
    int nbJoueurs;
    if (argc==1){
        do{
        printf("Combien de joueurs vont jouer cette partie ? (1 à 4) : ");
        scanf("%d", &nbJoueurs);
        emptyBuffer();
        }while (nbJoueurs>4 || nbJoueurs<1);
        return nbJoueurs;

    }else if (!(atoi(&argv[1])<0 || atoi(&argv[1])>5)){
        return atoi(&argv[0]);
    }else{
        exit(-1);
    }
}

int affecterCase(Joueur joueur, couleur couleur){
    switch(couleur){
        case JAUNE:
            return 4;
            break;
        case BLEU:
            return 20; //20
            break;
        case ROUGE:
            return 52; //36            
            break;
        case VERT:
            return 36; //52
            break;
    }
    return -1;
}

Joueur* creerJoueurs(int nbJoueurs){
    Joueur* tab_Joueurs = malloc(4*sizeof(Joueur));
    for(int i=0; i<nbJoueurs; i++){
        printf("Bienvenue Joueur, comment vous nommez vous?\n->");
        tab_Joueurs[i].id=malloc(sizeof(N));
        scanf("%s", tab_Joueurs[i].id);
        emptyBuffer();
        tab_Joueurs[i].c=i;
        tab_Joueurs[i].nbPionsDepart=4;
        tab_Joueurs[i].nbPionsArrivee=0;
        tab_Joueurs[i].is_Humain=1;
        tab_Joueurs[i].tab_pions=creerPions(tab_Joueurs[i].c);
        tab_Joueurs[i].caseSortie = affecterCase(tab_Joueurs[i], tab_Joueurs[i].c);
    }
    for(int i=nbJoueurs; i<4; i++){
        tab_Joueurs[i].id="IA";
        tab_Joueurs[i].c=i;
        tab_Joueurs[i].nbPionsDepart=4;
        tab_Joueurs[i].nbPionsArrivee=0;
        tab_Joueurs[i].is_Humain=0;
        tab_Joueurs[i].tab_pions=creerPions(tab_Joueurs[i].c);
        tab_Joueurs[i].caseSortie = affecterCase(tab_Joueurs[i], tab_Joueurs[i].c);
    }
    return tab_Joueurs;
}


pion* creerPions(couleur color){
    pion* tab_pions = malloc(4*sizeof(pion));
    for(int y=0;y<4;y++){
        tab_pions[y].color=color;
        tab_pions[y].position=-1;
        tab_pions[y].sprite="♞";
    }
    return tab_pions;
}

int throw_dice() {
    return 1+rand()%6;
}

//auteur: Lucas
//pre: Des coordonées
//post: Affiche une chaine de caractère au coordonée indiqué dans le termminal
void PrintHere(int x, int y, char* c)
{
    printf("\033[%d;%dH%s", x, y, c);
}

// auteur: Lucas
//pre: un int
//post: affiche le dès à droite du plateau 
void printf_dice(int n) {
    int l=10; // la ligne où afficher le texte
    int c=50; // la colonne où afficher le texte
    switch(n) {
        case 1:
            PrintHere(l  , c, "┌───────┐");
            PrintHere(l+1, c, "│       │");
            PrintHere(l+2, c, "│   •   │");
            PrintHere(l+3, c, "│       │");
            PrintHere(l+4, c, "└───────┘");
            break;
        case 2:
            PrintHere(l  , c, "┌───────┐");
            PrintHere(l+1, c, "│ •     │");
            PrintHere(l+2, c, "│       │");
            PrintHere(l+3, c, "│     • │");
            PrintHere(l+4, c, "└───────┘");
            break;
        case 3:
            PrintHere(l  , c, "┌───────┐");
            PrintHere(l+1, c, "│ •     │");
            PrintHere(l+2, c, "│   •   │");
            PrintHere(l+3, c, "│     • │");
            PrintHere(l+4, c, "└───────┘");
            break;
        case 4:
            PrintHere(l  , c, "┌───────┐");
            PrintHere(l+1, c, "│ •   • │");
            PrintHere(l+2, c, "│       │");
            PrintHere(l+3, c, "│ •   • │");
            PrintHere(l+4, c, "└───────┘");
            break;
        case 5:
            PrintHere(l  , c, "┌───────┐");
            PrintHere(l+1, c, "│ •   • │");
            PrintHere(l+2, c, "│   •   │");
            PrintHere(l+3, c, "│ •   • │");
            PrintHere(l+4, c, "└───────┘");
            break;
        case 6:
            PrintHere(l  , c, "┌───────┐");
            PrintHere(l+1, c, "│ •   • │");
            PrintHere(l+2, c, "│ •   • │");
            PrintHere(l+3, c, "│ •   • │");
            PrintHere(l+4, c, "└───────┘");
            break;
    }
}      

bool aGagne(Joueur Joueur){
    if (Joueur.nbPionsArrivee>3){
        return true;
    }
    return false;
}

bool memeCase(int cases, pion *pions){
    int nbPions=0;
    for(int i=0; i<4; i++){
        if (pions[i].position==cases){
            nbPions++;
        }
    }
    if (nbPions>1){
        return true;
    }
    return false;
}

bool estBarrage(int cases, Joueur *Joueurs){
    for(int i=0; i<3; i++){
        if (memeCase(cases, Joueurs[i].tab_pions)){
            return true;
        }
    }
    return false;
}

// void mangerPion(Joueur* tab_j, pion* pionMangeable, pion* pionMangeur, int cases){
//     printf("%s voulez vous manger le pions de %s ? (O/n)\n", tab_j[pionMangeur.color].id, tab_j[pionMangeable.color].id);
//     char c;
//     scanf("%c",&c);
//     if (c != 'n') {
//         &pionMangeable.position=-1;
//         tab_j[&pionMangeable.color].nbPionsDepart++;
//         &pionMangeur.position+=20;
//         if (&pionMangeur.position > 63) {
//             &pionMangeur.position -= 64;
//         }
//     }
// }


bool is_pawn(Joueur *tab_j,int num_case, couleur couleur) {
    bool condition=0;
    for (int i=0;i<=couleur;i++) {
        for (int j=0;j<=4;j++) {
            if (tab_j[i].tab_pions[j].position==num_case) {
                condition=1;
            }
        }
    }
    for (int i=couleur;i<=4;i++) {
        for (int j=0;j<=4;j++) {
            if (tab_j[i].tab_pions[j].position==num_case) {
                condition=1;
            }
        }
    }
    return condition;
}



void affiche_pion(Joueur* tab_j,cases* tab_c) {
    //jaune
    switch (tab_j[0].nbPionsDepart) { //bonne chance
        case 4:PrintHere(3,4,"\e[0;33m ♞ \e[0;37m");PrintHere(3,8,"\e[0;33m ♞ \e[0;37m");PrintHere(5,4,"\e[0;33m ♞ \e[0;37m");PrintHere(5,8,"\e[0;33m ♞ \e[0;37m");break;
        case 3:PrintHere(3,4,"\e[0;33m ♞ \e[0;37m");PrintHere(3,8,"\e[0;33m ♞ \e[0;37m");PrintHere(5,4,"\e[0;33m ♞ \e[0;37m");PrintHere(tab_c[tab_j[0].tab_pions[3].position].pos_l,tab_c[tab_j[0].tab_pions[3].position].pos_c,"\e[0;33m ♞ \e[0;37m");break;
        case 2:PrintHere(3,4,"\e[0;33m ♞ \e[0;37m");PrintHere(3,8,"\e[0;33m ♞ \e[0;37m");PrintHere(tab_c[tab_j[0].tab_pions[2].position].pos_l,tab_c[tab_j[0].tab_pions[2].position].pos_c,"\e[0;33m ♞ \e[0;37m");PrintHere(tab_c[tab_j[0].tab_pions[3].position].pos_l,tab_c[tab_j[0].tab_pions[3].position].pos_c,"\e[0;33m ♞ \e[0;37m");break;
        case 1:PrintHere(3,4,"\e[0;33m ♞ \e[0;37m");PrintHere(tab_c[tab_j[0].tab_pions[1].position].pos_l,tab_c[tab_j[0].tab_pions[1].position].pos_c,"\e[0;33m ♞ \e[0;37m");PrintHere(tab_c[tab_j[0].tab_pions[2].position].pos_l,tab_c[tab_j[0].tab_pions[2].position].pos_c,"\e[0;33m ♞ \e[0;37m");PrintHere(tab_c[tab_j[0].tab_pions[3].position].pos_l,tab_c[tab_j[0].tab_pions[3].position].pos_c,"\e[0;33m ♞ \e[0;37m");break;
        default:PrintHere(tab_c[tab_j[0].tab_pions[0].position].pos_l,tab_c[tab_j[0].tab_pions[0].position].pos_c,"\e[0;33m ♞ \e[0;37m");PrintHere(tab_c[tab_j[0].tab_pions[1].position].pos_l,tab_c[tab_j[0].tab_pions[1].position].pos_c,"\e[0;33m ♞ \e[0;37m");PrintHere(tab_c[tab_j[0].tab_pions[2].position].pos_l,tab_c[tab_j[0].tab_pions[2].position].pos_c,"\e[0;33m ♞ \e[0;37m");PrintHere(tab_c[tab_j[0].tab_pions[3].position].pos_l,tab_c[tab_j[0].tab_pions[3].position].pos_c,"\e[0;33m ♞ \e[0;37m");break;
    }
    //bleu
    switch (tab_j[1].nbPionsDepart) { //bonne chance
        case 4:PrintHere(17,4,"\e[0;36m ♞ \e[0;37m");PrintHere(17,8,"\e[0;36m ♞ \e[0;37m");PrintHere(19,4,"\e[0;36m ♞ \e[0;37m");PrintHere(19,8,"\e[0;36m ♞ \e[0;37m");break;
        case 3:PrintHere(17,4,"\e[0;36m ♞ \e[0;37m");PrintHere(17,8,"\e[0;36m ♞ \e[0;37m");PrintHere(19,4,"\e[0;36m ♞ \e[0;37m");PrintHere(tab_c[tab_j[1].tab_pions[3].position].pos_l,tab_c[tab_j[1].tab_pions[3].position].pos_c,"\e[0;36m ♞ \e[0;37m");break;
        case 2:PrintHere(17,4,"\e[0;36m ♞ \e[0;37m");PrintHere(17,8,"\e[0;36m ♞ \e[0;37m");PrintHere(19,4,"\e[0;36m ♞ \e[0;37m");PrintHere(tab_c[tab_j[1].tab_pions[2].position].pos_l,tab_c[tab_j[1].tab_pions[2].position].pos_c,"\e[0;36m ♞ \e[0;37m");PrintHere(tab_c[tab_j[1].tab_pions[3].position].pos_l,tab_c[tab_j[1].tab_pions[3].position].pos_c,"\e[0;36m ♞ \e[0;37m");break;
        case 1:PrintHere(17,4,"\e[0;36m ♞ \e[0;37m");PrintHere(tab_c[tab_j[1].tab_pions[1].position].pos_l,tab_c[tab_j[1].tab_pions[1].position].pos_c,"\e[0;36m ♞ \e[0;37m");PrintHere(tab_c[tab_j[1].tab_pions[2].position].pos_l,tab_c[tab_j[1].tab_pions[2].position].pos_c,"\e[0;36m ♞ \e[0;37m");PrintHere(tab_c[tab_j[1].tab_pions[3].position].pos_l,tab_c[tab_j[1].tab_pions[3].position].pos_c,"\e[0;36m ♞ \e[0;37m");break;
        default:PrintHere(tab_c[tab_j[1].tab_pions[0].position].pos_l,tab_c[tab_j[1].tab_pions[0].position].pos_c,"\e[0;36m ♞ \e[0;37m");;PrintHere(tab_c[tab_j[1].tab_pions[1].position].pos_l,tab_c[tab_j[1].tab_pions[1].position].pos_c,"\e[0;36m ♞ \e[0;37m");PrintHere(tab_c[tab_j[1].tab_pions[2].position].pos_l,tab_c[tab_j[1].tab_pions[2].position].pos_c,"\e[0;36m ♞ \e[0;37m");PrintHere(tab_c[tab_j[1].tab_pions[3].position].pos_l,tab_c[tab_j[1].tab_pions[3].position].pos_c,"\e[0;36m ♞ \e[0;37m");break;
    }
    //vert
    switch (tab_j[2].nbPionsDepart){
            case 4:PrintHere(3, 32, "\e[0;32m ♞ \e[0;37m");PrintHere(3, 36, "\e[0;32m ♞ \e[0;37m");PrintHere(5, 32, "\e[0;32m ♞ \e[0;37m");PrintHere(5, 36, "\e[0;32m ♞ \e[0;37m");break;
            case 3:PrintHere(3, 32, "\e[0;32m ♞ \e[0;37m");PrintHere(3, 36, "\e[0;32m ♞ \e[0;37m");PrintHere(5, 32, "\e[0;32m ♞ \e[0;37m");PrintHere(tab_c[tab_j[2].tab_pions[3].position].pos_l, tab_c[tab_j[2].tab_pions[3].position].pos_c, "\e[0;32m ♞ \e[0;37m");break;
            case 2:PrintHere(3, 32, "\e[0;32m ♞ \e[0;37m");PrintHere(3, 36, "\e[0;32m ♞ \e[0;37m");PrintHere(tab_c[tab_j[2].tab_pions[2].position].pos_l, tab_c[tab_j[2].tab_pions[2].position].pos_c, "\e[0;32m ♞ \e[0;37m");PrintHere(tab_c[tab_j[2].tab_pions[3].position].pos_l, tab_c[tab_j[2].tab_pions[3].position].pos_c,"\e[0;32m ♞ \e[0;37m");break;
            case 1:PrintHere(3, 32, "\e[0;32m ♞ \e[0;37m");PrintHere(tab_c[tab_j[2].tab_pions[1].position].pos_l, tab_c[tab_j[2].tab_pions[1].position].pos_c, "\e[0;32m ♞ \e[0;37m");PrintHere(tab_c[tab_j[2].tab_pions[2].position].pos_l, tab_c[tab_j[2].tab_pions[2].position].pos_c, "\e[0;32m ♞ \e[0;37m");PrintHere(tab_c[tab_j[2].tab_pions[3].position].pos_l, tab_c[tab_j[2].tab_pions[3].position].pos_c,"\e[0;32m ♞ \e[0;37m");break;
            default:PrintHere(tab_c[tab_j[2].tab_pions[0].position].pos_l,tab_c[tab_j[2].tab_pions[0].position].pos_c,"\e[0;32m ♞ \e[0;37m");PrintHere(tab_c[tab_j[2].tab_pions[1].position].pos_l,tab_c[tab_j[2].tab_pions[1].position].pos_c,"\e[0;32m ♞ \e[0;37m");PrintHere(tab_c[tab_j[2].tab_pions[2].position].pos_l,tab_c[tab_j[2].tab_pions[2].position].pos_c,"\e[0;32m ♞ \e[0;37m");PrintHere(tab_c[tab_j[2].tab_pions[3].position].pos_l,tab_c[tab_j[2].tab_pions[3].position].pos_c,"\e[0;32m ♞ \e[0;37m");break;
        }

    //rouge
    switch(tab_j[3].nbPionsDepart) {
        case 4:PrintHere(17,32,"\e[0;31m ♞ \e[0;37m");PrintHere(17,36,"\e[0;31m ♞ \e[0;37m");PrintHere(19,32,"\e[0;31m ♞ \e[0;37m");PrintHere(19,36,"\e[0;31m ♞ \e[0;37m");break;
        case 3:PrintHere(17,32,"\e[0;31m ♞ \e[0;37m");PrintHere(17,36,"\e[0;31m ♞ \e[0;37m");PrintHere(19,32,"\e[0;31m ♞ \e[0;37m");PrintHere(tab_c[tab_j[3].tab_pions[3].position].pos_l,tab_c[tab_j[3].tab_pions[3].position].pos_c,"\e[0;31m ♞ \e[0;37m");break;
        case 2:PrintHere(17,32,"\e[0;31m ♞ \e[0;37m");PrintHere(17,36,"\e[0;31m ♞ \e[0;37m");PrintHere(tab_c[tab_j[3].tab_pions[2].position].pos_l,tab_c[tab_j[3].tab_pions[2].position].pos_c,"\e[0;31m ♞ \e[0;37m");PrintHere(tab_c[tab_j[3].tab_pions[3].position].pos_l,tab_c[tab_j[3].tab_pions[3].position].pos_c,"\e[0;31m ♞ \e[0;37m");break;
        case 1:PrintHere(17,32,"\e[0;31m ♞ \e[0;37m");PrintHere(tab_c[tab_j[3].tab_pions[1].position].pos_l,tab_c[tab_j[3].tab_pions[1].position].pos_c,"\e[0;31m ♞ \e[0;37m");PrintHere(tab_c[tab_j[3].tab_pions[2].position].pos_l,tab_c[tab_j[3].tab_pions[2].position].pos_c,"\e[0;31m ♞ \e[0;37m");PrintHere(tab_c[tab_j[3].tab_pions[3].position].pos_l,tab_c[tab_j[3].tab_pions[3].position].pos_c,"\e[0;31m ♞ \e[0;37m");break;
        default:PrintHere(tab_c[tab_j[3].tab_pions[0].position].pos_l,tab_c[tab_j[3].tab_pions[0].position].pos_c,"\e[0;31m ♞ \e[0;37m");PrintHere(tab_c[tab_j[3].tab_pions[1].position].pos_l,tab_c[tab_j[3].tab_pions[1].position].pos_c,"\e[0;31m ♞ \e[0;37m");PrintHere(tab_c[tab_j[3].tab_pions[2].position].pos_l,tab_c[tab_j[3].tab_pions[2].position].pos_c,"\e[0;31m ♞ \e[0;37m");PrintHere(tab_c[tab_j[3].tab_pions[3].position].pos_l,tab_c[tab_j[3].tab_pions[3].position].pos_c,"\e[0;31m ♞ \e[0;37m");break;
    }
}

int n_pion_joueur(Joueur j) {
    return 4-j.nbPionsArrivee;
}

void print_score(Joueur* tab_j) {
    int score_jaune=n_pion_joueur(tab_j[0]);
    int score_bleu=n_pion_joueur(tab_j[1]);
    int score_rouge=n_pion_joueur(tab_j[2]);
    int score_vert=n_pion_joueur(tab_j[3]);
    char buffer[100];
    //concatenate int to string 
    sprintf(buffer, "\e[0;33m ♞ %d  \e[0;36m ♞ %d  \e[0;31m ♞ %d  \e[0;32m ♞ %d \e[0;37m \n", score_jaune,score_bleu,score_rouge,score_vert);
    PrintHere(22,0,buffer);
}

void affiche_tableau(){
    system("cat p.txt");
}


void init_case(cases* tab_c) {
    // cases 0 à 7
    for (int i = 0; i < 8; i++) {
        tab_c[i].pos_c = 14;
        tab_c[i].pos_l = i+1;
    }
    // cases 8 à 14
    for (int i = 8; i < 15; i++) {
        tab_c[i].pos_c = 28 - (2 * i);
        tab_c[i].pos_l = 8;
    }
    // case 15
    tab_c[15].pos_c = 0;
    tab_c[15].pos_l = 11;
    // cases 16 à 23
    for (int i = 16; i < 24; i++) {
        tab_c[i].pos_c = 0+2*i-32;
        tab_c[i].pos_l = 14;
    }
    // cases 24 à 30
    for (int i = 24; i < 31; i++) {
        tab_c[i].pos_c = 14;
        tab_c[i].pos_l = 16 + i - 25;
    }
    // case 31
    tab_c[31].pos_c = 20;
    tab_c[31].pos_l = 21;
    // cases 34 à 39
    for (int i = 32; i < 40; i++) {
        tab_c[i].pos_c = 26;
        tab_c[i].pos_l = 21-i+32;
    }
    // cases 42 à 46
    for (int i = 40; i < 47; i++) {
        tab_c[i].pos_c = 28+2*i-80;
        tab_c[i].pos_l = 14;
    }
    // case 47
    tab_c[47].pos_c = 40;
    tab_c[47].pos_l = 11;
    // cases 48 à 56
    for (int i = 48; i < 56; i++) {
        tab_c[i].pos_c = 40-2*i+96;
        tab_c[i].pos_l = 8;
    }
    // cases 56 à 66
    for (int i = 56; i < 63; i++) {
        tab_c[i].pos_c = 26;
        tab_c[i].pos_l = 7-i+56;
    }
    // case 67
    tab_c[63].pos_c = 20;
    tab_c[63].pos_l = 0;
    //jaune
    for (int i = 70; i < 76; i++) {
        tab_c[i].pos_c = 20;
        tab_c[i].pos_l = 2+i-70;
    }
    //bleu
    for (int i = 76; i < 82; i++) {
        tab_c[i].pos_c = 2*i+3-152;
        tab_c[i].pos_l = 11;
    }
    //rouge
    for (int i = 82; i < 88; i++) {
        tab_c[i].pos_c = 20;
        tab_c[i].pos_l = 17-i-2+87;
    }
    //vert
    for (int i = 88; i < 94; i++) {
        tab_c[i].pos_c = 38-2*i+176;
        tab_c[i].pos_l = 11;
    }
    
}


void message_final(Joueur j){
    printf("Bravo %s, vous avez gagnez la partie !", j.id);
}

void bougerBot (Joueur* tab_j, int i){
    int score_dice = throw_dice();
    if(score_dice == 6 && tab_j[i].nbPionsDepart>0){
        tab_j[i].nbPionsDepart--;
        tab_j[i].tab_pions[tab_j[i].nbPionsDepart].position = tab_j[i].caseSortie;
    }else {
        char temp[32];
        char buffer[1024];  
        for (int j = 0; j < 4; j++) {
            if (tab_j[i].tab_pions[j].position!=-1) {
                sprintf(temp, "%d : pion case %d  \n", j, tab_j[i].tab_pions[j].position);
                strcat(buffer, temp);
            }
        }
        int choix;
        choix=(rand() % 4);
        int position = tab_j[i].tab_pions[choix].position;
        position += score_dice;
        if ((i==0)&&((position)<69)&&((position)>63)){
            tab_j[i].tab_pions[choix].position=70;
        }else {
        if ((i==1)&&((position)<21&&((position)>14))){
            tab_j[i].tab_pions[choix].position=76;
        }else
        if ((i==3)&&((position)<37)&&((position>30))){
            tab_j[i].tab_pions[choix].position=84;
        }else
        if ((i==2)&&((position)<52)&&((position)>45)){
            tab_j[i].tab_pions[choix].position=94;
        }else{
            tab_j[i].tab_pions[choix].position += score_dice;
            if ((tab_j[i].tab_pions[choix].position > 63)&&(tab_j[i].tab_pions[choix].position < 70)) {
                tab_j[i].tab_pions[choix].position-=64;
                }
            }
        }
    }
}

bool veutsortirpion(){
    char buffer[1024]="->";  
    PrintHere(28, 0, "Voulez vous sortir un pion ? (O,n)\n");
    PrintHere(29, 0, buffer);
    char c;
    scanf("%c",&c);
    if (c != 'n') {
        return true;
    }
    return false;
}

void bouger(Joueur* tab_j, int i){
    int score_dice = throw_dice();
    char temp[32]="";
    char buffer[1024]=""; 
    printf_dice(score_dice);
    printf("Vous avez fait un %d\n", score_dice);usleep(1000000);
    if (tab_j[i].nbPionsDepart == 4) {
        if(score_dice == 6){
            tab_j[i].nbPionsDepart = 3;
            tab_j[i].tab_pions[3].position = tab_j[i].caseSortie;
            printf("Vous avez sorti un pion\n");
        } 
    }else{
        if((score_dice==6) && (veutsortirpion())){
            tab_j[i].tab_pions[4-tab_j[i].nbPionsDepart].position=tab_j[i].caseSortie;
            tab_j[i].nbPionsDepart--;
        }else{
            for (int j = 0; j < 4; j++) {
                if (tab_j[i].tab_pions[j].position!=-1) {
                    sprintf(temp, "%d : pion case %d  \n", j, tab_j[i].tab_pions[j].position);
                    strcat(buffer, temp);
                }
            }
            strcat(buffer, "->");
            PrintHere(28, 0, "Quel pion voulez vous bouger ?");
            PrintHere(29, 0, buffer);

            int choix;
            scanf("%d", &choix);

            if (choix < 0 || choix >= 4) {
                printf("Choix invalide.\n");
                return;
            }
            int position = tab_j[i].tab_pions[choix].position;
            position += score_dice;
            if ((i==0)&&((position)<69)&&((position)>63)){
                tab_j[i].tab_pions[choix].position=70;
            }else
            if ((i==1)&&((position)<21&&((position)>14))){
                tab_j[i].tab_pions[choix].position=76;
            }else
            if ((i==3)&&((position)<37)&&((position>30))){
                tab_j[i].tab_pions[choix].position=84;
            }else
            if ((i==2)&&((position)<52)&&((position)>45)){
                tab_j[i].tab_pions[choix].position=94;
            }else
            if ((i==0)&&(position>75)){
                tab_j[i].nbPionsArrivee++;
                tab_j[i].tab_pions[choix].position=-1;
            }else
            if ((i==01)&&(position>81)){
                tab_j[i].nbPionsArrivee++;
                tab_j[i].tab_pions[choix].position=-1;
            }else
            if ((i==3)&&(position>89)){
                tab_j[i].nbPionsArrivee++;
                tab_j[i].tab_pions[choix].position=-1;
            }else
            if ((i==2)&&(position>99)){
                tab_j[i].nbPionsArrivee++;
                tab_j[i].tab_pions[choix].position=-1;
            }else{
                tab_j[i].tab_pions[choix].position += score_dice;
                printf("%d",tab_j[i].tab_pions[choix].position);
                if ((tab_j[i].tab_pions[choix].position > 63)&&(tab_j[i].tab_pions[choix].position < 70)) {
                    tab_j[i].tab_pions[choix].position-=64;
                }
            }
        }
    }
}


void joue(Joueur* tab_j, cases* tab_c, int joueur){
    char* buffer=malloc(sizeof(N));
    char c;
    if (tab_j[joueur].is_Humain==false){
        bougerBot(tab_j,joueur);
    }else{
        sprintf(buffer,"C'est au tour de %s\nLancer le dès (d)\n->", tab_j[joueur].id);
        PrintHere(25,0,buffer);
        scanf("%c",&c);
        emptyBuffer();
        if (c=='d') {
            bouger(tab_j,joueur);
        } 
    }
    free(buffer);
}


void tourDeJeu(Joueur* tab_j, cases* tab_c,int nbJoueurs){
	int tour=0;
    bool partieContinue = true; 
    while(partieContinue){
        system("clear");
        affiche_tableau();
        affiche_pion(tab_j,tab_c);
        print_score(tab_j);
        //tours de jeu
        joue(tab_j, tab_c, tour%4);
        //vérification victoire
        if (aGagne(tab_j[tour%4])){
            message_final(tab_j[tour%4]);
            partieContinue = false;
        }        
		tour++;
    } 
}