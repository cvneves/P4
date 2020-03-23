#ifndef MAP_H
#define MAP_H

#include <stdio.h>
#include <stdlib.h>
#include "List.h"

#define MAX_BUCKETS 20000

typedef struct Map
{
	size_t numBuckets;
	List **bucket;
} Map;

Map *MapInitialize();
void *MapInsert(Map *map, void *T, unsigned long (*HashFunction)(void *A));
void *DestroyMap(Map *map);

unsigned long HashDjb2(void *T);

#endif
