#include "Account.h"

Account::Account(const std::string& email, const std::string& password, const Date& created)
	: email(email), password(password), created(created)
{
}

Account::~Account()
{
	for (int i = 0; i < users.length(); ++i)
	{
		delete users[i];
	}
}

const std::string& Account::GetEmail() const
{
	return email;
}

const std::string& Account::GetPassword() const
{
	return password;
}

const Date& Account::GetDateCreated() const
{
	return created;
}

List<User*>& Account::getAllUsers()
{
	return users;
}

void Account::addUser(Player* user)
{
	this->users.addAtEnd(user);
}

void Account::addUser(User* user)
{
	this->users.addAtEnd(user);
}


