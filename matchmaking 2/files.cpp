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

void files::Mount(const sf::String File_name)
{
	Error = PHYSFS_mount(File_name.toAnsiString().c_str(), "", 1);
	Error = !Error;
	if (Error)
	{
		Set_Error(PHYSFS_getLastError());
	}
}

sf::Texture files::Get_texture(const sf::String File_name)
{
	sf::String Extension = File_name.substring(File_name.getSize() - 3, 3);
	sf::Texture Texture;

	if (File_exist(File_name))
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

	return Texture;
}

sf::Image files::Get_image(const sf::String File_name)
{
	sf::String Extension = File_name.substring(File_name.getSize() - 3, 3);
	sf::Image Image;

	if (File_exist(File_name))
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

	return Image;
}

sf::SoundBuffer files::Get_sound(const sf::String File_name)
{
	sf::String Extension = File_name.substring(File_name.getSize() - 3, 3);
	sf::SoundBuffer Sound_buffer;

	if (File_exist(File_name))
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

	return Sound_buffer;
}

sf::Font files::Get_font(const sf::String File_name)
{
	sf::String Extension = File_name.substring(File_name.getSize() - 3, 3);
	sf::Font Font;

	if (File_exist(File_name))
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

	return Font;
}

void files::Set_Error(const sf::String Error)
{
	Error_String = Error;
}

bool files::File_exist(const sf::String File_name)
{
	if (PHYSFS_exists(File_name.toAnsiString().c_str()))
	{
		return true;
	}
	else
	{
		sf::String Error_text = "file not found: " + File_name;
		Set_Error(Error_text);
		return false;
	}
}
