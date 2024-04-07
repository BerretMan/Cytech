#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int puissanceRec (int a, int b) {
    if (b==1) {
        return a;

    } else {
        return puissanceRec(a,b-1)*a;
    }
}

int puissanceRecT(int a, int b,int c) {
    if (b==1) {
        return c*a;

    } else {
        return puissanceRecT(a,b-1,a*c);
    }
}

int pui(int a, int b) {
    return puissanceRecT(a,b,1);
}

int main(int argc,char** argv) {
    printf("%d\n",puissanceRec(3,4));
    printf("%d\n",pui(3,4));
    return 0;
}