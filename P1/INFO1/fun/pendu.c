#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE_MAX 100

void fill_tiret(char tiret[TAILLE_MAX],int len_mot) {
    for (int i=0;i<=len_mot-1;i++) {
        tiret[i]='-';
    }
}
void print_tab(char s[TAILLE_MAX],int len_mot){
    for (int i=0;i<=len_mot-1;i++) {
        printf("%c",s[i]);
    }
    printf("\n");
}

/* prends un tab de tiret de mot, une lettre et une longeur de mot
remplit le tableau de tiret avec la lettre trouvé
si trouvé alors renvoit -1 pour baisser l'indice i 
*/
int check_tiret(char tiret[TAILLE_MAX],char mot[TAILLE_MAX],char lettre,int len_mot) {
    int next_i=0;
    for (int i=0;i<=len_mot-1;i++) {
        if(lettre==mot[i]) {
            tiret[i]=lettre;
            next_i=-1;
        }
    }
    if (next_i == 0) {
        printf("\n\033[31mLa lettre %c n'est pas dans le mot \033[0m\n",lettre);
    }
    return next_i;
}
int main(int argc, char** argv) {
    char mot[TAILLE_MAX];
    char tiret[TAILLE_MAX];
    int i=0;
    char lettre;
    printf("              ┌─────────┐ \n              │  Pendu  │\n              └─────────┘ \n");
    printf("veuillez rentrer un mot:");
    scanf("%s[^\n]",mot);
    int len_mot=strlen(mot);
    printf("\e[1;1H\e[2J"); // clean terminal
    printf("%d\n",len_mot);
    fill_tiret(tiret,len_mot);
    do {
        printf("Voici le mot\n");
        print_tab(tiret,len_mot);
        printf("Rentre une lettre ->");  
        scanf(" %c",&lettre);
        i += check_tiret(tiret,mot,lettre,len_mot);
        i++;
    } while(i<=10);

    return 0;
}