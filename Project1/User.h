#pragma once
#include"Date.h"
#include "DynamicCString.h"
#include<iostream>
#include<stdio.h> 
#define fUSER "user.csv"
struct User {
	int ord_numb; //da'nh so thu tu
	char* ID, *password, *name,*identify_numb,*address;
	Date birth;
	int sex; // male = 1, female = 0
	int status; //lock = 1,activate = 2,admin = 3
	int type;
};


int loginUser(FILE* f);

void logoutUser(int& log);

int findUser(char* name, FILE* f);

int checkpassUser(int ord, char* pass, FILE* f);

void readUser(User& u, int ord, FILE* f);

void writeUser(User& u, FILE*& f);


void updateUserInfo(FILE*& f);

void updateUser_pass(FILE*& f);

void giveUser_status(FILE*& f);


void createUser(User& u, FILE*& f);

