//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// This program outputs the message "Hello, World!" to the monitor

#include "meetingWindow.h"
#include "meeting.h"
#include "person.h"
#include "Car.h"

//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
 void buttonClicked()
    {
        std::cout << "Someone clicked me!" << std::endl;
    }

int main() {
    // Show a nice message in the Terminal window
    Person h{"Henrik" , "stud@ntnu.no", std::make_unique<Car>(4)};
    std::cout << h;
    MeetingWindow met{50,50,1000,720,"emp win"};
    met.wait_for_close();
    met.printPeople();

    // This lets the operating system (Windows, Mac, Linux, etc.) know that the program
    // did not encounter any errors
    return 0;
}

//------------------------------------------------------------------------------
