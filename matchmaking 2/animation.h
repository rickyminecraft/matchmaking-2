#pragma once

#include <SFML/Graphics.hpp>

#include "animation_stats.h"
class animation
{
public:
	animation();
	~animation();

	//haut = true, bas = false
	void Set_Direction(const bool _Direction, const short _ID);
	//demarre l'animation
	void Start_Animation();
	//fait avancer l'animation
	void Do_animation();
	//recupere l'echelle en y
	const float Get_Scale(const short _ID);
	//recupere le statut, fini ? non fini ?
	const animation_statut Get_Statut(const short _ID);

protected:
	std::vector<short> Anim_Num;
	std::vector<sf::Vector2f> Anim_position;
	std::vector<bool> Anim_direction;

private:
	std::vector<float> Rotation;
	std::vector<animation_statut> Stats;
	std::vector<bool> Direction;
};

