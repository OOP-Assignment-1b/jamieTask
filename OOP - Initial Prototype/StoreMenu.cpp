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
	int cap = app->GetStore().getGames().length();
	if (cap >= index + gameRows) cap = gameRows + index;

	for (int i = 0 + index; i < cap; i++)
	{
		std::stringstream formatString;
		formatString << std::left << std::setfill(' ') << std::setw(15) << app->GetStore().getGames()[i]->GetName() << " | User Rating: " << std::to_string(app->GetStore().getGames()[i]->GetRating()) << "%";
		Option(i + 1, formatString.str());
	}
	Line();
	if (app->GetStore().getGames().length() > cap) {
		Option('+', "Next Page");
	}

	if (index >= gameRows) {
		Option('-', "Back page");
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

	if (index >= 0 && index <= games.length())
	{
		PurchaseMenu(Utils::toUpper(app->GetStore().getGames()[index]->GetName()), app, index);

	}
	switch (choice)
	{
	case 'S':
	{
		auto t = app->GetStore().searchByName();
		for (int i = 0; i < t.length(); i++)
		{
			BlockingMessage("Game Found: " + t[i]);
		}
	}break;
	case '+':
	{
		if (app->GetStore().getGames().length() > this->index) this->index += gameRows;
	}break;
	case '-':
	{
		if (this->index >= gameRows) this->index -= gameRows;
	}break;

	}

	return false;
}