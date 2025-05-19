import numpy as np
import matplotlib.pyplot as plt

from solve import *

g = 9.81
k = 3
m = 5
T = 10
h = 0.01

def f(t, v):
    return g - k / m * v

temps_euler, vitesse_euler = Euler(f, h, T)
temps_rk2, vitesse_rk2 = RK2(f, h, T)
temps_rk4, vitesse_rk4 = RK4(f, h, T)

temps_analytique = np.arange(0, T, h)
vitesse_analytique = list(map(lambda t: m * g/k * (1 - math.exp(- k/m * t)), temps_analytique))

plt.plot(temps_euler, vitesse_euler, label="Euler")
plt.plot(temps_rk2, vitesse_rk2, label="Runge-Kutta 2")
plt.plot(temps_rk4, vitesse_rk4, label="Runge-Kutta 4")
plt.plot(temps_analytique, vitesse_analytique, label="Analytique")

plt.xlabel("Temps (s)")
plt.ylabel("Vitesse")


plt.legend()
plt.grid(True)

plt.show()