#include "Map.h"

Map * MapInitialize()
{
	Map *map = malloc(sizeof(Map));
	map->bucket = malloc(MAX_BUCKETS * sizeof(List*));
	for(int i = 0; i < MAX_BUCKETS; i++)
	{
		map->bucket[i] = ListInitialize();
	}

}

void *DestroyMap(Map *map)
{
	for(int i = 0; i < MAX_BUCKETS; i++)
	{
		ListDestroy(map->bucket[i]);
	}
	free(map);
}
