#include "std_lib_facilities.h"
#include <cmath>
#include <AnimationWindow.h>
//------------------------------------------------------------------------------'
void pythagoras(){
    AnimationWindow win{100 , 100, 1000 , 500, "Pytagoras"};
    Point point1{500,200};
    Point point2{600,200};
    Point point3{500,150};

    win.draw_triangle(point1,point2,point3, Color::red);

    win.draw_quad(point1,point2, {600,300} , {500 , 300}, Color::green); // a^2
    win.draw_quad(point1,point3, {450,150} , {450 , 200}, Color::dark_orange); // b^2
    win.draw_quad(point2,point3, {600,100} , {700 , 150}, Color::blue); // c^2
    
    win.wait_for_close();
}

int main() {
    pythagoras();
    return 0;
}

//------------------------------------------------------------------------------
