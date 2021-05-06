#include "SearchMenu.h"

SearchMenu::SearchMenu(const std::string& title, Application* app, List<Game*> gamesIn )
	: games(gamesIn),  Menu(title, app)
{
	Paint();
}

void SearchMenu::OutputOptions()
{
	/*for (int i = 0; i < games.length(); i++)
	{
		Option((i + 1), games[i]->GetName());
	}

	Line();*/

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
		std::string userInput = Question(" Enter name to search for");
		//games = app->GetStore().searchByName(userInput);
		SearchResultMenu("SEARCH RESULTS", app, app->GetStore().searchByName(userInput));
	
	}break;
	case 'P':
	{
		
	}break;

	}

	return false;
}
