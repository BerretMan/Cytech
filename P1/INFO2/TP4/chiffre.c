#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
int sChiffre(int a) {
    if (a<10) {
        return a; 
    } else {
        return a%10+sChiffre((a%10)/10);
    }
}
void emptyBuffer(){
  char c;
  while (((c = getchar()) != '\n') && (c != EOF));
}

int estPalindromeMot(char m[MAX],int deb,int fin) {
    if (m[deb]==m[fin]) {
        return 1;
    }else {
        return estPalindromeMot(m,deb+1,fin-1)+m[deb]==m[fin];
    }
}


int main(int agrc, char** argv) {
    printf("%d\n",sChiffre(324));
    char mot[MAX];
    fgets(mot,sizeof(char)*100,stdin);
    int taille=strlen(mot)-1;
    switch(estPalindromeMot(mot,0,taille-1)) {
        case 0: printf("%s n'est pas un palindrome",mot);break;
        default: printf("%.*s est un palindrome",taille,mot);break;
    }
    return 0;
}