#include "matchmaking.h"

matchmaking::matchmaking()
{
	Statut = game_stats::Init;
	Resolution = sf::VideoMode(Width, Height);
	Windows = std::make_unique<sf::RenderWindow>(Resolution, Application_name, sf::Style::Close);

	Files = std::make_unique<files>();
	Sound = std::make_unique<sound>(Files.get());
	Texture = std::make_unique<textures>(Files.get());
	Renderer = std::make_unique<renderer>(Windows.get(), Texture.get());
}


matchmaking::~matchmaking()
{
}

bool matchmaking::Run()
{
	sf::Event event; 
	//sf::Sprite test; 
	//sf::Sound mtest; 
	//sf::Image image; 
	//sf::Text texte;

	while (Is_running)
	{
		Windows->pollEvent(event);
		switch (Statut)
		{
		case game_stats::Init:
			
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
			//mtest = Sound.get()->Sound(Sound_type::musique);
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
		/*if (mtest.getStatus() == sf::SoundSource::Stopped)
		{
			mtest.play();
		}*/
		//Rinstance->Draw(test);
		Renderer->Render();

	}

	return false;
}
