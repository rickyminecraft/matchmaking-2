#include "matchmaking.h"

matchmaking::matchmaking()
{
	Statut = game_stats::Init;
	Resolution = sf::VideoMode(Width, Height);
	Windows = std::make_unique<sf::RenderWindow>(Resolution, Application_name, sf::Style::Close);
	Rinstance = std::make_unique<renderer>(Windows.get());
	Sound = std::make_unique<sound>();
}


matchmaking::~matchmaking()
{
}

bool matchmaking::Run()
{
	sf::Event event; //sf::Sprite test2; //sf::Sound* mtest = new (sf::Sound); sf::Image image; sf::Text texte;

	while (Is_running)
	{
		Windows->pollEvent(event);
		switch (Statut)
		{
		case game_stats::Init:
			
			//Load("01.jpg");
			//Load("02.jpg");
			//printf(Get_error().toAnsiString().c_str());
			//Load("musique.ogg");
			//Load("arial.ttf");

			//short ID;
			//ID = Get_ID_for_name("02.jpg");
			//image = Get_image(ID);
			//test2.setTexture(*Get_texture(ID));
			//ID = Get_ID_for_name("musique.ogg");
			//mtest= 
				//Get_sound(ID)->play();
			//ID = Get_ID_for_name("arial.ttf");
			//	texte.setFont(*Get_font(ID));
			//	texte.setOutlineColor(sf::Color::Black);
			//	texte.setFillColor(sf::Color::Red);
			//	texte.setStyle(sf::Text::Regular);
			//	texte.setOutlineThickness(1.0f);
			//	texte.setCharacterSize(20);
			//	texte.setPosition(sf::Vector2f(30.0f, 30.0f));
			//	texte.setString("bonjour");
			Tiles.Reset();
			Statut = game_stats::Main;
			break;
		case game_stats::Main:
			switch (event.type)
			{
			case sf::Event::Closed:
				Is_running = false;
				break;
			}
			break;
		case game_stats::Play:
			break;
		case game_stats::Win:
			break;
		case game_stats::Next:
			break;
		case game_stats::Exit:
			Is_running = false;
			break;
		}
		//if (mtest->getStatus() == sf::SoundSource::Stopped)
		//{
		//	mtest->play();
		//}
		//Windows.get()->clear();
		//Windows.get()->draw(test2);
		//Windows.get()->draw(texte);
		//Windows.get()->display();
		//Rinstance->Draw(test);
		Rinstance->Render();

	}

	return false;
}
