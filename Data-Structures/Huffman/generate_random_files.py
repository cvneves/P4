import math
import random
import argparse

num_file_sizes = 10

num_types = 1
num_files = 20

folder_name = "random_instances/"

initial_alpha = 50
instance_type = str(chr(97))

alpha = initial_alpha
for k in range(0, num_files):
    a = (1 - initial_alpha)/(num_files - 1) * k + 50 

    file_name = instance_type + "-" + str(k)

    fileBytes = []

    fp = open(folder_name + file_name + ".bin", "wb")

    sum = 0

    fileSize = 1000000

    for i in range(0,fileSize):
        x = int(round(random.betavariate(a,1) * 255))
                
        fileBytes.append(x)


    fp.write(bytearray(fileBytes))