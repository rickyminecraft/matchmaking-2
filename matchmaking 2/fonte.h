#pragma once

#include <SFML/Graphics.hpp>

#include "files.h"
class fonte
{
public:
	fonte();
	explicit fonte(files * _Files);
	~fonte();

	//recupere un texte deja formater pour petite taille
	sf::Text Get_small();
	//recupere un texte deja formater pour grande taille
	sf::Text Get_big();
private:
	//stock a handle to files
	files * Files;

	sf::Font Fonte;
	sf::Text Text_1, Text_2;
};

