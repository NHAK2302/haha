#include<iostream>
#include<Windows.h>
#include"Menu.h"
using namespace std;
void main()
{
	SMALL_RECT windowSize = { 0 , 0 , 50 , 300 }; //change the values
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &windowSize);
	welcome();
}