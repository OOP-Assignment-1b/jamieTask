#pragma once

#include "Menu.h"
#include <algorithm>
#include "Admin.h"
#include "Player.h"
#include "Utils.h"
#include <iomanip>
#include <sstream>
#include "PurchaseMenu.h"

class ProfileMenu : public Menu

{

public:
	ProfileMenu(const std::string& title, Application* app);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;
private:
	int index = 0;
	const int gameRows = 5;
	const void DeleteUser(std::string& username);

};


