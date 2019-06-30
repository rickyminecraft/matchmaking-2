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

	
	//load a file
	//void Load(sf::String File_name);
	//Get the ID of a loaded file
	//short Get_ID_for_name(sf::String File_name);
	//sf::Texture * Get_texture(short ID);
	//sf::Image Get_image(short ID);
	//sf::Sound * Get_sound(short ID);
	//sf::Font * Get_font(short ID);

	sf::Texture Get_texture(sf::String File_name);
	sf::Image Get_image(sf::String File_name);
	sf::SoundBuffer Get_sound(sf::String File_name);
	sf::Font Get_font(sf::String File_name);
	
private:
	//mount a zip file
	void Mount(sf::String);
	void Set_Error(sf::String Error);

	const sf::String Pak_name = "matchmaking.zip";

	//tuple of file name and file ID
	//std::vector<std::tuple<sf::String, short>> Files_database;
	//vector of soundbuffer & sound, Same ID
	//std::vector<sf::SoundBuffer> Soundbuffer_database;
	//std::vector<sf::Sound> Sound_database;

	//tuple of font and a pointer to memory buffer
	//std::vector<std::tuple<sf::Font, char *>> Font_database;
	//vector of texture & image, same ID
	//std::vector<sf::Texture> Texture_database;
	//std::vector<sf::Image> Image_database;

	bool Error;
	sf::String Error_String;
};

