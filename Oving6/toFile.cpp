#include <std_lib_facilities.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "toFile.h"

void writeToFile()
{
    ofstream file("Oppg1.txt");

    if(file.is_open()){
        cout << "Success. \n";
    }
    cout << "Write words you want in file Oppg1" << endl;

    string str = "";
    cin >> str;

    cout << "To end, write: 'quit' ";
    while(str != "quit"){
        file << str << endl;
        cin >> str;
    }

    file.close();
}


void lineNumbers(string filename){ // must be .txt format
    string fName = filename + ".txt";

    ifstream input(fName);
    string line;

    int n = 0;
    ofstream numberfile ("Oppg1b.txt");
    if (numberfile.is_open()){
        cout << "Success!" << endl;
    }
    while(getline( input, line ) ) {
        numberfile << to_string(n)+line << '\n';
        n++;
    }
    }



void charStats(string filename){
    map<char , int> counter{
    {'a' , 0},{'b' , 0},{'c' , 0},{'d' , 0},{'e' , 0},{'f' , 0},{'g' , 0},{'h' , 0},{'i' , 0},{'j' , 0},{'k' , 0},
    {'l' , 0},{'m' , 0},{'n' , 0},{'o' , 0},{'p' , 0},{'q' , 0},{'r' , 0},{'s' , 0},{'t' , 0},{'u' , 0},{'v' , 0},
    {'w' , 0},{'x' , 0},{'y' , 0},{'z' , 0},
};
    char ch;
    ifstream characterfile (filename);
    while (characterfile >> noskipws >> ch) {
        char lower = tolower(ch);

        for (const auto& m:counter){
            if(lower == m.first){
                counter.at(lower) = counter[lower] + 1;
            }
        }
    }

    for(const auto& c:counter){
        cout << c.first << " : " << c.second << ", ";
    }
}

string getCapital(const string& country){ //endret fra [] til .at()
    return capitalsMap.at(country);
    };


void CourseCatalog::addCourse(string code , string name) {
    for (auto & elem:course){
        if(code == elem.first){
            course.at(code) = name;
        }
    }
    course.insert({code , name});
}
void CourseCatalog::removeCourse(string code) {
    course.erase(code);
}
string CourseCatalog::getCourse(string code) {
    return course.at(code);
}

 ostream& operator<<(ostream& os , const CourseCatalog& c) {
    for (const auto & l:c.course) {
        os << l.first << " : " << l.second << endl;
    }
    return os; 
 }

void CourseCatalog::mapToFile(string file , CourseCatalog m){
    ofstream mapf(file);
    for(auto & elem:m.course){
        mapf << elem.first << ',' << elem.second << endl;
    }
    mapf.close();
}

void CourseCatalog::fileToMap(string file , CourseCatalog b){
    ifstream fileM(file);
    string line;
    while(getline(fileM , line)) {
       string delimiter = ",";
       string code = line.substr(0 , line.find(delimiter));
       line.erase(0, line.find(delimiter) + delimiter.length());
       string name = line;
       b.addCourse(code,name);
    }
    cout << b << endl;
}
