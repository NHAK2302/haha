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
int namnhuan(Date& a)
{
	if (!(a.y % 4 == 0))
		return 0;
	else
	{
		if (a.y % 100 == 0)
		{
			if (a.y % 400 == 0)
				return 1;
			else
				return 0;
		}
		else
			return 1;
	}
}
int daysOfMonth(Date& a)
{
	int result;
	if (((a.m % 2 == 1) && (a.m < 8)) || ((a.m % 2 == 0) && (a.m >= 8)))
		result = 31;
	else
	{
		if (a.m == 2)
		{
			if (namnhuan(a))
				result = 29;
			else
				result = 28;
		}
		else
			result = 30;
	}
	return result;
}
int _2dateDistanceByday(Date p, Date n)
{
	if (!checkdate(p, n))
		swapdate(p, n);
	return daysFromzero(n) - daysFromzero(p);
}
int _2dateDistanceByyear(Date p, Date n)
{
	if (!checkdate(p, n))
		swapdate(p, n);
	int result = n.y - p.y;
	if (p.m > n.m)
		result--;
	else
		if (p.m == n.m && p.d > n.d)
			result--;
	return result;
}
int _2dateDistanceBymonth(Date p, Date n)
{
	if (!checkdate(p, n))
		swapdate(p, n);
	int result = _2dateDistanceByyear(p, n) * 12;
	if (p.m <= n.m)
	{
		result += n.m - p.m;
	}
	else
	{
		result += 12 - (p.m - n.m);
	}
	return result;
}
long daysFromzero(Date a)
{
	long result = 0;
	result += (a.y - 1) * 365 + (a.y - 1) / 4 - (a.y - 1) / 100 + (a.y - 1) / 400;
	result += a.d;
	a.m--;
	while (a.m > 0)
	{
		result += daysOfMonth(a);
		a.m--;
	}
	return result;
}
Date ngayhomsau(Date a)
{
	a.d++;
	if (a.d > daysOfMonth(a))
	{
		a.d = 1;
		a.m++;
		if (a.m > 12)
		{
			a.m = 1;
			a.y++;
		}
	}
	return a;
}
Date ngayhomtruoc(Date a)
{
	a.d--;
	if (a.d < 1)
	{
		a.d = daysOfMonth(a);
		a.m--;
		if (a.m < 1)
		{
			a.m = 12;
			a.y--;
		}
	}
	return a;
}
Date sau_k_ngay(Date a, int k)
{
	Date result = a;
	for (int i = 1; i <= k; i++)
	{
		result = ngayhomsau(result);
	}
	return result;
}
Date truoc_k_ngay(Date a, int k)
{
	Date result = a;
	for (int i = 1; i <= k; i++)
	{
		result = ngayhomtruoc(result);
	}
	return result;
}
int checkdate(Date& previous, Date& next)
{
	if (previous.y < next.y)
		return 1;
	else if (previous.y == next.y)
	{
		if (previous.m < next.m)
			return 1;
		else if (previous.m == next.m)
		{
			if (previous.d <= next.d)
				return 1;
		}
	}
	return 0;
}
void swapdate(Date& a, Date& b)
{
	Date temp = a;
	a = b;
	b = temp;
}
