#pragma once

#include <SFML/Graphics.hpp>

struct Bouton
{
	void Set_size(const sf::Vector2f Taille)
	{
		Bouton.setSize(Taille);
	}
	void Set_position(const sf::Vector2f Position)
	{
		Bouton.setPosition(Position);
	}
	void Set_origin(const sf::Vector2f Origin)
	{
		Bouton.setOrigin(Origin);
	}
	void Set_scale(const float Scale_x, const float Scale_y)
	{
		Bouton.setScale(Scale_x, Scale_y);
	}
	void Set_ID(const short _ID)
	{
		ID = _ID;
	}
	const sf::RectangleShape * Get_bouton()
	{
		return &Bouton;
	}
	const sf::Vector2f Get_Position()
	{
		return Bouton.getPosition();
	}
	const sf::Vector2f Get_Origin()
	{
		return Bouton.getOrigin();
	}
	const sf::Vector2f Get_Scale()
	{
		return Bouton.getScale();
	}
	const short Get_ID()
	{
		return ID;
	}
	const bool is_inside(const sf::Vector2f Position)
	{
		if (Bouton.getSize().x == 0 || Bouton.getSize().y == 0)
		{
			return false;
		}
		//si on est dedans a l'horizontal
		if (Position.x >= Bouton.getPosition().x && Position.x <= Bouton.getPosition().x + Bouton.getSize().x)
		{
			//est on dedans a la vertical ?
			if (Position.y >= Bouton.getPosition().y && Position.y <= Bouton.getPosition().y + Bouton.getSize().y)
			{
				return true;
			}
		}
		return false;
	}

private:
	sf::RectangleShape Bouton;
	short ID;
};