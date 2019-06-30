#pragma once

#include <vector>

#include <SFML/Audio.hpp>

#include "files.h"
#include "SoundTypes.h"
class sound
{
public:
	sound();
	sound(files * _Files);
	~sound();

	sf::Sound Sound(Sound_type Type);

private:
	//stock a handle to files
	files * Files;
	std::vector<sf::SoundBuffer> Buffers;
	std::vector<sf::Sound> Sounds;

	sf::String Files_name[4] = {"match.ogg", "musique.ogg", "retourne.ogg", "victoire.ogg"};
};

