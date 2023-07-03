// MultiThreading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Basics.h"

#include <thread>
#include "mutex.h"
using namespace std;
int main()  //The Single main Thread 
{
    std::cout << "Hello World!\n";
    //Serial Execution 
    //function1(100);
    //function2(100);

    //Parallel Execution
    //If we create multiple threads at the same time , we don't know which will start first 
    //1.Thread using Function Pointer 
    std::cout << " i am in main waiting " << std::endl;
    thread worker1(function1, 100);

    thread worker2(function2, 100);
    if (worker1.joinable())  //Common pratice is to add if joinable before we call join 
        worker1.join();  // there is a sleep in the function1 (the sleep will simulate, that the thread is taking time to complete its work ) , hence .join is waiting for it to complete  
    //.Join will wait for the spawned thread to complete and it will join it back to main thread 
    std::cout << " worker 1 joined back  " << std::endl;

    if (worker2.joinable())  //Common pratice is to add if joinable before we call join 
        worker2.join();
    std::cout << " worker 2 joined back  " << std::endl;  //it will join back faster, because the thread is taking less time to complete 
    //2.Thread using Lamda Function 
    //3.Thread using Functor 



    //4.Non-Static Member function 
    Baseclass b;
    thread worker3(&Baseclass::basefunction, &b, 100);

    if (worker3.joinable())  //Common pratice is to add if joinable before we call join 
        worker3.join();
    // worker3.join(); we can't add 2 join for the same thread , it wont be a compiler error , it will be a runtime error 
    // 
    // Safe way to do is to check whether if it is joinable 
    if (worker3.joinable()) // 
    {
        worker3.join(); //this won't throw an error , since we are using .joinable() 
    }
    thread worker4(&Baseclassstatic::basefunction, 100);
    if (worker4.joinable())  //Common pratice is to add if joinable before we call join 
        worker4.join();





    //Detach 
    thread worker5(function1, 100);
    cout << " I am before detaching ";
    if(worker5.joinable()) //Always check before you join or detach 
    worker5.detach();  //By detaching we are not waiting for the thread to complete we are just going ahead with our next statements 
    // worker1.detach(); // we can't call 2 detach it is better to check 
    cout << " I am after detaching ";

    //output::
    //***
    //I am before detaching
    //I am after detaching
    //Here we did not wait for the thread to complete 




    int retuno = fakemain();
    return 0;
}

