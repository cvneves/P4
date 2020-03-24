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
	char token[] = "0123456789.?!,;:@#$%&*()[]{}<>";

	int numWords = 0;
	int failedWords = 0;

	while (fscanf(fp, "%s", buffer) != EOF)
	{
		char *str = strtok(buffer, token);

		while (str != NULL)
		{

			if (!MapSearch(hashMap, (void *)str, HashDjb2, CompareString))
			{
				failedWords++;
				// printf("%s\n", str);
			}
			numWords++;
			str = strtok(NULL, token);
		}
	}

	printf("Número total de palavras no texto: %d\n", numWords);
	printf("Tempo total da verificação: %f\n");
	printf("Número de palavras que falharam no spell check: %d\n", failedWords);

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
