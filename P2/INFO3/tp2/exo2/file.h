#ifndef FILE_H
#define FILE_H

typedef struct Personne{
    char* donnee;
    struct Personne* precedent;
}Personne;

typedef Personne* File;

/* Auteur : xxxxx */
/* Date : xxxxxx */
/* Entrees :  une chaine de caracteres*/
/* Sorties :  une personne*/
/* Résumé :  Creer une personne avec un nom */
Personne* creerElementFile(char* valeur);
#endif