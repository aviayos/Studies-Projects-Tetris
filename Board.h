#pragma once
#include <vector>
#include <SFML\Graphics.hpp>
#include <algorithm>
#include <iostream>
#include <memory>
#include <experimental/vector>


using std::vector;
//CONSTANTS--------------------------------------------------------------------
const unsigned int NUM_SQUARES = 4;
const int HEIGHT = 20;
const int WIDTH = 10;
const float SHAPE_SIZE = 20;
const float SCREEN_X = 400;
const float SCREEN_Y = 600;
const float LEFTLIMIT = (SCREEN_X - SHAPE_SIZE * WIDTH) / 2;
const float RIGHTLIMIT = SCREEN_X - LEFTLIMIT;
const float DOWNLIMIT = SHAPE_SIZE * HEIGHT;
//---------------------------------------------------------------------------------------------

class Board//class hold the grid and manage the actions on him 
{
public:
	Board(sf::Vector2i size);
	int getFullLines();
	bool collision(sf::RectangleShape , sf::Vector2f new_position);
	void drawNet(sf::RenderWindow& win);
	void drawBackground(sf::RenderWindow& win);
	void drawBoard(sf::RenderWindow& win);
	void setNextShape(bool);
	void setGameOver(bool);
	bool getNextShape();
	void insertRec(sf::RectangleShape rec);
	bool isOver();
	~Board();
private:
	vector<vector<std::unique_ptr<sf::RectangleShape>>> m_board;//the grid
	vector<sf::RectangleShape> m_netX;
	vector<sf::RectangleShape> m_netY;
	sf::RectangleShape m_background;
	bool m_NextShape;
	bool m_gameOver;


};

