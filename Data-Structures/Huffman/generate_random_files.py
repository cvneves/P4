import math
import random
import argparse

min_file_size = 5000
max_file_size = 5000000

num_file_sizes = 2
num_types = 1

b = min_file_size
a = (max_file_size - b)/(num_file_sizes - 1)

folder_name = "random_instances/"

for j in range(0, num_types):
    instance_type = str(chr(99 + j))

    for k in range(0, num_file_sizes):
        file_name = instance_type + "-" + str(k)

        fileBytes = []

        fp = open(folder_name + file_name + ".bin", "wb")

        sum = 0

        fileSize = int(round(a * k + b))

        for i in range(0,fileSize):
            x = int(round(random.normalvariate(127, 16)))
            # x = int(round(random.uniform(0, 256)))
            if x < 0:
                x = 0
            if x > 255:
                x = 255
                
            fileBytes.append(x)


        fp.write(bytearray(fileBytes))
    