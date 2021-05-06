#include "SearchMenu.h"

SearchMenu::SearchMenu(const std::string& title, Application* app, List<Game*> gamesIn)
	: games(gamesIn), Menu(title, app)
{
	Paint();
}

void SearchMenu::OutputOptions()
{

	Line("SEARCHING " + std::to_string(games.length()) + " GAMES");
	Option('N', "Search by name");
	Option('P', "Search by price");

}

bool SearchMenu::HandleChoice(char choice)
{
	switch (choice)
	{
	case 'N':
	{
		auto userInput = Question("Enter name to search for");
		SearchResultMenu("SEARCH RESULTS", app, app->GetStore().searchByName(userInput, games));

	}break;
	case 'P':
	{
		auto input = Question("Enter price range (e.g. 5-10)");
		SearchResultMenu("SEARCH RESULTS", app, app->GetStore().searchByPrice(input, games));

	}break;

	}

	return false;
}
