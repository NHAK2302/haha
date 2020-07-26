#include"Date.h"
Date convertStringtoDate(char* str)
{
	Date result;
	result.d = (str[0]-48) * 10 + str[1]-48;
	result.m = (str[3]-48) * 10 + str[4]-48;
	result.y = atoi(str + 6);
	return result;
}
char* convertDatetoString(Date d)
{
	char* str = new char[11];
	char* temp;
	if(d.d>=10)
		str = _itoa(d.d,str,10);
	else
	{
		str[0] = '0';
		temp = str + 1;
		temp = _itoa(d.d, temp, 10);
	}
	str[2] = '/';
	if (d.m >= 10)
	{
		temp = str + 3;
		temp = _itoa(d.m, temp, 10);
	}
	else
	{
		str[3] = '0';
		temp = str + 4;
		temp = _itoa(d.m, temp, 10);
	}
	str[5] = '/';
	temp = str + 6;
	temp = _itoa(d.y, temp, 10);
	return str;
}
