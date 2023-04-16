//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// This program outputs the message "Hello, World!" to the monitor

#include <iostream>

#include <dynminne.h>

//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main() {
    int s = -1;
    while(s !=0)
    {
        std::cout<<"0) Avslutt." << std::endl;
        std::cout<<"1) Create Fibonacci." << std::endl;
        std::cout<<"2) matrise greier." << std::endl;



        if(s == 1){
            createFibonacci();
        }else if(s == 2) {
            // ekkelt 
        }
    }
    

 
    return 0;
}

//------------------------------------------------------------------------------
