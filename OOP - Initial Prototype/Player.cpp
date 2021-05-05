#include "Player.h"

Player::Player(const std::string& username, const std::string& password, const Date& created, const std::string& role)
	: User(username, password, created, role)
{
}

Player::~Player()
{
	for (int i = 0; i < library.size(); ++i)
	{
		delete library[i];
	}
}

void Player::addLibraryItem(LibraryItem* item)
{
	library.push_back(item);
}

std::vector<LibraryItem*> Player::getAllItems() const
{
	return library;
}
