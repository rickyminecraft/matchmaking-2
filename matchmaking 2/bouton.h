#pragma once

#include <SFML/Graphics.hpp>
class bouton
{
public:
	bouton();
	~bouton();

	void Set_size(const sf::Vector2f Taille);

	void Set_position(const sf::Vector2f Position);

	void Set_ID(const short _ID);

	void Select();
	void Unselect();

	const sf::Vector2f Get_Position();

	const short Get_ID();

	const bool Is_inside(const sf::Vector2f Position);

	const bool Is_select();

private:
	//utiliser pour stocker toutes les infos mais pas en tant que rectangleshape
	sf::RectangleShape Bouton;
	//si on a un ID
	short ID = 0;
	bool Bselect = false;
};

