#ifndef __JSONPARSER_H__
#define __JSONPARSER_H__

typedef enum JsonElementValueType{
	JSON_VALUE,
	JSON_MAP,
	JSON_ARRAY
}JsonElementValueType;

typedef struct jsonelem{
	JsonElementValueType type;
	char* key ;
	void* value;
}JsonElement, *pJsonElement;


#include "hash_map.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


void DeleteJSON(pJsonElement root);
void SkipDelim(char* s,int* p);
char* GetValue(char* s,int* p);
pHashMap ParseMap(char* s, int* p);
pJsonElement ParseData(void* value,char symbol,char* key);
pList ParseList(char* s,int* p);
pHashMap ParseJSON(FILE* file);

#endif