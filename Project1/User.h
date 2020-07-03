#pragma once
#include"Date.h"
#include "DynamicCString.h"
#include<iostream>
struct User {
	int ord_numb; //da'nh so thu tu
	char* ID, password, name,indentify_numb,address;
	Date birth;
	int sex; // male = 1, female = 0
	int status; //lock = 1,activate = 2,admin = 3
};

int loginUser(User& u);

int findUser(char* name, FILE* f);
