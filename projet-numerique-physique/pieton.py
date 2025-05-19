import pygame
import numpy as np
import math

from variable import *
from solve import *

class Pieton:
    def __init__(self, i, x, y):
        """
        Paramètres:
        i (int) : l'index/id du Pieton
        x (float) : la coordonee x initiale du Pieton
        y (float) : la coordonee y initiale du Pieton
        """
        self.id = i
        self.i = i
        self.pos = pygame.Vector2(x, y)

        self.vitesse = pygame.Vector2(0, 0)
        self.vect_direction = pygame.Vector2(0, 0)
        self.force_repulsive_pieton = pygame.Vector2(0, 0)
        self.force_repulsive_mur = pygame.Vector2(0, 0)
        self.force_motrice = pygame.Vector2(0, 0)


    def calc_force_repulsive_pietons(self, liste_pietons):
        self.force_repulsive_pieton = pygame.Vector2(0, 0)

        for pieton in liste_pietons:
            if pieton != self:
                distance_ij = self.pos.distance_to(pieton.pos) - RAYON * 2
                vect_ij = pygame.Vector2(self.pos.x - pieton.pos.x, self.pos.y - pieton.pos.y)
                
                self.force_repulsive_pieton += math.exp(- distance_ij / distance_confort) * vect_ij
    

    def calc_force_repulsive_murs(self, liste_murs):
        self.force_repulsive_mur = pygame.Vector2(0, 0)

        for mur in liste_murs:
            x_mur = max(mur.left, min(self.pos.x, mur.right))
            y_mur = max(mur.top, min(self.pos.y, mur.bottom))
            
            distance_ij = self.pos.distance_to(pygame.Vector2(x_mur, y_mur)) - RAYON
            vect_ij = pygame.Vector2(self.pos.x - x_mur, self.pos.y - y_mur)
            
            self.force_repulsive_mur += math.exp(- distance_ij / distance_confort) * vect_ij
    

    def calc_force_motrice(self, vitesse_desiree, dest_rect):
        self.vect_direction = pygame.Vector2(dest_rect.centerx - self.pos.x, dest_rect.centery - self.pos.y)
        self.vect_direction.normalize_ip()

        self.force_motrice = (vitesse_desiree * self.vect_direction - self.vitesse) / tau


    def deplacement(self):
        def f(t, v):
            return np.array(self.force_motrice + self.force_repulsive_pieton + self.force_repulsive_mur)
        
        temps, vitesse = RK4(f, T=0.001)
        self.vitesse += pygame.Vector2(vitesse[0][0], vitesse[0][1])

        norme_vitesse = math.sqrt(vitesse[0][0]**2 + vitesse[0][1]**2) / fps
        match self.id:
            case 1:
                liste_vitesse_point_p.append(norme_vitesse)
            case 2:
                liste_vitesse_point_b.append(norme_vitesse)
            case 3:
                liste_vitesse_point_v.append(norme_vitesse)
        
        self.pos += self.vitesse


    def afficher(self, ecran):
        pygame.draw.circle(ecran, BLACK, self.pos, RAYON+2)

        couleur = RED
        match self.id:
            case 1:
                couleur = PINK
            case 2:
                couleur = BLUE
            case 3:
                couleur = GREEN
        
        self.player = pygame.draw.circle(ecran, couleur, self.pos, RAYON)
        
        # pygame.draw.line(ecran, BLACK, self.pos, self.pos + self.vect_direction * RAYON)
        pygame.draw.line(ecran, BLACK, self.pos, self.pos + self.vitesse * RAYON)
        
    
    def verif_collission_dest(self, dest_rect):
        return dest_rect.colliderect(self.player)
