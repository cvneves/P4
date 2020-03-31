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

for line in fp:
    original_size.append(float(line.split()[0]))
    compressed_size.append(float(line.split()[1]))
    tree_size.append(float(line.split()[2]))
    entropy.append(float(line.split()[3]))
    compressed_ratio.append(100 - float(line.split()[1])/float(line.split()[0]) * 100)
    theorical_value.append(100 - float(line.split()[3])/8 * 100 )

xs, ys, zs = zip(*sorted(zip(entropy, compressed_ratio, theorical_value)))

plt.plot(xs, ys, 'ro', label="Taxa de compressão obtida")
plt.plot(xs, zs, label="Taxa de compressão esperada")
plt.xlabel("Entropia (bits / byte)")
plt.ylabel("Taxa de compressão (%)")

plt.legend()
plt.show()
