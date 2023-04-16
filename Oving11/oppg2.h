#pragma once
#include<string>
#include<list>
#include<iostream>

class Person
{
    private:
        std::string fName;
        std::string lName;

    public:
        Person(std::string firstName , std::string lastName):
             fName{firstName} , lName{lastName}{};
        
        std::string getFName();
        std::string getLName();
    
        friend std::ostream& operator<<(std::ostream &os , Person p);
};

std::list<Person> sortLastName(std::list<Person> lp);