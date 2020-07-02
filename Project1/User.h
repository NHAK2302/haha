#pragma once
#include"Date.h"
#include "DynamicCString.h"
#include<iostream>
struct User {
	char* ID, password, name,indentify_numb,address;
	Date birth;
	int sex; // male = 1, female = 0
	int status; //lock = 1,activate = 2,admin = 3
};
