#include "NinjaList.h"

NNode *NinjaListInsertAfter(NNode *prev_node, NNode *node, int value)
{
    NNode *temp = (NNode *)malloc(sizeof(NNode));
    temp->value = value;

    NNode *next_node = (NNode *)((__intptr_t)prev_node ^ (__intptr_t)node->np);

    if (next_node == NULL) 
    {
        temp->np = node;
        node->np = (NNode *)((__intptr_t)temp ^ (__intptr_t)prev_node);
        return temp;
    }

    temp->np = (NNode *)((__intptr_t)node ^ (__intptr_t)next_node);

    next_node->np = (NNode *)((__intptr_t)node ^ (__intptr_t)next_node->np);
    next_node->np = (NNode *)((__intptr_t)temp ^ (__intptr_t)next_node->np);

    node->np = (NNode *)((__intptr_t)prev_node ^ (__intptr_t)temp->np);

    return temp;
}

void NinjaListGetNext(NNode *node)
{
}