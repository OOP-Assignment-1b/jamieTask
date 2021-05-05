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
		const Date& GetDateCreated() const;
		List<User*> getAllUsers();
		void addUser(Player* user);
		void addUser(User* user);
	private:
		List<User*> users;
		std::string email;
		std::string password;
		Date created;
};