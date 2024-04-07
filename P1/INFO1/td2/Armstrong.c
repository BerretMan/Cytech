#include <stdio.h>
#include <math.h>
// Pre : prends un nombre entier >0
// Post: retourne si le nombre est un nombre Armstrong
int est_Armstrong(int n) {
    int save_n = n;
    int somme=0;
    int unite=0;
    while (n>0) {
        unite=n%10;
        somme+=pow(unite,3);
        n=(n-unite)/10;
    }
    if (somme==save_n) {
        return 1;
    }
    else {
        return 0;
    }
}
int main(int argc,char** argv) {
    int nombre;
    printf("Veuillez saisir un nombre entier : ");
    scanf("%d",&nombre);
    if (est_Armstrong(nombre)) {
        printf("le nombre est un nombre de Armstrong \n");
    } 
    else {
        printf("ceci n'est pas un nombre de Armstrong \n");
    }
    return 0;
}