#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

#include "std_lib_facilities.h"



void writeToFile();

void lineNumbers(string filename);

void charStats(string filename);

const map<string , string> capitalsMap {
    {"Norway" , "Oslo"} , {"Sweeden" , "Stockholm"} , {"Denmark" , "Copenhagen"},
};

string getCapital(const string& country);

class CodeName{
    private:
    string c;
    string n;

    public:
    CodeName(string code , string name);

};


class CourseCatalog {  
    private:
     map<string, string> course{};
    public:
    void addCourse(string code , string name);
    void removeCourse(string code);
    string getCourse(string code);

    //From txt file to map. 
    void fileToMap(string file , CourseCatalog b);
    //From map to txt file.
    void mapToFile(string file , CourseCatalog m);

    friend ostream& operator<<(ostream& os , const CourseCatalog& c);
};

