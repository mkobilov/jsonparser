#include "jsonparser.h"
int main(){
	
	FILE* file = fopen("test.txt","r");
	
	pHashMap map = ParseJSON(file);
	pJsonElement res = GetFromHMap(map,"bla");
	printf("bla = %s\n",(char*) res->value );
	
	pJsonElement jsonmap = (pJsonElement) calloc(1,sizeof(JsonElement));
	jsonmap->type = JSON_MAP;
	jsonmap->value = map;
	DeleteJSON(jsonmap);
	fclose(file);
	

	
	return 0;
}