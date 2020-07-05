#include<iostream>
#include"User.h"
#include"Menu.h"
#define fUSER "user.csv"
using namespace std;
void main()
{
	cout << "hello" << endl;
	cout << "dit con me" << endl;
	cout << "test" << endl;
	FILE* f = fopen(fUSER,"r+t");
	//debug login function
	//User a;
	//int log = loginUser(a, f);
	//cout << log<<endl;
	//logoutUser(a, log);
	//cout << log << endl;
	//debug welcome
	welcome(f);
}