#include "MainMenu.h"

MainMenu::MainMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void MainMenu::OutputOptions()
{
	Option('S', "Browse Store");

	if (app->IsUserLoggedIn())
	{
		Option('P', "View Profile");
		Option('L', "Logout");
	}
	else
	{
		Option('L', "Login");
	}
}

bool MainMenu::HandleChoice(char choice)
{
	switch (choice)
	{
	case 'S':
	{
		StoreMenu("STORE", app);
	} break;
	case 'L':
	{
		if (app->IsUserLoggedIn())
		{
			std::string answer = Question("Are you sure?");
			if (answer == "y" || answer == "Y")
			{
				app->LogoutUser();
			}
		}
		else
		{
			// this would need to go to a LoginMenu - similar to StoreMenu
			// instead we just set logged in to true on the main app object
			app->LoginUser("Adam","Banana");
		}
	} break;
	case 'P':
	{
		if (app->IsUserLoggedIn())
		{
			auto title = app->GetCurrentUser()->GetUsername() + "'s Profile";
			std::transform(title.begin(), title.end(), title.begin(), ::toupper); // Converts title to uppercase
			ProfileMenu(title, app); // Creates a Profile Menu with the current users name as the title
		}
	} break;
	}

	return false;
}