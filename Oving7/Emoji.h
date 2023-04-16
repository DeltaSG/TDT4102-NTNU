#pragma once
#include "std_lib_facilities.h"
#include "AnimationWindow.h"

// Abstrakt klasse. Arvende konkrete klasser må implementere funksjonen draw()
// som tegner former i vinduet de skal bli vist i.
class Emoji
{
public:
    virtual void draw(AnimationWindow&) = 0;
    virtual ~Emoji(){}; //destruktør
};

class Face: public Emoji {
    protected:
        Point center;
        int radius;
    public: 
    Face(Point p , int r);
    void draw(AnimationWindow& win) override;
    };

class EmptyFace: public Face {
    protected:
        Point eyeR;
        Point eyeL;
    public:
        EmptyFace(Point p , int r) : Face{p , r}{};
        void setEyeR();
        void setEyeL();
        void draw(AnimationWindow& win)override;
};

class SadFace: public EmptyFace {
    public:
        SadFace(Point c , int r) : EmptyFace{c,r}{};
        void draw(AnimationWindow& win)override;
};

class SmilingFace: public EmptyFace {
    protected:
        Point s_center;
        int width;
        int height;
        int start_deg;
        int end_deg;
    public:
        SmilingFace(Point c , int r): EmptyFace{c,r}{
            s_center = {center.x , center.y + radius/6};
            width = 2*radius/3;
            height = radius / 2;
            start_deg = 180;
            end_deg = 360;
        };
        void draw(AnimationWindow& win)override;
};

class sad2: public SmilingFace {
    public: 
        sad2(Point p , int r): SmilingFace{p,r}{};
        void draw(AnimationWindow& win)override;
};

class SurprisedFace: public EmptyFace {
    public: 
        SurprisedFace(Point c , int r) : EmptyFace{c,r}{};
        void draw(AnimationWindow& win)override;
};

class WinkyFace: public SmilingFace {
    public:
        WinkyFace(Point c , int r) : SmilingFace{c,r}{};
        void draw(AnimationWindow& win)override;
};