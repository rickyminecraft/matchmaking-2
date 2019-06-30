#pragma once

#include <array>
#include <random>

class tiles
{
public:
	tiles();
	~tiles();

	//get the content of tile 'numero'
	const short Get(const short Numero);
	//is tile 'numero' done ?
	const bool Is_done(const short Numero);
	//set tiles 'numero' done
	void Done(const short Numero);
	//is all tiles done ?
	const bool Is_all_done();
	//ready everything
	void Reset();

private:
	//shuffle array content
	void Shuffle();

	std::array<short, 48> Tiles;
	std::array<bool, 48> BTiles;
};

