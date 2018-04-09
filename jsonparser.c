#include "hash_map.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void SkipDelim(char* s,int* p);
char* GetValue(char* s,int* p);

int main(){
	pHashMap map = CreateHMap(100);
	FILE* file = fopen("test.txt","r");
	
	fseek(file,0,SEEK_END);
	long sizeoffile = ftell(file);
	fseek(file,0,SEEK_SET);
	char* s = (char*) malloc (sizeoffile*sizeof(char));
	fread(s,sizeof(char),sizeoffile,file);
	int p = 0;
	
	assert(s[p] == '{');
	p++;
	while(s[p] != '}'){
		SkipDelim(s,&p);
		char* key  = GetValue(s,&p);
		SkipDelim(s,&p);
		
		assert(s[p] = ':');
		p = p+1;
		
		SkipDelim(s,&p);
		char* value = GetValue(s,&p);
		SkipDelim(s,&p);
		printf("key = %s , value = %s\n",key,value);
		AddToHMap(map,key,value);
		if(s[p] == ','){
			p++;
			continue;
		}
	}
	
	
	printf("%d %s\n", IsInHMap(map, "we ll"), GetFromHMap(map, "we ll"));
	printf("%d %s\n", IsInHMap(map, "da"), GetFromHMap(map, "da"));
	printf("%d %s\n", IsInHMap(map, "ek"), GetFromHMap(map, "ek"));
	
	return 0;
}


void SkipDelim(char* s,int* p){
	while(s[*p] == ' ' || s[*p] == '\n' || s[*p] == '\t' || s[*p] == '\r'){
		(*p)++;
	}
	printf("SD s[p] = %c\n",s[*p]);
}
char* GetValue(char* s,int* p){
	printf("GV s[p] = %c\n",s[*p]);
	assert(s[*p] == '"');
	(*p)++; 				//set s[*p] at first symbol of key/value
	int count;
	int remember = (*p);
	while(s[*p] != '"' || s[(*p) - 1] != '\\'){
		count++;
		(*p)++;
	}
	*p = remember;
	char* ret = (char*) malloc ((count+1) * sizeof(char));
	count = 0; 			// now we use it as number of resulting string
	while(s[*p] != '"' || s[*p - 1] == '\\'){
		ret [count] = s[*p]; 
		(*p)++;
		count++;
	}
	ret[count] = '\0';
	(*p)++; // setting s[p] at the symbol next to closing "
	printf("ret = %s\n",ret);
	return ret;
}