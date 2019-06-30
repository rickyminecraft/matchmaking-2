#include "textures.h"



textures::textures()
{
	/*for (auto Names : Fonds_name)
	{
		Load(Names);
	}
	for (auto Names : Tuiles_name)
	{
		Load(Names);
	}
	Load(Selection);
	Load(Tuile_back);
	Load(Exit);
	Load(Play);*/
	Textures.push_back(Get_texture(Exit_name));

	sf::Image image_hover;
	image_hover.create(100, 100, sf::Color::Red);
	hover.loadFromImage(image_hover);
}


textures::~textures()
{
}

//sf::Texture * textures::Get_Texture(Type Texture_Type, short IDs)
//{
	//switch (Texture_Type)
	//{
	//case Type::Back:
	//	short ID = Get_ID_for_name(Tuile_back);
	//	return Get_texture(ID);
	//	break;
	//case Type::Exit:
	//	short ID = Get_ID_for_name(Exit);
	//	return Get_texture(ID);
	//	break;
	//case Type::Fond:
	//	short ID_texture = Get_ID_for_name(Fonds_name[IDs]);
	//	return Get_texture(ID_texture);
	//	break;
	//case Type::Hover:
	//	return &hover;
	//	break;
	//case Type::Play:
	//	short ID = Get_ID_for_name(Play);
	//	return Get_texture(ID);
	//	break;
	//case Type::Selection:
	//	short ID = Get_ID_for_name(Selection);
	//	return Get_texture(ID);
	//	break;
	//case Type::Tuile:
	//	short ID_texture = Get_ID_for_name(Tuiles_name[IDs]);
	//	return Get_texture(ID_texture);
	//	break;
	//}
//	return nullptr;
//}

sf::Image textures::Get_Image(short ID)
{
	short ID_image = Get_ID_for_name(Tuiles_name[ID]);
	return Get_image(ID_image);
}
