#include "animation.h"



animation::animation()
{
}


animation::~animation()
{
}

void animation::Set_Direction(const bool Direction, const short _ID)
{
	switch (_ID)
	{
	case 1:
		Direction_1 = Direction;
		break;
	case 2:
		Direction_2 = Direction;
		break;
	}
}

void animation::Start_Animation(const short _ID)
{
	switch (_ID)
	{
	case 1:
		switch (Direction_1)
		{
		case true:
			Rotation_1 = 1.0f;
			break;
		case false:
			Rotation_1 = 0.0f;
			break;
		}
		
		Stats_1 = animation_statut::en_cours;
		break;
	case 2:
		switch (Direction_1)
		{
		case true:
			Rotation_2 = 1.0f;
			break;
		case false:
			Rotation_2 = 0.0f;
			break;
		}
		Stats_2 = animation_statut::en_cours;
		break;
	}
}

void animation::Do_animation()
{
	switch (Direction_1)
	{
	case true:
		if (Rotation_1 > 0.0f)
		{
			Rotation_1 -= 0.002f;
		}
		else
		{
			Stats_1 = animation_statut::fini;
		}
		break;
	case false:
		if (Rotation_1 < 1.0f)
		{
			Rotation_1 += 0.002f;
		}
		else
		{
			Stats_1 = animation_statut::fini;
		}
		break;
	}

	switch (Direction_2)
	{
	case true:
		if (Rotation_2 > 0.0f)
		{
			Rotation_2 -= 0.002f;
		}
		else
		{
			Stats_2 = animation_statut::fini;
		}
		break;
	case false:
		if (Rotation_2 < 1.0f)
		{
			Rotation_2 += 0.002f;
		}
		else
		{
			Stats_2 = animation_statut::fini;
		}
		break;
	}
}

const float animation::Get_Scale(const short _ID)
{
	switch (_ID)
	{
	case 1:
		return Rotation_1;
	case 2:
		return Rotation_2;
	}
	return 0.0f;
}

const bool animation::Get_Direction(const short _ID)
{
	switch (_ID)
	{
	case 1:
		return Direction_1;
	case 2:
		return Direction_2;
	}
	return false;
}

const animation_statut animation::Get_Statut(const short _ID)
{
	switch (_ID)
	{
	case 1:
		return Stats_1;
	case 2:
		return Stats_2;
	}
	return animation_statut::fini;
}
