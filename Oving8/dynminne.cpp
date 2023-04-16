#include "dynminne.h"
#include "iostream"s


void fillInFibonacciNumbers(int* result , int length)
{
    //forstår ikke helt hva denne skal gjøre
    result[0] = 0;
    result[1] = 1;
    for (int i = 2; i < length; i++)
    {
        result[i] = result[i-2] + result[i-1]; 
    }
}

void printArray(int* arr , int length)
{
    for(int i = 0; i<length; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout <<'\n';
}

void createFibonacci()
{
    int n = 1;
    std::cout << "Hvor mange tall skal genereres?: "; 
    std::cin >> n; 

   int *numbers = new int[n] {};
   fillInFibonacciNumbers(numbers , n);
   printArray(numbers , n);

   delete[] numbers;
   numbers = nullptr;
}