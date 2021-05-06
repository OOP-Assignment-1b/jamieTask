#include "SearchResultMenu.h"

SearchResultMenu::SearchResultMenu(const std::string& title, Application* app, List<Game*> gamesIn)
	: games(gamesIn), Menu(title, app)
{
	Paint();
}

void SearchResultMenu::OutputOptions()
{

	for (int i = 0 + index; i < Utils::GetCap(games.length(), this->index, this->gameRows); i++)
	{
		Option((i + 1), games[i]->GetName());
	}

	Line();

	if (app->GetStore().getGames().length() > Utils::GetCap(games.length(), this->index, this->gameRows)) {
		Option('N', "Next Page");
		Line();
	}

	if (index >= gameRows) {
		Option('P', "Back page");
		Line();
	}

	Option('S', "Search");
}

bool SearchResultMenu::HandleChoice(char choice)
{
	int index = choice - '1';

	if (index >= this->index && index <= Utils::GetCap(games.length(), this->index, this->gameRows))
	{
		PurchaseMenu(Utils::toUpper(app->GetStore().getGames()[games[index]->GetId()]->GetName()), app, games[index]->GetId());
	}

	switch (choice)
	{
	case 'S':
	{
		SearchMenu("SEARCH GAMES", app, games);
	}break;
	case 'N':
	{
		if (app->GetStore().getGames().length() > Utils::GetCap(app->GetStore().getGames().length(), this->index, this->gameRows)) this->index += gameRows;
	}break;
	case 'P':
	{
		if (this->index >= gameRows) this->index -= gameRows;
	}break;
	}

	return false;

}

