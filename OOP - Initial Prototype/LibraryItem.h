#pragma once

#include "Game.h"
#include "Date.h"

class LibraryItem
{
	public:
		LibraryItem(const Date&, const Game&, const int&);
		Game getGame() const;

		const int& GetPlaytime() const;
		const Date& GetPurchasedDate() const;

		void SetPlaytime(const int&);
		void AddPlaytime(const int&);

	private:
		const Game game;
		const Date purchased;
		int playtime;
};