//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include <AnimationWindow.h>
#include <cannonball.hpp>
#include <utuilities.hpp>
#include "cannonball_viz.h"
//------------------------------------------------------------------------------'
void testDeviation(double compareOperand , double toOperand , double maxError , string name); //Deklarering
// C++ programs start by executing the function main
int main() {
    double maxError = 0.0001; //vet ikke helt hvor du skal....

    int choise = (-1);
    
    while (choise != 0) {
        cout << "\n Choose one:" <<  endl;
        cout << "1) Test position at t = 2.5s , 5.0s." << endl;
        cout << "2) Test deviation (posX(0.0 , 50 , 5.0) , 250 , maxError)" << endl;
        cout << "3) Target practice (25 , 13.87 , 7.22), expected result = 4m" << endl;
        cout << "4) checkIfDistanceToTargetIsCorrect" << endl;
        cout << "5) Random int, upper, lower = 0 , 10" << endl;
        cout << "6) Play target practice distance(100 , 1000)" << endl;
        cout << "Skriv inn ett tall: (0 , 6): ";
        cin >> choise;

        if (choise == 0) {
         return 0;
        }else if (choise == 1) {
            cout << setw(10) << "t = 2.5s" << setw(10) << "t = 5.0" << endl;
            cout << "velY" << setw(10) << velY(25 , 2.5) << setw(10) << velY(25 , 5.0) << endl; 
            cout << "posY" << setw(10) << posY(0, 25 , 2.5) << setw(10) << posY(0 ,25 , 5.0) << endl;
     }else if (choise == 2) {
        testDeviation(posX(0.0 , 50 , 5.0) , 250 , maxError , "posX(0.0 , 50 , 5.0)");
    }else if (choise == 3) {
         cout << targetPractice(25 , 13.87 , 7.22) << " meters to target.";
    }else if(choise == 4){
        cout << (checkIfDistanceToTargetIsCorrect() ? "true" : "false");
    }else if(choise == 5){
        cout << randomWithLimits(0 ,10);
        return 0;
    }else if(choise == 6){
        playTargetPractice();
    }
    }
    
    // Show a nice message in the Terminal window
return 0;
}

void testDeviation(double compareOperand , double toOperand , double maxError , string name) {if (abs(compareOperand - toOperand) <= maxError) {
    cout << name << " is valid" << endl;
}else{
    cout <<"Not valid, Expected: " << toOperand << ", got: " << compareOperand << endl;
}}


//------------------------------------------------------------------------------
