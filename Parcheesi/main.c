/**
 * @file main.c
 * @author Bixente Hiriart--Dicharry <hiriartdic@cy-tech.fr>
 * @version 0.1
 * @date 2024-05-21 09:09:36
 * @brief Programme principal du parcheesi 
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include "fonctions.h" 

int main(int argc, char *argv[]){
      srand(time(NULL));
      if (verifArgs(argc, argv)){
            system("clear");
            printf("              ┌─────────────┐ \n              │ \e[0;36m Parchessi  \e[0;37m│\n              └─────────────┘ \n");
            int nbJoueurs = nombreJoueurs(argc, *argv);
            Joueur* tab_Joueurs = creerJoueurs(nbJoueurs);
            for (int i =0;i<nbJoueurs;i++) {
                  tab_Joueurs[i].tab_pions=creerPions(i);
            }
            cases* tab_c=malloc(sizeof(cases)*94);
            init_case(tab_c);

            tourDeJeu(tab_Joueurs, tab_c,nbJoueurs);
            free(tab_Joueurs);  
            free(tab_c);     
            return 0;
      }else{
            printf("Erreur dans les arguments\n");
            return 1;
      }
}