#include "renderer.h"



renderer::renderer()
{
	Time = Horloge.now();
}

renderer::renderer(sf::RenderWindow * Handle, textures * _Textures, fonte * _Fonte)
{
	Textures = _Textures;
	Fonte = _Fonte;
	Windows = Handle;
}


renderer::~renderer()
{
}

void renderer::Add_tuile(const sf::Vector2f Position, const short Number)
{
	Rectangle(Position);
	Rectangle_database[Rectangle_database.size() - 1].setSize(sf::Vector2f(128.0f, 128.0f));
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
	Rectangle_database[Rectangle_database.size() - 1].setSize(sf::Vector2f(Width, Height));
	Rectangle_database[Rectangle_database.size() - 1].setTexture(Textures->Get_fond(Number));
}

void renderer::Add_exit(const sf::Vector2f Position)
{
	Rectangle(Position);
	Rectangle_database[Rectangle_database.size() - 1].setSize(sf::Vector2f(100.0f, 100.0f));
	Rectangle_database[Rectangle_database.size() - 1].setTexture(Textures->Get_exit());
}

void renderer::Add_play(const sf::Vector2f Position)
{
	Rectangle(Position);
	Rectangle_database[Rectangle_database.size() - 1].setSize(sf::Vector2f(100.0f, 100.0f));
	Rectangle_database[Rectangle_database.size() - 1].setTexture(Textures->Get_play());
}

void renderer::Add_hover(const sf::Vector2f Position)
{
	Rectangle(Position);
	Rectangle_database[Rectangle_database.size() - 1].setSize(sf::Vector2f(100.0f, 100.0f));
	Rectangle_database[Rectangle_database.size() - 1].setTexture(Textures->Get_hover());
}

void renderer::Add_selection(const sf::Vector2f Position)
{
	Rectangle(Position);
	Rectangle_database[Rectangle_database.size() - 1].setSize(sf::Vector2f(128.0f, 128.0f));
	Rectangle_database[Rectangle_database.size() - 1].setTexture(Textures->Get_selection());
}

void renderer::Add_score_small(const short Score)
{
	Texte = Fonte->Get_small();
	sf::String String = "nombre d'essai : " + std::to_string(Score);
	Texte.setString(String);
	Draw_text = true;
}

void renderer::Add_score_big(const short Score)
{
	Texte = Fonte->Get_big();
	sf::String String = "SCORE : " + std::to_string(Score);
	Texte.setString(String);
	Draw_text = true;
}

void renderer::Render()
{
	auto Time2 = Horloge.now();
	//permet de ne tourner qu'a 50 ips
	if ((Time2 - Time) >= std::chrono::microseconds(20000))
	{
		//on efface
		Windows->clear();

		//d'abord on dessine tuiles ou boutons
		for (int Boucle = 0; Boucle < Rectangle_database.size(); ++Boucle)
		{
			Windows->draw(Rectangle_database[Boucle]);
		}
		Rectangle_database.clear();
		//puis on dessine les animations
		if (Anim_Num_1 != -1)
		{
			Run_anim();
			for (int Boucle = 0; Boucle < Rectangle_database.size(); ++Boucle)
			{
				Windows->draw(Rectangle_database[Boucle]);
			}
			Rectangle_database.clear();
		}
		//on dessine les particules s'il y en a
		make_particles();
		//et enfin le texte
		if (Draw_text)
		{
			Windows->draw(Texte);
			Draw_text = false;
		}

		//et on affiche le tout
		Windows->display();
	}
}

void renderer::Destroy(const sf::Vector2f Position, const short Number)
{
	Destroy_positions.push_back(Position);
	Destroy_tuile_ID.push_back(Number);
	Destroy_tuile_progression.push_back(0);
	sf::Image Image = Textures->Get_Image(Number);
	sf::Texture Texture;
	Destroy_images.push_back(Image);
	Texture.loadFromImage(Destroy_images[Destroy_images.size() - 1]);
	Destroy_Textures.push_back(Texture);
	Is_destroying = true;
}

void renderer::Start_anim(const sf::Vector2f Position, const short Number, const bool Direction)
{
	Is_doing_anim = true;
	switch (Animation_ID)
	{
	case 1:
		Anim_Num_1 = Number;
		Anim_position_1 = Position;
		Set_Direction(true, Animation_ID);
		Start_Animation(Animation_ID);
		++Animation_ID;
		break;
	case 2:
		Anim_Num_2 = Number;
		Anim_position_2 = Position;
		Set_Direction(true, Animation_ID);
		Start_Animation(Animation_ID);
		break;
	}
}

void renderer::Reset_anim()
{
	Anim_Num_1 = Anim_Num_2 = -1;
	Animation_ID = 1;
	Anim_reverse_1 = Anim_reverse_2 = false;
}

const bool renderer::Is_Anim_End()
{
	return !Is_doing_anim;
}

void renderer::make_particles()
{
	if (Is_destroying)
	{
		sf::RectangleShape Rectangle;
		
		for (short Boucle = 0; Boucle < Destroy_images.size(); ++Boucle)
		{
			if (Destroy_tuile_progression[Boucle] < Destroy_images[Boucle].getSize().y)
			{
				for (unsigned int X = 0; X < Destroy_images[Boucle].getSize().x; ++X)
				{
					Pixel newPixel;
					newPixel.create();
					newPixel.setcolor(Destroy_images[Boucle].getPixel(X, Destroy_tuile_progression[Boucle]));
					newPixel.setpos(sf::Vector2u(X + (unsigned int)Destroy_positions[Boucle].x, Destroy_tuile_progression[Boucle] + (unsigned int)Destroy_positions[Boucle].y));
					newPixel.setspeed();
					newPixel.setdirection();
					Pixels.push_back(newPixel);
					Destroy_images[Boucle].setPixel(X, Destroy_tuile_progression[Boucle], sf::Color::Transparent);
				}
				Destroy_tuile_progression[Boucle] += 1;
			}
		}
		for (short Boucle = 0; Boucle < Destroy_Textures.size(); ++Boucle)
		{
			Rectangle.setPosition(Destroy_positions[Boucle]);
			Rectangle.setSize(sf::Vector2f(128.0f, 128.0f));
			Destroy_Textures[Boucle].update(Destroy_images[Boucle]);
			Rectangle.setTexture(&Destroy_Textures[Boucle]);
			Windows->draw(Rectangle);
		}

		if (!Pixels.empty())
		{
			sf::VertexArray vertexarray(sf::Points);
			for (std::size_t Boucle = Pixels.size(); Boucle > 0; Boucle--)
			{
				if (Pixels[Boucle - 1].alive())
				{
					Pixels[Boucle - 1].move();
					sf::Vertex vertex;
					vertex.color = Pixels[Boucle - 1].getcolor();
					vertex.position = Pixels[Boucle - 1].getpos();
					vertexarray.append(vertex);
				}
				else
				{
					Pixels.erase(Pixels.cbegin() + (Boucle - 1));
				}
			}
			Windows->draw(vertexarray);
		}
		else
		{
			Destroy_positions.clear();
			Destroy_tuile_ID.clear();
			Destroy_tuile_progression.clear();
			Destroy_images.clear();
			Destroy_Textures.clear();
			Is_destroying = false;
		}
		Time = Horloge.now();
	}
}

void renderer::Stop_anim()
{
	Is_doing_anim = false;
}

void renderer::Run_anim()
{
	Do_animation();
	if (Get_Statut(1) == animation_statut::fini)
	{
		if (!Anim_reverse_1)
		{
			Reverse_anim(1);
		}
		else
		{
			Rectangle(sf::Vector2f(Anim_position_1.x + 64.0f, Anim_position_1.y + 64.0f));
			Rectangle_database[Rectangle_database.size() - 1].setScale(sf::Vector2f(1.0f, Get_Scale(1)));
			Rectangle_database[Rectangle_database.size() - 1].setSize(sf::Vector2f(128.0f, 128.0f));
			Rectangle_database[Rectangle_database.size() - 1].setOrigin(64.0f, 64.0f);
			Rectangle_database[Rectangle_database.size() - 1].setTexture(Textures->Get_tuile(Anim_Num_1));
		}
	}
	else
	{
		Rectangle(sf::Vector2f(Anim_position_1.x + 64.0f, Anim_position_1.y + 64.0f));
		Rectangle_database[Rectangle_database.size() - 1].setScale(sf::Vector2f(1.0f, Get_Scale(1)));
		Rectangle_database[Rectangle_database.size() - 1].setSize(sf::Vector2f(128.0f, 128.0f));
		Rectangle_database[Rectangle_database.size() - 1].setOrigin(64.0f, 64.0f);
		if (!Anim_reverse_1)
		{
			Rectangle_database[Rectangle_database.size() - 1].setTexture(Textures->Get_back());
		}
		else
		{
			Rectangle_database[Rectangle_database.size() - 1].setTexture(Textures->Get_tuile(Anim_Num_1));
		}
	}
	if (Anim_Num_2 != -1)
	{
		if (Get_Statut(2) == animation_statut::fini)
		{
			if (!Anim_reverse_2)
			{
				Reverse_anim(2);
			}
			else
			{
				Rectangle(sf::Vector2f(Anim_position_1.x + 64.0f, Anim_position_1.y + 64.0f));
				Rectangle_database[Rectangle_database.size() - 1].setScale(sf::Vector2f(1.0f, Get_Scale(1)));
				Rectangle_database[Rectangle_database.size() - 1].setSize(sf::Vector2f(128.0f, 128.0f));
				Rectangle_database[Rectangle_database.size() - 1].setOrigin(64.0f, 64.0f);
				Rectangle_database[Rectangle_database.size() - 1].setTexture(Textures->Get_tuile(Anim_Num_1));
				Stop_anim();
			}
		}
		else
		{
			Rectangle(sf::Vector2f(Anim_position_2.x + 64.0f, Anim_position_2.y + 64.0f));
			Rectangle_database[Rectangle_database.size() - 1].setScale(sf::Vector2f(1.0f, Get_Scale(2)));
			Rectangle_database[Rectangle_database.size() - 1].setSize(sf::Vector2f(128.0f, 128.0f));
			Rectangle_database[Rectangle_database.size() - 1].setOrigin(64.0f, 64.0f);
			if (!Anim_reverse_2)
			{
				Rectangle_database[Rectangle_database.size() - 1].setTexture(Textures->Get_back());
			}
			else
			{
				Rectangle_database[Rectangle_database.size() - 1].setTexture(Textures->Get_tuile(Anim_Num_2));
			}
		}
	}
}

void renderer::Reverse_anim(const short _ID)
{
	switch (_ID)
	{
	case 1:
		Anim_reverse_1 = true;
		Set_Direction(false, 1);
		Start_Animation(1);
		break;
	case 2:
		Anim_reverse_2 = true;
		Set_Direction(false, 2);
		Start_Animation(2);
		break;
	}
}

void renderer::Rectangle(const sf::Vector2f Position)
{
	sf::RectangleShape Rectangle;
	Rectangle.setPosition(Position);
	Rectangle_database.push_back(Rectangle);
}
