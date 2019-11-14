import numpy as np
import matplotlib.pylab as plt

d1 = np.loadtxt("datos1.dat")
d2 = np.loadtxt("datos2.dat")

plt.figure()
plt.title("Trayectoria de proyectil")
plt.plot(d1[:,0], d1[:,1], label="Con fricción")
plt.plot(d2[:,0], d2[:,1], label="Sin friccion")
plt.xlabel("x")
plt.xlabel("y")
plt.legend()
plt.savefig("Trayectoria.png")