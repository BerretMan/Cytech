#include "liste.h"
#include <stdlib.h>
#include <stdio.h>

/* corps des différentes fonctions/procédures */

maillon* creerMaillon(int donnee) {
    maillon* m = (maillon*)malloc(sizeof(maillon));
    m->donnee= donnee;
    m->suivant=NULL;
    return m;
}

Liste ajouterTete(Liste maListe, int donnee) {
    maillon* m = creerMaillon(donnee);
    m->suivant=maListe;
    maListe=m;
    return maListe;
}

void afficher(Liste maListe) {
    printf(" %d |",maListe->donnee);
    if (maListe->suivant!=NULL) {
        afficher(maListe->suivant);
    } else {
        printf("\n");
    }
}

Liste ajouterFin(Liste maListe, int donnee) {
    if(maListe->suivant!=NULL) {
        maListe->suivant=ajouterFin(maListe->suivant,donnee);
        return maListe;
    } 
    maillon* m = creerMaillon(donnee);
    maListe->suivant=m;
    return maListe;
}

Liste ajouterPos(Liste maListe,int donnee,int pos) {
    if (maListe->suivant==NULL || pos==1) {
        return ajouterTete(maListe,donnee);
    }
        maListe->suivant = ajouterPos(maListe->suivant,donnee,pos-1);
        return maListe;
}


Liste supprimerDebut(Liste maListe) {
    return maListe->suivant;
}

Liste supprimerFin(Liste maListe) {
    if (maListe==NULL) {
        return maListe;
    } else {
        if (maListe->suivant==NULL) {
            return supprimerDebut(maListe);
        } else {
            maListe->suivant=supprimerFin(maListe->suivant);
            return maListe;
        }
    }
}


Liste supprimerPos(Liste maListe,int pos) {
    if (maListe==NULL) {
        return maListe;
    } else {
        if (pos==1) {
            return supprimerDebut(maListe);
        } else {
            maListe->suivant=supprimerPos(maListe->suivant,pos-1);
        }   return maListe;
    }
}

Liste viderListe(Liste maListe)  {
    maListe->suivant=NULL;
    return maListe;
}

Liste supFirst(Liste maListe, int elt) {
    if(maListe==NULL) {
        return maListe;
    } else {
        if (maListe->donnee== elt) {
            return supprimerDebut(maListe);
        } else {
            maListe->suivant=supFirst(maListe->suivant,elt);
            return maListe;
        }
    } 
}

Liste supAllOccurence(Liste maListe, int elt) {
    if (maListe==NULL) {
        return maListe;
    } else {
        if (maListe->donnee==elt) {
            maListe=supprimerDebut(maListe);
            return supAllOccurence(maListe,elt);
        } else {
            maListe->suivant=supAllOccurence(maListe->suivant,elt);
            return maListe;
        }
    }
}





