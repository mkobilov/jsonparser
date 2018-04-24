#include "calc.h"

double Calculator(const char* file_name){
	FILE* file = fopen(file_name,"r");
	pHashMap map = ParseJSON(file);
	
	
	assert(IsInHMap(map,"calculate"));		// check if there is element with value "calculate"
	pJsonElement calc_elem = GetFromHMap(map,"calculate");
	
	int res = Calculate(calc_elem);
	
	pJsonElement jsonmap = (pJsonElement) calloc(1,sizeof(JsonElement));
	jsonmap->type = JSON_MAP;
	jsonmap->value = map;
	DeleteJSON(jsonmap);
	fclose(file);
	
	return res;
}

double Calculate(pJsonElement calc_elem){
	if(calc_elem->type == JSON_VALUE){
		char* res = (char*) calc_elem->value;
		printf("calculate res = %f\n",atof(res));
		return atof(res);
	}
	
	if(IsInHMap(calc_elem->value,"sum")){
		printf("calculate res sum= %f\n",Sum(GetFromHMap(calc_elem->value,"sum")));
		return Sum(GetFromHMap(calc_elem->value,"sum"));
	}
	
	if(IsInHMap(calc_elem->value,"sub")){
		return Sub(GetFromHMap(calc_elem->value,"sub"));
	}
	if(IsInHMap(calc_elem->value,"div")){
		return Div(GetFromHMap(calc_elem->value,"div"));
	}
	if(IsInHMap(calc_elem->value,"mul")){
		return Mul(GetFromHMap(calc_elem->value,"mul"));
	}
	
	
}


double Sum(const pJsonElement sum_element){
	assert(sum_element->type == JSON_MAP);
	
	pHashMap sum_map = sum_element->value ;
	
	assert(IsInHMap(sum_map,"arg1"));
	assert(IsInHMap(sum_map,"arg2"));
	
	pJsonElement arg1 = GetFromHMap(sum_map,"arg1");
	pJsonElement arg2 = GetFromHMap(sum_map,"arg2");
	//printf("sum res = %f\n",Calculate(arg1) + Calculate(arg2));
	return Calculate(arg1) + Calculate(arg2);
	
	
}
double Sub(const pJsonElement sum_element){
	assert(sum_element->type == JSON_MAP);
	
	pHashMap sum_map = sum_element->value ;
	
	assert(IsInHMap(sum_map,"arg1"));
	assert(IsInHMap(sum_map,"arg2"));
	
	pJsonElement arg1 = GetFromHMap(sum_map,"arg1");
	pJsonElement arg2 = GetFromHMap(sum_map,"arg2");
	//printf("sum res = %f\n",Calculate(arg1) + Calculate(arg2));
	return Calculate(arg1) - Calculate(arg2);
	
	
}
double Mul(const pJsonElement sum_element){
	assert(sum_element->type == JSON_MAP);
	
	pHashMap sum_map = sum_element->value ;
	
	assert(IsInHMap(sum_map,"arg1"));
	assert(IsInHMap(sum_map,"arg2"));
	
	pJsonElement arg1 = GetFromHMap(sum_map,"arg1");
	pJsonElement arg2 = GetFromHMap(sum_map,"arg2");
	//printf("sum res = %f\n",Calculate(arg1) + Calculate(arg2));
	return Calculate(arg1) * Calculate(arg2);
	
	
}
double Div(const pJsonElement sum_element){
	assert(sum_element->type == JSON_MAP);
	
	pHashMap sum_map = sum_element->value ;
	
	assert(IsInHMap(sum_map,"arg1"));
	assert(IsInHMap(sum_map,"arg2"));
	
	pJsonElement arg1 = GetFromHMap(sum_map,"arg1");
	pJsonElement arg2 = GetFromHMap(sum_map,"arg2");
	//printf("sum res = %f\n",Calculate(arg1) + Calculate(arg2));
	return Calculate(arg1) / Calculate(arg2);
	
	
}
