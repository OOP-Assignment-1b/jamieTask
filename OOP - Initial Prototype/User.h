#pragma once

#include <string>
#include "Date.h"

class User
{
	public:
		User(const std::string&, const std::string&, const Date&, const std::string& role);
		virtual ~User();
		const std::string& GetUsername() const;
		std::string getRole() const;

	private:
		std::string username;
		std::string password;
		const Date created;
		const std::string role;
};