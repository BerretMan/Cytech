#ifndef PILE_H
#define PILE_H

enum fleche{ROUGE, VERTE, BLEUE};

typedef struct {
    int valeur;
    struct maillonPile* suivant;
} maillonPile;

typedef maillonPile* Pile;

/* Auteur : Inès */
/* Date : xxxxxx */
/* Entrees :  une valeur*/
/* Sorties :  le nouvel elt créer */
/* Résumé :  créer un nouvel elt */
maillonPile* creerElementPile (int valeur);

/* Auteur : xxxxxx */
/* Date : xxxxxx */
/* Entrees :  Pile et une fleche*/
/* Sorties :  la Pile */
/* Résumé :  Ajouter une fleche à une Pile */
void emPiler(Pile *p, int fl);

/* Auteur : xxxxxx */
/* Date : xxxxx */
/* Entrees :  une Pile*/
/* Sorties : la fleche depilée */
/* Résumé :  enlever la flèche de la Pile */
int dePiler(Pile* p);

/* Auteur : xxxxxxxx */
/* Date : xxxxxxx */
/* Entrees :  une Pile*/
/* Sorties :  */
/* Résumé :  Afficher une Pile */
void afficherP(Pile p);

/* Auteur : xxxxxxxx */
/* Date : xxxxxxx */Pile p=NULL; /* Premier élément de la pile */
/* Entrees :  une Pile et un accumulateur*/
/* Sorties : le nb de flèches*/
/* Résumé :  Compte le nombre de flèche dans une Pile */
int compterP(Pile p, int acc);

/* Auteur : xxxxxx */
/* Date : xxxxxx */
/* Entrees :  une Pile p1 et une Pile p2*/
/* Sorties : une Pile p2 */
/* Résumé :  inverse la Pile p1 dans p2 */
Pile inverserP(Pile p1, Pile p2);

/* Auteur : xxxxxx */
/* Date : xxxxxxxxx */
/* Entrees :  une Pile p1 et une Pile p2 */
/* Sorties : une Pile p2 */
/* Résumé :  doubler la Pile p1 dans la Pile p2  */
Pile doublerP(Pile p1,Pile p2);

void viderP (Pile* p);

int estVide(Pile p); 
#endif