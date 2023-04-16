#include <std_lib_facilities.h>
#include "tests.hpp"
#include "utilities.hpp"
#include "mastermind.hpp"


int checkCharactersAndPosition(int size , string code ,string guess) {
   

    int counter = 0;
    for (int i=0;i<size;i++) {
        if (guess[i] == code[i] ){
            counter += 1;
        }
    }
return counter;
}
int checkCharacters(string code , string guess) {
     
    int teller = 0;
    for(auto & del:guess) {
        if(countChar(code , del) >= 1){
            teller++;
            //Vil ikke funke på fuplikate bokstaver men men
        }
    }
return teller; 
}


void playMastermind(){
    constexpr int size = 4;
    constexpr int leters = 6;

    string code = randomizeString(size , 'A' , 'F');
    string guess = readInputToString(size , 'F'); 

    int tries = 0;
    const int totalTries = 10;

    while(tries < totalTries) {
        
        if (checkCharactersAndPosition(size , code , guess) != size) {
        cout << "Korrekt char og pos: " << checkCharactersAndPosition(size , code , guess) << endl;
        cout << "Korrekt char: " << checkCharacters(code , guess) << "(Obs! gjelder ikke duplikater.)" << endl;
        cout << "Skriv inn nytt forsok: ";
        guess = readInputToString(size , 'F');
        cout << "\n";
        tries++;
        }else {
            cout << "Gratulerer du knakk koden! ordet var: " << code << endl;
            return;}
  
        }
            cout << "Det var synd, du klarte ikke knekke koden." << endl;
            cout << "koden var: " << code << endl;
            return;
    }
   
    
    
