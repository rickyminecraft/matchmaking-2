#pragma once

#include <SFML/Graphics.hpp>

#include "animation_stats.h"
class animation
{
public:
	animation();
	~animation();

	//haut = true, bas = false
	void Set_Direction(const bool Direction, const short _ID);
	//demarre l'animation
	void Start_Animation(const short _ID);
	//fait avancer l'animation
	void Do_animation();
	//recupere l'echelle en y
	const float Get_Scale(const short _ID);
	//recupere le statut, fini ? non fini ?
	const animation_statut Get_Statut(const short _ID);

protected:
	short Anim_Num_1 = -1, Anim_Num_2 = -1;
	sf::Vector2f Anim_position_1, Anim_position_2;
	bool Anim_reverse_1 = false, Anim_reverse_2 = false;

private:
	float Rotation_1, Rotation_2;
	animation_statut Stats_1, Stats_2;
	bool Direction_1, Direction_2;
	//en version release, trop rapide avec les valeurs debug
	bool debug = false;
};

