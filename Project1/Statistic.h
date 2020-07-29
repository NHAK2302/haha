#pragma once
#include <iostream>
#include "Date.h"
#include "DynamicCString.h"
#include "Book.h"
#include "Reader.h"
#define fBOOK "book.csv"
#define fREADER "reader.csv"
using namespace std;

int numbOfBooks_all(FILE* f);

void numbOfBooks_type(FILE* f);

bool typeNotExist(char typeArr[100][LENGTH_MAX], int n, char* cur_type);

int numbOfReaders_all(FILE* f);

void numbOfReaders_sex(FILE* f);

int numbOfBooks_borrowed(FILE* f1, FILE* f2);