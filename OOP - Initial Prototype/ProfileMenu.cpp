#include "ProfileMenu.h"



ProfileMenu::ProfileMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}


void ProfileMenu::OutputOptions()
{
	Player* player = dynamic_cast<Player*>(app->GetCurrentUser());

	if (player->getRole() == "admin")
	{
		Line("[Admin]");
		Option('A', "Add User");
		Option('D', "Delete User");
		Line();
	}
	Line("Credits: 10.00");
	Option('I', "Purchase 1   credit");
	Option('O', "Purchase 10  credits");
	Option('P', "Purchase 100 credits");
	Line();
	Line("GAMES");



	List<LibraryItem*> temp = player->getAllItems();

	for (int i = 0; i < temp.length(); i++)
	{
		std::string t = temp[i]->getGame().GetName() + "  (1.5 hours)";
		Option(i + 1, t);
	}

}

bool ProfileMenu::HandleChoice(char choice)
{
	
	Player* player = dynamic_cast<Player*>(app->GetCurrentUser());
	int index = choice - '1';

	if (index >= 0 && index < player->getAllItems().length())
	{

	}
	else {

		switch (choice)
		{
		case 'I':
		{
		} break;
		case 'O':
		{

		} break;
		case 'P':
		{

		} break;

		case 'A':
		{
			std::string role = Question("What's the role of the user");
			if (role == "admin" || role == "user")
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
				if (role == "admin")
				{
					Player* admin = new Admin(username, password, Date(Utils::getDay(), Utils::getMonth(), Utils::getYear()), "admin");
					app->GetCurrentAccount()->users.addInFront(admin);
				} else
				{
					Player* user = new Player(username, password, Date(Utils::getDay(), Utils::getMonth(), Utils::getYear()), "user");
					app->GetCurrentAccount()->users.addInFront(user);
				}
				BlockingMessage("Account Created!");
			}
			else
			{
				BlockingMessage("Type can only be [Admin] or [User]");
			}

		}break;
		case'D':
		{
			std::string username = Question("What's the name of the user");
			List<User*> users = app->GetCurrentAccount()->users;
			bool removed = false;
			for (int i=0; i < users.length(); i++)
			{
				if (users[i]->GetUsername() == username)
				{
					removed = !removed;
					BlockingMessage("Removed Account: " + users[i]->GetUsername());
					users.deleteOne(users[i]);
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
