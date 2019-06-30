#include "renderer.h"



renderer::renderer()
{

}

renderer::renderer(sf::RenderWindow * Handle)
{
	Windows = Handle;
}


renderer::~renderer()
{
}

void renderer::set_window_handle(sf::RenderWindow * Handle)
{
	Windows = Handle;
}

//renderer renderer::Add(sf::Vector2f Position, sf::Vector2f Origin, Type Texture_type, sf::Vector2f Scale1, short Number)
//{
//	Rectangle(Position, Origin);
//	Scale(Scale1);
//	Texture(Texture_type, Number);
//	return *this;
//}

void renderer::Render()
{
	Windows->clear();

	for (int Boucle = 0; Boucle < Rectangle_database.size(); ++Boucle)
	{
		Windows->draw(Rectangle_database[Boucle]);
	}
	Rectangle_database.clear();
	Windows->display();
}

void renderer::Rectangle(sf::Vector2f Position, sf::Vector2f Origin)
{
	sf::RectangleShape Rectangle;
	Rectangle.setOrigin(Origin);
	Rectangle.setPosition(Position);
	Rectangle_database.push_back(Rectangle);
}

void renderer::Scale(sf::Vector2f Scale)
{
	Rectangle_database[Rectangle_database.size()].setScale(Scale);
}

//renderer renderer::Texture(Type Texture_type, short ID)
//{
	//Rectangle_database[Rectangle_database.size()].getTexture;
//	return *this;
//}
