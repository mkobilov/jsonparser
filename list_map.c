#include "list_map.h"

#include <stdlib.h>

int KeysAreEqual(MapKeyType a, MapKeyType b);
pMapElement GetMapElementFromMap(pMap map, MapKeyType key);

pMap CreateMap()
{
	pMap map = (pMap) malloc(sizeof(Map));
	
	map->data = CreateList();
	
	return map;
}

void DeleteMap(pMap *map)
{
	if(map == NULL)
	{
		return;
	}
	
	ListIterator iter;
	for(iter = GetBeginListIterator((*map)->data);
		!IsListIteratorNULL(&iter);
		ListIteratorNext(&iter))
	{
		free(GetListIteratorValue(&iter));
		DeleteListElementByIterator(&iter);
	}
	
	DeleteList(&(*map)->data);
	
	free(*map);
	*map = NULL;
}

void AddToMap(pMap map, MapKeyType key, MapValueType value)
{
	// if exists
	pMapElement element = GetMapElementFromMap(map, key);
	
	if(element)
	{
		element->value = value;
		return;
	}
	
	// add new
	pMapElement new_element = (pMapElement) malloc(sizeof(MapElement));
	new_element->key = key;
	new_element->value = value;
	
	PushBackToList(map->data, new_element);
}

int IsInMap(pMap map, MapKeyType key)
{
	pMapElement element = GetMapElementFromMap(map, key);
	
	return element != NULL;
}

MapValueType GetFromMap(pMap map, MapKeyType key)
{
	pMapElement element = GetMapElementFromMap(map, key);
	
	return element?element->value:NULL;
}

pMapElement GetMapElementFromMap(pMap map, MapKeyType key)
{
	ListIterator iter;
	for(iter = GetBeginListIterator(map->data);
		!IsListIteratorNULL(&iter);
		ListIteratorNext(&iter))
	{
		pMapElement current = (pMapElement) GetListIteratorValue(&iter);
		
		if(KeysAreEqual(key, current->key))
		{
			return current;
		}
	}
	
	return NULL;
}


int KeysAreEqual(MapKeyType a, MapKeyType b)
{
	return strcmp(a, b) == 0;
}
