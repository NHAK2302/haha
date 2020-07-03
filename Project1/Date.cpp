#include"Date.h"
Date convertStringtoDate(char* str)
{
	Date result;
	result.d = str[0] * 10 + str[1];
	result.m = str[3] * 10 + str[4];
	result.y = atoi(str + 6);
	return result;
}