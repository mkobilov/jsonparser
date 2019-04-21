#ifndef __CALC_H__
#define __CALC_H__
//testing merge
#include "jsonparser.h"

double Calculator(const char* file_name);
double Calculate(pJsonElement calc_elem);
double Sum(const pJsonElement sum_elem);
double Sub(const pJsonElement sum_element);
double Mul(const pJsonElement sum_element);
double Div(const pJsonElement sum_element);
#endif
