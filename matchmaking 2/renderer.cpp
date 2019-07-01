#include "renderer.h"



renderer::renderer()
{

}

renderer::renderer(sf::RenderWindow * Handle, textures * _Textures)
{
	Textures = _Textures;
	Windows = Handle;
}


renderer::~renderer()
{
}

void renderer::Add_tuile(const sf::Vector2f Position, const short Number)
{
	Rectangle(Position);
	Rectangle_database[Rectangle_database.size()-1].setSize(sf::Vector2f(128.0f, 128.0f));
	Rectangle_database[Rectangle_database.size() - 1].setTexture(Textures->Get_tuile(Number));
}

void renderer::Add_back(const sf::Vector2f Position)
{
	Rectangle(Position);
	Rectangle_database[Rectangle_database.size() - 1].setSize(sf::Vector2f(128.0f, 128.0f));
	Rectangle_database[Rectangle_database.size() - 1].setTexture(Textures->Get_back());
}

void renderer::Add_fond(const short Number)
{
	Rectangle(sf::Vector2f(0.0f, 0.0f));
	Rectangle_database[Rectangle_database.size()-1].setSize(sf::Vector2f(Width, Height));
	Texture(Number);
}

void renderer::Add_exit(const sf::Vector2f Position)
{
	Rectangle(Position);
	Rectangle_database[Rectangle_database.size()-1].setSize(sf::Vector2f(100.0f, 100.0f));
	Rectangle_database[Rectangle_database.size()-1].setTexture(Textures->Get_exit());
}

void renderer::Add_play(const sf::Vector2f Position)
{
	Rectangle(Position);
	Rectangle_database[Rectangle_database.size()-1].setSize(sf::Vector2f(100.0f, 100.0f));
	Rectangle_database[Rectangle_database.size()-1].setTexture(Textures->Get_play());
}

void renderer::Add_hover(const sf::Vector2f Position)
{
	Rectangle(Position);
	Rectangle_database[Rectangle_database.size()-1].setSize(sf::Vector2f(100.0f, 100.0f));
	Rectangle_database[Rectangle_database.size()-1].setTexture(Textures->Get_hover());
}

void renderer::Add_selection(const sf::Vector2f Position)
{
	Rectangle(Position);
	Rectangle_database[Rectangle_database.size()-1].setSize(sf::Vector2f(128.0f, 128.0f));
	Rectangle_database[Rectangle_database.size()-1].setTexture(Textures->Get_selection());
}

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

void renderer::Rectangle(const sf::Vector2f Position)
{
	sf::RectangleShape Rectangle;
	Rectangle.setPosition(Position);
	Rectangle_database.push_back(Rectangle);
}

void renderer::Rectangle(const sf::Vector2f Position, const sf::Vector2f Origin)
{
	sf::RectangleShape Rectangle;
	Rectangle.setOrigin(Origin);
	Rectangle.setPosition(Position);
	Rectangle_database.push_back(Rectangle);
}

void renderer::Scale(const sf::Vector2f Scale)
{
	Rectangle_database[Rectangle_database.size()-1].setScale(Scale);
}

void renderer::Texture(const short _ID)
{

}
