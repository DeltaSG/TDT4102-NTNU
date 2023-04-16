#pragma once

#include "std_lib_facilities.h"

//Lager en klasse for de forskjellige typene kort
enum class Suit {clubs = 1 , dimonds , hearts, spades};
//Lager en klasse for de forskjellige verdiene av kort
enum class Rank {two=2 , three ,four, five, six ,seven, eight, nine , ten ,jack, queen, king, ace};

const map<Rank,string> VERDIMAP = {
    {Rank::two,    "Two"},
    {Rank::three,  "Three"},
    {Rank::four,   "Four"},
    {Rank::five,   "Five"},
    {Rank::six,    "Six"},
    {Rank::seven,  "Seven"},
    {Rank::eight,  "Eight"},
    {Rank::nine,   "Nine"},
    {Rank::ten,    "Ten"},
    {Rank::jack,   "Jack"},
    {Rank::queen,  "Queen"},
    {Rank::king ,  "King"},
    {Rank::ace ,   "Ace"},
};

const map<Suit,string> FARGEMAP = {
    {Suit::clubs , "Clubs"},
    {Suit::dimonds, "Dimonds"},
    {Suit::hearts, "Hearts"},
    {Suit::spades, "Spades"}
};



string suitToString(Suit str);
string rankToString(Rank str);

class Card {
    private: 
    Suit s;
    Rank r;

    public:
    Card(Suit suit , Rank rank);
    string getSuit();
    string getRank();
    string toString();
};
