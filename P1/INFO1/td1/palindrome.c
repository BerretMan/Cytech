#include <stdio.h>
#include <string.h>


/*
précondition: prends un string en entrée
postcondition: renvoit si le string est un palindrome*/
int palindrome(char mot[]) {
    for (int i; i<strlen(mot)/2;i++) {
        if (mot[i] != mot[-i]) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char** argv) {
    char mot[50];
    printf("donne un mot ou une phrase");
    scanf("%s",mot);
    if (palindrome(mot)) {
        printf("%s est un palindrome \n",mot);
    }
    else {
        printf("%s n'est pas un palindrome? \n",mot);
    }
    return 0;
}
