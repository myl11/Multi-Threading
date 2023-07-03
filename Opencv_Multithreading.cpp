// Opencv_Multithreading.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
using namespace std;
using namespace cv;
#include <chrono>
#include <ctime>
void singleread(string path)
{
   Mat image= imread(path);
   Sleep(2000);
   imwrite("./Extra/output/" + path , image);
   
}
int main()
{
    std::cout << "Hello World!\n";
    vector<String> fn;
    string Image_Name;
    std::chrono::time_point<std::chrono::high_resolution_clock> ModelLoadstart, ModelLoadend, InferenceTimestart, InferenceTimeend, TimeforOneFrameStart1, TimeforOneFrameEnd1, TimeforOneFrameStart, TimeforOneFrameEnd, PreProcessstart, PreProcessend;

    glob("./Extra/input/*.png", fn);
    TimeforOneFrameStart = std::chrono::high_resolution_clock::now();
    for (auto f : fn)
    {
        
        // std::cout << f << std::endl;



        string str1 = "./Extra/input";



        // Find first occurrence of "geeks"
        size_t found = f.find(str1);
        /* std::cout << str1.size() << std::endl;*/
        string r = f.substr(str1.size() + 1, f.size());
        r.erase(r.length() - 4);
        // prints the result
        cout << "String is: " << r << std::endl;
        /* cout << "-------------------------------------" << std::endl;*/



        const std::string imageFile = f;
        singleread(imageFile);
    }
    TimeforOneFrameEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = TimeforOneFrameEnd - TimeforOneFrameStart;
    std::cout << "Without MultiThreading  " << elapsed_seconds.count() << std::endl;



    std::vector<std::thread> threads;
    glob("./Extra/input/*.png", fn);
    TimeforOneFrameStart1 = std::chrono::high_resolution_clock::now();
    for (auto f : fn)
    {

        // std::cout << f << std::endl;



        string str1 = "./Extra/input";



        // Find first occurrence of "geeks"
        size_t found = f.find(str1);
        /* std::cout << str1.size() << std::endl;*/
        string r = f.substr(str1.size() + 1, f.size());
        r.erase(r.length() - 4);
        // prints the result
        cout << "String is: " << r << std::endl;
        /* cout << "-------------------------------------" << std::endl;*/



        const std::string imageFile = f;
        const int numThreads = 5;
      

        // Create multiple threads
        {           
            threads.push_back(thread(singleread,imageFile));
        }



       ;
    }
    // Wait for all threads to finish
    for (auto& thread : threads) {
        thread.join();
    }
    TimeforOneFrameEnd1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds1 = TimeforOneFrameEnd1 - TimeforOneFrameStart1;
    std::cout << "with  MultiThreading  " << elapsed_seconds1.count() << std::endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
