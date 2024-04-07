#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
void supprCar(char mot[MAX],char car) {
    for (int i=0;i<strlen(mot)-1;i++) {
        if (mot[i]!=car){
            printf("%c",mot[i]);
        }
    }
    printf("\n");
}
int main(int argc,char** argv){
    char mot[MAX];
    fgets(mot,sizeof(char)*100,stdin);
    supprCar(mot,'r');
    return 0;
}