#pragma once
#include<string.h>
#include <stdlib.h>

struct Date {
	int d, m, y;
};

Date convertStringtoDate(char* str);

char* convertDatetoString(Date d);
