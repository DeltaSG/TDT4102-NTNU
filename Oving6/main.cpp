//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"

#include "toFile.h"
#include "temperatur.h"

//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main() {
    
    int num = -1;
    while(num != 0) {
        cout << endl;
        cout << "0) End" << endl;
        cout << "1) Write to file" << endl;
        cout << "2) Add linenuber to new file" << endl;
        cout << "3) Count characters in file (a-z)" << endl;
        cout << "4) Print Capitals" << endl;
        cout << "5) Print map and save in file" << endl;
        cout << "For å oppdatere variablene er det lagt inn en if-settning slik at om en key eksisterer skal variabelen oppdateres og ikke opprettes." << endl;
        cout << "6) Print map from file" << endl;



        cout << "Write a number between: (0,--): ";
        cin >> num;
        cout << endl;


        if(num == 1){
            writeToFile();
        }else if(num == 2){
            lineNumbers("Oppg1");
        }else if(num == 3){
            charStats("grunnlov.txt");
        }else if(num == 4) {
            cout << "Capitals: " << endl;
            for( pair<const string , const string> elem:capitalsMap){
            cout << getCapital(elem.first) << endl; 
            }
        }else if(num == 5) {
            CourseCatalog c;
            c.addCourse( "TDT4110" , "ITGK");
            c.addCourse( "TDT4102" , "P-OOP");
            c.addCourse( "TMA4100" ,  "Matte 1");
            cout << c << endl;
            c.mapToFile("Oppg3e.txt" , c);
        }else if(num == 6) {
            CourseCatalog b;
            b.fileToMap("Oppg3e.txt", b);
        }else if(num == 7) {
            //Temps a;
            vector<pair<double,double>> tempVect = readTemps("temperatures.txt");
            tempStats(tempVect);
        }
    }
    return 0;
}
//------------------------------------------------------------------------------

