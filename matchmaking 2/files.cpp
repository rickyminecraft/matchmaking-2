#include "files.h"



files::files()
{
	Error = false;
	Error = PHYSFS_init(nullptr);
	//we mount the zip file at start to avoid file not found error
	Mount(Pak_name);
}


files::~files()
{
	PHYSFS_deinit();
}

const bool files::Has_error()
{
	return Error;
}

const sf::String files::Get_error()
{
	return Error_String;
}

void files::Mount(sf::String File_name)
{
	Error = PHYSFS_mount(File_name.toAnsiString().c_str(), "", 1);
	Error = !Error;
	if (Error)
	{
		Set_Error(PHYSFS_getLastError());
	}
}

//void files::Load(sf::String File_name)
//{
//	sf::String Extension = File_name.substring(File_name.getSize() - 3, 3);
//
//	if (PHYSFS_exists(File_name.toAnsiString().c_str()))
//	{
//		PHYSFS_File * File_Handle = PHYSFS_openRead(File_name.toAnsiString().c_str());
//		PHYSFS_sint64 File_size = PHYSFS_fileLength(File_Handle);
//
//		char * buffer = new char[File_size];
//		PHYSFS_readBytes(File_Handle, buffer, File_size);
//		PHYSFS_seek(File_Handle, 0);
//
//		if (Extension == "jpg" || Extension == "png")
//		{
//			int ID = (int)Texture_database.size();
//			sf::Image Image;
//			sf::Texture Texture;
//			Image.loadFromMemory(buffer, File_size);
//			Texture.loadFromImage(Image);
//			Image_database.push_back(Image);
//			Texture_database.push_back(Texture);
//			Files_database.push_back(std::make_tuple(File_name, ID));
//		}
//		if (Extension == "ogg")
//		{
//			int ID = (int)Sound_database.size();
//			sf::SoundBuffer Sound_buffer;
//			sf::Sound Sound;
//			Sound_buffer.loadFromMemory(buffer, File_size);
//			Soundbuffer_database.push_back(Sound_buffer);
//			Sound.setBuffer(Soundbuffer_database[ID]);
//			Sound_database.push_back(Sound);
//			Files_database.push_back(std::make_tuple(File_name, ID));
//		}
//		if (Extension == "ttf")
//		{
//			int ID = (int)Font_database.size();
//			sf::Font Font;
//			Font.loadFromMemory(buffer, File_size);
//			Font_database.push_back(std::make_tuple(Font, buffer));
//			Files_database.push_back(std::make_tuple(File_name, ID));
//		}
//
//		PHYSFS_close(File_Handle);
//	}
//	else
//	{
//		sf::String Error_text = "file not found: " + File_name;
//		Set_Error(Error_text);
//	}
//}

//short files::Get_ID_for_name(sf::String File_name)
//{
//	for (int Boucle = 0; Boucle < Files_database.size(); ++Boucle)
//	{
//		if (std::get<0>(Files_database[Boucle]) == File_name)
//		{
//			return std::get<1>(Files_database[Boucle]);
//		}
//	}
//	
//	return -1;
//}
//
//sf::Texture * files::Get_texture(short ID)
//{
//	return ID == -1 ? nullptr : &Texture_database[ID];
//}
//
//sf::Image files::Get_image(short ID)
//{
//	sf::Image Vide;
//	return ID == -1 ? Vide : Image_database[ID];
//}
//
//sf::Sound * files::Get_sound(short ID)
//{
//	return ID == -1 ? nullptr : &Sound_database[ID];
//}
//
//sf::Font * files::Get_font(short ID)
//{
//	return ID == -1 ? nullptr : &std::get<0>(Font_database[ID]);
//}

sf::Texture files::Get_texture(sf::String File_name)
{
	sf::String Extension = File_name.substring(File_name.getSize() - 3, 3);
	sf::Texture Texture;

	if (PHYSFS_exists(File_name.toAnsiString().c_str()))
	{
		PHYSFS_File * File_Handle = PHYSFS_openRead(File_name.toAnsiString().c_str());
		PHYSFS_sint64 File_size = PHYSFS_fileLength(File_Handle);

		char * buffer = new char[File_size];
		PHYSFS_readBytes(File_Handle, buffer, File_size);
		PHYSFS_seek(File_Handle, 0);

		if (Extension == "jpg" || Extension == "png")
		{
			sf::Image Image;
			Image.loadFromMemory(buffer, File_size);
			Texture.loadFromImage(Image);
		}

		PHYSFS_close(File_Handle);
	}
	else
	{
		sf::String Error_text = "file not found: " + File_name;
		Set_Error(Error_text);
	}
	return Texture;
}

sf::Image files::Get_image(sf::String File_name)
{
	sf::String Extension = File_name.substring(File_name.getSize() - 3, 3);
	sf::Image Image;

	if (PHYSFS_exists(File_name.toAnsiString().c_str()))
	{
		PHYSFS_File * File_Handle = PHYSFS_openRead(File_name.toAnsiString().c_str());
		PHYSFS_sint64 File_size = PHYSFS_fileLength(File_Handle);

		char * buffer = new char[File_size];
		PHYSFS_readBytes(File_Handle, buffer, File_size);
		PHYSFS_seek(File_Handle, 0);

		if (Extension == "jpg" || Extension == "png")
		{
			Image.loadFromMemory(buffer, File_size);
		}

		PHYSFS_close(File_Handle);
	}
	else
	{
		sf::String Error_text = "file not found: " + File_name;
		Set_Error(Error_text);
	}
	return Image;
}

sf::SoundBuffer files::Get_sound(sf::String File_name)
{
	sf::String Extension = File_name.substring(File_name.getSize() - 3, 3);
	sf::SoundBuffer Sound_buffer;

	if (PHYSFS_exists(File_name.toAnsiString().c_str()))
	{
		PHYSFS_File * File_Handle = PHYSFS_openRead(File_name.toAnsiString().c_str());
		PHYSFS_sint64 File_size = PHYSFS_fileLength(File_Handle);

		char * buffer = new char[File_size];
		PHYSFS_readBytes(File_Handle, buffer, File_size);
		PHYSFS_seek(File_Handle, 0);

		if (Extension == "ogg")
		{
			Sound_buffer.loadFromMemory(buffer, File_size);
		}

		PHYSFS_close(File_Handle);
	}
	else
	{
		sf::String Error_text = "file not found: " + File_name;
		Set_Error(Error_text);
	}
	return Sound_buffer;
}

sf::Font files::Get_font(sf::String File_name)
{
	sf::String Extension = File_name.substring(File_name.getSize() - 3, 3);
	sf::Font Font;

	if (PHYSFS_exists(File_name.toAnsiString().c_str()))
	{
		PHYSFS_File * File_Handle = PHYSFS_openRead(File_name.toAnsiString().c_str());
		PHYSFS_sint64 File_size = PHYSFS_fileLength(File_Handle);

		char * buffer = new char[File_size];
		PHYSFS_readBytes(File_Handle, buffer, File_size);
		PHYSFS_seek(File_Handle, 0);

		if (Extension == "ttf")
		{
			Font.loadFromMemory(buffer, File_size);
		}

		PHYSFS_close(File_Handle);
	}
	else
	{
		sf::String Error_text = "file not found: " + File_name;
		Set_Error(Error_text);
	}
	return Font;
}

void files::Set_Error(sf::String Error)
{
	Error_String = Error;
}
