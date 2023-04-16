#include "oppg2.h"

std::ostream &operator<<(std::ostream &os , Person p)
{
    os<< "Name: " << p.fName << " " << p.lName << std::endl;
    return os;
}

std::string Person::getFName(){return fName;}
std::string Person::getLName(){return lName;}


std::list<Person>::iterator it;
std::list<Person> sortLastName(std::list<Person> lp)
{
    lp.sort([](Person lhs , Person rhs){return lhs.getLName() < rhs.getLName();});
    return lp;
}

