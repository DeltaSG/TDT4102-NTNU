#include <std_lib_facilities.h>
#include "utilities.hpp"

int incrementByValueNumTimes(int startValue , int increment , int numTimes){
    for (int i=0;i<numTimes;i++) {
        startValue += increment;
    }
    return startValue;
}
int incrementByValueNumTimesRef(int & startValue , int & increment , int & numTimes) {
    int result = startValue;
    for (int i=0;i<numTimes;i++) {
        result += increment;
    }
    return result;
}

void swapNumbers(int a , int b) {
    int c = a;
    a = b;
    b = c;
    std::cout << a << "  " << b << endl;
}

void printStudent(Student stud) {
    std::cout << "Name: " << stud.name << endl;
    std::cout << "Age: " << stud.age << endl;
    std::cout << "Program: " << stud.program << endl;

}

bool isInProgram(Student stud , string studie) {
    if (stud.program == studie) {
        cout << stud.name << " Is also attending " << studie << "." << endl;
        return true;
    }
    return false;
}

// Oppgave 3
int randomWithLimits(int lowerLimit , int  upperLimit) {
    random_device rd;
    default_random_engine generator(rd());
    uniform_real_distribution<double> distribution(lowerLimit , upperLimit);

    double number = distribution(generator);
    int intNumber = static_cast<int> (number);
    return intNumber;
}
string randomizeString(int antallTegn , char lowerChar , char upperChar){
    string str = "";
    for(int i =0 ; i<antallTegn;i++) {
        int n = randomWithLimits(static_cast<int> (lowerChar) , static_cast<int> (upperChar));
        int c = n;
        str += static_cast<char> (c);
    }
    return str;
}

string readInputToString(int antall , char upperChar) {
    int lowerLim = static_cast<int>('A');
    int upperLim = static_cast<int>(upperChar);
    int lowerLim2 = static_cast<int>('a');
    int upperLim2 = static_cast<int>(upperChar + 32);
    string str = "";
        char c = 'A';

        cout << "Skriv inn en bokstav: ";
        int i = 0;
        while(i<antall){
        
        
        cin >> c;

        if(((static_cast<int>(c) >= lowerLim) and (upperLim >= static_cast<int>(c))) or ((static_cast<int>(c) >= lowerLim2) and (upperLim2 >= static_cast<int>(c)))){
             str += c;
             i++;

             cout << str << endl;
        }else {
            std::cout << "ikke gylding bokstav, skriv inn ny: ";
            
        cout << str << endl;
        }
       
        }
        std::cout << str << endl;
        
    return str;
}

int countChar(string str , char c) {
    int counter = 0;
    for (auto &elem: str) {
        if (elem == c) {
            counter++;
        }
    }
    return counter;
}

