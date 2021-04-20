#pragma once

#include "Menu.h"
#include "StoreMenu.h"
#include "ProfileMenu.h"
#include <algorithm>

class MainMenu : public Menu
{
public:
	MainMenu(const std::string& title, Application* app);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;
};