#pragma once
#include "Date.h"
#include <iostream>
#include <stdio.h>
#include "DynamicCString.h"
#define fREADER "reader.csv"
using namespace std;
struct Reader {
	char* ID, *name, *identify_numb, *email, *address;
	Date birth, mfg, exp; // mfg = ngay san xuat, exp = han su dung
	int sex, ord_numb; // male = 1, female = 0
};

void readReader(Reader& r, int ord, FILE* f);

int findReaderByIdenNumb(char* ID, FILE* f);

void writeReader(Reader& r, FILE*& f);

int findReaderByName(char* name, FILE* f);

void updateReaderInfo(FILE*& f);

void createReader(FILE*& f);