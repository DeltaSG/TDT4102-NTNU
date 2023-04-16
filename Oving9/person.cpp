#include "Car.h"
#include "person.h"

std::string Person::getName()
{
    return name;
}
std::string Person::getEmail()
{
    return email;
}
void Person::setEmail(std::string newMail)
{
    email = newMail;
}
bool Person::hasAvailableSeats()
{
    if ( car != nullptr ){
        return(car ->hasFreeSeats());
    }
    else{
        return false;
    }
}

std::ostream& operator<<(std::ostream& os, const Person& p)
{
    if(p.car != nullptr){
        os<< "Name: " << p.name 
          <<", mail: " << p.email
          <<", car with seats: " <<((p.car -> hasFreeSeats()) ? "true, ":"false, ") << 
             p.car.get() << std::endl;
    return os;
    }else{
        os<< "Name: " << p.name 
          <<", mail: " << p.email
          << ", no car." << std::endl; 
    return os;    
    }
}