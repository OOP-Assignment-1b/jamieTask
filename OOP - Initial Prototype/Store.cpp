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
List<std::string> Store::searchByName()
{
	auto u = Utils::toLower(Utils::getLineFromUser());
	List<std::string> temp;
	for(int i=0; i<games.length(); i++)
	{
		auto l = games[i]->GetName();
		auto t = Utils::toLower(l);
		if(t.find(u)<t.length())
		{
			temp.addInFront(l);
		}
		
	}
	return temp;
}