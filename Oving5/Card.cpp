#include "std_lib_facilities.h"
#include "Card.hpp"




string rankToString(Rank str){
    string s = VERDIMAP.at(str);
    return s;
}

string suitToString(Suit str){
    string s = FARGEMAP.at(str);
    return s;
}

// It is easier to use suits to represent cards than numbers 
// As people are more used to it. 

Card::Card(Suit suit , Rank rank): s{suit} , r{rank}{}

string Card::getSuit(){
    return suitToString(s);
}

string Card::getRank(){
    return rankToString(r);
}

string Card::toString(){
    string card = "  " + Card::getRank() + " of " + Card::getSuit() + "  " ;
    return card;
}

