#include "hash_map.h"

pHashMap CreateHMap(unsigned);
void DeleteHMap(pHashMap*);
pList HMapGetKeys(pHashMap);
void AddToHMap(pHashMap, HMapKeyType, HMapValueType);
int IsInHMap(pHashMap, HMapKeyType);
HMapValueType GetFromHMap(pHashMap, HMapKeyType);

pList HMapGetKeys(pHashMap map){
	if (! map->data)
		return NULL;
	
	pList list = CreateList();
	
	int i;
	for(i=0; i<map->size; i++){
		ListIterator iter;
		for(iter = GetBeginListIterator(map->data[i]); !IsListIteratorNULL(&iter); ListIteratorNext(&iter)){
			pHashMapElement cur = (pHashMapElement) GetListIteratorValue(&iter);
			PushBackToList(list, cur->key);
		}
	}
	
	return list;
}

pHashMap CreateHMap(unsigned int n){		// n = number of elements in map 
	if(n <= 0){
		printf("CreateHMap ERR invalid size\n");
		assert(n<=0);				//exit(EXIT_FALURE)
	}
	
	pHashMap map = (pHashMap) calloc(1,sizeof(HashMap));
	map->size = n;
	map->data = (pList*) calloc(n,sizeof(pList));
	int i;
	for(i = 0;i<n;i++)
		map->data[i] = CreateList();
	return map;
}

void DeleteHMap(pHashMap* map){
	if(!map){
		printf("Destructing map twice pbbly\n");
		return;
	}
	
	int i;
	for(i=0; i<(*map)->size; i++){
		ListIterator iter;
		for(iter = GetBeginListIterator((*map)->data[i]);
			!IsListIteratorNULL(&iter);
			ListIteratorNext(&iter))
		{
			free(GetListIteratorValue(&iter));
			DeleteListElementByIterator(&iter);
		}
		
		DeleteList(&((*map)->data[i]));
	}
	
	free((*map)->data);
	
	free(*map);
	*map = NULL;
}

int hash_func(int size, HMapKeyType key){
	if(size <= 0){
		printf("hash_func ERR bad size");
		assert(size<=0);   			//exit(EXIT_FALURE);
	}
	int hash = 7;
	int len = strlen(key);
	
	int i;
	for(i=0; i<len; i++)
		hash = hash*31 + key[i];
	
	return hash % size;
}

pHashMapElement GetMapElementFromHMap(pHashMap map, HMapKeyType key){ 				//Help function used to make IsInHMap and GetFromHMap simplier
	int hash = hash_func(map->size, key);
	
	ListIterator iter;
	for(iter = GetBeginListIterator(map->data[hash]); !IsListIteratorNULL(&iter);	ListIteratorNext(&iter)){
		pHashMapElement cur = (pHashMapElement) GetListIteratorValue(&iter);
		
		if(!strcmp(key,cur->key)){		//check if keys are equal
			return cur;
		}
	}
	return NULL;
}
void AddToHMap(pHashMap map, HMapKeyType key, HMapValueType value)
{
	pHashMapElement element = GetMapElementFromHMap(map, key);
	
	if(element){
		element->value = value;
		return;
	}
	
	element = (pHashMapElement) calloc(1,sizeof(HashMapElement));
	element->key = key;
	element->value = value;
	
	unsigned hash = hash_func(map->size, key);
	PushBackToList(map->data[hash], element);
}

int IsInHMap(pHashMap map, HMapKeyType key){
	pHashMapElement element = GetMapElementFromHMap(map, key);
	
	return element != NULL;
}

HMapValueType GetFromHMap(pHashMap map, HMapKeyType key){
	pHashMapElement element = GetMapElementFromHMap(map, key);
	
	if(element)
		return element->value;

	return NULL;
}