import math
import random
import argparse
import matplotlib.pyplot as plt
import numpy as np

x = np.arange(0,1,0.01)
a, b = 2,0.01
y = np.random.normal(a,b,len(x))
print(len(x))


plt.plot(x, y, 'ro')
plt.show()