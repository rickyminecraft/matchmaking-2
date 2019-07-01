#pragma once

#include <SFML/Graphics.hpp>

#include "textures.h"
#include "animation.h"
class renderer: private animation
{
public:
	renderer();
	renderer(sf::RenderWindow *Handle, textures * _Textures);
	~renderer();

	void Add_tuile(const sf::Vector2f Position, const short Number = 0);
	void Add_back(const sf::Vector2f Position);
	void Add_fond(const short Number);
	void Add_exit(const sf::Vector2f Position);
	void Add_play(const sf::Vector2f Position);
	void Add_hover(const sf::Vector2f Position);
	void Add_selection(const sf::Vector2f Position);
	//draw everything waiting to be rendered
	void Render();

private:
	//stock a handle to textures
	textures * Textures;

	void Rectangle(const sf::Vector2f Position);
	void Rectangle(const sf::Vector2f Position, const sf::Vector2f Origin);
	void Scale(const sf::Vector2f Scale);
	//renderer Texture(Type Texture_type, short ID);

	short Rectangle_ID = 0;

	//resolution
	const float Width = 1024.0f, Height = 768.0f;

	//window handle
	sf::RenderWindow *Windows;

	std::vector<sf::RectangleShape> Rectangle_database;
};

