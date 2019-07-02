#include "bouton.h"



bouton::bouton()
{
}


bouton::~bouton()
{
}

void bouton::Set_size(const sf::Vector2f Taille)
{
	Bouton.setSize(Taille);
}
void bouton::Set_position(const sf::Vector2f Position)
{
	Bouton.setPosition(Position);
}

void bouton::Set_ID(const short _ID)
{
	ID = _ID;
}
void bouton::Select()
{
	Bselect = true;
}
void bouton::Unselect()
{
	Bselect = false;
}

const sf::Vector2f bouton::Get_Position()
{
	return Bouton.getPosition();
}

const short bouton::Get_ID()
{
	return ID;
}
const bool bouton::Is_inside(const sf::Vector2f Position)
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

const bool bouton::Is_select()
{
	return Bselect;
}
