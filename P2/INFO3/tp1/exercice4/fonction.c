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

int pgcd(int a, int b) {
    int c;
    while (b !=0) {
        c=b;
        b=a%b;
        a=c;
    }
    return a;
}

int sommeChiffre(int n) {
    if (n<=9) {
        return n;
    } else {
        return sommeChiffre((n-n%10)/10)+n%10;
    }
}