#include "Player.h"

Player::Player(const std::string& username, const std::string& password, const Date& created, const std::string& role)
	: User(username, password, created, role)
{
}

Player::~Player()
{
	for (int i = 0; i < library.length(); ++i)
	{
		delete library[i];
	}
}

void Player::addLibraryItem(LibraryItem* item)
{
	library.addInFront(item);
}

List<LibraryItem*> Player::getAllItems() const
{
	return library;
}
