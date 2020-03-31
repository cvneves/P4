import math
import random
import argparse
import numpy as np
import matplotlib.pyplot as plt

fp = open("relatorio", "r")

original_size = []
compressed_size = []
tree_size = []
entropy = []
compressed_ratio = []
theorical_value = []
tree_ratio = []

for line in fp:
    original_size.append(float(line.split()[0]))
    compressed_size.append(float(line.split()[1]))
    tree_size.append(float(line.split()[2])/1000)
    entropy.append(float(line.split()[3]))
    compressed_ratio.append(100 - float(line.split()[1])/float(line.split()[0]) * 100)
    theorical_value.append(100 - float(line.split()[3])/8 * 100 )
    tree_ratio.append(float(line.split()[2]) / float(line.split()[1]))

# xs, ys, zs = zip(*sorted(zip(entropy, compressed_ratio, theorical_value)))
xs, ys = zip(*sorted(zip(entropy, tree_size)))

# plt.plot(xs, ys, 'ro', label="Taxa de compressão obtida")
# plt.plot(xs, zs, label="Taxa de compressão esperada")
plt.xlabel("Entropia (bits / byte)")
plt.ylabel("Tamanho da árvore (kB)")

# plt.plot(original_size, tree_ratio, "ro")
plt.plot(xs, ys)

# plt.legend()
plt.show()
