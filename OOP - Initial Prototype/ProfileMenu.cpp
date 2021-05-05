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
	std::stringstream formatStringTwo;
	double credits = app->GetCurrentUser()->getCredits() / 100.00f;
	formatStringTwo << "Credits: " << std::setprecision(5) << credits;
	Line(formatStringTwo.str());
	Option('I', "Purchase 1   credit");
	Option('O', "Purchase 10  credits");
	Option('P', "Purchase 100 credits");
	Line();
	Line("GAMES");



	std::vector<LibraryItem*> temp = player->getAllItems();

	for (int i = 0; i < temp.size(); i++)
	{
		double playTimeHours = temp[i]->GetPlaytime() / 60.00f;
		Option(i + 1, Utils::formatPlayTime(playTimeHours, temp[i]->getGame().GetName()));
	}

}

bool ProfileMenu::HandleChoice(char choice)
{
	
	Player* player = dynamic_cast<Player*>(app->GetCurrentUser());
	int index = choice - '1';
	auto list = player->getAllItems();
	auto games = app->GetStore().getGames();

	
	if (index >= 0 && index < list.size())
	{
		
		list[index]->AddPlaytime(Utils::getRandomNumber(60,10));
	}
	else {

		switch (choice)
		{
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
			std::string role = Question("What's the role of the user");
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
				List<User*> userList = app->GetCurrentAccount()->getAllUsers();
				for (int i=0; i < userList.length(); i++)
				{
					std::string usernameInList = userList[i]->GetUsername();
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
				} else
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
			std::string username = Question("What's the name of the user");
			List<User*> users = app->GetCurrentAccount()->getAllUsers();
			bool removed = false;
			for (int i=0; i < users.length(); i++)
			{
				if (Utils::recursiveToUpper(users[i]->GetUsername()) == Utils::recursiveToUpper(username))
				{
					removed = !removed;
					app->GetCurrentAccount()->getAllUsers().deleteOne(app->GetCurrentAccount()->getAllUsers()[i]);
					BlockingMessage("Removed Account: " + users[i]->GetUsername());
				}
				
			}
			if (!removed)
			{
				BlockingMessage("No account removed");
			}
			
		}break;
		}
	}

	return false;

}
