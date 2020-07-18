#include"Date.h"
Date convertStringtoDate(char* str)
{
	Date result;
	result.d = (str[0]-48) * 10 + str[1]-48;
	result.m = (str[3]-48) * 10 + str[4]-48;
	result.y = atoi(str + 6);
	return result;
}
