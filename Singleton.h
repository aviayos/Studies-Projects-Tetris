#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <string>

class Singleton//singletone class 
{
public:
	sf::Texture& getPic(std::string);
	static Singleton & instance();
	sf::Font& getFont();
	void getMusic();

private:
	Singleton();
	std::map<std::string, sf::Texture> m_file;
	sf::Font m_font;
	sf::Music m_sound;
};

