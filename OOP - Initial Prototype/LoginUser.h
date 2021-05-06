#pragma once
#include "Menu.h"
class LoginUser :
	public Menu
{
public:
	LoginUser(const std::string& title, Application* app);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;
private:
};

