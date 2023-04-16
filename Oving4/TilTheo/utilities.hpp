#pragma once 

int incrementByValueNumTimes(int startValue , int increment , int numTimes);
int incrementByValueNumTimesRef(int & startValue , int & increment , int & numTimes);

void swapNumbers(int a , int b);

struct Student{
    string name;
    string program;
    int age;
};

void printStudent(Student stud);

bool isInProgram(Student stud , string studie);

// Oppgave 3

string randomizeString(int antallTegn , char lowerChar , char upperChar);

string readInputToString(int antall , char upperChar);

int countChar(string str , char c);