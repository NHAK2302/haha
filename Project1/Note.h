#pragma once
#include"Date.h"
#include"Book.h"
#include"Reader.h"
#include"DynamicCString.h"
#define fBORROW "borrow.txt"
#define fRETURN "return.txt"

struct Note {
	char* reader_ID;
	Date bor_date, expe_date, real_date;
	int numb;
	int book_number;
	char** book_ISBN;
};

void createBorrowNote(FILE* &f);

void createReturnNote(FILE*& f);

int findNote(char* name, FILE* f, Note* result);

void fillNote(Note& n, FILE* f);

void readNote_array(Note* arr, int n);

int chooseNote(Note* arr, int n);
