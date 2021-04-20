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
		bool Save();

		bool IsAccountLoggedIn() const;
		bool IsUserLoggedIn() const;
		Account* GetCurrentAccount() const;
		User* GetCurrentUser() const;

		Store& GetStore();

		bool LoginAccount(const std::string& email, const std::string& password);
		bool LoginUser(const std::string& username, const std::string& password);
		void LogoutUser();

		void addAccount(Account* account);
		Account* getAccount(const int& index) const;

	private:
		List<Account*> accounts;
		Store store;
		Account* currentAccount;
		User* currentUser;
};