#pragma once

#include "Game.h"
#include "List.h"
#include "Utils.h"

class Store
{
	public:
		Store() = default;
		~Store();

		void addGame(Game* game);

		Game getAtIndex(const int&);
		List<Game*> getGames();

		List <Game*> searchByName(std::string& userI);

	private:
		List<Game*> games;
};