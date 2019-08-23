#pragma once
#include <SFML/Graphics.hpp>
#include "Shapes.h"
#include "Singleton.h"

class StatusBar//the player status during the game
{
public:
	StatusBar();
	~StatusBar();
	void NewNextShape(std::unique_ptr<Shapes> &nextShape);
	void PrintBar(sf::RenderWindow& win);
	void setScore(unsigned int num);
	void setLevel(unsigned int num);
private:
	sf::RectangleShape m_BackgroundShape;
	Shapes m_NextShape;
	sf::Text m_score;
	sf::Text m_Level;
	sf::Text m_nextShapeText;
	sf::Text m_NumLevel;
	sf::Text m_NumScore;
	
};

