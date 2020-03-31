import math
import random
import argparse

num_file_sizes = 10

num_types = 1
num_files = 25

folder_name = "random_instances/"

fileSize = 2
instance_type = str(chr(97))


for k in range(0, num_files):
    fileBytes = []
    fp = open(folder_name + instance_type + "-" + str(k) + ".bin", "wb")
    
    for i in range(0,fileSize):
        x = int(round(random.betavariate(1,1) * 255))
                
        fileBytes.append(x)

    fp.write(bytearray(fileBytes))
    fileSize = fileSize + 40000
