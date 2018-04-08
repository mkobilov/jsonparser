#include <stdio.h>
#include <stdlib.h>

//#include "list.h"
#include "list_map.h"

#ifdef DEBUG
	#include <stdio.h>
	#define DEBUG_PRINT(...) printf(__VA_ARGS__);
#else
	#define DEBUG_PRINT(...)
#endif

int main()
{
	DEBUG_PRINT("HELLO %d\n", 1);
	
	pMap map = CreateMap();
		
	AddToMap(map, "q", 4);
	AddToMap(map, "w", 5);
	AddToMap(map, "e", 6);
	AddToMap(map, "2", 7);
	AddToMap(map, "w", 7);
	
	printf("%d %d\n", IsInMap(map, "q"), GetFromMap(map, "q"));
	printf("%d %d\n", IsInMap(map, "w"), GetFromMap(map, "w"));
	printf("%d %d\n", IsInMap(map, "e"), GetFromMap(map, "e"));
	
	printf("%d %d\n", IsInMap(map, "r"), GetFromMap(map, "r"));
		
	ListIterator iter;
	for(iter = GetBeginListIterator(map->data);
		!IsListIteratorNULL(&iter);
		ListIteratorNext(&iter))
	{
		pMapElement current = (pMapElement) GetListIteratorValue(&iter);
		printf("=> %s %d\n", current->key, current->value);
	}
	
	DeleteMap(&map);
	
	/*
	// 
	pList a = CreateList();
	
	PushBackToList(a, 4);
	PushBackToList(a, 8);
	PushBackToList(a, 12);
	
	pListIterator iter = CreateBeginListIterator(a);
	while(iter)
	{
		printf("%d\n", GetListIteratorValue(iter));
		ListIteratorNext(&iter);
	}
	
	DeleteList(&a);*/
	
	return 0;
}
