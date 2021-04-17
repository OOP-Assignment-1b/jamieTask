#include "Store.h"

Store::~Store()
{
	for (int i = 0; i < games.length(); ++i)
	{
		delete games[i];
	}
}

void Store::addGame(Game* game)
{
	games.addInFront(game);
}

Game Store::getAtIndex(const int index)
{
	return  *games[index];
}
