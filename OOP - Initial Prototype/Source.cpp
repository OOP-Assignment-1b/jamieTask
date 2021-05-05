#include <iostream>
#include <string>
#include "Application.h"
#include "Account.h"
#include "User.h"
#include "Player.h"
#include "Admin.h"

#include "List.h"
#include "Date.h"

#include "MainMenu.h"

void main()
{

	Application app;

	app.Load();
	app.LoginAccount("alice@shu.com", "password");

	MainMenu("Main Menu", &app);

	app.Save();

}