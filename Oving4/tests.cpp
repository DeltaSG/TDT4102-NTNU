#include <std_lib_facilities.h>
#include "tests.hpp"
#include "utilities.hpp"

void testCallByValue() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0 , increment , iterations);
    cout << "v0: " << v0
         << " increment: " << increment
         << " iterations: " << iterations
         << " result: " << result << endl;
}

void testCallByRefrence() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimesRef(v0 ,increment , iterations);
    cout << "v0: " << v0
         << " increment: " << increment
         << " iterations: " << iterations
         << " result: " << result << endl;
}

// oppg 3)

void testString() {
    string grades = randomizeString(8 , 'A' , 'F');
    cout << grades << endl;
    vector<int> gradeCount;
    for (int i = 65 ; i<70;i++) {
        gradeCount.push_back(countChar(grades , static_cast<char>(i)));
    }
    int sum = 0;
    for (int i=0;i<5;i++) {
        sum += (gradeCount[i] * (5 - i));
    }
    int average = (sum / 8);
    cout << "Gjennomsnitts karakteren er: " << average << endl;

}