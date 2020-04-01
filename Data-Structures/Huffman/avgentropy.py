import math
import random
import argparse
import numpy as np
import matplotlib.pyplot as plt

fp = open("avgjpg.txt", "r")

avgEntropy = 0
avgCompressionRate = 0

for line in fp:
    avgEntropy = avgEntropy + float(line.split()[3])/5
    avgCompressionRate = avgCompressionRate + 100 * (1 - float(line.split()[1])/float(line.split()[0])) / 5

print(avgEntropy)
print(avgCompressionRate)