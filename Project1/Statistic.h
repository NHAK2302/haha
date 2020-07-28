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

bool typeNotExist(char* typeArr[], int n, char* cur_type);

void typeOfBooks(FILE* f, char* typeArr[], int& amount);

int numbOfReaders_all(FILE* f);

void numbOfReaders_sex(FILE* f);