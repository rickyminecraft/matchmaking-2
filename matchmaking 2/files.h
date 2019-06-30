#pragma once

#include <vector>
#include <tuple>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <physfs.h>

class files
{
public:
	files();
	~files();

	const bool Has_error();
	const sf::String Get_error();

	sf::Texture Get_texture(sf::String File_name);
	sf::Image Get_image(sf::String File_name);
	sf::SoundBuffer Get_sound(sf::String File_name);
	sf::Font Get_font(sf::String File_name);
	
private:
	//mount a zip file
	void Mount(sf::String);
	void Set_Error(sf::String Error);

	const sf::String Pak_name = "matchmaking.zip";

	bool Error;
	sf::String Error_String;
};

