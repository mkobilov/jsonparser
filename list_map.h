#ifndef __LIST_MAP__
#define __LIST_MAP__

#include "list.h"

typedef char *MapKeyType;
typedef void *MapValueType;

typedef struct _map_element
{
	MapKeyType key;
	MapValueType value;
} MapElement, *pMapElement;

typedef struct _map
{
	pList data;
} Map, *pMap;

pMap CreateMap();
void DeleteMap(pMap*);

void AddToMap(pMap, MapKeyType, MapValueType);

int IsInMap(pMap, MapKeyType);
MapValueType GetFromMap(pMap, MapKeyType);

#endif	//__LIST_MAP__
