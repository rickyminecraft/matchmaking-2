#pragma once

#include <SFML/Graphics.hpp>

#include "textures.h"
#include "fonte.h"
#include "animation.h"
#include "particle.h"
class renderer: private animation
{
public:
	renderer();
	renderer(sf::RenderWindow *Handle, textures * _Textures, fonte * _Fonte);
	~renderer();

	void Add_tuile(const sf::Vector2f Position, const short Number);
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

	void Start_anim(const sf::Vector2f Position, const short Number, const bool Direction = false);
	void Reset_anim();
	const bool Is_Anim_End();

private:
	//stock a handle to textures
	textures * Textures;
	fonte * Fonte;

	void Stop_anim();
	void Run_anim();
	void Reverse_anim(const short _ID);
	void Rectangle(const sf::Vector2f Position);

	short Rectangle_ID = 0, Animation_ID = 1;
	short Anim_Num_1 = -1, Anim_Num_2 = -1;
	sf::Vector2f Anim_position_1, Anim_position_2;
	bool Anim_reverse_1 = false, Anim_reverse_2 = false;
	bool Draw_text = false;
	bool Is_doing_anim = false;

	//resolution
	const float Width = 1024.0f, Height = 768.0f;

	//window handle
	sf::RenderWindow *Windows;
	sf::Text Texte;

	std::vector<sf::RectangleShape> Rectangle_database;
};

