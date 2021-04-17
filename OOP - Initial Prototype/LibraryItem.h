#pragma once

#include "Game.h"
#include "Date.h"

class LibraryItem
{
	public:
		LibraryItem(const Date&, Game*);
	private:
		const Game *game;
		const Date purchased;
};