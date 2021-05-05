#pragma once

#include <string>
#include "Date.h"

class User
{
	public:
		User(const std::string&, const std::string&, const Date&, const std::string& role);
		virtual ~User();
		const std::string& GetUsername() const;
		const std::string& GetPassword() const;
		const Date& GetDateCreated() const;
		const std::string getRole() const;

		void setCredits(const int& amount);
		void addCredits(const int& amount);
		void removeCredits(const int& amount);
		int getCredits() const;

	private:
		std::string username;
		std::string password;
		const Date created;
		const std::string role;

		int credits;
};