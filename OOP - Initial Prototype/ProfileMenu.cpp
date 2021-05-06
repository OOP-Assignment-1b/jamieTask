#include "ProfileMenu.h"

ProfileMenu::ProfileMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void ProfileMenu::OutputOptions()
{
	Player* player = dynamic_cast<Player*>(app->GetCurrentUser());

	if (player->getRole() == "ADMIN")
	{
		Line("[Admin]");
		Option('A', "Add User");
		Option('D', "Delete User");
		Line();
	}

	Line(Utils::formatCurrency("Credits: ", app->GetCurrentUser()->getCredits()));
	Option('I', "Purchase 1   credit");
	Option('O', "Purchase 10  credits");
	Option('P', "Purchase 100 credits");
	Line();
	Line("GAMES");

	std::vector<LibraryItem*> temp = player->getAllItems();

	for (int i = 0 + index; i < GetCap(); i++)
	{
		double playTimeHours = temp[i]->GetPlaytime() / 60.00f;
		Option((i + 1) - index, Utils::formatPlayTime(playTimeHours, temp[i]->getGame().GetName()));
	}

	Line();
	Line("PAGE " + std::to_string(((index / gameRows) + 1)) + " OF " + std::to_string(static_cast<int>(ceil(static_cast<float>(dynamic_cast<Player*>(app->GetCurrentUser())->getAllItems().size()) / static_cast<float>(gameRows)))));
	if (dynamic_cast<Player*>(app->GetCurrentUser())->getAllItems().size() > GetCap()) {
		Option('E', "Next Page");
	}

	if (index >= gameRows) {
		Option('Q', "Back page");
	}
	Line();
	Option('V', "Launch Game");


}

bool ProfileMenu::HandleChoice(char choice)
{

	Player* player = dynamic_cast<Player*>(app->GetCurrentUser());
	int index = choice - '1';
	index += this->index;
	auto list = player->getAllItems();
	auto games = app->GetStore().getGames();


	if (index >= 0 && index < list.size())
	{
		PurchaseMenu(Utils::recursiveToUpper(list[index]->getGame().GetName()), app, list[index]->getGame().GetId());
	}

	switch (choice)
	{
	case 'V':
	{
		auto t = Question("What game would you like to launch");
		index = t[0] - '1';
		if (index >= 0 && index < list.size())
		{
			list[index]->AddPlaytime(Utils::getRandomNumber(60, 10));
		}

	}break;
	case 'I':
	{
		player->addCredits(100);
	} break;
	case 'O':
	{
		player->addCredits(1000);
	} break;
	case 'P':
	{
		player->addCredits(10000);
	} break;

	case 'A':
	{
		std::string role = Utils::toUpper(Question("What's the role of the user"));
		if (role == "ADMIN" || role == "PLAYER")
		{
			std::string username = Question("What's the name of the user");
			if (std::all_of(username.begin(), username.end(), isspace))
			{
				BlockingMessage("No spaces allowed for username");
				break;
			}

			bool spaceUsername = false;
			for (int i = 0; i < username.length(); i++)
			{
				if (isspace(username[i]))
				{
					spaceUsername = true;
				}
			}
			if (spaceUsername)
			{
				BlockingMessage("No spaces allowed for username");
				break;
			}
			bool inList = false;
			for (int i = 0; i < app->GetCurrentAccount()->getAllUsers().length(); i++)
			{
				std::string usernameInList = app->GetCurrentAccount()->getAllUsers()[i]->GetUsername();
				if (Utils::toLower(usernameInList) == Utils::toLower(username)) inList = !inList;
			}
			if (inList)
			{
				BlockingMessage("That user already exists!");
				break;
			}
			std::string password = Question("What's the password of the user");
			if (std::all_of(password.begin(), password.end(), isspace))
			{
				BlockingMessage("No spaces allowed for password");
				break;
			}
			bool spacePassword = false;
			for (int i = 0; i < password.length(); i++)
			{
				if (isspace(password[i]))
				{
					spacePassword = true;
				}
			}
			if (spacePassword)
			{
				BlockingMessage("No spaces allowed for password");
				break;
			}
			if (role == "ADMIN")
			{
				Player* admin = new Admin(username, password, Date(Utils::getDay(), Utils::getMonth(), Utils::getYear()), "ADMIN");
				app->GetCurrentAccount()->addUser(admin);
			}
			else
			{
				Player* user = new Player(username, password, Date(Utils::getDay(), Utils::getMonth(), Utils::getYear()), "PLAYER");
				app->GetCurrentAccount()->addUser(user);
			}
			BlockingMessage("Account Created!");
		}
		else
		{
			BlockingMessage("Type can only be [ADMIN] or [PLAYER]");
		}

	}break;
	case'D':
	{
		DeleteUser(Question("What's the name of the user"));
	}break;
	case 'E':
	{
		if (dynamic_cast<Player*>(app->GetCurrentUser())->getAllItems().size() > GetCap()) this->index += gameRows;
	}break;
	case 'Q':
	{
		if (this->index >= gameRows) this->index -= gameRows;
	}break;

	}

	return false;

}

const void ProfileMenu::DeleteUser(std::string& username) {
	for (int i = 0; i < app->GetCurrentAccount()->getAllUsers().length(); i++)
	{
		if (Utils::recursiveToUpper(app->GetCurrentAccount()->getAllUsers()[i]->GetUsername()) == Utils::recursiveToUpper(username))
		{
			BlockingMessage("Removed Account: " + app->GetCurrentAccount()->getAllUsers()[i]->GetUsername());
			app->GetCurrentAccount()->getAllUsers().deleteOne(app->GetCurrentAccount()->getAllUsers()[i]);
			return;
		}

	}

	BlockingMessage("No account removed");

}

const int& ProfileMenu::GetCap() const {

	int cap = dynamic_cast<Player*>(app->GetCurrentUser())->getAllItems().size();
	if (cap >= this->index + gameRows) cap = gameRows + this->index;

	return cap;

}
