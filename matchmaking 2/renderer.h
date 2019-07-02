#pragma once

#include <SFML/Graphics.hpp>

#include "textures.h"
#include "fonte.h"
#include "animation.h"
class renderer: private animation
{
public:
	renderer();
	renderer(sf::RenderWindow *Handle, textures * _Textures, fonte * _Fonte);
	~renderer();

	void Add_tuile(const sf::Vector2f Position, const short Number = 0);
	void Add_back(const sf::Vector2f Position);
	void Add_fond(const short Number);
	void Add_exit(const sf::Vector2f Position);
	void Add_play(const sf::Vector2f Position);
	void Add_hover(const sf::Vector2f Position);
	void Add_selection(const sf::Vector2f Position);

	void Add_score_small(const short Score);
	void Add_score_big(const short Score);
	//draw everything waiting to be rendered
	void Render();

private:
	//stock a handle to textures
	textures * Textures;
	fonte * Fonte;

	void Rectangle(const sf::Vector2f Position);
	void Rectangle(const sf::Vector2f Position, const sf::Vector2f Origin);
	void Scale(const sf::Vector2f Scale);
	//renderer Texture(Type Texture_type, short ID);

	short Rectangle_ID = 0;
	bool Draw_text = false;

	//resolution
	const float Width = 1024.0f, Height = 768.0f;

	//window handle
	sf::RenderWindow *Windows;
	sf::Text Texte;

	std::vector<sf::RectangleShape> Rectangle_database;
};

