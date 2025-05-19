#include <stdio.h>
#include <stdlib.h>

int pgcd(int a, int b);
int main(){
    int a; int b;
    printf("a=");
    scanf("%d",&a);
    printf("b=");
    scanf("%d",&b);
    printf("le pgcd(%d,%d)=%d",a,b,pgcd(a,b));
    return 0;
}

int pgcd(int a, int b) {
    int c;
    while (b !=0) {
        c=b;
        b=a%b;
        a=c;
    }
    return a;
}