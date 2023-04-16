#include "MinesweeperWindow.h"
#include <iostream>
#include "random"
#include "widgets/TextInput.h"

MinesweeperWindow::MinesweeperWindow(int x, int y, int width, int height, int mines, const string &title) : 
	// Initialiser medlemsvariabler, bruker konstruktoren til AnimationWindow-klassen
	AnimationWindow{x, y, width * cellSize, (height + 1) * cellSize, title},
	width{width}, height{height}, mines{mines}
{
	// Legg til alle tiles i vinduet
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			tiles.emplace_back(new Tile{ Point{j * cellSize, i * cellSize}, cellSize});
			tiles.back()->setCallback(std::bind(&MinesweeperWindow::cb_click, this));
			auto temp = tiles.back().get();
			add(*temp); 
		}
	}
	for (int i = 0; i < mines;)
	{
		Point rand = {randomCell(width , 0)*cellSize ,randomCell(height , 0)*cellSize };
		if(!at(rand) ->getIsMine() ){
			at(rand) -> setIsMine();
			i++;
		}
	}
	add(status);

	
}

int MinesweeperWindow::randomCell(int upperLim , int lowerLim){
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_real_distribution<double> distribution(lowerLim , upperLim);

    double number = distribution(generator);
    int intNumber = static_cast<int> (number);
    return intNumber;
}

vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
	vector<Point> points;
	for (int di = -1; di <= 1; ++di) {
		for (int dj = -1; dj <= 1; ++dj) {
			if (di == 0 && dj == 0) {
				continue;
			}

			Point neighbour{ xy.x + di * cellSize,xy.y + dj * cellSize };
			if (inRange(neighbour)) {
				points.push_back(neighbour);
			}
		}
	}
	return points;
}

int MinesweeperWindow::countMines(vector<Point> coords) const 
{
	int adjmin = 0;	
	for(auto& elem:coords){
		if(at(elem) ->getIsMine()){
			adjmin++;
		}
	}
	return adjmin;
}


void MinesweeperWindow::openTile(Point xy) {
	switch (at(xy) -> getState()){
	case Cell::closed:{
		at(xy) -> open();
		if(!at(xy) ->getIsMine()){
			int m= countMines(adjacentPoints(xy));
			if(m==0){
				at(xy) -> setLabel("0");
				at(xy) -> setLabelColor(TDT4102::Color::blue);
				tilesOpen++;
				for(auto& elem: adjacentPoints(xy)){
					openTile(elem);
				}				
			}else{
				at(xy)->setAdjMines(m);
				tilesOpen++;
				
					/*
					if(at(elem)->getState() == Cell::closed){
						at(elem) -> open();
						int mn= countMines(adjacentPoints(elem));
						tilesOpen++;
					if(mn > 0){
						at(elem)->setAdjMines(mn);
					}else{
						at(elem) ->setLabel("0");
						at(elem) ->setLabelColor(TDT4102::Color::blue);}}
						*/}
		}else{
					/*you lost*/
					status.setText("You lost. close window");
					return;
				}
				int teller{0};
				int flagget{0};
				for(auto& tile:tiles){
					if(tile ->getState() == Cell::open){
						teller++;
					}else if(tile -> getState() == Cell::flagged){
						flagget++;
					}else{}
				}
				status.setText((std::to_string(tilesOpen)));

				if(tilesOpen == width*height - mines){
					/*you won*/
					status.setText("You Won! close window");
				}
			
		break; }

	default:
		break;
	}}
void MinesweeperWindow::flagTile(Point xy) {
	switch (at(xy) -> getState())
	{
	case Cell::closed:{
		at(xy) -> flag();
		break;}
	case Cell::flagged:{
		at(xy) -> flag();
		break;}
	default:{
		break;
	}
	}}

//Kaller openTile ved venstreklikk og flagTile ved hoyreklikk
void MinesweeperWindow::cb_click() {
	Point xy{this->get_mouse_coordinates()};
	//std::cout << xy.x << " " << xy.y <<": " << xy.x / (cellSize) + (xy.y / cellSize) * width<<"\n";
	if (!inRange(xy)) {
		return;
	}
	if (this->is_left_mouse_button_down()) {
		openTile(xy);
	}
	else if(this->is_right_mouse_button_down()){
		flagTile(xy);
	}}
