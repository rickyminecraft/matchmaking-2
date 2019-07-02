#pragma once

#include "animation_stats.h"
class animation
{
public:
	animation();
	~animation();

	//up = true, down = false
	void Set_Direction(const bool Direction, const short _ID);
	void Start_Animation(const short _ID);
	void Do_animation();
	const float Get_Scale(const short _ID);
	const bool Get_Direction(const short _ID);
	const animation_statut Get_Statut(const short _ID);

private:
	float Rotation_1, Rotation_2;
	animation_statut Stats_1, Stats_2;
	bool Direction_1, Direction_2;
};

