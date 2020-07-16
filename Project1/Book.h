#pragma once
#include "Date.h"
#include<iostream>
#define fBOOK "book.csv"
struct Book {
	char* ISBN, name, author, pub_company, type;
	int pub_year, price, amount;
};

struct Note {
	char* ID;
	Date bor_date, expe_date, real_date;
	int numb;
	char* listISBN[];
};