import math
import random
import argparse

num_files = 10
num_file_sizes = 10
instance_type = "A"

for j in range(0, num_files):
    for k in range(0, num_file_sizes):
        file_name = instance_type + str(j)

        fileBytes = []

        folder_name = "random_instances/"

        fp = open(folder_name + file_name + ".bin", "wb")

        sum = 0

        fileSize = 100

        for i in range(0,fileSize):
            # x = int(round(random.normalvariate(128, 128)))
            x = int(round(random.uniform(0, 256)))
            if x < 0:
                x = 0
            if x > 255:
                x = 255
                
            fileBytes.append(x)


    fp.write(bytearray(fileBytes))
    