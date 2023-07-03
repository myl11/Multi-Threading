#include "Basics.h"
#include <Windows.h>
using namespace std;

void function1(int count)
{
	for(int i=0;i<=count ;i++)
	{
		cout << "*";
	}
	cout << "\n";
	Sleep(3000);

}
void function2(int count)
{
	for (int i = 0; i <= count; i++)
	{
		cout << "-" ;
	}
	cout << "\n";
}

