#pragma once

#include "Menu.h"
#include <algorithm>
#include "Admin.h"
#include "Player.h"
#include "Utils.h"


class ProfileMenu : public Menu

{

public:
	ProfileMenu(const std::string& title, Application* app);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;
private:
	
};


