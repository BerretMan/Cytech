#include <stdio.h>
#define ERREUR(message) fprintf(stderr,"%s\n",message)
struct maya {
    int trait;
    int point;
}; typedef struct maya maya;
// Pre: prends un nombre de trait et de point<=4
// Post: retourne un nombre Maya
maya creerMaya(int trait, int point) {
    maya nombre;
    if (trait <4 && point <=4 && trait >=0 && point >=0) {
        nombre.trait=trait;
        nombre.point=point;
    
        return nombre;
    }
    if (point <=8 && trait <4) {
        nombre.trait=trait+1;
        nombre.point=point-4;
        return nombre;
    }
    else {
        ERREUR("le nombre n'est pas possible");
        return EXIT_FAILURE;
    }
}
// Prends deux nombres mayas tq n1+n2<=19
// Post: la somme des deux nombres en maya.
maya plus(maya n1,maya n2) {
    return creerMaya(n1.trait+n2.trait,n1.point+n2.trait);
}

void p_maya(maya n) {
    printf("trait:%d point:%d",n.trait,n.point);
}
int main(int argc , char** argv) { 
    maya n1,n2;n1.trait =2;n1.point=1;n2.trait =1;n2.point=1;
    p_maya(plus(n1,n2));
    printf("\n");
    return 0;
}