#ifndef NINJALIST_H
#define NINJALIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NNode
{
    int value;
    struct NNode *np;
} NNode;

NNode *NinjaListInsertAfter(NNode *node, int value);

#endif