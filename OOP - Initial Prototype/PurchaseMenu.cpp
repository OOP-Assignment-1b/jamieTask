#include "PurchaseMenu.h"

PurchaseMenu::PurchaseMenu(const std::string& title, Application* app, const int& index) : index(index), Menu(title, app)
{
	game = app->GetStore().getGames()[this->index];
	Paint(); // required in constructor
}

void PurchaseMenu::OutputOptions()
{
	Line(game->GetDescription());
	Line(Utils::formatCurrency("Cost: ", game->GetCost()));

	if (app->IsUserLoggedIn())
	{
		Line(Utils::formatCurrency("Credits: ", app->GetCurrentUser()->getCredits()));
		Line();

		int itemIndex = GetLibraryItemIndex();
		if (itemIndex >= 0) {

			auto games = dynamic_cast<Player*>(app->GetCurrentUser())->getAllItems();

			Line("You own this game!");

			Line();
			Line("Purchased: " + games[itemIndex]->GetPurchasedDate().getDate());
			double playTimeHours = games[itemIndex]->GetPlaytime() / 60.00f;
			Line("Playtime: " + Utils::formatPlayTime(playTimeHours, games[itemIndex]->getGame().GetName()));

			Line();
			Line("Review Purchased Game");

			if (!games[itemIndex]->GetHasReviewed()) {
				Option('L', "Like Game?");
				Option('D', "Dislike Game?");
			}
			else
			{
				Line("You have already reviewed!");
			}
		}
		else {
			Option('P', "Purchase " + game->GetName());
		}
	}

}



bool PurchaseMenu::HandleChoice(char choice)
{

	if (app->IsUserLoggedIn())
	{

		switch (choice)
		{

		case 'P': {
			Purchase();
		}break;
		case 'L': {
			ReviewGame(true);
		}break;
		case 'D': {
			ReviewGame(false);
		}break;
		}

	}


	return false;
}

const void PurchaseMenu::Purchase() {
	Player* player = dynamic_cast<Player*>(app->GetCurrentUser());
	if (player->getCredits() >= game->GetCost())
	{
		player->removeCredits(game->GetCost());
		player->addLibraryItem(new LibraryItem(Date(Utils::getDay(), Utils::getMonth(), Utils::getYear()), *game, 0));
	}
}

const void PurchaseMenu::ReviewGame(const bool& review) {
	int iteamIndex = GetLibraryItemIndex();
	if (iteamIndex >= 0) {
		if (!dynamic_cast<Player*>(app->GetCurrentUser())->getAllItems()[iteamIndex]->GetHasReviewed()) {
			game->AddReview(review);
			dynamic_cast<Player*>(app->GetCurrentUser())->getAllItems()[iteamIndex]->SetHasReviewed(true);
		}
	}
}

const int& PurchaseMenu::GetLibraryItemIndex() {
	std::vector<LibraryItem*> games = dynamic_cast<Player*>(app->GetCurrentUser())->getAllItems();
	for (int i = 0; i < games.size(); i++)
	{
		if (games[i]->getGame().GetName() == app->GetStore().getGames()[index]->GetName())
		{
			return i;
		}
	}

	return -1;
}
