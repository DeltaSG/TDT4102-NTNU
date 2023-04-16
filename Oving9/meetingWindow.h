#pragma once

#include "memory"
#include "vector"
#include "iostream"
#include "meeting.h"
#include "AnimationWindow.h"
#include "widgets/TextInput.h"
#include "widgets/Button.h"
#include "person.h"
#include "Car.h"


class MeetingWindow: public TDT4102::AnimationWindow
{
    private:
        TDT4102::Button quitBtn{{width()-pad,pad}, btnW, btnH , "Quit"};
        TDT4102::TextInput personName{{fieldPad , pad} , fieldW , fieldH , "Name: "};
        TDT4102::TextInput personEmail{{fieldPad , 2*pad + fieldH} , fieldW , fieldH , "Email: "};
        TDT4102::Button personNewBtn{{fieldPad , 3*pad + 2*fieldH} , btnW , btnH , "New Person"};
    public:
        MeetingWindow(int x , int y, int w, int h, const std::string& title); 
        static constexpr int pad{100}; 
        static constexpr int btnW{100}; 
        static constexpr int btnH{40}; 
        static constexpr int fieldW{300}; 
        static constexpr int fieldH{50}; 
        static constexpr int fieldPad{50}; 

        std::vector<std::shared_ptr<Person>> people;

        void cb_quit();
        void newPerson();
        void printPeople();
        

};