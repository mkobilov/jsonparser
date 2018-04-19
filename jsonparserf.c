#include "jsonparser.h"
pHashMap ParseJSON(FILE* file){
	fseek(file,0,SEEK_END);
	long sizeoffile = ftell(file);
	fseek(file,0,SEEK_SET);
	char* s = (char*) calloc ((sizeoffile+1),sizeof(char));
	fread(s,sizeof(char),sizeoffile,file);
	s[sizeoffile] = '\0';
	int p = 0;
	pHashMap map = ParseMap(s,&p);
	free(s);
	return map;
}

pList ParseList(char* s,int* p){
	assert(s[*p] == '[');
	(*p)++;
	pList list = CreateList();
	
	while(s[*p] != ']'){
		SkipDelim(s,p);
		PushBackToList(list,ParseData(ParseMap(s,p),'{',NULL));
		SkipDelim(s,p);
	//	printf("PL s[*p] == %c\n",s[*p]);
		if(s[*p] == ','){
			(*p)++;
			continue;
		}	
	}
	assert(s[*p] == ']');
	(*p)++;
	SkipDelim(s,p);
	//printf(" PL end s[*p] == %c\n",s[*p]);
	return list;
}


pHashMap ParseMap(char* s, int* p){
	pHashMap map = CreateHMap(100);
	assert(s[*p] == '{');
	(*p)++;
	while(s[*p] != '}'){
		SkipDelim(s,p);
		char* key  = GetValue(s,p);
		SkipDelim(s,p);
		
		assert(s[*p] == ':');
		(*p) = (*p)+1;
		
		SkipDelim(s,p);
		if(s[*p] == '"'){
			char* value = GetValue(s,p);
			SkipDelim(s,p);
			//printf("key = %s , value = %s, s[*p] == %c\n",key,value,s[*p]);
			AddToHMap(map,key,ParseData(value,'"',key));
			if(s[*p] == ','){
				(*p)++;
				SkipDelim(s,p);
				continue;
			}
		}
		if(s[*p] == '{'){
			AddToHMap(map,key,ParseData(ParseMap(s,p),'{',key));
			if(s[*p] == ','){
				(*p)++;
				SkipDelim(s,p);
				continue;
			}
		}
		if(s[*p] == '['){
			AddToHMap(map,key,ParseData(ParseList(s,p),'[',key));
			printf("Success PL\n");
			if(s[*p] == ','){
				(*p)++;
				SkipDelim(s,p);
				continue;
			}
		}
	}
	//printf("PM s[*p] == %c,    count = %d\n",s[*p],countsmth);
	assert(s[*p] == '}');
	if(s[(*p)+1] != '\0'){	
		(*p)++;
		SkipDelim(s,p);
	}
	return map;
}

pJsonElement ParseData(void* data,char symbol,char* key){
	assert(symbol == '"' || symbol == '{' || symbol == '[');
	
	pJsonElement res = (pJsonElement) malloc (sizeof(JsonElement));
	res->value = data;
	res->key = key;
	
	if(symbol == '"')
		res->type = JSON_VALUE;
	if(symbol == '{')
		res->type = JSON_MAP;
	if(symbol == '[')
		res->type = JSON_ARRAY;
	return res;
	
}

void SkipDelim(char* s,int* p){
	while(s[*p] == ' ' || s[*p] == '\n' || s[*p] == '\t' || s[*p] == '\r'){
		(*p)++;
		if(s[*p] == '\0'){
			break;
		}
	}
	//printf("SD s[p] = %c\n",s[*p]);
}
char* GetValue(char* s,int* p){
	//printf("GV s[p] = %c\n",s[*p]);
	assert(s[*p] == '"');
	(*p)++; 				//set s[*p] at first symbol of key/value
	int count = 0;
	int remember = (*p);
	while(s[*p] != '"'){
		count++;
		(*p)++;
	}
	(*p) = remember;
	char* ret = (char*) calloc ((count+1) , sizeof(char));
	count = 0; 			// now we use it as number of char in resulting string
	while(s[*p] != '"'){
		
		ret [count] = s[(*p)]; 
		count++;
		
			
		(*p)++;
			
	}
	ret[count] = '\0';
	(*p)++; 			// setting s[p] at the symbol next to closing "
	return ret;
}




void DeleteJSON(pJsonElement root)
{
	if(root == NULL)
		return;
	
	
	if(root->type == JSON_VALUE){		
		free(root->value);
	}
	if(root->type == JSON_ARRAY){
		ListIterator iter;
		for(iter = GetBeginListIterator(root->value); !IsListIteratorNULL(&iter); ListIteratorNext(&iter)){
			DeleteJSON(GetListIteratorValue(&iter));
			DeleteListElementByIterator(&iter);
		}
		
		free(root->value);
	}
	if(root->type == JSON_MAP){		
		pHashMap map = root->value;
		
		pList keys = HMapGetKeys(map);
		
		ListIterator iter;
		for(iter = GetBeginListIterator(keys); !IsListIteratorNULL(&iter); ListIteratorNext(&iter)){
			char *key = GetListIteratorValue(&iter);
			DeleteJSON((pJsonElement)GetFromHMap(map, key));
		}
		
		DeleteList(&keys);
		
		DeleteHMap(&map);
	}
	
	if(root->key)
		free(root->key);
	free(root);
}