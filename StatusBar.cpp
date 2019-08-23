#include "StatusBar.h"


//c-tor
StatusBar::StatusBar()
{
	m_BackgroundShape.setSize(sf::Vector2f(120, 120));
	m_BackgroundShape.setOutlineColor(sf::Color::White);
	m_BackgroundShape.setOutlineThickness(2);
	m_BackgroundShape.setFillColor(sf::Color::Black);
	m_BackgroundShape.setPosition(LEFTLIMIT + LEFTLIMIT / 2, DOWNLIMIT + DOWNLIMIT/6 );

	m_score.setCharacterSize(30);
	m_score.setString("Score");
	m_score.setOutlineColor(sf::Color::White);
	m_score.setOutlineThickness(3);
	m_score.setPosition(LEFTLIMIT/4, DOWNLIMIT + DOWNLIMIT / 20);
	m_score.setColor(sf::Color::Black);
	m_score.setFont(Singleton::instance().getFont());

	m_nextShapeText.setCharacterSize(30);
	m_nextShapeText.setString("Next Shape");
	m_nextShapeText.setOutlineColor(sf::Color::White);
	m_nextShapeText.setOutlineThickness(3);
	m_nextShapeText.setPosition(LEFTLIMIT+ LEFTLIMIT/4, DOWNLIMIT + DOWNLIMIT / 20);
	m_nextShapeText.setColor(sf::Color::Black);
	m_nextShapeText.setFont(Singleton::instance().getFont());

	m_Level.setCharacterSize(30);
	m_Level.setString("Level");
	m_Level.setOutlineColor(sf::Color::White);
	m_Level.setOutlineThickness(3);
	m_Level.setPosition(RIGHTLIMIT, DOWNLIMIT + DOWNLIMIT / 20);
	m_Level.setColor(sf::Color::Black);
	m_Level.setFont(Singleton::instance().getFont());

	m_NumLevel.setCharacterSize(40);
	m_NumLevel.setString("1");
	m_NumLevel.setOutlineColor(sf::Color::White);
	m_NumLevel.setOutlineThickness(3);
	m_NumLevel.setPosition(RIGHTLIMIT, DOWNLIMIT + DOWNLIMIT / 6);
	m_NumLevel.setColor(sf::Color::Black);
	m_NumLevel.setFont(Singleton::instance().getFont());

	m_NumScore.setCharacterSize(40);
	m_NumScore.setString("0");
	m_NumScore.setOutlineColor(sf::Color::White);
	m_NumScore.setOutlineThickness(3);
	m_NumScore.setPosition((LEFTLIMIT / 4), DOWNLIMIT + DOWNLIMIT / 6);
	m_NumScore.setColor(sf::Color::Black);
	m_NumScore.setFont(Singleton::instance().getFont());
}

//d-tor
StatusBar::~StatusBar()
{
}
//replace the next shpae on the status bar, after collision in board
void StatusBar::NewNextShape(std::unique_ptr<Shapes> &nextShape)
{
	m_NextShape = *nextShape.get();

	m_NextShape.setNextShape();

}

void StatusBar::PrintBar(sf::RenderWindow& win)
{
	win.draw(m_BackgroundShape);
	win.draw(m_score);
	win.draw(m_nextShapeText);
	m_NextShape.print(win);
	win.draw(m_Level);
	win.draw(m_NumLevel);
	win.draw(m_NumScore);
	
}
//set updated score
void StatusBar::setScore(unsigned int num)
{
	
	m_NumScore.setString(std::to_string(num));
}
//set updated level
void StatusBar::setLevel(unsigned int num)
{
	m_NumLevel.setString(std::to_string(num));
}
