#pragma once

#include <vector>

#include <SFML/Audio.hpp>

#include "files.h"
#include "SoundTypes.h"
class sound
{
public:
	sound();
	explicit sound(files * _Files);
	~sound();

	sf::Sound * Sound(const Sound_type Type);

private:
	//stock a handle to files
	files * Files;
	std::vector<sf::SoundBuffer> Buffers;
	std::vector<sf::Sound> Sounds;

	const sf::String Files_name[4] = {"match.ogg", "musique.ogg", "retourne.ogg", "victoire.ogg"};
};

