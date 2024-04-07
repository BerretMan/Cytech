#include <stdio.h>
#include <ctype.h>
// stock un joueur, caractérisé par son nom, son age et son char
struct joueur {
    char nom[20];
    int age;
    char charactere;
}; typedef struct joueur joueur;
// calcule si le joueur a gagné ou pas 
int gagne(char p[3][3]) {
    int victoire=1;
    for (int i =0;i<3;i++) {
        if (p[i][0]==p[i][1] && p[i][1] ==p[i][2] || //ligne 
        p[0][i]==p[1][i] && p[1][i]==p[2][i]) //colone
            victoire=0;
    }
    if (p[2][0]==p[1][1] && p[1][1]==p[2][2] ||
    p[0][2]==p[1][1] && p[1][1]==p[2][0]) {
        victoire=0;
    }
    return victoire;
}
// vide le buffer
void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

// affiche la grille
void AffGrille(char plateau[3][3]){
    for (int i=0;i<3;i++) {
        printf("—————————————\n| %c | %c | %c |\n",plateau[i][0],plateau[i][1],plateau[i][2]);
    }
    printf("—————————————\n");
}

// pre grille de jeux, le joueur, coord du coups
// post : joue le coup et l'affiche
void joue(char plateau[3][3],joueur j,int i, int k)
{ 
    plateau[i][k]=j.charactere;
    AffGrille(plateau);
}

void tour_de_jeu(char plateau[3][3], joueur j)
{
    int x,y;
    int choix;
    do {
        printf("%s (%c): \e[1;32mQuelle case voulez vous jouer? \e[0m",j.nom,j.charactere);
        scanf("%d",&choix);
    } while(choix>9 || choix<0);
    // attribue les touches aux bonnes cases
    if (choix==7){y=0;x=0;}
    if (choix==8){y=0;x=1;}
    if (choix==9){y=0;x=2;}
    if (choix==4){y=1;x=0;}
    if (choix==5){y=1;x=1;}
    if (choix==6){y=1;x=2;}
    if (choix==1){y=2;x=0;}
    if (choix==2){y=2;x=1;}
    if (choix==3){y=2;x=2;}
    if (isdigit(plateau[y][x])){
        joue(plateau,j,y,x);
    } else {
        printf("\e[1;91mcase déjà prise,veuillez refaire votre coup svp\e[0m \n");
        tour_de_jeu(plateau,j);
    }
}

//remplit le tableau pour les controles de bases
void fill_tab(char plateau[3][3]){
    int choix=7;
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            plateau[i][j]=choix+'0';
            choix++;
        }
        choix=choix-6;
    }
}

int main(int argc , char** argv) { 
    char plateau[3][3];
    fill_tab(plateau);
    joueur joueur1={.nom="Kevin",.age=10,.charactere='X'};
    joueur joueur2={.nom="Lucas",.age=18,.charactere='O'};
    /*printf("\e[1;32mBonjour joueur1, donne moi ton prénom, ton age et ton charactère:\e[0m\n");
    scanf("%s",joueur1.nom);
    viderBuffer();
    scanf("%d",&joueur1.age);
    viderBuffer();
    scanf("%c",&joueur1.charactere);
    viderBuffer();
    printf("\e[1;32mBonjour joueur2, donne moi ton prénom, ton age et ton charactère:\e[0m\n");
    scanf("%s",joueur2.nom);
    viderBuffer();
    scanf("%d",&joueur2.age);
    viderBuffer();
    scanf("%c",&joueur2.charactere);
    viderBuffer();*/
    AffGrille(plateau);
    int tour=0;
    while (gagne(plateau) || tour != 9){
        tour++;
        if (tour%2==0) {
            tour_de_jeu(plateau,joueur1);
        }
        else {
            tour_de_jeu(plateau,joueur2);
        }
    }
    if (tour ==8) {
        printf("match nulle!");
    }
    else {
    printf("\e[1;33m%s a gagné!!\e[0m\n",(tour%2==0? joueur1.nom:joueur2.nom)); // affiche qui a gagné
    }
    return 0;
}


