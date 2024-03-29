#pragma once

#include <chrono>

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

	//dessine une tuile
	void Add_tuile(const sf::Vector2f Position, const short Number);
	//dessine le dessous des tuile
	void Add_back(const sf::Vector2f Position);
	//dessine le fond derriere les tuile
	void Add_fond(const short Number);
	//dessine le bouton quitter
	void Add_exit(const sf::Vector2f Position);
	//dessine le bouton jouer
	void Add_play(const sf::Vector2f Position);
	//dessine le carr� rouge quand on passe sur le bouton jouer/quitter
	void Add_hover(const sf::Vector2f Position);
	//dessine le ? quand on passe sur une tuile
	void Add_selection(const sf::Vector2f Position);
	//dessine le texte en haut a gauche
	void Add_score_small(const short Score);
	//dessine le score en gros
	void Add_score_big(const short Score);
	//draw everything waiting to be rendered
	void Render();
	//lance le systeme de particules
	void Destroy(const sf::Vector2f Position, const short Number);
	//lance l'animation quand on selectionne une tuile
	void Start_anim(const sf::Vector2f Position, const short Number);
	//raz l'animation
	void Reset_anim();
	//recuepre l'info si les animations sont fini
	const bool Is_Anim_End();

private:
	//stock a handle to textures
	textures * Textures;
	//stock a handle to fonte
	fonte * Fonte;

	void make_particles();
	void Stop_anim();
	void Run_anim();
	void Rectangle(const sf::Vector2f Position);

	short Rectangle_ID = 0, Animation_ID = 1;
	
	bool Draw_text = false;
	bool Is_doing_anim = false;
	bool Is_destroying = false;

	//valeurs indispensable pour les particules
	std::vector<sf::Vector2f> Destroy_positions;
	std::vector<short> Destroy_tuile_ID;
	std::vector<unsigned int> Destroy_tuile_progression;
	std::vector<sf::Image> Destroy_images;
	std::vector<sf::Texture> Destroy_Textures;

	//resolution
	const float Width = 1024.0f, Height = 768.0f;

	//window handle
	sf::RenderWindow *Windows;
	//to show text on screen
	sf::Text Texte;

	std::vector<sf::RectangleShape> Rectangle_database;
	//vector of particules
	std::vector< Pixel> Pixels;

	//obliger en version release, pour temporisation
	std::chrono::steady_clock Horloge;
	std::chrono::steady_clock::time_point Time;
};

