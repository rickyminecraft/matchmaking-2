#include <cstdlib>
#include <memory>

#include "matchmaking.h"

int main()
{
	std::unique_ptr<matchmaking> Game(new matchmaking());

	if (!Game->Run())
	{
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}