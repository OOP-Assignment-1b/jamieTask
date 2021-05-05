#include "LoginUser.h"

LoginUser::LoginUser(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void LoginUser::OutputOptions()
{

	auto users = app->GetCurrentAccount()->getAllUsers();
	if (users.length() > 0) {
		for (int i = 0; i < users.length(); i++) {
			Option(i + 1, users[i]->GetUsername());
		}
	}

	Line();
}

bool LoginUser::HandleChoice(char choice)
{
	// since we are using numbers here we shift the char down by '1'
	// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
	// this reverses the + 1 above and lets us do the range check below
	int index = choice - '1';

	
	if (index >= 0 && index < app->GetCurrentAccount()->getAllUsers().length())
	{
		auto password = Question("Enter Password");
		if (app->LoginUser(app->GetCurrentAccount()->getAllUsers()[index]->GetUsername(), password)) {
			return true;
		}
		else
		{
			BlockingMessage("Incorrect login");
		}
	}

	return false;
}