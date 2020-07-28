#pragma once
#include "Date.h"
#include <iostream>
#include "DynamicCString.h"
#define fBOOK "book.csv"
using namespace std;
struct Book {
	char* ISBN, *name, *author, *pub_company, *type;
	int pub_year, price, amount, ord_numb;
};

int findBookByISBN(char* ISBN, FILE* f, int* result);

int findBookByName(char* name, FILE* f, int* result);

void readBook(Book& b, int ord, FILE* f);

void writeBook(Book& b, FILE*& f);

void updateBookInfo(FILE*& f);

void createBook(FILE*& f);

void readBook_array(FILE* f, int* ord, Book* arr, int n);

void outputBook(Book& b);

int chooseBook(Book* arr, int n);

void readBook_all(FILE* f);

void findBookByISBN_interface(Book& b, FILE* f);

void findBookByName_interface(Book& b, FILE* f);

void freeBook();

void fillBook(Book& b, FILE* f);

void deleteBook(Book b, FILE* f);

void deleteBook_interface(FILE* f);