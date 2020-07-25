#pragma once
#include "Date.h"
#include<iostream>
#include<stdio.h>
#include"DynamicCString.h"
#define fBOOK "book.csv"
struct Book {
	char* ISBN, *name, *author, *pub_company, *type;
	int pub_year, price, amount, ord_numb;
};

struct Note {
	char* ID;
	Date bor_date, expe_date, real_date;
	int numb;
	char* listISBN[];
};

int findBookByISBN(char* ISBN, FILE* f);

int findBookByName(char* name, FILE* f);

void readBook(Book& b, int ord, FILE* f);

void writeBook(Book& b, FILE*& f);

void updateBookInfo(FILE*& f);

void createBook(FILE*& f);