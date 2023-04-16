//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "cardDeck.hpp"
#include "Card.hpp"

//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main() {

    int operand = -1;
    while(operand != 0) {
        cout << '\n' << endl;
        cout << "0) End" << endl;
        cout << "1) Test Card and print card" << endl;
        cout << "2) Make deck, print, draw, shuffle and print." << endl;
        cout << "3) Play BlacJack" << endl;

        cout << "Write a number between: (0 , 3): ";
        cin >> operand;
        cout << endl;
        
        if(operand == 1) {
            Rank r = Rank::king;
            Suit s = Suit::hearts;
            string rank = rankToString(r);
            string suit = suitToString(s);
            cout << "Rank: " << rank << " Suit: " << suit << '\n';
            Card c{Suit::spades , Rank::ace};
            cout << c.toString() << '\n';
        }else if(operand == 2) {
            CardDeck a{};
            a.print();
            //a.shuffle();
            cout << '\n' << endl;
            // Kan ikke shufle siden størrelsen på decken er endret mulig å fikse med å lese av .size()
            cout << a.drawCard().toString() << endl;
            //a.print();
            
        }else if (operand == 3) {
            BlackJack b;
            b.playGame();

        }
    }
    return 0;
}

//------------------------------------------------------------------------------
