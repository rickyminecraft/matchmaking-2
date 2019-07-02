#include "tiles.h"



tiles::tiles()
{
}


tiles::~tiles()
{
}

const short tiles::Get(const short Numero)
{
	if (Numero < Min || Numero > Max)
	{
		return -1;
	}
	return Tiles[Numero];
}

const bool tiles::Is_done(const short Numero)
{
	if (Numero < Min || Numero > Max)
	{
		return false;
	}
	return BTiles[Numero];
}

void tiles::Done(const short Numero)
{
	if (Numero > Min || Numero < Max)
	{
		BTiles[Numero] = true;
	}
}

const bool tiles::Is_all_done()
{
	bool Done = true;
	for (short Boucle = Min; Boucle < Max; ++Boucle)
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
	for (short Boucle = Min; Boucle < Max/2; ++Boucle)
	{
		Tiles[Boucle] = Boucle;
		Tiles[Boucle + Max/2] = Boucle;

		BTiles[Boucle] = false;
		BTiles[Boucle + Max/2] = false;
	}
	Shuffle();
}

void tiles::Shuffle()
{
	std::random_device Rdevice;
	std::default_random_engine Engine(Rdevice());
	std::shuffle(Tiles.begin(), Tiles.end(), Engine);
}
