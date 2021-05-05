#include "Application.h"
#include <fstream>

Application::Application() : currentAccount(nullptr), currentUser(nullptr)
{
}

Application::~Application()
{
	for (int i = 0; i < accounts.length(); ++i)
	{
		delete accounts[i];
	}
}

/// <summary>
/// This is the load data fucnction. It is used to load
/// data from the data.txt file.
/// </summary>
/// <returns>
/// returns true if data loaded.
/// returns false if data is not loaded or data.txt is not there.
/// </returns>
bool Application::Load()
{

	try {

		std::ifstream data("data.txt");

		if (data.is_open()) {

			std::string line;

			int i = 0;
			int y = 0;

			std::string username = "";
			std::string email = "";
			std::string password = "";

			while (getline(data, line))
			{
				if (line == "GAME") {

					std::string name;
					std::string description;
					int ageRatting;
					int cost;
					int like;
					int dislike;

					for (int i = 0; i < 7; i++) {
						getline(data, line);
						switch (i)
						{

						case 0: break;
						case 1:
							name = line;
							break;
						case 2:
							description = line;
							break;
						case 3:
							cost = std::stoi(line);
							break;
						case 4:
							ageRatting = std::stoi(line);
							break;
						case 5:
							like = std::stoi(line);
							break;
						case 6:
							dislike = std::stoi(line);
							break;

						default:
							return false;
							break;
						}

					}
					GetStore().addGame(new Game(name, description, cost, ageRatting, like, dislike));
				}
				else if (line == "ACCOUNT")
				{

					int day;
					int month;
					int year;

					int i;

					for (int i = 0; i < 3; i++) {
						getline(data, line);
						switch (i)
						{

						case 0:

							day = std::stoi(line.substr(0, line.find('-')));
							month = std::stoi(line.substr(5, line.find('-')));
							year = std::stoi(line.substr(8, line.find('-')));

							break;
						case 1:
							email = line;
							break;
						case 2:
							password = line;
							break;

						default:
							return false;
							break;
						}
					}

					Date date(day, month, year);
					accounts.addInFront(new Account(email, password, date));
				}
				else if (line == "LIBRARY-ITEM")
				{

					int id;

					int day;
					int month;
					int year;

					int minutes;

					for (i = 0; i < 3; i++) {
						getline(data, line);
						switch (i)
						{

						case 0:
							id = std::stoi(line);
							break;
						case 1:

							day = std::stoi(line.substr(0, line.find('-')));
							month = std::stoi(line.substr(5, line.find('-')));
							year = std::stoi(line.substr(8, line.find('-')));

							break;
						case 2:
							minutes = std::stoi(line);
							break;

						default:
							return false;
							break;
						}
					}

					Date date = Date(day, month, year);
					Player* user = dynamic_cast<Player*>(accounts[0]->users[0]);
					Game game = Game(GetStore().getAtIndex(id));
					LibraryItem* iteam = new LibraryItem(date, game);
					user->addLibraryItem(iteam);
				}
				else if (line == "ACCOUNT-PLAYER")
				{

					int day;
					int month;
					int year;

					for (i = 0; i < 3; i++) {
						getline(data, line);
						switch (i)
						{

						case 0:
							day = std::stoi(line.substr(0, line.find('-')));
							month = std::stoi(line.substr(5, line.find('-')));
							year = std::stoi(line.substr(8, line.find('-')));
							break;
						case 1:
							username = line;
							break;
						case 2:
							password = line;
							break;

						default:
							return false;
							break;
						}
					}

					Date date(day, month, year);
					User* user = new Player(username, password, date, "user");
					accounts[0]->users.addInFront(user);

				}
				else if (line == "ACCOUNT-ADMIN")
				{

					int day;
					int month;
					int year;

					for (i = 0; i < 3; i++) {

						getline(data, line);

						switch (i)
						{

						case 0:

							year = std::stoi(line.substr(0, line.find('-')));
							month = std::stoi(line.substr(5, line.find('-')));
							day = std::stoi(line.substr(8, line.find('-')));
							break;
						case 1:
							username = line;
							break;
						case 2:
							password = line;
							break;

						default:
							return false;
							break;
						}

					}

					Date date(day, month, year);
					User* user = new Admin(username, password, date, "admin");
					accounts[0]->users.addInFront(user);

				}

			}

			data.close();
			return true;

		}
	}
	catch (...) {
		return false;
	}

	return false;

}

bool Application::Save()
{

	try {

		std::ofstream data;
		data.open("data2.txt", std::fstream::out | std::fstream::trunc);

		if (data.is_open()) {

			List<Game*> games = GetStore().getGames();

			for (int i = 0; i < games.length(); i++) {
				data << "GAME" << std::endl;
				data << i + 1 << std::endl;
				data << games[i]->GetName() << std::endl;
				data << games[i]->GetDescription() << std::endl;
				data << 0 << std::endl;
				data << games[i]->GetCost() << std::endl;
			}

			for (int i = 0; i < accounts.length(); i++) {
				data << "ACCOUNT" << std::endl;
				for (int y = 0; y < accounts[i]->users.length() ;y++) {
					/*
					if (accounts[i]->users) {
						data << "ACCOUNT-PLAYER" << std::endl;
					}
					else
					{
						data << "ACCOUNT-ADMIN" << std::endl;
					}
					data << accounts[i]->users[y]->GetUsername() << std::endl;
					data << accounts[i]->users[y]->GetUsername() << std::endl;
					*/

				}

			}

		}

		data.close();

	}
	catch (...) {

	}

	return false;
}

bool Application::IsUserLoggedIn() const
{
	return currentUser != nullptr;
}

bool Application::IsAccountLoggedIn() const
{
	return currentAccount != nullptr;
}

Account* Application::GetCurrentAccount() const
{
	return currentAccount;
}

User* Application::GetCurrentUser() const
{
	return currentUser;
}

Store& Application::GetStore()
{
	return store;
}

bool Application::LoginAccount(const std::string& email, const std::string& password)
{

	currentAccount = accounts[0];
	return true;

	for (int i = 0; i < accounts.length(); i++) {
		if (accounts[i]->GetEmail() == email && accounts[i]->GetPassword() == password) {
			currentAccount = accounts[i];
			return true;
		}
	}

	return false;
}

bool Application::LoginUser(const std::string& username, const std::string& password)
{
	for (int i = 0; i < currentAccount->users.length(); i++) {
		if (currentAccount->users[i]->GetUsername() == username && currentAccount->users[i]->GetPassword() == password) {
			currentUser = currentAccount->users[i];
			return true;
		}
	}

	return false;
}

void Application::LogoutUser()
{
	currentUser = nullptr;
}

void Application::LogoutAccount()
{
	currentAccount = nullptr;
	currentUser = nullptr;
}

Account* Application::getAccount(const int& index) const
{
	if (!(accounts.isEmpty() && accounts.length() < index))
	{
		return accounts[index];
	}
}


void Application::addAccount(Account* account)
{
	this->accounts.addInFront(account);
}
