#pragma once

#include <SFML/Graphics.hpp>

#include "game_stats.h"
#include "renderer.h"
#include "tiles.h"
#include "sound.h"
#include "textures.h"
#include "files.h"

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
	//game name
	sf::String Application_name = "Matchmaking";
	//resolution instance
	sf::VideoMode Resolution;
	//window instance
	std::unique_ptr <sf::RenderWindow> Windows;

	tiles Tiles;
	//sound instance
	std::unique_ptr <sound>  Sound;
	//texture instance
	std::unique_ptr <textures>  Texture;
	//files instance
	std::unique_ptr <files>  Files;
	//renderer instance
	std::unique_ptr <renderer> Renderer;
};

