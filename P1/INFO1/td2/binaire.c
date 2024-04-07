#include <stdio.h>

void dec_to_bin(int n) {
    printf("Le nombre est : ");
    while (n!=0) {
        printf("%d",n%2);
        n/=2;
    }
    printf("\n");
}

int main(int argc, char** argv) {
    int nombre;
    printf("rentre un nombre entier");
    scanf("%d",&nombre);
    dec_to_bin(nombre);
    return 0;
}