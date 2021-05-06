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
	games.addAtEnd(game);
}

Game Store::getAtIndex(const int& index)
{
	return  *games[index];
}

List<Game*> Store::searchByName(std::string& userI)
{
	std::string userSearch = Utils::toLower(userI);
	List<Game*> foundGames;
	for (int i = 0; i < games.length(); i++)
	{
			if (Utils::startsWith(Utils::toLower(games[i]->GetName()), userSearch))
			{
				foundGames.addInFront(games[i]);
			}
	}
	return foundGames;
}

List<Game*> Store::getGames()
{
	return List<Game*>(games);
}
