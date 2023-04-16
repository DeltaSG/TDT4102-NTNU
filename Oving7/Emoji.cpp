#include "Emoji.h"
#include "std_lib_facilities.h"

Face::Face(Point p, int r): center{p},radius{r}{};


void Face::draw(AnimationWindow& win) {
    win.draw_circle(center , radius , Color::yellow);
}
void EmptyFace::setEyeR(){
    eyeR = {center.x - radius/3 , center.y - radius/5};  
}
void EmptyFace::setEyeL(){
    eyeL = {center.x + radius/3 , center.y - radius/5};
}
void EmptyFace::draw(AnimationWindow& win) {
    Face::draw(win);
    setEyeL();
    setEyeR();

    win.draw_circle(eyeR , radius/6 , Color::black , Color::white);
    win.draw_circle(eyeL , radius/6 , Color::black , Color::white);
} 

void SadFace::draw(AnimationWindow& win){
    Point s_center = {center.x , center.y + radius/2};

    int width = 2*radius / 3;
    int height = radius / 5;
    int start_deg = 10;
    int end_deg = 170;
    EmptyFace::draw(win);
    win.draw_arc(s_center , width , height , start_deg , end_deg , Color::black);
}

void SmilingFace::draw(AnimationWindow& win){
    EmptyFace::draw(win);
    win.draw_arc(s_center , width , height , start_deg , end_deg , Color::black);
    //Lagde smilefjes først men er usikker på hvordan å arve alt og bare endre på munnen :p 
}

void sad2::draw(AnimationWindow& win){
    EmptyFace::draw(win);
    SmilingFace::s_center.y = center.y + radius/2;
    SmilingFace::start_deg = 10;
    SmilingFace::end_deg = 170;
    win.draw_arc(s_center,width,height,start_deg,end_deg,Color::red);
};

void SurprisedFace::draw(AnimationWindow& win){
    Point s_center = {center.x , center.y + radius/3};
    EmptyFace::draw(win);
    win.draw_circle(s_center , radius/5 , Color::black);
}

void WinkyFace::draw(AnimationWindow& win) {
    SmilingFace::draw(win);
    win.draw_circle(eyeR , radius/6 , Color::yellow , Color::yellow);
    win.draw_arc({eyeR.x ,eyeR.y - radius/8} , radius/10 , radius/10 , 140 , 300);
}