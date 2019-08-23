#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
//#include "Shapes.h"
#include "Square.h"
#include "Zaw.h"
#include "Saw.h"
#include "Gamma.h"
#include "Alpha.h"
#include "Pyramid.h"
#include "Stick.h"
#include <memory>
#include <queue>
#include "Singleton.h"
#include <iostream>
#include "StatusBar.h"

//using std::queue;
const int NUM_SHAPES = 7;



class Controller//main class, get the input from the player and activate the other classes
{
public:
	Controller();
	~Controller();
	void run();//main function

private:
	Board m_gameBoard;
	std::queue<std::unique_ptr<Shapes>> m_shapes;//hold two shapes each iteration
	StatusBar m_bar;//gane status
	unsigned int m_level;
	unsigned int m_score;
	int getRandom();
	void draw(sf::RenderWindow& win);
	void createNewShape();
	void moveAutomaticlly(float &time, sf::Clock& clock);
	void gameOver(sf::RenderWindow& win);


};

