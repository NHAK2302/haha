#pragma once
#include<string.h>
#include <stdlib.h>

struct Date {
	int d, m, y;
};

Date convertStringtoDate(char* str);

char* convertDatetoString(Date d);

int namnhuan(Date& a);

int daysOfMonth(Date& a);

int _2dateDistanceByday(Date p, Date n);

int _2dateDistanceByyear(Date p, Date n);

int _2dateDistanceBymonth(Date p, Date n);

long daysFromzero(Date a);

Date ngayhomsau(Date a);

Date ngayhomtruoc(Date a);

Date sau_k_ngay(Date a, int k);

Date truoc_k_ngay(Date a, int k);

int checkdate(Date& previous, Date& next);

void swapdate(Date& a, Date& b);

