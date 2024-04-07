#include <stdio.h>

int PGCD(int a, int b);
int dateValide(int jour, int mois, int annee);


int main(int argc, char** argv) {
    int jour,mois,annee; 
    printf("rentre jour, mois, annee");
    scanf("%d",&jour);
    scanf("%d",&mois);
    scanf("%d",&annee);
    printf("est ce un date valide ? : %d \n",dateValide(jour,mois,annee));
    return 0;
}
// préconditions: deux nombres entiers a et b 
// postconditions : renvoit le pgcd de a et b

int PGCD(int a, int b) {
    int r=a%b;
    int pgcd;
    while (r!=0) {
        r=a%b;
        if (r==0) {
        pgcd = b;
            }
        else {
            a=b;
            b=r;
        } 
    }
    return pgcd;
}
/*Précondition: Prends trois int jour mois et année
Postcondition : renvoit 1 si vrai et 0 si faux*/
int dateValide(int jour, int mois, int annee) {
    if (mois >0 && mois <= 12) {
        switch (mois) {
            case 1: //31 jours
            case 3: 
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if (jour <= 31){
                    return 1; 
                    }
                else {
                    return 0;
                }
            case 4:
            case 6://30 jours
            case 9:
            case 11:
                if (jour <= 30){
                    return 1;
                    }
                else {
                    return 0;
                }
            default:
                if (annee%4==0 && (annee%100!=0 || annee%400==0)){ // est bisextile
                    return 1;
                    } 
                else { 
                    return 0;
                }
        }
    }
    else {
        return 0;
    }
}
