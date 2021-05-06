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

			int credit = 0;

			int day;
			int month;
			int year;

			std::string username = "";
			std::string email = "";
			std::string password = "";

			while (getline(data, line))
			{
				if (line == "GAME") {

					std::string name;
					std::string description;
					int id;
					int ageRatting;
					int cost;
					int like;
					int dislike;

					for (int i = 0; i < 7; i++) {
						getline(data, line);
						switch (i)
						{

						case 0:
							id = std::stoi(line);
							break;
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
					GetStore().addGame(new Game(name, description, cost, ageRatting, like, dislike, id));
				}
				else if (line == "ACCOUNT")
				{

					for (int i = 0; i < 3; i++) {
						getline(data, line);
						switch (i)
						{

						case 0:

							year = std::stoi(line.substr(0, line.find('-')));
							month = std::stoi(line.substr(5, line.find('-')));
							day = std::stoi(line.substr(8, line.find('-')));

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
					int minutes;
					bool hasReviewed;

					for (i = 0; i < 4; i++) {
						getline(data, line);
						switch (i)
						{

						case 0:
							id = std::stoi(line);
							break;
						case 1:

							year = std::stoi(line.substr(0, line.find('-')));
							month = std::stoi(line.substr(5, line.find('-')));
							day = std::stoi(line.substr(8, line.find('-')));

							break;
						case 2:
							minutes = std::stoi(line);
							break;
						case 3:
							hasReviewed = line == "1" ? true : false;
							break;

						default:
							return false;
							break;
						}
					}

					Date date = Date(day, month, year);
					Player* user = dynamic_cast<Player*>(accounts[0]->getAllUsers().last());
					Game game = Game(GetStore().getAtIndex(id));
					LibraryItem* iteam = new LibraryItem(date, game, minutes);
					iteam->SetHasReviewed(hasReviewed);
					user->addLibraryItem(iteam);
				}
				else if (line == "ACCOUNT-PLAYER")
				{

					for (i = 0; i < 4; i++) {
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
						case 3:
							credit = std::stoi(line);
							break;

						default:
							return false;
							break;
						}
					}

					Date date(day, month, year);
					User* user = new Player(username, password, date, "PLAYER");
					user->setCredits(credit);
					accounts[0]->addUser(user);

				}
				else if (line == "ACCOUNT-ADMIN")
				{

					for (i = 0; i < 4; i++) {

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
						case 3:
							credit = std::stoi(line);
							break;

						default:
							return false;
							break;
						}

					}

					Date date(day, month, year);
					User* user = new Admin(username, password, date, "ADMIN");
					user->setCredits(credit);
					accounts[0]->addUser(user);

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
		data.open("data.txt", std::fstream::out | std::fstream::trunc);

		if (data.is_open()) {

			if (GetStore().getGames().length() > 0) {
				for (int i = 0; i < GetStore().getGames().length(); i++) {
					data << "GAME" << std::endl;
					data << i << std::endl;
					data << GetStore().getGames()[i]->GetName() << std::endl;
					data << GetStore().getGames()[i]->GetDescription() << std::endl;
					data << GetStore().getGames()[i]->GetCost() << std::endl;
					data << GetStore().getGames()[i]->GetAgeRating() << std::endl;
					data << GetStore().getGames()[i]->GetLikes() << std::endl;
					data << GetStore().getGames()[i]->GetDislikes() << std::endl;
				}
			}


			if (accounts.length() > 0) {
				for (int i = 0; i < accounts.length(); i++) {
					data << "ACCOUNT" << std::endl;
					data << accounts[i]->GetDateCreated().getDate() << std::endl;
					data << accounts[i]->GetEmail() << std::endl;
					data << accounts[i]->GetPassword() << std::endl;
					if (accounts[i]->getAllUsers().length() > 0) {
						List<User*> users = accounts[i]->getAllUsers();
						for (int y = 0; y < users.length(); y++) {
							data << "ACCOUNT-" + users[y]->getRole() << std::endl;
							data << users[y]->GetDateCreated().getDate() << std::endl;
							data << users[y]->GetUsername() << std::endl;
							data << users[y]->GetPassword() << std::endl;
							data << std::to_string(users[y]->getCredits()) << std::endl;
							if (dynamic_cast<Player*>(accounts[i]->getAllUsers()[y])->getAllItems().size() > 0) {
								std::vector<LibraryItem*> items = dynamic_cast<Player*>(accounts[i]->getAllUsers()[y])->getAllItems();
								for (int j = 0; j < items.size(); j++) {
									data << "LIBRARY-ITEM" << std::endl;
									data << std::to_string(items[j]->getGame().GetId()) << std::endl;
									data << items[j]->GetPurchasedDate().getDate() << std::endl;
									data << std::to_string(items[j]->GetPlaytime()) << std::endl;
									data << (items[j]->GetHasReviewed() == true ? "1" : "0") << std::endl;
								}
							}
						}
					}

				}
			}

		}

		data.close();
		return true;

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


	for (int i = 0; i < currentAccount->getAllUsers().length(); i++) {
		if (currentAccount->getAllUsers()[i]->GetUsername() == username && currentAccount->getAllUsers()[i]->GetPassword() == password) {
			currentUser = currentAccount->getAllUsers()[i];
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
