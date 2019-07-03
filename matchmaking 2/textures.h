#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

#include "files.h"
class textures
{
public:
	textures();
	explicit textures(files * _Files);
	~textures();

	//on recupere un pointeur sur la texture 'number' pour les tuiles
	sf::Texture * Get_tuile(const short Number);
	//on recupere un pointeur sur la texture du fond
	sf::Texture * Get_fond(const short Number);
	//on recupere un pointeur sur la texture quitter
	sf::Texture * Get_exit();
	//on recupere un pointeur sur la texture jouer
	sf::Texture * Get_play();
	//on recupere un pointeur sur la texture '?'
	sf::Texture * Get_selection();
	//on recupere un pointeur sur la texture arriere de tuile
	sf::Texture * Get_back();
	//on recupere un pointeur sur la texture rouge de fond
	sf::Texture * Get_hover();
	//on recupere une copie de l'image d'une texture
	//pour les particules
	sf::Image Get_Image(const short Number);

private:
	//stock a handle to files
	files * Files;

	std::vector<sf::Texture> Tuiles;
	std::vector<sf::Texture> Fonds;
	std::vector<sf::Image> Images_tuile;
	sf::Texture TBack;
	sf::Texture TExit;
	sf::Texture TPlay;
	sf::Texture TSelection;
	sf::Texture Thover;

	const sf::String Fonds_name[17] = { "01.jpg", "02.jpg", "03.jpg", "04.jpg", "05.jpg", "06.jpg", "07.jpg", "08.jpg", "09.jpg", "10.jpg", "11.jpg", "12.jpg", "13.jpg", "14.jpg", "15.jpg", "16.jpg", "17.jpg" };
	const sf::String Tuiles_name[24] = { "tuile_01.png", "tuile_02.png", "tuile_03.png", "tuile_04.png", "tuile_05.png", "tuile_06.png", "tuile_07.png", "tuile_08.png", "tuile_09.png", "tuile_10.png",
		"tuile_11.png", "tuile_12.png", "tuile_13.png", "tuile_14.png", "tuile_15.png", "tuile_16.png", "tuile_17.png", "tuile_18.png", "tuile_19.png", "tuile_20.png", "tuile_21.png", "tuile_22.png", "tuile_23.png", "tuile_24.png" };
	const sf::String Selection_name = "selection.png";
	const sf::String Tuile_back_name = "tuile_back.png";
	const sf::String Exit_name = "exit.png";
	const sf::String Play_name = "play.png";
	
};

