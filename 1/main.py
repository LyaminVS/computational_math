import numpy as np
from matplotlib import pyplot as plt
import subprocess

subprocess.call("1/main")

data = np.loadtxt("data_gorner.txt")
data_brute_force = np.loadtxt("data_brute_force.txt")

plt.plot(data[:, 0], data[:, 1])
plt.plot(data_brute_force[:, 0], data_brute_force[:, 1])

plt.show()
