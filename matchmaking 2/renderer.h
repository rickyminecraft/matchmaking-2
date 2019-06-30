#pragma once

#include <SFML/Graphics.hpp>

#include "textures.h"
#include "particle.h"
#include "variables.h"

class renderer: private textures
{
public:
	renderer();
	renderer(sf::RenderWindow *Handle);
	~renderer();

	//copy the window handle here
	//to allow drawing
	void set_window_handle(sf::RenderWindow *Handle);

	//void rectangle(sf::Vector2f Position, sf::Vector2f Origin);
	//renderer Add(sf::Vector2f Position, sf::Vector2f Origin, Type Texture_type, sf::Vector2f Scale = { 1.0f, 1.0f }, short Number = 0);
	//renderer add_fond(short Number);
	//renderer add_exit();
	//renderer add_play();
	//draw everything waiting to be rendered
	void Render();

	

private:
	void Rectangle(sf::Vector2f Position, sf::Vector2f Origin);
	void Scale(sf::Vector2f Scale);
	//renderer Texture(Type Texture_type, short ID);

	short Rectangle_ID = 0;

	//window handle
	sf::RenderWindow *Windows;

	std::vector<sf::RectangleShape> Rectangle_database;
};

