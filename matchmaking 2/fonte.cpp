#include "fonte.h"



fonte::fonte()
{
}

fonte::fonte(files * _Files)
{
	Files = _Files;
	Fonte = Files->Get_font("arial.ttf");
	Text_1.setFont(Fonte);
	Text_1.setOutlineColor(sf::Color::Black);
	Text_1.setFillColor(sf::Color::Red);
	Text_1.setStyle(sf::Text::Regular);
	Text_1.setOutlineThickness(1.0f);
	Text_1.setCharacterSize(20);
	Text_1.setPosition(sf::Vector2f(30.0f, 30.0f));
	Text_2.setFont(Fonte);
	Text_2.setOutlineColor(sf::Color::Black);
	Text_2.setFillColor(sf::Color::Transparent);
	Text_2.setStyle(sf::Text::Regular);
	Text_2.setOutlineThickness(2.0f);
	Text_2.setCharacterSize(150);
	Text_2.setPosition(sf::Vector2f(80.0f, 300.0f));
}


fonte::~fonte()
{
}

sf::Text fonte::Get_small()
{
	return Text_1;
}

sf::Text fonte::Get_big()
{
	return Text_2;
}
