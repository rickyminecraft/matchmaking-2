#include "textures.h"



textures::textures()
{
}

textures::textures(files * _Files)
{
	Files = _Files;
	short Boucle = 0;
	for (auto Names : Fonds_name)
	{
		Fonds.push_back(Files->Get_texture(Fonds_name[Boucle]));
		++Boucle;
	}
	Boucle = 0;
	for (auto Names : Tuiles_name)
	{
		Tuiles.push_back(Files->Get_texture(Tuiles_name[Boucle]));
		Images_tuile.push_back(Files->Get_image(Tuiles_name[Boucle]));
		++Boucle;
	}
	
	TBack = Files->Get_texture(Tuile_back_name);
	TExit = Files->Get_texture(Exit_name);
	TPlay = Files->Get_texture(Play_name);
	TSelection = Files->Get_texture(Selection_name);

	sf::Image image_hover;
	image_hover.create(100, 100, sf::Color::Red);
	Thover.loadFromImage(image_hover);
}


textures::~textures()
{
}

sf::Texture * textures::Get_tuile(const short Number)
{
	return &Tuiles[Number];
}

sf::Texture * textures::Get_fond(const short Number)
{
	return &Fonds[Number];
}

sf::Texture * textures::Get_exit()
{
	return &TExit;
}

sf::Texture * textures::Get_play()
{
	return &TPlay;
}

sf::Texture * textures::Get_selection()
{
	return &TSelection;
}

sf::Texture * textures::Get_back()
{
	return &TBack;
}

sf::Texture * textures::Get_hover()
{
	return &Thover;
}

sf::Image textures::Get_Image(const short Number)
{
	return Images_tuile[Number];
}
