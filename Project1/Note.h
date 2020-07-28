#pragma once
#include"Date.h"
#include"Book.h"
#include"Reader.h"
#define fBORROW "borrow.txt"
#define fRETURN "return.txt"
struct Note {
	char* reader_ID;
	Date bor_date, expe_date, real_date;
	int numb;
	char* listISBN[];
};