#include <stdlib.h>
#include <stdio.h>
#include "List.h"
#include "Map.h"
#include <string.h>

int main(int argc, char **argv)
{
	Map *hashMap = MapInitialize();

	FILE *fp = fopen(argv[1], "r");
	char buffer[100];

	while (fscanf(fp, "%s", buffer) != EOF)
	{
		// printf("%lu\n", HashDjb2(buffer) % MAX_BUCKETS);
		unsigned char *str = malloc((strlen(buffer) + 1) * sizeof(unsigned char));
		strcpy(str, buffer);

		MapInsert(hashMap, (void *)str, HashDjb2);
	}

	fclose(fp);

	fp = fopen(argv[2], "r");

	while (fscanf(fp, "%s", buffer) != EOF)
	{

		if (MapSearch(hashMap, (void *)buffer, HashDjb2, CompareString))
			printf("%s\n", buffer);
	}

	fclose(fp);

	// for (int i = 0; i < MAX_BUCKETS; i++)
	// {
	// 	if (hashMap->bucket[i]->size)
	// 	{
	// 		Node *node = hashMap->bucket[i]->head;
	// 		printf("#################################\n");
	// 		while (node != NULL)
	// 		{
	// 			printf("%s\n", (char *)node->data);
	// 			node = node->next;
	// 		}
	// 		printf("#################################\n");
	// 		// printf("%ld\n", hashMap->bucket[i]->size);
	// 	}
	// }

	DestroyMap(hashMap);
}
