#include "animation.h"



animation::animation()
{
	Rotation.resize(2);
	Stats.resize(2);
	Direction.resize(2);
}


animation::~animation()
{
}

void animation::Set_Direction(const bool _Direction, const short _ID)
{
	Direction[_ID] = _Direction;
	Stats[_ID] = animation_statut::en_cours;
}

void animation::Start_Animation()
{
	for (short Boucle = 0; Boucle < Anim_Num.size(); ++Boucle)
	{
		if (Get_Statut(Boucle) != animation_statut::fini)
		{
			switch (Direction[Boucle])
			{
			case true:
				Rotation[Boucle] = 1.0f;
				Stats[Boucle] = animation_statut::en_cours;
				break;
			case false:
				Rotation[Boucle] = 0.0f;
				Stats[Boucle] = animation_statut::en_cours;
				break;
			}
		}
	}
}

void animation::Do_animation()
{
	for (short Boucle = 0; Boucle < Anim_Num.size(); ++Boucle)
	{
		if (Get_Statut(Boucle) != animation_statut::fini)
		{
			switch (Direction[Boucle])
			{
			case true:
				if (Rotation[Boucle] > 0.0f)
				{
					Rotation[Boucle] -= 0.1f;
				}
				else
				{
					Stats[Boucle] = animation_statut::_retourne;
				}
				break;
			case false:
				if (Rotation[Boucle] < 1.0f)
				{
					Rotation[Boucle] += 0.1f;
				}
				else
				{
					Stats[Boucle] = animation_statut::fini;
				}
				break;
			}
		}
	}
}

const float animation::Get_Scale(const short _ID)
{
	switch (_ID)
	{
	case 0:
		return Rotation[0];
	case 1:
		return Rotation[1];
	}
	return 0.0f;
}

const animation_statut animation::Get_Statut(const short _ID)
{
	switch (_ID)
	{
	case 0:
		return Stats[0];
	case 1:
		return Stats[1];
	}
	return animation_statut::fini;
}
