#include "AnimationWindow.h"
#include "Emoji.h"


// Definer størrelse på vindu og emoji
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 50;

int main()
{

	const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	AnimationWindow win{tl.x, tl.y, xmax, ymax, win_label};


	Point c = {xmax/4,ymax/4};
	SadFace sad(c , emojiRadius);
	sad.draw(win);

	Point d {xmax/4 , ymax/2};
	SmilingFace smil(d,emojiRadius);
	smil.draw(win);

	Point e {xmax/2 , ymax/2};
	SurprisedFace sup(e,emojiRadius);
	sup.draw(win);

	Point f {xmax/2 , ymax/4};
	WinkyFace s2(f,emojiRadius);
	s2.draw(win);
	


	win.wait_for_close();

	

	return 0;
}
