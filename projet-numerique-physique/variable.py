import pygame
import sys

# nombre de Pieton
N = 100
RAYON = 15
tau = 0.5
distance_confort = RAYON / 4

# interface
largeur = 1280
hauteur = 720
millieu_x = int(largeur / 2)
millieu_y = int(hauteur / 2)

# Les couleurs
PINK = (255, 90, 172)
BLACK = (0, 0, 0)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 150, 255)
GREY = (200, 200, 200)
TURQUOISE = (64, 224, 208)

# simulation
fps = 30
simulation = int(sys.argv[1]) if len(sys.argv) > 1 else 1

# murs
match simulation:
    case 1:
        liste_murs = [
            pygame.Rect(500, 0, largeur, 20), # haut
            pygame.Rect(largeur - 20, 0, 20, hauteur - 100), # droite
            pygame.Rect(500, 0, 20, hauteur), # gauche
            pygame.Rect(500, hauteur - 20, largeur, 20), # bas
        ] 
        destination = (millieu_x+650, millieu_y+300)

    case 2:
        liste_murs = [
            pygame.Rect(500, 0, largeur, 20), # haut
            pygame.Rect(largeur - 20, 0, 20, hauteur - 100), # droite
            pygame.Rect(500, 0, 20, hauteur), # gauche
            pygame.Rect(500, hauteur - 20, largeur, 20), # bas

            pygame.Rect(largeur -200, 500, 40,120), # table
        ] 
        destination = (millieu_x+650, millieu_y+300)
    
    case 3: 
        liste_murs=[
            pygame.Rect(500, 0, largeur, 20), # haut
            pygame.Rect(largeur - 20, 0, 20, hauteur - 100), # droite
            pygame.Rect(500, 0, 20, hauteur), # gauche
            pygame.Rect(500, hauteur - 20, largeur, 20), #bas
            pygame.Rect(largeur-150, 275, 50, hauteur - 500) #bureau du professeur
        ]
        for i in range(3): # rangées des élèves
            liste_murs.append(pygame.Rect(650 + 150 * i, 100, 50, hauteur - 500))
            liste_murs.append(pygame.Rect(650 + 150 * i, 450, 50, 200))
        
        destination = (millieu_x+650, millieu_y+300)


liste_vitesse_point_v = []
liste_vitesse_point_b = []
liste_vitesse_point_p = []
