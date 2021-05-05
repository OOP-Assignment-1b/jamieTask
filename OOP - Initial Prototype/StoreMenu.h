#pragma once

#include "Menu.h"
#include "List.h"
#include "PurchaseMenu.h"
#include <iomanip>
#include <sstream>

#include <string>

class StoreMenu : public Menu
{
public:
	StoreMenu(const std::string& title, Application* app);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;
private:
	List<std::string> games;
};