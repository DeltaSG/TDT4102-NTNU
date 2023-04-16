//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// This program outputs the message "Hello, World!" to the monitor

#include "oppg1.h"
#include "oppg2.h"

//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main() {
    int number = -1;
    while(number != 0)
    {
        std::cout << "0) Avslutt" << std::endl;
        std::cout << "1) Print ut vector med iterator" << std::endl;
        std::cout << "2) Print ut set med iterator" << std::endl;
        std::cout << "3) Print ut personer" << std::endl;
        
        std::cout<<"Skriv inn et tall: ";
        std::cin>>number;
        std::cout << "\n";

        if(number == 1){
            std::vector<std::string> liste {"Lorem" , "Ipsum" , "Dolor" , "Sit" , "Amet" , "Consectetur"};
            printListe(liste);
            std::cout<<"\n";
            printReverse(liste);
            std::cout<<"\n";
            replace(liste , "Lorem" , "Latin");
            printListe(liste);
            std::cout<< "\n";
        }else if(number == 2){
            std::set<std::string> test {"Lorem" , "Ipsum" , "Dolor" , "Sit" , "Amet" , "Consectetur"};
            printSet(test);
            std::cout<<"\n";
            reversedSet(test);
            std::cout<<"\n";
            replaceSet(test, "Lorem" , "Latin");
            printSet(test);
            std::cout<< "\n";
        }else if(number == 3){
            Person a("Henrik" , "Bakke");
            Person b("Stian" , "Tangen");
            Person c("Olav" , "Aasheim");
            std::list<Person> pers{a , b, c};
            for(auto&elem: pers){
                std::cout << elem;}
            
            for(auto&elem: sortLastName(pers)){
                std::cout << elem;
            }
        }
    }


    return 0;
}

//------------------------------------------------------------------------------
