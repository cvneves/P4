#include <stdlib.h>
#include <stdio.h>
#include "List.h"
#include "Map.h"

int main()
{
	Map *hashMap = MapInitialize();

	DestroyMap(hashMap);
}
