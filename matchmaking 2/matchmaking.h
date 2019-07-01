#pragma once

#include <chrono>

#include <SFML/Graphics.hpp>

#include "game_stats.h"
#include "renderer.h"
#include "tiles.h"
#include "sound.h"
#include "textures.h"
#include "files.h"
#include "bouton.h"

class matchmaking
{
public:
	matchmaking();
	~matchmaking();

	//boucle principal
	bool Run();

private:
	//etat actuel
	game_stats Statut;
	//continue t'on a jouer ?
	bool Is_running = true, do_select = false;

	//resolution
	const unsigned int Width = 1024, Height = 768;
	//game name
	sf::String Application_name = "Matchmaking";
	//resolution instance
	sf::VideoMode Resolution;
	//window instance
	std::unique_ptr <sf::RenderWindow> Windows;

	//une representation des tuiles
	tiles Tiles;
	//une representation des boutons
	std::vector<bouton> Tuiles;
	bouton Play;
	bouton Exit;
	bouton Hover;
	//sound instance
	std::unique_ptr <sound>  Sound;
	//texture instance
	std::unique_ptr <textures>  Texture;
	//files instance
	std::unique_ptr <files>  Files;
	//renderer instance
	std::unique_ptr <renderer> Renderer;

	std::chrono::steady_clock horloge;
	std::chrono::steady_clock::time_point time;
	std::chrono::steady_clock::time_point time2;
};

