#include "Admin.h"

Admin::Admin(const std::string& username, const std::string& password, const Date& created, const std::string& role)
	: Player(username, password, created, role)
{
}

Admin::~Admin()
{
}