#ifndef COMPRESS_H
#define COMPRESS_H

#include <stdlib.h>
#include <stdio.h>
#include "Data.h"
#include "ByteInfo.h"
#include "PriorityQueue.h"
#include "Tree.h"

void CompressFile(char *file_name, Node *root);

#endif