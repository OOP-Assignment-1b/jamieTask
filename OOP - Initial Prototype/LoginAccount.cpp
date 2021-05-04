#include "LoginAccount.h"

LoginAccount::LoginAccount(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void LoginAccount::OutputOptions()
{
	Line();
	Option('L', "Login");
}

bool LoginAccount::HandleChoice(char choice)
{
	// since we are using numbers here we shift the char down by '1'
	// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
	// this reverses the + 1 above and lets us do the range check below
	int index = choice - '1';

	auto email = Question("Enter Email");


	auto password = Question("Enter Password");

	if (app->LoginAccount(email, password)) {
		return true;
	}
	else
	{
		BlockingMessage("Incorrect login");
	}

return false;

}