#include "DynamicCString.h"
void inputString(char* &s)
{
	char temp[LENGTH_MAX];
	scanf("%s", &temp);
	s = (char*)calloc(strlen(temp)+1, sizeof(char));
	strcpy(s, temp);
}