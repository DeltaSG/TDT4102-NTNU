#include "masterVisual.h"
#include "std_lib_facilities.h"

#include "utilities.hpp"
#include "mastermind.hpp"






void playMasterVisual(){
	
    constexpr int size = 4;
    constexpr int leters = 6;
	MastermindWindow mwin{800 , 20 , winW , winH , size , "Mastermind"};

    string code = randomizeString(size , 'A' , 'F');
    string guess = mwin.getInput(size , 'A' , 'F'); 

    int tries = 0;
    const int totalTries = 10;

    while(tries < totalTries) {
        
        if (checkCharactersAndPosition(size , code , guess) != size) {
        cout << "Korrekt char og pos: " << checkCharactersAndPosition(size , code , guess) << endl;
        cout << "Korrekt char: " << checkCharacters(code , guess) << "(Obs! gjelder ikke duplikater.)" << endl;
        cout << "Skriv inn nytt forsok: ";
        guess = mwin.getInput(size , 'A' , 'F');
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



void addGuess(MastermindWindow &mwin, const std::string code, const char startLetter)
{
	// definer addGuess 
	vector<string>guesses{};

}

void addFeedback(MastermindWindow &mwin, const int correctPosition, const int correctCharacter)
{
	// definer addFeedback
}

void MastermindWindow::drawCodeHider()
{
	if(code_hidden) {
		draw_rectangle(Point{padX, 3 * padY}, winW - size * padX, padY, Color::black);
	}
}

MastermindWindow::MastermindWindow(int x, int y, int w, int h, int size, const std::string &title) 
: AnimationWindow(x, y, w, h, title),
guessBtn{{upperLeftCornerBtn.x, upperLeftCornerBtn.y}, btnW, btnH, "Add"},
guess{{upperLeftCornerInBox.x, upperLeftCornerInBox.y}, inBoxW, inBoxH, ""},
size(size)
{
	add(guess);
	add(guessBtn);
	guessBtn.setCallback(std::bind(&MastermindWindow::newGuess, this));
};

string MastermindWindow::wait_for_guess()
{

	std::map<int, Color> colorConverter{
    {1, Color::red},
    {2, Color::green},
    {3, Color::yellow},
    {4, Color::blue},
    {5, Color::blue_violet},
    {6, Color::dark_cyan}
	};

	while (!button_pressed && !should_close())
	{
		for(int guessIndex = 0; guessIndex < static_cast<int>(guesses.size()); guessIndex++) {
			//Implementer gjett slik at det vises fargede rektangler i grafikkvinduet
			{
                // Tegn rektangler ved bruk av draw_rectangle(). Bruk: colorConverter.at() for å få riktig farge
				//draw_rectangle(Point(xPos , yPos) , padX , padY , colorConverter.at(intName)) 
				// Må få xPos til å gå fra 0 til 4 for hver y økning, for løkke? 

			}
		}

		for(int feedbackIndex = 0; feedbackIndex < static_cast<int>(feedbacks.size()); feedbackIndex++) {
			// Implementer feedback

			for (int i = 0; i < size; i++)
			{
				// Tegn sirkler ved hjelp av draw_circle
				
			}
		}

		// Burde tegnes sist siden den skal ligge på toppen
		drawCodeHider();

		next_frame();
	}
	button_pressed = false;

	string newGuess = guess.getText();
	guess.setText("");
	
	return newGuess;
}

string MastermindWindow::getInput(unsigned int n, char lower, char upper)
{
	bool validInput = false;
	string guess;
	while (!validInput && !should_close())
	{
		guess.clear();
		string input = wait_for_guess();
		if (input.size() == n)
		{
			for (unsigned int i = 0; i < n; i++)
			{
				char ch = input.at(i);
				if (isalpha(ch) && toupper(ch) <= upper && lower <= toupper(ch))
				{
					guess += toupper(ch);
				}
				else
					break;
			}
		}
		if (guess.size() == n)
		{
			validInput = true;
		}
		else
		{
			cout << "Invalid input guess again" << endl;
		}
	}
	return guess;
}

void MastermindWindow::setCodeHidden(bool hidden) {
	code_hidden = hidden;
}
