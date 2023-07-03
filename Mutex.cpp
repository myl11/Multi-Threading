// Mutex --> Mutual Exclusion 

//Race Condition 
//0. When 2 or more threads are trying to modify (not while read ) a common variable then there is the race condition 
//we need to protect it 




#include <iostream>
#include <thread>
#include "Mutex.h"
#include <mutex>
#include <Windows.h>
using namespace std;
int amount = 0;
std::mutex m;
void addmoney()
{ 
	//Both the Functions are trying to modify the variable so we use mutex
	//By adding mutex we are protecting the variable.
	m.lock();
	++amount; 
	m.unlock();
	Sleep(3000);

    // If worker1 reaches first it will lock it , while worker2 comes it will check whether it can lock , but since it is already locked it will wait for it to lock again
	// at the same time, worker1 has completed updating it and it will unlock the variable , now since it is unlocked worker2 who was waiting will lock it now 
}
int fakemain()
{
	for (int i = 0; i < 10; i++)
	{
		thread worker1(addmoney);
		thread worker2(addmoney);
		if (worker1.joinable())
			worker1.join();
		if (worker2.joinable())
			worker2.join();
	}
	cout <<" amount :: " << amount << endl;
	return 0;
}