#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"
#include "abr.h"
#include <time.h>
/* corps des différentes fonctions/procédures */

arbre insertionArbre(int val, arbre a) {
    if (a==NULL) {
        a=creerArbreBinaire(val,NULL,NULL);
    } else {
        if (val< a->val) {
            a->filsG=insertionArbre(val,a->filsG);
        } else {
            a->filsD=insertionArbre(val,a->filsD);
        }

    }
    return a;
}

arbre rechercheArbre(int val, arbre a) {
    if (a==NULL) {
        return a;
    } else {
        if (a->val == val) {
            return a;
        }if( val < a->val) {
            return rechercheArbre(val,a->filsG);
        } else {
            return rechercheArbre(val,a->filsD);
        }

    }
}

int minArbre(arbre a) {
    if (a->filsG==NULL) {
        return a->val
    } else {
        return minArbre(a->filsG);
    }
}

int maxArbre(arbre a) {
    if (a->filsD==NULL) {
        return a->val
    } else {
        return minArbre(a->filsD);
    }
}

arbre supprArbre(int val, arbre a) {
    if (a==NULL) {
        return a;
    } else {
        if (a->val > val) {
            return creerArbreBinaire(a->val,a->filg,supprArbre(val,a));
        } else if (a->val <val){
            return creerArbreBinaire(a->val,supprArbre(val,a),a->filsD);
        } else {
            return creerArbreBinaire(maxArbre(a->filsG),supprArbre(max,a->filsG),a->filsD);
        }
    }
}

arbre supprMax(arbre a) {
    return supprArbre(maxArbre(a),a);
}

arbre intersection(arbre a1, arbre a2, arbre a3) {
    if (a==NULL) {
        a=creerArbreBinaire(val,NULL,NULL);
    } else {
        if (val <a->val) {
             a->filsG=insertionArbre(val,a->filsG);
        }
       else {
        a->filsD=insertionArbre(val,a->filsD);
       }
    }
    return a;
}

arbre aleatoireArbre(int nbNoeuds, arbre a) {
    if (nbNoeuds==0) {
        return NULL;
    } else {
        while (nbNoeuds!=0) {
            int n=rand();
            insertionArbre(n,a);
            nbNoeuds--;
        }
    }
    return a;

}





int estBinaire(arbre a) {
    return (a->filG==a->filG && a->filD==a->filD);
}