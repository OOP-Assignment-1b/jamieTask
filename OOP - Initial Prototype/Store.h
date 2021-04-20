#pragma once

#include "Game.h"
#include "List.h"

class Store
{
	public:
		Store() = default;
		~Store();

		void addGame(Game* game);

		Game getAtIndex(const int index);
		List<Game*> getGames();

	private:
		List<Game*> games;
};