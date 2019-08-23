#include "Shapes.h"


Shapes::Shapes()
{
	sf::Color shape_col = randColors();
	m_shape.resize(NUM_SQUARES);

	for (int i = 0; i < NUM_SQUARES; i++)
	{
		m_shape[i].setSize(sf::Vector2f(SHAPE_SIZE, SHAPE_SIZE));
		m_shape[i].setFillColor(shape_col);
	}

}

Shapes::Shapes(const Shapes & shape)
{
	*this = shape;
}


Shapes::~Shapes()
{
}

void Shapes::print(sf::RenderWindow & win)
{
	for (int i = 0; i < m_shape.size(); i++)
	{
		win.draw(m_shape[i]);
	}
}

void Shapes::move(Direction_t direction, Board & board)
{
	sf::Vector2f new_position;

	{
		switch (direction)
		{
		case Up_t:
			rotateShape();
			break;
		case Down_t:
			new_position = { 0.f, SHAPE_SIZE };
			break;
		case Right_t:
			new_position = { SHAPE_SIZE, 0 };
			break;
		case Left_t:
			new_position = { -SHAPE_SIZE, 0 };
			break;
		}
		if (direction != Up_t)
			move_to(new_position, board, direction);

	}

}

void Shapes::rotateShape()
{

	for (int i = 0; i < m_shape.size(); i++)
		m_shape[i].rotate(90);
	auto check = [](sf::RectangleShape & rec) {return (rec.getGlobalBounds().left + SHAPE_SIZE > RIGHTLIMIT ||
		rec.getGlobalBounds().left < LEFTLIMIT ||
		rec.getGlobalBounds().top  > DOWNLIMIT); };
	if (std::any_of(m_shape.begin(), m_shape.end(), check))
	{
		std::for_each(m_shape.begin(), m_shape.end(), [](sf::RectangleShape & rec) {rec.rotate(-90); });
	}

}

Shapes & Shapes::operator=(const Shapes & s)
{
	for (int i = 0; i < NUM_SQUARES; i++)
	{
		m_shape[i] = s.getRec(i);
	}
	return *this;
}

void Shapes::setNextShape()
{
	for (unsigned int i = 0; i < m_shape.size(); i++)
	{
		m_shape[i].setOutlineThickness(2);
		m_shape[i].setOutlineColor(sf::Color::White);
		m_shape[i].move(0, 560);
		//m_shape[i].setSize(sf::Vector2f(SHAPE_SIZE * 2, SHAPE_SIZE * 2));
	}
}



void Shapes::move_to(sf::Vector2f &new_position, Board & board, Direction_t direction)
{
	auto InBounds = [&new_position](sf::RectangleShape &rec) {return (rec.getGlobalBounds().left + new_position.x >= LEFTLIMIT &&
		rec.getGlobalBounds().left + new_position.x + SHAPE_SIZE <= RIGHTLIMIT &&
		rec.getGlobalBounds().top + SHAPE_SIZE + new_position.y <= DOWNLIMIT); };

	auto Collide = [&](sf::RectangleShape &rec) {return board.collision(rec, new_position); };

	auto OutBounds = [&](sf::RectangleShape &rec) 
	{ return (rec.getGlobalBounds().left < LEFTLIMIT ||
		rec.getGlobalBounds().left > RIGHTLIMIT ||
		rec.getGlobalBounds().top > DOWNLIMIT ||
		rec.getGlobalBounds().top < 0); };
	//move if not collide
	if (std::any_of(m_shape.begin(), m_shape.end(), OutBounds) && std::any_of(m_shape.begin(), m_shape.end(), Collide))
	{	
		board.setGameOver(true);
	}
	else if (std::all_of(m_shape.begin(), m_shape.end(), InBounds) && !std::any_of(m_shape.begin(), m_shape.end(), Collide))
	{
		auto func = [&new_position](sf::RectangleShape & rec) {rec.move(new_position); };
		std::for_each(begin(m_shape), end(m_shape), func);
	}
	else if (direction == Down_t) {//move down and collide
		board.setNextShape(true);
		if(!board.isOver())
			std::for_each(m_shape.begin(), m_shape.end(), [&](sf::RectangleShape & rec) {board.insertRec(rec); });
	}


}

sf::Color Shapes::randColors()//פונקציה שמגרילה צבע לצורה
{
	srand((unsigned)time(NULL));
	int num;
	num = rand() % 7;
	switch (num) {
	case 0: return sf::Color::Blue;
	case 1: return sf::Color::Green;
	case 2: return sf::Color::Red;
	case 3: return sf::Color::Cyan;
	case 4: return sf::Color::Yellow;
	case 5: return sf::Color::Magenta;
	case 6: return sf::Color::Cyan;
	}
	return sf::Color::Cyan;
}

sf::RectangleShape Shapes::getRec(int i)const
{
	return m_shape[i];
}

