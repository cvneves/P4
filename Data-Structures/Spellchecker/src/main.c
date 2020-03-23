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

	for (int i = 0; i < MAX_BUCKETS; i++)
	{
		Node *node = hashMap->bucket[i]->head;
		printf("#################################\n");
		while (node != NULL)
		{
			printf("%s\n", (char *)node->data);
			node = node->next;
		}
		printf("#################################\n");
		// printf("%ld\n", hashMap->bucket[i]->size);
	}

	fclose(fp);
	DestroyMap(hashMap);
}
