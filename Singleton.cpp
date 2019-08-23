#include "Singleton.h"


//C-TOR, loading the game effects(sounds, screens)
Singleton::Singleton()
{
	sf::Texture temp;
	temp.loadFromFile("themes\\pokemon.png");
	m_file.insert(std::pair<std::string,sf::Texture>("background", temp));
	temp.loadFromFile("themes\\game_over.png");
	m_file.insert(std::pair<std::string, sf::Texture>("gameOver", temp));

	m_font.loadFromFile("Font\\game_font.ttf");
	m_sound.openFromFile("themes\\pokemon.ogg");
	

}

sf::Texture& Singleton::getPic(std::string key)
{
	
	return  m_file[key];
}

Singleton & Singleton::instance()
{
	static Singleton inst;
	return inst;
}

sf::Font & Singleton::getFont()
{
	return m_font;
}

void Singleton::getMusic()
{
	m_sound.setLoop(true);
	m_sound.play();
}
