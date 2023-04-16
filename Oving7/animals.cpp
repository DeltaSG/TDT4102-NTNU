#include <std_lib_facilities.h>

#include "animals.h"

Animals::Animals(string name , int age): name{name} , age{age}{};

void testAnimal(){
    Dog a("Heisan" , 5);
    Dog b("Biscuit" , 10);
    Cat c("Tibbels" , 4);
    Cat d("Tom" , 20);

    Animals* pntrA = &a;
    Animals* pntrB = &b;
    Animals* pntrC = &c;
    Animals* pntrD = &d;



    vector<Animals*> anim{};

    anim.push_back(pntrA);
    anim.push_back(pntrB);
    anim.push_back(pntrC);
    anim.push_back(pntrD);

    for (auto & elem:anim)
    {
        elem->toString();
    }
    
}