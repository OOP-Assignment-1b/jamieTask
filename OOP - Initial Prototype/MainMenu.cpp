#include "MainMenu.h"

MainMenu::MainMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void MainMenu::OutputOptions()
{

	Option('S', "Browse Store");

	if (app->IsAccountLoggedIn())
	{
		if (app->IsUserLoggedIn()) {
			Option('P', "View Profile");
			Option('L', "Logout User");
		}
		else
		{
			Option('L', "Login User");
		}

		Option('O', "Logout Account");
	}
	else
	{
		Option('L', "Login Account");
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
		if (app->IsAccountLoggedIn() == false)
		{
			LoginAccount("ACCOUNT LOGIN", app);
		}
		else if (app->IsAccountLoggedIn())
		{
			if (app->IsUserLoggedIn()) {
				std::string answer = Question("Are you sure?");
				if (answer == "y" || answer == "Y")
				{
					app->LogoutUser();
				}
			}
			else {
				LoginUser("USER LOGIN", app);

			}
		}
	} break;
	case 'O':
	{
		if (app->IsAccountLoggedIn()) {
			std::string answer = Question("Are you sure?");
			if (answer == "y" || answer == "Y")
			{
				app->LogoutAccount();
			}
		}

	}break;
	case 'P':
	{
		if (app->IsUserLoggedIn())
		{
			ProfileMenu(Utils::toUpper(app->GetCurrentUser()->GetUsername() + "'s Profile"), app); // Creates a Profile Menu with the current users name as the title
		}
	} break;
	}

	return false;
}