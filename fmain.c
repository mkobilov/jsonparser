#include "jsonparser.h"
int main(){
	
	FILE* file = fopen("test.txt","r");
	
	pHashMap map = ParseJSON(file);
	assert(IsInHMap(map,"calculate"));
	printf("bla = %d\n",IsInHMap(map,"calculate"));
	
	pJsonElement jsonmap = (pJsonElement) calloc(1,sizeof(JsonElement));
	jsonmap->type = JSON_MAP;
	jsonmap->value = map;
	DeleteJSON(jsonmap);
	fclose(file);
	

	
	return 0;
}