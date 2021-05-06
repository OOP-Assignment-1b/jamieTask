#include "SearchResultMenu.h"

SearchResultMenu::SearchResultMenu(const std::string& title, Application* app, List<Game*> gamesIn)
	: games(gamesIn), Menu(title, app)
{
	Paint();
}

void SearchResultMenu::OutputOptions() 
{

	for (int i = 0; i < games.length(); i++)
	{
		Option((i + 1), games[i]->GetName());
	}

	Line();

	Option('S', "Search");
}

bool SearchResultMenu::HandleChoice(char choice)
{
	int index = choice - '1';

	if (index >= 0 && index <= games.length())
	{
		PurchaseMenu(Utils::toUpper(app->GetStore().getGames()[games[index]->GetId() ]->GetName()), app, games[index]->GetId());
	}

	switch (choice)
	{
	case 'S':
	{
		SearchMenu("SEARCH GAMES", app, games);
	}break;
	}

	return false;

}
