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

	//recupere une texture
	sf::Texture Get_texture(const sf::String File_name);
	//recupere une image
	sf::Image Get_image(const sf::String File_name);
	//recupere un son
	sf::SoundBuffer Get_sound(const sf::String File_name);
	//recupere une fonte
	sf::Font Get_font(const sf::String File_name);
	
private:
	//monte un fichier zip
	void Mount(const sf::String);
	//met un message d'erreur
	void Set_Error(const sf::String Error);
	//le fichier existe ?
	bool File_exist(const sf::String File_name);

	const sf::String Pak_name = "matchmaking.pak";

	bool Error;
	sf::String Error_String;
};

