#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

#include "files.h"
#include "variables.h"
class textures: virtual private files
{
public:
	textures();
	~textures();

	//sf::Texture * Get_Texture(Type Texture_Type, short IDs = 0);

	sf::Image Get_Image(short ID);

private:
	std::vector<sf::Texture> Textures;

	sf::String Fonds_name[17] = { "01.jpg", "02.jpg", "03.jpg", "04.jpg", "05.jpg", "06.jpg", "07.jpg", "08.jpg", "09.jpg", "10.jpg", "11.jpg", "12.jpg", "13.jpg", "14.jpg", "15.jpg", "16.jpg", "17.jpg" };
	sf::String Tuiles_name[24] = { "tuile_01.png", "tuile_02.png", "tuile_03.png", "tuile_04.png", "tuile_05.png", "tuile_06.png", "tuile_07.png", "tuile_08.png", "tuile_09.png", "tuile_10.png",
		"tuile_11.png", "tuile_12.png", "tuile_13.png", "tuile_14.png", "tuile_15.png", "tuile_16.png", "tuile_17.png", "tuile_18.png", "tuile_19.png", "tuile_20.png", "tuile_21.png", "tuile_22.png", "tuile_23.png", "tuile_24.png" };
	sf::String Selection = "selection.png";
	sf::String Tuile_back = "tuile_back.png";
	sf::String Exit_name = "exit.png";
	sf::String Play_name = "play.png";
	sf::Texture hover;
};
