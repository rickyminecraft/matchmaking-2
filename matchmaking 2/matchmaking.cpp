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

	//la position actuel
	//la position du click de la souris
	sf::Vector2f Position_actuel, Position_click;
	//pour eviter les repetition de clic
	//pour compter les tuiles retourn�
	short Click = 0, Retourne = 0, Un, Deux;

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

			Tuiles.resize(48);
			for (short y = 0; y < 6; ++y)
			{
				for (short x = 0; x < 8; ++x)
				{
					Tuiles[x + (8 * y)].Set_position(sf::Vector2f((float)(x * 128), (float)(y * 128)));
					Tuiles[x + (8 * y)].Set_size(sf::Vector2f(128.0f, 128.0f));
					Tuiles[x + (8 * y)].Set_ID(Tiles.Get(x + (8 * y)));
				}
			}

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
				if (Play.Is_inside(sf::Vector2f((float)event.mouseButton.x, (float)event.mouseButton.y)))
				{
					Statut = game_stats::Readyplay;
					time = horloge.now();
				}
				if (Exit.Is_inside(sf::Vector2f((float)event.mouseButton.x, (float)event.mouseButton.y)))
				{
					Statut = game_stats::Exit;
				}
				break;
			case sf::Event::MouseMoved:
				if (Play.Is_inside(sf::Vector2f((float)event.mouseMove.x, (float)event.mouseMove.y)))
				{
					Hover.Set_position(Play.Get_Position());
					Is_hover = true;
				}
				if (Exit.Is_inside(sf::Vector2f((float)event.mouseMove.x, (float)event.mouseMove.y)))
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
		case game_stats::Readyplay:
			//laisse un peut de temps pour vider le pool d'event
			time2 = horloge.now();
			if (time2 - time >= std::chrono::milliseconds(200))
			{
				Statut = game_stats::Play;
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
				if (Click == 0)
				{
					Position_actuel = sf::Vector2f((float)event.mouseButton.x, (float)event.mouseButton.y);
					Position_click = Position_actuel;
					do_select = true;
				}
				Click++;
				break;
			case sf::Event::MouseButtonReleased:
				Click = 0;
				break;
			case sf::Event::MouseMoved:
				Position_actuel = sf::Vector2f((float)event.mouseMove.x, (float)event.mouseMove.y);
				break;
			}

			for (short Boucle = 0; Boucle < 48; ++Boucle)
			{
				if (do_select)
				{
					if (Tuiles[Boucle].Is_inside(Position_click))
					{
						Tuiles[Boucle].Select();
						switch (Retourne)
						{
						case 0:
							++Retourne;
							Un = Boucle;
							break;
						case 1:
							++Retourne;
							Deux = Boucle;
							time = horloge.now();
							break;
						}
						do_select = false;
					}
				}

				if (Tuiles[Boucle].Is_select())
				{
					Renderer->Add_tuile(Tuiles[Boucle].Get_Position(), Tuiles[Boucle].Get_ID());
				}
				else
				{
					Renderer->Add_back(Tuiles[Boucle].Get_Position());
					if (Tuiles[Boucle].Is_inside(Position_actuel))
					{
						Renderer->Add_selection(Tuiles[Boucle].Get_Position());
					}
				}

				time2 = horloge.now();
				if (Retourne == 2 && time2 - time >= std::chrono::seconds(1))
				{
					if (Tiles.Get(Un) == Tiles.Get(Deux))
					{
						Tiles.Done(Un);
						Tiles.Done(Deux);
					}
					else
					{
						Tuiles[Un].Unselect();
						Tuiles[Deux].Unselect();
					}
					Retourne = 0;
				}
			}

			if (Tiles.Is_all_done())
			{
				Statut = game_stats::Win;
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
