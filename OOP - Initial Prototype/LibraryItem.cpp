#include "LibraryItem.h"

LibraryItem::LibraryItem(const Date& date, const Game& game, const int& playtime)
	: purchased(date), game(game), playtime(playtime)
{
}


Game LibraryItem::getGame() const
{
	return game;
}

void LibraryItem::SetPlaytime(const int& playtime) {
	this->playtime = playtime;
}

void LibraryItem::AddPlaytime(const int& playtime) {
	this->playtime =+ playtime;
}

const int& LibraryItem::GetPlaytime() const
{
	return playtime;
}

const Date& LibraryItem::GetPurchasedDate() const
{
	return purchased;
}

