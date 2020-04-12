#include "Map.h"

Map *MapInitialize()
{
	Map *map = malloc(sizeof(Map));
	map->bucket = malloc(MAX_BUCKETS * sizeof(List *));
	for (int i = 0; i < MAX_BUCKETS; i++)
	{
		map->bucket[i] = ListInitialize();
	}

	return map;
}

void *DestroyMap(Map *map)
{
	for (int i = 0; i < MAX_BUCKETS; i++)
	{
		ListDestroy(map->bucket[i]);
	}
	free(map->bucket);
	free(map);
}

void MapInsert(Map *map, void *T, unsigned long (*HashFunction)(void *A))
{
	int hash = HashFunction((void *)T) % MAX_BUCKETS;
	// printf("%d\n", hash);
	ListAppend(map->bucket[hash], (void *)T);
}

int MapSearch(Map *map, void *T, unsigned long (*HashFunction)(void *Element), int CompareFunction(void *a, void *b))
{
	int hash = HashFunction((void *)T) % MAX_BUCKETS;

	void *a = T;
	Node *node = map->bucket[hash]->head;
	
	while(node != NULL)
	{
		if(CompareFunction(a, node->data))
		{
			return 1;
		}
		node = node->next;
	}
	
	return 0;
}

int CompareString(void *a, void *b)
{
	char *str1 = (char *)a;
	char *str2 = (char *)b;

	return !strcmp(str1, str2);
}

unsigned long HashDjb2(void *T)
{
	unsigned long hash = 5381;
	int c;

	unsigned char *str = (unsigned char *)T;

	while (c = *str++)
		hash = ((hash << 5) + hash) + c;

	return hash;
}