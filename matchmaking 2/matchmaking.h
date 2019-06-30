#pragma once

#include <SFML/Graphics.hpp>

#include "game_stats.h"
#include "renderer.h"
#include "tiles.h"
#include "sound.h"

class matchmaking//: virtual private files
{
public:
	matchmaking();
	~matchmaking();

	//start the game
	bool Run();

private:
	//current stat
	game_stats Statut;
	//is the game alive and running ?
	bool Is_running = true;

	//resolution
	const unsigned int Width = 1024, Height = 768;
	//name
	sf::String Application_name = "Matchmaking";
	//resolution handle
	sf::VideoMode Resolution;
	//window handle
	std::unique_ptr <sf::RenderWindow> Windows;
	//renderer handle
	std::unique_ptr <renderer> Rinstance;

	tiles Tiles;
	std::unique_ptr <sound>  Sound;
};

