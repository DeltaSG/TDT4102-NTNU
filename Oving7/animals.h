#pragma once
#include <std_lib_facilities.h>

class Animals{
    protected:
    string name;
    int age;
    public:
    Animals(string name , int age);
    virtual ~Animals() {};
    void virtual toString() {cout << "Animal:" << name << "," << to_string(age) << endl;};
    
};

class Dog: public Animals {
    public:
    using Animals::Animals;
    void virtual toString() {cout << "Dog: " << name <<","<< to_string(age)<<endl;};
};

class Cat: public Animals {
    public:
    using Animals::Animals;
    void virtual toString() {cout << "Cat: " << name <<","<< to_string(age)<<endl;};
};

void testAnimal();