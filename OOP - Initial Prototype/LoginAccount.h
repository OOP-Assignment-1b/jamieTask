#pragma once
#include "Menu.h"
class LoginAccount :
    public Menu
{

public:
	LoginAccount(const std::string& title, Application* app);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;
private:

};

