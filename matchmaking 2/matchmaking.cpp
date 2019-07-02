#include "matchmaking.h"

matchmaking::matchmaking()
{
	Statut = game_stats::Init;
	Resolution = sf::VideoMode(Width, Height);
	Windows = std::make_unique<sf::RenderWindow>(Resolution, Application_name, sf::Style::Close);

	Files = std::make_unique<files>();
	Sound = std::make_unique<sound>(Files.get());
	Texture = std::make_unique<textures>(Files.get());
	Fonte = std::make_unique<fonte>(Files.get());
	Renderer = std::make_unique<renderer>(Windows.get(), Texture.get(), Fonte.get());
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
	//pour compter les tuiles retourné
	//les 2 numero de tuiles a comparer
	short Click = 0, Retourne = 0, Un, Deux;

	while (Is_running)
	{
		Windows->pollEvent(event);
		switch (Statut)
		{
		case game_stats::Init:
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
			//si on est au dessus d'un bouton
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
			if (time2 - time >= std::chrono::milliseconds(100))
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
			//ajoute le fond
			Renderer->Add_fond(Fond);

			//puis les tuiles 
			for (short Boucle = 0; Boucle < 48; ++Boucle)
			{
				//si la tuile actuel n'est pas deja enlever
				if (!Tiles.Is_done(Boucle))
				{
					//si on a choisit une tuile
					if (do_select)
					{
						//si on est dedans la tuile actuel
						if (Tuiles[Boucle].Is_inside(Position_click))
						{
							//evite de retourner plus de 2 tuiles
							if (Retourne < 2)
							{
								//on signal que l'on a choisit cette tuile
								Tuiles[Boucle].Select();
								switch (Retourne)
								{
								case 0:
									++Retourne;
									Un = Boucle;
									Renderer->Start_anim(Tuiles[Boucle].Get_Position(), Tiles.Get(Un), true);
									Sound.get()->Sound(Sound_type::retourne)->play();
									break;
								case 1:
									//evite que le jeu considere que l'on click 2 fois sur la meme tuile
									if (Un == Boucle)
										break;
									++Retourne;
									Deux = Boucle;
									Renderer->Start_anim(Tuiles[Boucle].Get_Position(), Tiles.Get(Deux), true);
									Sound.get()->Sound(Sound_type::retourne)->play();
									time = horloge.now();
									break;
								}
								do_select = false;
							}
						}
					}

					//si la tuile est choisit
					if (Tuiles[Boucle].Is_select())
					{
						if (Renderer->Is_Anim_End())
						{
							Renderer->Add_tuile(Tuiles[Boucle].Get_Position(), Tuiles[Boucle].Get_ID());
						}
					}
					else
					{
						//on affiche l'arriere
						Renderer->Add_back(Tuiles[Boucle].Get_Position());
						//et si on est dedans, on affiche le ? de selection
						if (Tuiles[Boucle].Is_inside(Position_actuel))
						{
							Renderer->Add_selection(Tuiles[Boucle].Get_Position());
						}
					}
				}
				//affiche le score en petit
				Show_score(false);
				
				time2 = horloge.now();
				//si on a choisit 2 tuiles, on attend d'abord une demi-seconde
				if (Retourne == 2 && time2 - time >= std::chrono::milliseconds(500))
				{
					//on incremente le nombre d'essai
					++Essai;
					//et si elle sont d'égal
					if (Tiles.Get(Un) == Tiles.Get(Deux))
					{
						Tiles.Done(Un);
						Tiles.Done(Deux);
						Renderer->Destroy(Tuiles[Un].Get_Position(), Tiles.Get(Un));
						Renderer->Destroy(Tuiles[Deux].Get_Position(), Tiles.Get(Deux));
						Sound.get()->Sound(Sound_type::pair)->play();
					}
					//dans tout les cas, on les remet a l'etat par defaut
					//sera utile pour la suite
					Tuiles[Un].Unselect();
					Tuiles[Deux].Unselect();
					//et on remet le nombre de tuiles retourner a zero
					Retourne = 0;
					Renderer->Reset_anim();
				}
			}

			//quand on a tout retourner
			if (Tiles.Is_all_done())
			{
				//si on gagne, joue un son
				Sound.get()->Sound(Sound_type::victoire)->play();
				Statut = game_stats::Win;
			}
			break;
		case game_stats::Win: //quand on a fini de retourner toutes les tuiles
			//attend que la musique finisse
			if (Sound.get()->Sound(Sound_type::victoire)->getStatus() != sf::SoundSource::Playing)
			{
				Statut = game_stats::Next;
			}
			//ajoute le fond
			Renderer->Add_fond(Fond);
			//affiche le score en gros
			Show_score(true);
			break;
		case game_stats::Next: //pour changer le fond et renouveler les tuiles
			Tiles.Reset();
			for (short y = 0; y < 6; ++y)
			{
				for (short x = 0; x < 8; ++x)
				{
					Tuiles[x + (8 * y)].Set_ID(Tiles.Get(x + (8 * y)));
				}
			}
			Essai = 0;
			++Fond;
			if (Fond == 17)
			{
				Fond = 0;
			}
			Statut = game_stats::Play;
			break;
		case game_stats::Exit: //quitte le jeu
			Is_running = false;
			break;
		}
		//musique de fond qui tourne en boucle
		if (Sound.get()->Sound(Sound_type::musique)->getStatus() == sf::SoundSource::Stopped)
		{
			Sound.get()->Sound(Sound_type::musique)->play();
		}

		Renderer->Render();

	}

	return true;
}

void matchmaking::Show_score(bool Big)
{
	switch (Big)
	{
	case true:
		Renderer->Add_score_big(Essai);
		break;
	case false:
		Renderer->Add_score_small(Essai);
		break;
	}
}
