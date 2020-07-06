#include<iostream>
#include"User.h"
#include"Menu.h"
using namespace std;
void main()
{
	FILE* f = fopen(fUSER,"r+t");
	welcome(f);
}