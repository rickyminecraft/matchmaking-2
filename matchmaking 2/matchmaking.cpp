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

	//pour eviter les repetition de clic
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
			Tiles.Reset();
			Play.Set_position(sf::Vector2f(400.0f, 334.0f));
			Play.Set_size(sf::Vector2f(100.0f, 100.0f));
			Exit.Set_position(sf::Vector2f(524.0f, 334.0f));
			Exit.Set_size(sf::Vector2f(100.0f, 100.0f));
			Hover.Set_size(sf::Vector2f(100.0f, 100.0f));
			Statut = game_stats::Main;
			break;
		case game_stats::Main:
			bool Is_hover;
			Is_hover = false;
			switch (event.type)
			{
			case sf::Event::Closed:
				Statut = game_stats::Exit;
				break;
			case sf::Event::MouseButtonPressed:
				if (count == 0)
				{
					if (Play.is_inside(sf::Vector2f((float)event.mouseButton.x, (float)event.mouseButton.y)))
					{
						Statut = game_stats::Play;
					}
					if (Exit.is_inside(sf::Vector2f((float)event.mouseButton.x, (float)event.mouseButton.y)))
					{
						Statut = game_stats::Exit;
					}
				}
				count++;
				break;
			case sf::Event::MouseButtonReleased:
				count = 0;
				break;
			case sf::Event::MouseMoved:
				if (Play.is_inside(sf::Vector2f((float)event.mouseMove.x, (float)event.mouseMove.y)))
				{
					Hover.Set_position(Play.Get_Position());
					Is_hover = true;
				}
				if (Exit.is_inside(sf::Vector2f((float)event.mouseMove.x, (float)event.mouseMove.y)))
				{
					Hover.Set_position(Exit.Get_Position());
					Is_hover = true;
				}
				break;
			}
			if (Is_hover)
			{
				Renderer->Add_hover(Hover.Get_Position());
			}
			Renderer->Add_play(Play.Get_Position());
			Renderer->Add_exit(Exit.Get_Position());
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
			Sound.get()->Sound(Sound_type::victoire)->play();
			Tiles.Reset();
			//do something
			Statut = game_stats::Next;
			break;
		case game_stats::Next:
			//do something
			Statut = game_stats::Play;
			break;
		case game_stats::Exit:
			Is_running = false;
			break;
		}
		//musique de fond
		if (Sound.get()->Sound(Sound_type::musique)->getStatus() == sf::SoundSource::Stopped)
		{
			Sound.get()->Sound(Sound_type::musique)->play();
		}

		Renderer->Render();

	}

	return true;
}
