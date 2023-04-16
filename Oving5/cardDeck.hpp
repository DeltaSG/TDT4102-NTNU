#pragma once
#include <std_lib_facilities.h>
#include "Card.hpp"

int randomWithLimits(int lowerLimit , int  upperLimit);

//Hjelpemap for å konvertere string til verdi

const map<string,int> value{
    {"Two" , 2},
    {"Three" , 3},
    {"Four" , 4},
    {"Five" , 5},
    {"Six" , 6},
    {"Seven" , 7},
    {"Eight" , 8},
    {"Nine" , 9},
    {"Ten" , 10},
    {"Jack" , 10},
    {"Queen" , 10},
    {"King" , 10},
    {"Ace" , 11},
};


class CardDeck {
    private:
    vector<Card> cards{};

    public:
    CardDeck();

    void swap(int a , int b);
    void print();
    void shuffle();
    Card drawCard();
};


class BlackJack {
    private:
    CardDeck a{};

    vector<Card> playerHand {};
    vector<Card> dealerHand {};

    int playerHandSum();
    int dealerHandSum();

    public:
    int getCardValue(Card c);
    int getHandScore(vector<Card> vekt);
    bool askPlayerDrawCard();
    void drawPlayerCard();
    void drawDealerCard();
    void playGame();

};


bool isAce(Card c);