#include <stdio.h>
#include <stdlib.h>

int puissanceNonTerminale(int a, int b);
int puissanceTerminale(int a,int b, int acc);
int main(){
    int a=10;
    int b=12;
    int test = puissanceNonTerminale(a,b);
    printf("%d**%d = %d \n", a,b,test);
    int test2 = puissanceTerminale(10,12,1);
    printf("%d**%d = %d \n",a,b,test2);
    return 0;
}

int puissanceNonTerminale(int a, int b) {
    if (b==0) {
        return 1;
    }
    else {
        return a*puissanceNonTerminale(a,b-1);
    }
}

int puissanceTerminale(int a,int b, int acc) {
    if (b==0) {
        return acc;
    } else {
        return puissanceTerminale(a,b-1,a*acc);
    }
}