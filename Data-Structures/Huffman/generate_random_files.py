import math
import random
import argparse

# fp = open("instance/random_files/A.bin", "w")

fileBytes = []

fp = open("b", "wb")

sum = 0

fileSize = 1000000

for i in range(0,fileSize):
    # x = int(round(random.normalvariate(128, 128)))
    x = int(round(random.uniform(0, 256)))
    if x < 0:
        x = 0
    if x > 255:
        x = 255
        
    fileBytes.append(x)

fp.write(bytearray(fileBytes))
# print(fileBytes)
    