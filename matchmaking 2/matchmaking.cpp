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

	short count = 0;

	while (Is_running)
	{
		Windows->pollEvent(event);
		switch (Statut)
		{
		case game_stats::Init:
			
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
				Statut = game_stats::Exit;
				break;
			case sf::Event::MouseButtonPressed:
				if (count == 0)
				{
					
				}
				count++;
				break;
			case sf::Event::MouseButtonReleased:
				count = 0;
				break;
			case sf::Event::MouseMoved:
				
				break;
			}
			break;
		case game_stats::Play:
			switch (event.type)
			{
			case sf::Event::Closed:
				Statut = game_stats::Exit;
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
				{
					Statut = game_stats::Main;
				}
				break;
			case sf::Event::MouseButtonPressed:
				if (count == 0)
				{

				}
				count++;
				break;
			case sf::Event::MouseButtonReleased:
				count = 0;
				break;
			case sf::Event::MouseMoved:

				break;
			}
			break;
		case game_stats::Win:
			//si on gagne, joue un son
			Sound.get()->Sound(Sound_type::victoire);
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
		Renderer->Render();

	}

	return true;
}
