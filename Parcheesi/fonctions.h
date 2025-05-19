#ifndef FONCTIONS_H
#define FONCTIONS_H


typedef enum{
      JAUNE, BLEU, ROUGE, VERT,
}couleur;

typedef struct{
      int pos_l;
      int pos_c;
}cases;

typedef struct {
      int position;
      couleur color;
      char* sprite;
}pion;

typedef struct{
      char *id;
      couleur c;
      int nbPionsDepart;
      int nbPionsArrivee;
      bool is_Humain;
      pion *tab_pions;
      int caseSortie;
}Joueur;

/**
 * @author Serrano Lucas
 * @fn void initPion(Joueur joueur)
 * @date 2024-05-23 10:02:31
 * @brief Fonction qui initialise les joueurs
 *
 * @param argc Nombre d'arguments
 * @param argv Tableau d'arguments
*/
void initPion(Joueur joueur);

//Debug

void afficherJoueurs(Joueur * tabJoueurs);

//Utile

//Utile

/**
 * @author bixente Hirriart--Dicharry
 * @fn bool verifArgs(int argc, char *argv[])
 * @date 2024-05-23 10:02:31
 * @brief Fonction qui vérifie les arguments passés en paramètre
 *
 * @param argc Nombre d'arguments
 * @param argv Tableau d'arguments
*/
bool verifArgs(int argc, char *argv[]);

/**
 * @author Bixente Hiriart--Dicharry
 * @fn int nombreJoueurs(char *argv[])
 * @date 2024-05-23 10:22:19
 * @brief Fonction qui demande le nombre de joueurs
 * 
 * @param argv Tableau d'arguments

*/

/**
 * @author Serrano Lucas
 * @fn int nombreJoueurs(int argc, char *argv)
 * @date 2024-06-19 23:55:58
 * @brief donne le nombre de joueur
 *
 * @param argc le nombre d'argument
 * @param argv les arguments
*/
int nombreJoueurs(int argc, char *argv);

/**
 * @author Serrano Lucas
 * @fn Joueur *creerJoueurs(int nbJoueurs)
 * @date 2024-06-19 23:57:41
 * @brief Créer des Joueurs
 *
 * @param argc le nombre de joueur
*/
Joueur *creerJoueurs(int nbJoueurs);

/**
 * @author Serrano Lucas
 * @fn void printf_dice(int n);
 * @date 2024-06-19 23:55:58
 * @brief génére un nombre aléatoire entre 0 et 6
*/
pion* creerPions(couleur color);

/**
 * @author Serrano Lucas
 * @fn void printf_dice(int n);
 * @date 2024-06-19 23:55:58
 * @brief génére un nombre aléatoire entre 0 et 6
*/
int throw_dice();

/**
 * @author Serrano Lucas
 * @fn void printf_dice(int n);
 * @date 2024-06-19 23:55:36
 * @brief affiche le dès

 * @param n l'entier du dès
*/
void printf_dice(int n);

/**
 * @author Bixente Hiriart--Dicharry
 * @fn tourDeJeu(Joueur* tab_j, cases* tab_c,int nbJoueurs)
 * @date 2024-05-24 10:16:30
 * @brief change le joueur qui à la main sur le jeu

 * @param Joueur* tab_j
 * @param cases* tab_c
 * @param int nbJoueurs
*/
void tourDeJeu(Joueur* tab_j, cases* tab_c,int nbJoueurs);

/**
 * @author Bixente Hiriart--Dicharry
 * @fn bool aGagne(Joueur Joueur)
 * @date 2024-06-15 15:44:06
 * @brief Fonction qui vérifie si le joueur donné en argument a gagné
 * 
 * @param Joueur Joueur
*/

/**
 * @author Bixente Hiriart--Dicharry
 * @fn bool aGagne(Joueur Joueur)
 * @date 2024-06-15 15:44:06
 * @brief Fonction qui vérifie si le joueur donné en argument a gagné
 * 
 * @param Joueur Joueur
*/
bool aGagne(Joueur Joueur);

/**
 * @author Bixente Hiriart--Dicharry
 * @fn bool memeCase(int case, Joueur *Joueurs)
 * @date 2024-06-15 16:48:43
 * @brief Fonction qui vérifie si deux pions d'un joueur sont sur la même case
 * 
 * @param case La case à vérifier
 * @param Joueurs Les joueurs
 */
bool memeCase(int cases, pion *pions);


/**
 * @author Bixente Hiriart--Dicharry
 * @fn bool estBarrage(int case)
 * @date 2024-06-15 16:11:20
 * @brief Fonction qui vérifie si la case donnée en argument est un barrage
 * 
 * @param case
 */
bool estBarrage(int cases, Joueur *Joueurs);

void PrintHere(int x, int y, char* c);

/**
 * @author Serrano Lucas
 * @fn int n_pion_joueur(Joueur j)
 * @date 2024-06-19 23:54:03
 * @brief retourne le nombre de pion d'un joueur 
 * @param j Un joueur
 */
int n_pion_joueur(Joueur j);

/**
 * @author Serrano Lucas
 * @fn void print_score()
 * @date 2024-06-19 23:54:03
 * @brief procédure qui permet d'afficher le score en bas du plateau
 * 
 */
void print_score();


/**
 * @author Ambre Florette
 * @fn int affiche_tableau(char tab[21][21])
 * @date 2024-05-27 
 * @brief procédure qui permet d'afficher le plateau de jeu
 * 
 * @param char tab_aff[21][21]
 */
void affiche_tableau();

/**
 * @author Ambre Florette
 * @fn cases* init_case(cases* tab_c)
 * @date 2024-06-17 09:46:20
 * @brief Fonction qui lie le tableau de l'affichage a celui du parcours du jeu 
 * @param cases* tab_c
 */
void init_case(cases* tab_c);


/**
 * @author Ambre Florette
 * @fn void init_case_escalier_jaune(cases* tab_c) 
 * @date 2024-06-16 
 * @brief Fonction qui lie le tableau de l'affichage a celui du parcours du jeu 
 * 
 */
void init_case_escalier_jaune(cases* tab_c);


/**
 * @author Ambre Florette
 * @fn void init_case_escalier_bleu(cases* tab_c) 
 * @date 2024-06-16 
 * @brief Fonction qui lie le tableau de l'affichage a celui du parcours du jeu 
 * 
 */
void init_case_escalier_bleu(cases* tab_c);

/**
 * @author Ambre Florette
 * @fn void init_case_escalier_rouge(cases* tab_c) 
 * @date 2024-06-16 
 * @brief Fonction qui lie le tableau de l'affichage a celui du parcours du jeu 
 * 
 */
void init_case_escalier_rouge(cases* tab_c);

/**
 * @author Ambre Florette
 * @fn void init_case_escalier_vert(cases* tab_c) 
 * @date 2024-06-18
 * @brief Fonction qui lie le tableau de l'affichage a celui du parcours du jeu 
 * 
 */
void init_case_escalier_vert(cases* tab_c);

/**
 * @author Ambre Florette
 * @fn void message_final(Joueur j)
 * @date 2024-06-16 
 * @brief Affiche le message de fin après qu'un joueur est gagné  
 * 
 * @param Joueur j
 */
void message_final(Joueur j);

/**
 * @author Bixente Hiriart--Dicharry
 * @fn void mangerPion(pion pionMangeable, pion pionMangeur, int cases)
 * @date 2024-06-16 16:56:55
 * @brief Procédure permettant le choix de manger un pion ou non
 */
void mangerPion(Joueur* tab_j, pion* pionMangeable, pion* pionMangeur, int cases);

/**
 * @author Bixente Hiriart--Dicharry
 * @fn void affecterCase(Joueur joueur, couleur couleur)
 * @date 2024-06-16 17:28:18
 * @brief Procédure permettant d'affecter une case de sortie à un joueur
 * 
 * @param joueur Le joueur
 * @param couleur La couleur du joueur
 */
int affecterCase(Joueur joueur, couleur couleur);

/**
 * @author Serrano Lucas
 * @fn void affiche_pion(Joueur* tab_j,cases* tab_c)
 * @date 2024-06-19 23:52:54
 * @brief Affiche le pion
 * 
 * @param tab_j Un tableau de joueur
 * @param tab_c Un tableau de case
 */
void affiche_pion(Joueur* tab_j,cases* tab_c);

bool is_pawn(Joueur *tab_j,int num_case, couleur couleur); 
/** 
* @author Bixente Hiriart--Dicharry
* @fn void joue(Joueur * tab_j, cases* tab_c, int joueur)
* @date 2024-06-19 18:06:09
* @brief Fonction qui permet de jouer un tour
*
* @param tab_j Tableau de joueurs
* @param tab_c Tableau de cases
*/
void joue(Joueur * tab_j, cases* tab_c, int joueur);


#endif 