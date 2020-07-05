#pragma once
#include"Date.h"
#include "DynamicCString.h"
#include<iostream>
#define fUSER "user.csv"
struct User {
	int ord_numb; //da'nh so thu tu
	char* ID, *password, *name,*identify_numb,*address;
	Date birth;
	int sex; // male = 1, female = 0
	int status; //lock = 1,activate = 2,admin = 3
	int type;
};


int loginUser(User& u, FILE* f);

void logoutUser(User& u, int& log);

int findUser(char* name, FILE* f);

int checkpassUser(int ord, char* pass, FILE* f);

void readUser(User& u, int ord, FILE* f);

void writeUser(User& u, FILE*& f);

void updateUserInfo(User& u, FILE* &f);

void updatePass(User& u, FILE* f);

void giveStatus(User& u, FILE* f);