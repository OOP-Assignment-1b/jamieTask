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

List<Game*> Store::searchByName(std::string& userI, List<Game*> listGames)
{
	std::string userSearch = Utils::toLower(userI);
	List<Game*> foundGames;
	for (int i = 0; i < listGames.length(); i++)
	{
			if (Utils::startsWith(Utils::toLower(listGames[i]->GetName()), userSearch))
			{
				foundGames.addInFront(listGames[i]);
			}
	}
	return foundGames;
}

List<Game*> Store::getGames()
{
	return List<Game*>(games);
}

List<Game*> Store::searchByPrice(std::string& input, List<Game*> listGames)
{
	auto t = Utils::split(input, "-");
	List<Game*> foundGames;
	if (t.size() == 2) {
		
		for (int i = 0; i < games.length(); i++)
		{
			auto cost = games[i]->GetCost();
			if (cost >= std::stoi(t[0])*100 && cost <= std::stoi(t[1])*100)
			{
				foundGames.addAtEnd(games[i]);
			}
		}

		
	}
	return foundGames;
}

