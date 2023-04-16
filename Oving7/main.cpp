//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "animals.h"

//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int mai() {
    int pick = -1;
    while(pick != 0){
        cout << "0) Quit" << endl;
        cout << "Public: Avaliable for all, Private: inaccessible outside of class, Protected: inaccessible outside of class but can be accesed by subclass" << endl;
        cout << "1) test Animal" << endl;
        cout << "2) Quit" << endl;
        cout << "3) Quit" << endl;

        cout << "Write a number between 0 and -- : " << endl;
        cin >> pick;
        cout << endl;

        if(pick == 1){
             testAnimal();
        }else if(pick == 2){
            //do two
        }else if(pick == 3){
            //do three
        }else if(pick == 4){
            //do four
        }


    }


    return 0;
}

//------------------------------------------------------------------------------
