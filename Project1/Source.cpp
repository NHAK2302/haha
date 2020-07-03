#include<iostream>
#include"User.h"
#define fUSER "user.csv"
using namespace std;
void main()
{
	cout << "hello" << endl;
	cout << "dit con me" << endl;
	cout << "test" << endl;
	//debug login function
	FILE* f = fopen(fUSER,"r+t");
	User a;
	int log = loginUser(a, f);
	cout << log<<endl;
	logoutUser(a, log);
	cout << log << endl;
}