#pragma once

#include <vector>

#include <SFML/Audio.hpp>

#include "files.h"
#include "SoundTypes.h"
class sound : virtual private files
{
public:
	sound();
	~sound();

	sf::Sound Sound(Sound_type Type);

private:
	std::vector<sf::SoundBuffer> Buffers;
	std::vector<sf::Sound> Sounds;

	sf::String Files_name[4] = {"match.ogg", "musique.ogg", "retourne.ogg", "victoire.ogg"};
};

