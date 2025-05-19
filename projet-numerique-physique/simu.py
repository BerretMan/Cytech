import pygame
import os

from variable import *
from fonction import *
import matplotlib.pyplot as plt

liste_pietons = creation_pietons(N, liste_murs)

pygame.init()
pygame.display.set_caption(f"Simulation {simulation}")

clock = pygame.time.Clock()
ecran = pygame.display.set_mode((largeur, hauteur))

police = pygame.font.Font("Font/Roboto.ttf", 30)

simu_en_cours = True
simu_en_pause = True
tour = 0
chrono = 0


rect_bouton_playpause = afficher_bouton_playpause(ecran, simu_en_pause)

rect_bouton_simu = [
    pygame.Rect(150, hauteur - 350, 60, 60),
    pygame.Rect(220, hauteur - 350, 60, 60),
    pygame.Rect(290, hauteur - 350, 60, 60)
]

while simu_en_cours:

    if N == 0:
        simu_en_pause = True
    
    for event in pygame.event.get():
        
        if event.type == pygame.QUIT:
            simu_en_cours = False
    
        if event.type == pygame.MOUSEBUTTONDOWN:
            for i, bouton in enumerate(rect_bouton_simu):
                if bouton.collidepoint(event.pos):
                    pygame.quit()
                    os.system(f"python3 simu.py {i + 1} || python simu.py {i + 1}")

            if rect_bouton_playpause.collidepoint(event.pos):
                simu_en_pause = not simu_en_pause
            
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_r:
                pygame.quit()
                os.system(f"python3 simu.py {simulation} || python simu.py {simulation}") 
            
            if event.key == pygame.K_g:
                y_v = liste_vitesse_point_v
                y_b = liste_vitesse_point_b
                y_p = liste_vitesse_point_p

                taille_max = max(len(y_v) ,len(y_b), len(y_p))
                x = [i for i in range(taille_max)]

                y_v += [0] * (taille_max - len(y_v))
                y_b += [0] * (taille_max - len(y_b))
                y_p += [0] * (taille_max - len(y_p))


                plt.title("Vitesse du point au cours de la simulation")
                plt.xlabel("Temps (en frame)")
                plt.ylabel("Vitesse")
                plt.legend()

                plt.plot(x, y_v, color="green")
                plt.plot(x, y_b, color="blue")
                plt.plot(x, y_p, color="pink")
                plt.show()

            if event.key == pygame.K_SPACE:
                simu_en_pause = not simu_en_pause

    ecran.fill(GREY)

        

    for mur in liste_murs:
        pygame.draw.rect(ecran, TURQUOISE, mur)
    
    dest_rect = pygame.draw.circle(ecran, GREEN, destination, 20)

    if simu_en_pause:
        for pieton in liste_pietons:
            pieton.afficher(ecran)
    else:
        i = 0
        while i < N:
            pieton = liste_pietons[i]
            pieton.i = i
            
            if pieton.verif_collission_dest(dest_rect):
                liste_pietons.remove(pieton)
                N -= 1
                continue

            pieton.calc_force_repulsive_pietons(liste_pietons)
            pieton.calc_force_repulsive_murs(liste_murs)
            pieton.calc_force_motrice(1.34, dest_rect)
            pieton.deplacement()

            pieton.afficher(ecran)
            
            i += 1

    #affichage du compteur de pions et du chronomètre
    clock.tick(fps)
    if not simu_en_pause:
        chrono += clock.get_time() / 1000
    
    affichage_chrono = police.render(f"Chrono: {chrono:.2f}s", 1, BLACK)
    ecran.blit(affichage_chrono, (10, 0))
    
    affichage_compteur_pions = police.render(f"Nombre de pietons restants: {N}", 1, BLACK)
    ecran.blit(affichage_compteur_pions, (10, 50))


    quel_simulation = police.render(f"Quelle simulation voulez-vous?", 1, BLACK)
    ecran.blit(quel_simulation, (70, 300))

    rect_bouton_playpause = afficher_bouton_playpause(ecran, simu_en_pause)

    for i, bouton in enumerate(rect_bouton_simu):
        pygame.draw.rect(ecran, BLUE if i + 1 == simulation else TURQUOISE, bouton)
        nbr_simu = police.render(str(i + 1), 1, BLACK)
        ecran.blit(nbr_simu, (bouton.x + bouton.width * 3/8, bouton.y + bouton.height * 1/4))
    
    pygame.display.flip()
    tour += 1


pygame.quit()