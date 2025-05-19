#include "pile.h"
#include <stdio.h>


int main() {
    Pile Link;
    Pile Kilton;
    Pile Zelda;
    emPiler(&Link,1);
    emPiler(&Kilton,2);
    emPiler(&Zelda,3);
    afficherP(Link);
    printf("hell world");
    return 0;
}