#pragma once

#include "Account.h"
#include "User.h"
#include "Player.h"
#include "Admin.h"
#include "Store.h"
#include "List.h"

class Application
{
	public:
		Application();
		~Application();

		bool Load();
		void Save();

		bool IsAccountLoggedIn() const;
		bool IsUserLoggedIn() const;
		Account* GetCurrentAccount() const;
		User* GetCurrentUser() const;

		Store& GetStore();

		bool LoginAccount(const std::string& email, const std::string& password);
		bool LoginUser(const std::string& username, const std::string& password);
		void LogoutUser();
		
		List<Account*> accounts;
	private:
		Store store;
		Account* currentAccount;
		User* currentUser;
};