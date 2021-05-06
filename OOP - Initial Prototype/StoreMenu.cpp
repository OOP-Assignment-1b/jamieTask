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

	for (int i = 0 + index; i < Utils::GetCap(app->GetStore().getGames().length(), this->index, this->gameRows); i++)
	{
		std::stringstream formatString;
		formatString << std::left << std::setfill(' ') << std::setw(15) << app->GetStore().getGames()[i]->GetName() << " | User Rating: " << std::to_string(app->GetStore().getGames()[i]->GetRating()) << "%";
		Option((i + 1) - index, formatString.str());
	}
	Line();
	Line("PAGE " + std::to_string(((index / gameRows) + 1)) + " OF " + std::to_string(static_cast<int>(ceil(static_cast<float>(app->GetStore().getGames().length()) / static_cast<float>(gameRows)))));
	if (app->GetStore().getGames().length() > Utils::GetCap(app->GetStore().getGames().length(), this->index, this->gameRows)) {
		Option('N', "Next Page");
	}

	if (index >= gameRows) {
		Option('P', "Back page");
	}

	Option('S', "Search");
}

bool StoreMenu::HandleChoice(char choice)
{
	// since we are using numbers here we shift the char down by '1'
	// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
	// this reverses the + 1 above and lets us do the range check below
	int index = choice - '1';
	index += this->index;

	if (index >= this->index && index <= Utils::GetCap(app->GetStore().getGames().length(), this->index, this->gameRows) - 1)
	{
		PurchaseMenu(Utils::toUpper(app->GetStore().getGames()[index]->GetName()), app, index);
	}
	switch (choice)
	{
	case 'S':
	{
		SearchMenu("SEARCHING GAMES", app, app->GetStore().getGames());
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