#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__
#include "jsonparser.h"

int Calculator(const char* file_name);
int Calculate(pJsonElement calc_elem);
int Sum(const pJsonElement sum_elem);
#endif