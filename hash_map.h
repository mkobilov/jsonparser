#ifndef __HASH_MAP_H__
#define __HASH_MAP_H__

#include "list.h"
#include "string.h"

typedef char *HMapKeyType;
typedef void *HMapValueType;

typedef struct _hash_map_element
{
	HMapKeyType key;
	HMapValueType value;
} HashMapElement, *pHashMapElement;

typedef struct _hash_map
{
	unsigned size;
	pList *data;
} HashMap, *pHashMap;

pHashMap CreateHMap(unsigned);
void DeleteHMap(pHashMap*);
pList HMapGetKeys(pHashMap);
void AddToHMap(pHashMap, HMapKeyType, HMapValueType);

int IsInHMap(pHashMap, HMapKeyType);
HMapValueType GetFromHMap(pHashMap, HMapKeyType);

#endif	//__HASH_MAP_H__
