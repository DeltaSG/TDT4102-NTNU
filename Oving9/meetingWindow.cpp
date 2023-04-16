#include "memory"
#include "vector"
#include "iostream"
#include "meeting.h"
#include "AnimationWindow.h"
#include "widgets/TextInput.h"
#include "widgets/Button.h"
#include "meetingWindow.h"
#include "person.h"
#include "Car.h"


MeetingWindow::MeetingWindow(int x , int y, int w, int h, const std::string& title)
            :AnimationWindow(x,y,w,h,title){
                add(quitBtn);
                add(personName);
                add(personEmail);
                add(personNewBtn);
                quitBtn.setCallback(std::bind(&MeetingWindow::cb_quit , this));
                personNewBtn.setCallback(std::bind(&MeetingWindow::newPerson , this));
}

void MeetingWindow::cb_quit(){
    AnimationWindow::close();
}
void MeetingWindow::newPerson(){
    if(!personName.getText().empty() and !personEmail.getText().empty()){
        people.emplace_back(new Person{personName.getText() , personEmail.getText()});
        personName.setText("Name: ");
        personEmail.setText("Mail: ");
    }else if (personName.getText().empty()){
        personName.setText("Must write Name: ");
    }else{
        personEmail.setText("Must write Mail: ");
    }
}
void MeetingWindow::printPeople(){
    for(auto& elem:people){
        std::cout << *elem;
    }
}