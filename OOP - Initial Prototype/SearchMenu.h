#pragma once
#include "SearchResultMenu.h" 
#include "PurchaseMenu.h"
#include "Menu.h"
#include "List.h"

class SearchMenu : public Menu
{
public:
	SearchMenu(const std::string& title, Application* app, List<Game*> gamesIn);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;

private:
	List<Game*> games;

};

