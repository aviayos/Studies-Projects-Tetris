#pragma once
#include "Shapes.h"
#include <vector>
#include <SFML\Graphics.hpp>
#include "Singleton.h"
#include "Board.h"

using std::vector;




enum Direction_t { Up_t, Down_t, Left_t, Right_t };

class Shapes//base class of the base, hold actions on the shpaes
{
public:
	Shapes();
	Shapes(const Shapes& shape);
	virtual ~Shapes();
	virtual void print(sf::RenderWindow& win);
	void move(Direction_t,  Board & board );
	void rotateShape();
	Shapes & operator=(const Shapes & s);
	void setNextShape();
protected:
	vector<sf::RectangleShape> m_shape;
	void move_to(sf::Vector2f &new_position,  Board & board, Direction_t direction);
	sf::Color randColors();
	sf::RectangleShape getRec(int)const;

	
};

