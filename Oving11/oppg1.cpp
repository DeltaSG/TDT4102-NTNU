#include "oppg1.h"


typedef std::vector<std::string>::iterator iter_type;




void printListe(std::vector<std::string> l)
{
    iter_type from {l.begin()};
    iter_type until {l.end()};

    for(iter_type i=from;i!= until; i++){
        std::cout << *i << " ";
    }
}

void printReverse(std::vector<std::string> l)
{
    iter_type from {l.begin()};
    iter_type until {l.end()};
    std::reverse_iterator<iter_type> rev_until {from};
    std::reverse_iterator<iter_type> rev_from {until};
   
    for(auto i=rev_from; i!=rev_until; i++)
    {
        std::cout<<*i<<" ";
    }
}

std::vector<std::string> replace(std::vector<std::string> &v , std::string old , std::string replace)
{
    std::vector<std::string>::iterator i; 
    for(i= v.begin(); i!= v.end(); i++)
    {
        if(*i == old)
        {
            v.erase(i);
            v.insert(i , replace);
        }
    }
    return v; 
}

//typedef std::set<std::string>::iterator set_it;
std::set<std::string>::iterator it_S;
void printSet(std::set<std::string> s)
{
    //set_it from = ;
    //set_it until = s.end();

    for( it_S = s.begin(); it_S != s.end() ; it_S++)
    {
        std::cout << *it_S << " ";
    }
}

void reversedSet(std::set<std::string> s)
{
    std::reverse_iterator rev_from {s.end()};
    std::reverse_iterator rev_until{s.begin()};

    for(auto i = rev_from; i != rev_until ; i++)
    {
        std::cout << *i << " ";
    }

}

std::set<std::string> replaceSet(std::set<std::string> &s, std::string old, std::string replacement)
{
    for(it_S = s.begin() ; it_S != s.end() ; it_S++)
    {
        if(*it_S == old)
        {
            s.erase(old);
            s.insert(replacement); //et set er alt sotert så den bestemmer selv hvor elementet skal stå 
        }
    }
    return s;
}