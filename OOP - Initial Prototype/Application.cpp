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

		std::ifstream myfile("data.txt");

		if (myfile.is_open()) {

			std::string line;

			int i = 0;
			int y = 0;

			while (getline(myfile, line))
			{
				if (line == "GAME") {

					std::string name;
					std::string description;
					int ageRatting;
					int cost;

					for (int i = 0; i < 5; i++) {
						getline(myfile, line);
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

						default:
							return false;
							break;
						}

					}
					GetStore().addGame(new Game(name, description, cost, ageRatting));
				}
				else if (line == "ACCOUNT")
				{

					std::string email;
					std::string password;

					int day;
					int month;
					int year;

					int i;

					for (int i = 0; i < 3; i++) {
						getline(myfile, line);
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
						getline(myfile, line);
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

					Date date(day, month, year);
					Player* user = dynamic_cast<Player*>(accounts[0]->users[0]);
					user->library.addInFront(new LibraryItem(date, new Game(GetStore().getAtIndex(id))));
				}
				else if (line == "ACCOUNT-PLAYER")
				{

					std::string username;
					std::string password;

					int day;
					int month;
					int year;

					for (i = 0; i < 3; i++) {
						getline(myfile, line);
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
					accounts[0]->users.addInFront(new Player(username, password, date));

				}
				else if (line == "ACCOUNT-ADMIN")
				{

					std::string username;
					std::string password;

					int day;
					int month;
					int year;

					for (i = 0; i < 3; i++) {

						getline(myfile, line);

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
					accounts[0]->users.addInFront(new Admin(username, password, date));

				}

			}

			myfile.close();
			return true;

		}
	}
	catch (...) {
		return false;
	}

	return false;

}

void Application::Save()
{
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
	// TODO: This currently always logs you in as the first account
	currentAccount = accounts[0];

	return true;
}

bool Application::LoginUser(const std::string& username, const std::string& password)
{
	// TODO: This currently always logs you in as the first user
	currentUser = currentAccount->users[0];

	return true;
}

void Application::LogoutUser()
{
	currentUser = nullptr;
}