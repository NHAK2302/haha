#pragma once
#include"Date.h"
#include<iostream>
#define fREADER "reader.csv"
using namespace std;
struct Reader {
	char* ID, name, indentify_numb,email,address;
	Date birth, mfg, exp; // mfg = ngay san xuat, exp = han su dung
	int sex; // male = 1, female = 0
};
int loginReader(Reader& r);
