#include "tiles.h"



tiles::tiles()
{
}


tiles::~tiles()
{
}

const short tiles::Get(const short Numero)
{
	if (Numero < 0 || Numero > 48)
	{
		return -1;
	}
	return Tiles[Numero];
}

const bool tiles::Is_done(const short Numero)
{
	if (Numero < 0 || Numero > 48)
	{
		return false;
	}
	return BTiles[Numero];
}

void tiles::Done(const short Numero)
{
	if (Numero > 0 || Numero < 48)
	{
		BTiles[Numero] = true;
	}
}

const bool tiles::Is_all_done()
{
	bool Done = true;
	for (short Boucle = 0; Boucle < 48; ++Boucle)
	{
		if (!BTiles[Boucle])
		{
			Done = false;
		}
	}
	return Done;
}

void tiles::Reset()
{
	for (short Boucle = 0; Boucle < 24; ++Boucle)
	{
		Tiles[Boucle] = Boucle;
		Tiles[Boucle + 24] = Boucle;

		BTiles[Boucle] = false;
		BTiles[Boucle + 24] = false;
	}
	Shuffle();
}

void tiles::Shuffle()
{
	std::random_device Rdevice;
	std::default_random_engine Engine(Rdevice());
	std::shuffle(Tiles.begin(), Tiles.end(), Engine);
}
