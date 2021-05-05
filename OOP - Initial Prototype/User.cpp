#include "User.h"

User::User(const std::string& username, const std::string& password, const Date& created, const std::string& role)
	: username(username), password(password), created(created), role(role)
{
}

User::~User()
{
}

const std::string& User::GetUsername() const
{
	return username;
}

const std::string& User::GetPassword() const
{
	return password;
}

std::string User::getRole() const
{
	return this->role;
}

void User::setCredits(const int& amount)
{
	if (amount >= 0) {
		this->credits = amount;
	}
}

void User::addCredits(const int& amount)
{
	this->credits += amount;
}

void User::removeCredits(const int& amount)
{
	if (this->credits > amount) {
		this->credits -= amount;
	}
}

int User::getCredits() const
{
	return this->credits;
}



