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
	int ord;
	char name[LENGTH_MAX] = "tonyvu1288\0";
	ord = findUser(name, f);
	printf("%d\n", ord);
}