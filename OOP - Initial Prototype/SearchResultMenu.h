#pragma once
#include "Menu.h"
#include "List.h"
#include "SearchMenu.h"
#include "PurchaseMenu.h"

class SearchResultMenu :
	public Menu
{
public:
	SearchResultMenu(const std::string& title, Application* app, List<Game*> gamesIn);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;

private:
	List<Game*> games;
	int index = 0;
	const int gameRows = 5;

};

