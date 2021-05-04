#pragma once

#include <string>
#include "Player.h"
#include "List.h"
#include "Date.h"

class Account
{
	public:
		Account(const std::string&, const std::string&, const Date&);
		~Account();
		const std::string& GetEmail() const;
		const std::string& GetPassword() const;
		List<User*> users;
	private:
		std::string email;
		std::string password;
		Date created;
};