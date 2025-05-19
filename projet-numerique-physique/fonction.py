import math
import random as rd
from variable import *
from pieton import *

def creation_pietons(n, liste_murs):
    pietons=[]
    positions_initiales_aleatoires = poisson_disque_sampling(RAYON, N, liste_murs)

    #Créer les piétons
    for i in range(n):
        x, y = positions_initiales_aleatoires[i]
        pieton = Pieton(i, x, y)
        pietons.append(pieton)
    
    return pietons


def afficher_bouton_playpause(ecran, en_pause):
    bouton = pygame.image.load("Image/bouton-play.png" if en_pause else "Image/bouton-pause.png").convert_alpha()
    bouton = pygame.transform.scale(bouton, (100, 100))
    return ecran.blit(bouton, (180, 100))

def poisson_disque_sampling(rayon, n, liste_murs):
    def collision_mur(mur, x, y):
        x_mur = max(mur.left, min(x, mur.right))
        y_mur = max(mur.top, min(y, mur.bottom))
        return math.sqrt((x - x_mur)**2 + (y - y_mur)**2) < rayon + 10

    liste = []
    liste.append((rd.randint(550, largeur - 150), rd.randint(50, 650)))
    
    i = 0
    while i < n:
        x, y = rd.randint(550, largeur - 150), rd.randint(50, 650)
        if all(math.sqrt((x - x_l)**2 + (y - y_l)**2) > 2 * rayon + 10 for x_l, y_l in liste):
            if not any(collision_mur(mur, x, y) for mur in liste_murs):
                liste.append((x, y))
                i += 1
    
    return liste
