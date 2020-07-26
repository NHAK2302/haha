#pragma once
#include "Date.h"
#include <iostream>
#include "DynamicCString.h"
#define fREADER "reader.csv"
using namespace std;
struct Reader {
	char* ID, *name, *identify_numb, *email, *address;
	Date birth, mfg, exp; // mfg = ngay san xuat, exp = han su dung
	int sex, ord_numb; // male = 1, female = 0
};

void readReader(Reader& r, int ord, FILE* f);

int findReaderByIdenNumb(char* ID, FILE* f,int* result);

void writeReader(Reader& r, FILE*& f);

void findReaderByIdenNumb_interface(FILE* f);

void findReaderByName_interface(FILE* f);

int findReaderByName(char* name, FILE* f, int* result);

void updateReaderInfo(FILE*& f);

void createReader(FILE*& f);

void readReader_all(FILE* f);

void outputReader(Reader& r);

void readReader_array(FILE* f, int* ord, Reader* arr, int n);

int chooseReader(Reader* arr, int n);
