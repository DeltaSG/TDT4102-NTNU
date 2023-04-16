#include <std_lib_facilities.h>
#include "Card.hpp"
#include "cardDeck.hpp"

int randomWithLimits(int lowerLimit , int  upperLimit) {
    random_device rd;
    default_random_engine generator(rd());
    uniform_real_distribution<double> distribution(lowerLimit , upperLimit);

    double number = distribution(generator);
    int intnumber = static_cast<int>(number);

    return intnumber;
}

CardDeck::CardDeck() {
    for(auto & x:FARGEMAP){
        for(auto & y:VERDIMAP){
            Card n{x.first , y.first};
            cards.push_back(n);
        }
    }
}

void CardDeck::print() {
    for(auto  & elem:cards) {
        cout << elem.toString() << " , ";
    }
}

void CardDeck::swap(int a , int b) {
    Card temp = cards.at(a);
    cards.at(a) = cards.at(b);
    cards.at(b) = temp;
}

void CardDeck::shuffle() {
    for(int i = 0; i<40;i++){
        int str = cards.size();
        int a = randomWithLimits(0,(str));
        int b = randomWithLimits(0,(str));

        swap(a,b);
    // bruke random number generator til å finne to heltall og så sette disse inn i swap. og gjøre dette n ganger
}}

Card CardDeck::drawCard() {
    int n = cards.size();
    Card b = cards[n-1];
    cards.pop_back();
    return b;


}

bool isAce(Card c) {
    if(c.getRank() == "ace") {
        return true;
    }
    return false;
}

int BlackJack::getCardValue(Card c){
    return (value.at(c.getRank()));
}

int BlackJack::getHandScore(vector<Card> vekt) {
    int sum = 0;
    for(auto elem:vekt ) {
        sum += getCardValue(elem);
    }
    return sum;
}

bool BlackJack::askPlayerDrawCard(){
    int drawCard = -1;

    cout << "Do you want to draw a card? (Yes=1 , No = 0): ";
    cin >> drawCard;

    return drawCard;
   
}

void BlackJack::drawPlayerCard(){
    Card d = a.drawCard();
    playerHand.push_back(d);
    cout << "Value of card is: " << getCardValue(d) << endl;
    cout << "Value of hand is: " << getHandScore(playerHand) << endl;
    cout << '\n' << endl;
}

void BlackJack::drawDealerCard() {
    Card d = a.drawCard();
    dealerHand.push_back(d);
    int dealerSum = getHandScore(dealerHand);
    // Dette er mest for feilsøkning og kan fjærnes når programmet funker som det skal. 
    cout << "Value of card is: " << getCardValue(d) << endl;
    cout << "Value of dealer hand is: " << getHandScore(dealerHand) << endl;
    cout << '\n' << endl;
}

void BlackJack::playGame(){
    //Hvordan shuffle
    a.shuffle();

    //Vi starter med å gi spilleren og dealer ett kort hver.
    drawPlayerCard();
    drawDealerCard();
    //Spilleren skal få lov til å vite det første kortet til Dealer så vi kan skrive ut dette til konsollen
    drawPlayerCard();
    drawDealerCard();
    //Vi har nå starten av spillet.
    if (getHandScore(playerHand) == 21 and playerHand.size() == 2) {
        cout << "Congratulation! \n You got a True BlackJack" << endl;
        return;
    }else if(getHandScore(dealerHand) == 21){
        cout << "The Dealer got 21 you lost" << endl;
    }else{
        bool ask = askPlayerDrawCard();
        while (ask== 1){
            
            drawPlayerCard();
            if (getHandScore(playerHand) > 21){
                cout << "You went over 21 and lost :(" << endl;
                return;
            }
            ask = askPlayerDrawCard();
            }
    }while(getHandScore(dealerHand) < 17){
        drawDealerCard();
    }
    if (getHandScore(dealerHand) <= 21){
        if(getHandScore(dealerHand) >= getHandScore(playerHand)){
            cout << "The house allways wins. Better luck next time!" << endl;
        }else{
         cout << "Congratulations you beat the odds and the House!!" << endl;
        }}
        cout << "The dealer got over 21. You WON!" << endl;
}