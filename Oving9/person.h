#pragma once

#include <iostream>
#include <string>
#include <memory>

#include "Car.h"

class Person{
    private:
        std::string name;
        std::string email;
        std::unique_ptr<Car> car; 

    public:
        Person(std::string names, std::string mail, std::unique_ptr<Car> c = nullptr):
                    name{names} , email{mail} , car{std::move(c)} {}; 

        std::string getName();
        std::string getEmail();
        void setEmail(std::string newMail);
        bool hasAvailableSeats();

        friend std::ostream& operator<<(std::ostream& os, const Person& p);
};