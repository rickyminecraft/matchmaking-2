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
