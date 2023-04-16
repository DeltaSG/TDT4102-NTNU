#include <std_lib_facilities.h>

#include "utilities.hpp"
#include "tests.hpp"
#include "mastermind.hpp"

// 1 a) Koden vil skirive ut 5 + 2 * 10 = 25.

int main(){
    int number = -1;
    while(number != 0) {
    cout << "0) Avslutt" << endl;
    cout << "1) Skriv ut summ av tall, increment." << endl;
    cout << "2) Skriv ut summ av tall med referanse" << endl;
    cout << "3) Bytter om på to variabler" << endl;
    cout << "4) 2d) What program am i studying?" << endl;
    cout << "oppgave 2 e) feilen ligger i at en header fil"
         << " er inkludert i en annen header fil. så den blir laster to ganger" << endl;
    cout << "5) Skriver ut en tilfeldig streng med lengde 8 og bokstaver mellom A og F" << endl;
    cout << "6) Skriv inn bokstaver i intervallet A-F eller a-f" << endl;
    cout << "7) PlayMastermind" << endl;

    cout << "Skriv in et tall, (1 , --): ";
    cin >> number;
    cout << "\n";

    
    if (number == 1) {
        testCallByValue();
    }else if (number == 2) {
        testCallByRefrence();
    }else if (number == 3) {
        cout << "a = 3 , b = 5" << endl;
        swapNumbers(3, 5);
    }else if (number == 4) {
        Student meg {"Henrik Gronlund" , "FysMat" , 21};
        printStudent(meg);
        cout << isInProgram(meg , "FysMat") << endl;
    }else if (number == 5) {
        testString();
    }else if(number == 6) {
        cout << readInputToString(8 , 'F') << endl;
    }else if(number == 7) {
        playMastermind();
    }
}
return 0;
}