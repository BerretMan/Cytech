#include <stdio.h>
#include <stdlib.h>

int sommeChiffre(int n);

int main(){
    int nombre;
    printf("donne un nombre");
    scanf("%d",&nombre);
    printf("Somme des chiffres de sommeChiffre(%d)=%d",nombre,sommeChiffre(nombre));
    return 0;
}

int sommeChiffre(int n) {
    if (n<=9) {
        return n;
    } else {
        return sommeChiffre((n-n%10)/10)+n%10;
    }
}