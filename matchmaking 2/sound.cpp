#include "sound.h"



sound::sound()
{
	
}

sound::sound(files * _Files)
{
	Files = _Files;
	for (auto Name : Files_name)
	{
		Buffers.push_back(Files->Get_sound(Name));
	}
	for (auto Boucle : { 0,1,2,3 })
	{
		sf::Sound Sound;
		Sound.setBuffer(Buffers[Boucle]);
		Sounds.push_back(Sound);
	}
}


sound::~sound()
{
}

sf::Sound sound::Sound(Sound_type Type)
{
	switch (Type)
	{
	case Sound_type::musique:
		return Sounds[1];
		break;
	case Sound_type::pair:
		return Sounds[0];
		break;
	case Sound_type::retourne:
		return Sounds[2];
		break;
	case Sound_type::victoire:
		return Sounds[3];
		break;
	}
	return sf::Sound();
}
