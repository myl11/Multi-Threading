#pragma once
#include <iostream>
using namespace std;

void function1(int count);
void function2(int count);

//Non-Static member Function 
class Baseclass {
public:
	void basefunction(int x)
	{
		while (x-- > 0)
		{
			cout << x << endl;
		}
	}
};

//Static member Function 
class Baseclassstatic {
public:
	static void basefunction(int x)
	{
		while (x-- > 0)
		{
			cout << x << endl;
		}
	}
};