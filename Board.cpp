#include "Board.h"

//c-tor, get the board height and width as 'size'
Board::Board(sf::Vector2i size) :
	m_NextShape(false), m_gameOver(false)
{
	m_board.resize(size.y);
	m_netY.resize((size.y) + 1);
	m_netX.resize((size.x) + 1);
	m_background.setSize(sf::Vector2f(SHAPE_SIZE*size.x, SHAPE_SIZE*size.y));
	m_background.setPosition(100, 0);
	m_background.setFillColor(sf::Color::Black);


	for (unsigned int i = 0; i <unsigned int(size.y); i++)
	{
		m_board[i].resize(int(size.x));
	}

	for (unsigned int i = 0; i < m_netY.size(); i++)
	{
		m_netY[i].setSize(sf::Vector2f(SHAPE_SIZE * WIDTH, 2));
		m_netY[i].setFillColor(sf::Color::White);
		m_netY[i].setPosition(LEFTLIMIT, float(i) * SHAPE_SIZE);
	}
	for (unsigned int i = 0; i < m_netX.size(); i++)
	{
		m_netX[i].setSize(sf::Vector2f(2, SHAPE_SIZE * HEIGHT));
		m_netX[i].setFillColor(sf::Color::White);
		m_netX[i].setPosition(LEFTLIMIT + (i * SHAPE_SIZE), 0);
	}
}

//d-tor
Board::~Board()
{
}

//method return the number of full lines on grid
int Board::getFullLines()
{

	auto IsFull = [&](std::unique_ptr<sf::RectangleShape> &rec)
	{ return rec != nullptr; };

	m_board.erase(std::remove_if(m_board.begin(), m_board.end(),
		[&](vector<std::unique_ptr<sf::RectangleShape>> & line)
	{return std::all_of(line.begin(), line.end(), IsFull); }),
		m_board.end());

	int full_lines = HEIGHT - m_board.size();

	for (unsigned int i = 0; i < full_lines; i++)
		m_board.insert(m_board.begin(), vector<std::unique_ptr<sf::RectangleShape>>(WIDTH));

	return full_lines;
}
//method check the collisions on boards
bool Board::collision(sf::RectangleShape rec, sf::Vector2f new_position)
{
	rec.move(new_position);

	int x = (rec.getGlobalBounds().left - LEFTLIMIT) / SHAPE_SIZE;
	int y = rec.getGlobalBounds().top / SHAPE_SIZE;

	
	if (y >= 0 && y < m_board.size() && x >= 0 && x < m_board[0].size())
	{
		if (m_board[y][x] != nullptr)
			return true;
	}
	return false;
}

void Board::drawNet(sf::RenderWindow & win)
{//הדפסה של הרשת
	for (unsigned int i = 0; i < m_netX.size(); i++)
		win.draw(m_netX[i]);
	for (unsigned int j = 0; j < m_netY.size(); j++)
		win.draw(m_netY[j]);



}

void Board::drawBackground(sf::RenderWindow & win)
{
	win.draw(m_background);
}

void Board::drawBoard(sf::RenderWindow & win)
{
	for (int y = m_board.size() - 1; y >= 0; y--)
	{
		for (int x = 0; x < m_board[y].size(); x++)
		{
			if (m_board[y][x] != nullptr)
			{
				m_board[y][x].get()->setPosition(LEFTLIMIT + (x * SHAPE_SIZE), (y * SHAPE_SIZE));
				win.draw(*m_board[y][x].get());
			}
		}
	}
}

void Board::setNextShape(bool change)
{
	m_NextShape = change;
}

void Board::setGameOver(bool status)
{
	m_gameOver = status;
}

bool Board::getNextShape()
{
	return m_NextShape;
}

//method insert rectangleshape to the board, after the shape collide object on board
void Board::insertRec(sf::RectangleShape rec)
{
	int x = (rec.getGlobalBounds().left - LEFTLIMIT) / SHAPE_SIZE;
	int y = rec.getGlobalBounds().top / SHAPE_SIZE;

	rec.setOrigin(0, 0);
	rec.setRotation(0);

	m_board[y][x] = std::make_unique<sf::RectangleShape>(rec);
}

bool Board::isOver()
{
	return m_gameOver;
}

