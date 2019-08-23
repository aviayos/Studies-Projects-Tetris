#include "Controller.h"


//c-tor
Controller::Controller() :
	m_gameBoard(sf::Vector2i(WIDTH, HEIGHT)), m_level(1), m_score(0)
{
	m_shapes.push(std::make_unique<Pyramid>());
	m_shapes.push(std::make_unique<Stick>());
	m_bar.NewNextShape(m_shapes.back());

}
//d-tor
Controller::~Controller()
{
}
//main methid, build the window and reponsible the whole game plot
void Controller::run()
{
	srand((unsigned)time(NULL));
	sf::Clock clock;
	float timeToMove;
	sf::RenderWindow window(sf::VideoMode(SCREEN_X, SCREEN_Y), "Tetris", sf::Style::Titlebar | sf::Style::Close);
	Singleton::instance().getMusic();

	while (window.isOpen() && !m_gameBoard.isOver())
	{
		sf::Event user_event;
		window.clear();

		while (window.pollEvent(user_event) && !m_gameBoard.isOver())
		{
			if (user_event.type == sf::Event::Closed)
				window.close();

			if (user_event.type == sf::Event::KeyPressed)
			{
				if (user_event.key.code == sf::Keyboard::Right) {
					m_shapes.front().get()->move(Right_t, m_gameBoard);
				}

				else if (user_event.key.code == sf::Keyboard::Down) {
					m_shapes.front().get()->move(Down_t, m_gameBoard);
				}

				else if (user_event.key.code == sf::Keyboard::Left) {
					m_shapes.front().get()->move(Left_t, m_gameBoard);
				}

				else if (user_event.key.code == sf::Keyboard::Up) {
					m_shapes.front().get()->move(Up_t, m_gameBoard);
				}
			}
		}
		//each shape move down after half second 
		timeToMove = clock.getElapsedTime().asSeconds() * m_level;
		moveAutomaticlly(timeToMove, clock);
		draw(window);

		if (m_gameBoard.getNextShape()) {//if there is a collision
			m_score += m_level;
			m_score += m_gameBoard.getFullLines() * 10 * m_level;
			createNewShape();
			m_gameBoard.setNextShape(false);
			m_bar.NewNextShape(m_shapes.back());
			m_bar.setScore(m_score);

			if (m_score > m_level * 100) {
				m_level++;
				m_bar.setLevel(m_level);
			}
		}

		window.display();
	}
	gameOver(window);

}

int Controller::getRandom()
{
	return rand() % NUM_SHAPES;
}
//draw the whole objects of the game
void Controller::draw(sf::RenderWindow& win)
{
	sf::Sprite background;
	background.setTexture(Singleton::instance().getPic("background"));
	win.draw(background);
	m_gameBoard.drawBackground(win);

	for (unsigned int i = 0; i < m_shapes.size(); i++)
		m_shapes.front()->print(win);

	m_gameBoard.drawBoard(win);
	m_gameBoard.drawNet(win);

	m_bar.PrintBar(win);
}

void Controller::createNewShape()
{
	m_shapes.pop();
	switch (getRandom())
	{
	case 0: m_shapes.push(std::make_unique<Square>());
		break;
	case 1: m_shapes.push(std::make_unique<Zaw>());
		break;
	case 2: m_shapes.push(std::make_unique<Saw>());
		break;
	case 3: m_shapes.push(std::make_unique<Stick>());
		break;
	case 4: m_shapes.push(std::make_unique<Pyramid>());
		break;
	case 5: m_shapes.push(std::make_unique<Gamma>());
		break;
	case 6: m_shapes.push(std::make_unique<Alpha>());
		break;
	}
}

void Controller::moveAutomaticlly(float &time, sf::Clock& clock)
{
	if (time >= 0.5f) {
		clock.restart();
		m_shapes.front().get()->move(Down_t, m_gameBoard);
		time = 0;
	}
}
//method activate while the is over, print "game over" screen
void Controller::gameOver(sf::RenderWindow & win)
{
	win.clear();
	sf::Sprite s;
	s.setTexture(Singleton::instance().getPic("gameOver"));
	win.draw(s);

	sf::Text gameover;
	gameover.setFont(Singleton::instance().getFont());
	gameover.setCharacterSize(50);
	gameover.setFillColor(sf::Color::Red);
	gameover.setPosition(SHAPE_SIZE * 2, SHAPE_SIZE * 10);
	gameover.setOutlineColor(sf::Color::Black);
	gameover.setOutlineThickness(3);
	gameover.setString("Game Over!!");
	win.draw(gameover);
	
	gameover.setString("\n\nYou got: " + std::to_string(m_score) + " points");
	gameover.setCharacterSize(30);
	gameover.setOutlineThickness(2);
	gameover.setPosition(SHAPE_SIZE * 2, SHAPE_SIZE * 11);
	win.draw(gameover);
	
	gameover.setString("Press any key to exit");
	gameover.setPosition(SHAPE_SIZE * 2, SHAPE_SIZE * 17);
	gameover.setFillColor(sf::Color::Blue);
	win.draw(gameover);

	win.display();
	
	
	while (win.isOpen())
	{
		sf::Event event;
		while (win.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				win.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Return);
				{
					win.close();
					break; 
				}
			}
		}
	}
	
	
}


