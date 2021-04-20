#pragma once

#include "Game.h"
#include "Date.h"

class LibraryItem
{
	public:
		LibraryItem(const Date&, const Game&);
		Game getGame() const;

	private:
		const Game game;
		const Date purchased;
};