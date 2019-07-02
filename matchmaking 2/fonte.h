#pragma once

#include <SFML/Graphics.hpp>

#include "files.h"
class fonte
{
public:
	fonte();
	explicit fonte(files * _Files);
	~fonte();

	sf::Text Get_small();
	sf::Text Get_big();
private:
	//stock a handle to files
	files * Files;

	sf::Font Fonte;
	sf::Text Text_1, Text_2;
};

