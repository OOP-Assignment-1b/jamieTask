#include "StoreMenu.h"

StoreMenu::StoreMenu(const std::string& title, Application* app) : Menu(title, app)
{

	auto storeGames = app->GetStore().getGames();
	for (int i = 0; i < storeGames.length(); i++) {
		games.addInFront(storeGames[i]->GetName());
	}

	Paint(); // required in constructor
}

void StoreMenu::OutputOptions()
{
	for (int i = 0; i < games.length(); i++)
	{
		// adding 1 so the display is nicer for the user
		Option(i + 1, games[i]);
	}
	Line();
	Option('S', "Search by name");
}

bool StoreMenu::HandleChoice(char choice)
{
	// since we are using numbers here we shift the char down by '1'
	// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
	// this reverses the + 1 above and lets us do the range check below
	int index = choice - '1';

	if (index >= 0 && index < games.length())
	{
		BlockingMessage("Not implemented, press return to continue");
		// go to game detail page
	}
	switch (choice)
	{
		case 'S':
		{
			auto t = app->GetStore().searchByName();
				for (int i=0; i<t.length(); i++)
				{
					BlockingMessage("Game Found: " +t[i]);
				}
		}break;
	}

	return false;
}