#include "DynamicCString.h"
void inputString(char* &s)
{
	char temp[LENGTH_MAX];
	scanf("%s", &temp);
	copyString_statictodynamic(temp, s);
}
void copyString_statictodynamic(char* stat, char* &dyn)
{
	if (stat == NULL)
		return;
	dyn = (char*)calloc(strlen(stat), sizeof(char));
	strcpy(dyn, stat);
}