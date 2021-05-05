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

const Date& User::GetDateCreated() const
{
	return created;
}

const std::string User::getRole() const
{
	return this->role;
}
