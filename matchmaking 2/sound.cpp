#include "sound.h"



sound::sound()
{
	for (auto Name : Files_name)
	{
		Buffers.push_back(Get_sound(Name));
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
