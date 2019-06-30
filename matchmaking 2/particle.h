#pragma once

#include <random>

#include <SFML/Graphics.hpp>

struct Animpixels
{
	void create()
	{
		std::random_device r;
		std::default_random_engine engine(r());
		std::uniform_int_distribution<int> uniform_dist(5, 30);
		live = uniform_dist(engine);
	}

	void move()
	{
		pos.x += direction.x;
		pos.y += direction.y;
	}

	bool alive()
	{
		--live;

		if (live)
		{
			return true;
		}
		return false;
	}

	void setspeed()
	{
		std::random_device r;
		std::default_random_engine engine(r());
		std::uniform_real_distribution<float> uniform_dist(1.0f, 1.5f);
		speed = uniform_dist(engine);
	}

	void setdirection()
	{
		std::random_device r;
		std::default_random_engine engine(r());
		std::uniform_real_distribution<float> uniform_dist(75.0f, 85.0f);
		float rotation = uniform_dist(engine);
		float angle = rotation * 3.14f / 180.f;
		direction.x = cos(angle) * speed;
		direction.y = sin(angle) * speed;
	}

	void setpos(sf::Vector2u positioni)
	{
		pos.x = (float)positioni.x;
		pos.y = (float)positioni.y;
	}

	void setcolor(sf::Color couleur)
	{
		couleurp = couleur;
	}

	sf::Vector2f getpos()
	{
		return pos;
	}

	sf::Color getcolor()
	{
		return couleurp;
	}
private:
	sf::Color couleurp;
	sf::Vector2f pos;
	sf::Vector2f direction;
	short live = 0;
	float speed = 0;
};